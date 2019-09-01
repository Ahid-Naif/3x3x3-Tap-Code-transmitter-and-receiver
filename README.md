# 3x3x3-Tap-Code-transmitter-and-receiver

The 3x3x3 tap code is *designed* as a 3D array as the table code below:
<pre>
|-------|-------|-----------|
| A|B|C | D|E|F |   G|H|I   |
|-------|-------|-----------|
| J|K|L | M|N|O |   P|Q|R   |
|-------|-------|-----------|
| S|T|U | V|W|X | Y|Z|space |
|-------|-------|-----------|
</pre>
Pause length between dimensions: 1 <br>
Pause length between letters: 2 <br>

## Transmitter:

For example “HELLO” will be coded as:
<pre>
. ... ..  . .. ..  .. . ...  .. . ...  .. .. ...  
(   H  )  (   E  ) (   L  )  (   L  )  (   O   )
</pre>
Each (.) represents a 10 (one zero) signal.
Each "pause" is represented by 0 signal.
So, to transmit the word "Hello" in 3x3x3 tap code, we will transmit the mesaage below:
10 0 101010 0 1010 00 10 0 1010 0 1010 00 1010 0 10 0 101010 00 1010 0 10 0 101010 00 1010 0 1010 0 101010 00
(        H       )    (      E       )    (        L       )    (        L       )    (         O        )

The transmitter is 

## Receiver
On the other side, the receiver which is a microphone receives the sound signal and decodes back to retrieve the message "Hello".
