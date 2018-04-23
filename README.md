# Waffle [![Build Status](https://travis-ci.org/kamejosh/waffle.svg?branch=master)](https://travis-ci.org/kamejosh/waffle) [![BCH compliance](https://bettercodehub.com/edge/badge/kamejosh/waffle?branch=master)](https://bettercodehub.com/)

A microcontroller framework which provides an easy solution to connect devices to the internet.

This project is maintained by @Fitzi, @litterboks and @kamejosh. You can contribute by forking and creating a Pull Request with you suggested changes.

## Setup

1. Fork the framework and create clone the forked project on your machine
2. Open `platformio.ini` and remove all boards you are not using (e.g. if you use the esp8266, only keep the `[env:nodemcuv2]` block)
3. Open `src/config.h` and check if the default settings work four you
4. Implement your project in `src/app/...`

## Framework
The framwork is built as a basic state machine. Per default, it consists of 3 states: selfcheck, hotspot and app state.

### Selfcheck state
Note: This state is not implemented yet. It will come in the future.
This state will check if wifi access data is persisted and can be connected to. If the connection succeeded, the state machine will switch to your app state, otherwise the hotspot state is opened.

### Hotspot state
Once switched to hotspot state, a hotspot (or access point) will be opened. Its default name is `Waffle` and default password is `PrettyFlyForAWiFi` however you can changes these in `src/config.h` by changing `HOTSPOT_SSID ` and `HOTSPOT_PASSWD`.
You can then connect to the hotspot and open `http://127.0.0.1` in your browser (on your mobile device or computer) an see the wifi dialog. Choose your home wifi and password and save. The framework will then change to your app state.

### App state
This is the entry point for your project. As a rule of thumb you should put your code in `src/app` and you should not change any of the other code (except config.h)

Per default you will find `src/app/setup.cpp`, `src/app/app.h`and `src/app/app.cpp` in the project.
Put all your code that initializes hardware (everything you would put in the arduino setup function) into the setup.cpp setup function and your loop into the app.cpp within the loop method. You can find more information directly in those files.

## State Machine
The framework is basically a state machine. Every piece of code must be withing a state. To make your own state, simply subclass state and implement your own state. For the state switching logic, there is also a class statemachine (which subclasses state itself) which acts as a container for multiple substates. Per default, a statemachine instance has no other logic then exectuing and switching between its registered substates. If you need to add custom logic, you simply subclass statemachine. (Dont forget to call `parent::loop()` withing your subclass.)

More information to the state machine implementation will follow.
