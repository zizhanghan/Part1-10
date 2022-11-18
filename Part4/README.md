* Update your sequencer to be able to slow down and speed up recordings/replay. On the input side, the goal is ultimately to be able to handle the full 4 Gbps "firehose" from the PIO logic analyzer example in the SDK manual, which would fill up 256Kb of RAM in only 31 µs at a system clock speed of 125000 MHz if captured 'raw'! On the output side, the goal is to be able to output precisely timed sequences from the PIO at system clock resolution based on a handful of control points.

update your sequencer to be able to record just the timestamped transitions between input values, and to be able to play data in this format
give your sequencer the ability to select a range of output rates for both live and recorded input

I make the delay in part3 to vary to achieve the slow motion and fast motion.

https://github.com/zizhanghan/Part1-10/blob/main/Part4/b415bda593945a6901d193b8ab20a246.mp4
