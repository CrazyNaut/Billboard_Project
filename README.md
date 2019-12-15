# Billboard_Project

BLE Billboard Project<br>
<b>Group Members</b>: Peter Giordano, Leonardo Camaj, Arturo Palomino<br>
<b>Class</b>: Embedded Systems (EECE 321 - 02), Professor Ahmed Hussein

Based on Project 37 in "100 Projects in 100 Days" by Cypress.

<p>Our project entailed coding for a BLE Billboard and then getting a message to show up on the billboard. The billboard itself consits of 4 8x8 Matrix modules to display the message. To get the message on the billboard the user will have to input it on the CySmart App using a mobile phone. We connected the billboard to a computer, then using the Cypress program were able to edit the code for the billboard. We modified our program to change the lighting of the LEDS, and display  various messages, including the default, "PSoC  Rocks!" message. The CY8CKIT-042-BLE board is bluetooth so no wires are needed to update the message being displayed. The CySmart App has an ASCII section, here you type your message, below it is the HEX section that converts the ASCII characters into hexadecimal. The App also includes the date and time in which the message will be displayed. Once a message is ready to be displayed we press the "Write" button to write our message to the board, then we press the "Read" button display the message on the board. </p>
