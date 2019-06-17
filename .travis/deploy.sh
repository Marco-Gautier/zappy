#!/bin/bash
set -e
git config --global push.default simple # we only want to push one branch — master
# specify the repo on the live server as a remote repo, and name it 'production'
# <user> here is the separate user you created for deploying
git remote add production ssh://marco@51.77.202.182:4242/home/marco/apps/zappy-deploy
git push --force production master # push our updates
ssh marco@51.77.202.182 -p 4242 "sh -c 'cd apps/zappy-deploy; nohup docker-compose up --build > /dev/null 2>&1 &'"