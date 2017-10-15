# Myo AI Rock-Paper-Scissors
## Inspiration
We wanted to make a fun project that had large-scale impact and engaged our audience. After hours of brainstorming and determining the limits of our available hardware and skillsets, we decided to develop Rock-Paper-Myo.

## What It Does
We built a Myo Armband and Arduino-based Rock Paper Scissors player that will detect your move and beat you. It is a first step towards more complex EMG analysis, and an inspirational tool to help students see the potential of tech.

## How We Built it
### Using Myo Armband
A Myo is a device worn around your forearm that has a 9 axis IMU, which is composed of an accelerometer and gyroscope, and an 8 point EMG sensor which reads the electric signals from forearm muscles. We used the Myo to differentiate between the three gestures we use in rock paper scissor.

### Using An Arduino
Once the motion is detected and classified by the Myo, this data is relayed to an Arduino Uno. Each player gesture corresponds to an IO pin which gets the signal to rotate the winning servo arm; we made one arm for each play position: rock, paper and scissors.
## Challenges We Ran Into
#### Battery Issue
The servos that we had were high powered, and took a very high amount of current, about 1A max each, along with about 5-10V each. Since we were using 3 servos in parallel, the power needed was too high for just an arduino to supply. We fixed this by using an external 9V battery connected to the breadboard. In an effort to not ruin our battery during testing, we used LEDs instead of Servo motors during the testing phase so that we do not have to attach an external power source.

#### Mapping Correct Gestures
Myo classifies a few basic motions that include making a fist, spreading your fingers, waving in, waving out and tapping your middle finger against your thumb twice. For this project, we mapped the fist action to be our rock and the spread finger action to be our paper but when we mapped scissors we ran into several issues. One issue was that tapping your fingers twice the action we used for scissors is the Myo’s default locking gesture, which turned the device gesture recognition off to prevent unwanted actions. We fixed this by turning the device’s locking state to always active.

## Accomplishments that we're proud of
We got the Arduino and Myo to interface, reading gesture data from the Myo and passing it to the Arduino. Using these two technologies side-by-side was a massive challenge, but we are very happy that we got it working. We are also proud of overcoming hardware limitations using innovative solutions. 

## What we learned
As a team, we learning more about how technologies interface, as well as a lot of non-technical skills. Communication was a large part of the project, as the code and the circuit building were tightly integrated. All the team members learned more about Arduino.

## What's next for Rock-Paper-Myo
Rock-Paper-Myo impacts society in two major ways: Applicability and Accessibility.
### Applicability 
This project is a step forward in human motion detection, and interfacing with computers in a different way. It is a base-case for a future where human actions can be read accurately and processed precisely and quickly. 
* For patients with Multiple Sclerosis or Muscular Dystrophy, sensors and software like this can be used to detect precise muscle movements and map them to actions that . The readings from the Myo Armband can be substituted with EMG Readings from sensors on any part of the body. These sensors are much more portable and extensible to different applications.
* To take this further, the EMG mapping functionality can be made into an API, which can be developed to make custom gestures.
* Machine Learning can be used to map EMG commands to accurate muscle movements. This is the hardest part of using this data currently, and using classifiers such as Support Vector Machines (SVMs) and Random Forest Classifiers on data from hundreds of patients can be used to accurately know exactly what part of the body is moving. 
 
The impact is vast. There are more than 2.5 million cases of MS in the world, and Muscular Dystrophy affects more than 1 in 7000 males. A software like this would be able to provide accurate support to these people, safely and reliably with the help of technology.
 
### Accessibility 
A student playing a game of rock-paper-scissors can suddenly play against an AI that recognizes his or her hand motion, and will beat them (or let them win).  Anybody can play rock-paper-scissors, and any student can see the impact of such a project and technology in general on the everyday lives of people. We hope that this project, and the accompanying video, that will be released to middle-school students across the country, will inspire bright young minds to enter into the technology fields and create the next big innovations.
