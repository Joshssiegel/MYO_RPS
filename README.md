# Myo AI Rock-Paper-Scissors
Use a Myo armband and an arduino to beat everyone in rock paper scissors
## General Plan for the Project
### Using an arduino
An arduino will be used to make "arms" that you can play rock paper scissors against.  There will be three arms, one for each position (Rock, Paper, Scissors). The hands are connected using servo motors which can be triggered using the IO pins on an Arduino Uno to lower the corresponding hand.
### Using Myo Armband
A Myo Armband will be used to detect what the player is throwing. To differentiate between hand motions, we will use a machine learning one-to-all classifier. 
### Connecting the game
After recieving input from the Myo, the arduino will lower the appropriate position, beating the player.

## Future Plans and Implications
This project is a step forward in human motion detection, and interfacing with computers in a different way. This is a base-case for the future, where human actions can be read accurately and processed appropriately.
Major implications of this are in the healthcare industry, where reading arm motions from disabled people will enable nursing homes and hospitals to accurately and quickly ensure the proper responses.
