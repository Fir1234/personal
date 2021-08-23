CI | Build | Code Quality | Unity | Git Inspector | 
------|----------|-------|--------------|-------
[![CI](https://github.com/ajith-io/SDLC_18_Geek_Squad/actions/workflows/main.yml/badge.svg)]| |*![Code Quality](https://www.code-inspector.com/project/26754/score/svg)
version: 0.2
phases:
  install:
    runtime-versions:
      nodejs: 12
  pre_build:
    commands:
      - buildExitCode=1
      - echo Logging into install phase...
      - yum update -y
      - yum install sudo -y
  build:
    commands:
      - echo Build started
      - (cd nodejs-app; npm install)
      - buildExitCode=$?
    finally:
      - |
        if [ "$buildExitCode" -ne 0 ]; then
          badge_status=failing
          badge_colour=red
        else
          badge_status=passing
          badge_colour=green
        fi
      - curl -s "https://img.shields.io/badge/Build-$badge_status-$badge_colour.svg" > ${GithubBranch}-build.svg
      - aws s3 cp ${GithubBranch}-build.svg s3://${S3Bucket}/badges/${GithubBranch}-build.svg --acl public-read --cache-control no-cache
  post_build:
    commands:
      - echo Build completed on `date`
