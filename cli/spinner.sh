#!/bin/bash
# Shows a spinner while another command is running. Randomly picks one of 12 spinner styles.
# @args command to run (with any parameters) while showing a spinner. 
#       E.g. ‹spinner sleep 10›

function shutdown() {
    tput cnorm # reset cursor
}

if [ "$CI_MODE" != "1" ];then
    trap shutdown EXIT
fi

function cursorBack() {
    echo -en "\033[$1D"
}

function spinner() {
    # make sure we use non-unicode character type locale 
    # (that way it works for any locale as long as the font supports the characters)
    local LC_CTYPE=C

    local pid=$1 # Process Id of the previous running command

    local spin='⣾⣽⣻⢿⡿⣟⣯⣷'
    local charwidth=3

    local i=0
    tput civis # cursor invisible
    while kill -0 $pid 2>/dev/null; do
        local i=$(((i + $charwidth) % ${#spin}))
        echo -n -e "\e[0;33m${spin:$i:$charwidth} \e[0m$message"

        cursorBack 999
        sleep .1
    done
    tput cnorm
    wait $pid # capture exit code
    return $?
}

if [ "$CI_MODE" = "1" ];then
    message=$1
    shift
    echo -e "\e[0;93m$message\e[0m"
    ("$@")
else
    message=$1
    shift
    ("$@") &
    spinner $! $message
    echo -e "\e[32m✔\e[0m $message                \e[0m"
fi