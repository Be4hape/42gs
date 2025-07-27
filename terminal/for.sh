#!/usr/bin/env bash
# for_git_configsetup.sh

#— 컬러 & 스타일 정의 (ANSI-C quoting) —#
RED=$'\e[31m'; GREEN=$'\e[32m'; YELLOW=$'\e[33m'; BLUE=$'\e[34m'
BOLD=$'\e[1m'; RESET=$'\e[0m'

#— 섹션 헤더 —#
header() {
  echo -e "${BOLD}${BLUE}========================================${RESET}"
  echo -e "${BOLD}${BLUE}  $1${RESET}"
  echo -e "${BOLD}${BLUE}========================================${RESET}"
  sleep 0.3
}

#— 랜덤 청크 단위 타이핑 효과 —#
type_msg_rand_chunk() {
  local text="$1"
  local delay="${2:-0.009}"
  local min="${3:-1}"
  local max="${4:-3}"
  local len=${#text}
  local i=0

  while (( i < len )); do
    local range=$(( max - min + 1 ))
    local chunk=$(( RANDOM % range + min ))
    (( i + chunk > len )) && chunk=$(( len - i ))
    printf "%s" "${text:i:chunk}"
    sleep "$delay"
    (( i += chunk ))
  done
  printf "\n"
}

########## 스크립트 시작 ##########

header "GIT CONFIGURATION"
type_msg_rand_chunk "${YELLOW}• INITIATE user.email configuration — qkrtlgud95@naver.com${RESET}"
git config --global user.email "qkrtlgud95@naver.com"
sleep 0.4

type_msg_rand_chunk "${YELLOW}• INITIATE user.name configuration — si-park${RESET}"
git config --global user.name "si-park"
sleep 0.4

type_msg_rand_chunk "${GREEN}✔ GIT CONFIGURATION COMPLETE — SYSTEMS GO${RESET}"
sleep 0.8


header "DISPLAY & BRIGHTNESS"
type_msg_rand_chunk "${YELLOW}• SCAN display outputs…${RESET}"
sleep 0.3
xrandr -q
sleep 0.6

type_msg_rand_chunk "${YELLOW}• EXECUTE brightness adjust — HDMI‑1 → 1.1${RESET}"
sleep 0.4
xrandr --output HDMI-1 --brightness 1.1
sleep 0.4

type_msg_rand_chunk "${GREEN}✔ BRIGHTNESS CONTROL COMPLETE — NOMINAL${RESET}"



## github pull 덮어쓰기
## git fetch --all
#### git reset --hard origin/master ##
