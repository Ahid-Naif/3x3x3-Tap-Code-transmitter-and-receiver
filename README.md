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
* Pause length between dimensions: 1 <br>
* Pause length between letters: 2 <br>

## Transmitter:

* The transmitter is a `buzzer` that makes a sound when the signal wave is `HIGH` or `1`, and it stops if the signal is `LOW` or `0` for an interval of time called `period`.
* Each (.) represents a `10` (one zero) *signal*.
* Each "pause" is represented by `0` *signal*.
* So, to transmit the word "Hello" in **3x3x3** tap code, we will send the mesaage below to the `buzzer`:<br>
10 *0* 101010 *0* 1010 **00** 10 *0* 1010 *0* 1010 **00** 1010 *0* 10 *0* 101010 **00** 1010 *0* 10 *0* 101010 **00** 1010 *0* 1010 *0* 101010 **00**<br>
* For example “HELLO” will be coded as:
<pre>
. ... ..  . .. ..  .. . ...  .. . ...  .. .. ...  
(   H  )  (   E  ) (   L  )  (   L  )  (   O   )
</pre>

### Circuit
![](https://github.com/Ahid-Naif/3x3x3-Tap-Code-transmitter-and-receiver/blob/master/Circuit%20schematic/Sound_Transmitter.png)
## Receiver
On the other side, the receiver which is a digital microphone receives the sound signal and decodes it back to retrieve the message "Hello". There is a low-pass filter applied to the circuit to remove any noise from the readings of the microphone.

### Circuit
![](https://github.com/Ahid-Naif/3x3x3-Tap-Code-transmitter-and-receiver/blob/master/Circuit%20schematic/sound_receiver.png)
* **Note**: the used capcitor is a ceramic capacitor.
