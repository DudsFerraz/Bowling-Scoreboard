# Bowling-Scoreboard

## Made by Eduardo Ferraz.

## This is a project made for my software engineering degree.

### Project description:

#### The score is the sum of the knocked-down pins.
#### Except when a strike occurs (knocking down 10 pins with the first ball) or a spare (knocking down 10 pins with two balls):
#### If a strike occurs, the player earns a bonus based on the number of pins knocked down in the next two balls.
#### If a spare occurs, the player earns a bonus based on the pins knocked down in the next ball.
#### A bowling game score can range from zero (when no pins are knocked down in the ten rounds or "frames") to a maximum of 300 points, which means achieving 12 consecutive strikes. Theoretically, since each game has 10 frames, it’s only possible to get 10 strikes. However, if the player knocks down all pins in the first roll of the 10th frame, they are allowed to throw two more balls, potentially completing 12 strikes in the same game.

#### Write a program that reads the number of pins knocked down by a bowler on each roll and outputs:

#### The sequence of knocked-down pins
#### The final score of the player.

#### Input and Output Format:

#### Input:
#### The input consists of a single line containing a sequence of integers. Each integer represents the number of pins knocked down on that roll.

#### Output:
#### The output should have two lines: The first line should represent the score in the format shown in the examples below, where each frame is separated by a vertical bar. A strike is represented by an "X", and a spare is represented by a "/". The second line of the output should show the total score obtained by the player.