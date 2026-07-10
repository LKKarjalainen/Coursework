#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <target_timezone>"
  echo "Example: $0 GMT"
  exit 1
fi

case "${1^^}" in
  "GMT"|"UTC") TZ="UTC" ;;
  "EST") TZ="America/New_York" ;;
  "CST") TZ="America/Chicago" ;;
  "MST") TZ="America/Denver" ;;
  "PST") TZ="America/Los_Angeles" ;;
  "EET") TZ="Europe/Helsinki" ;;
  "CET") TZ="Europe/Paris" ;;
  "IST") TZ="Asia/Kolkata" ;;
  "JST") TZ="Asia/Tokyo" ;;
  "EAT") TZ="Africa/Nairobi" ;;
  "WAT") TZ="Africa/Lagos" ;;
  "AEST") TZ="Australia/Sydney" ;;
  *) TZ="$1" ;;
esac

if ! target_time=$(TZ="$TZ" date +"%Y-%m-%d %H:%M:%S" 2>/dev/null); then
  exit 1
fi

echo "$target_time"
