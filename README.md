This c file holds all the source code for converting between roman numerals and numbers. For compiling this file on windows, I like to use the developer command prompt for visual studios 2022. This makes it so the c file is placed in the current desired directory and can be built into an executable by running the command "cl filename.c". In this circumstance, the command is: cl numeralConverter.c.

Time spent: 3hrs 33min on planning, coding and editing.
I did have to change my strategy to simplify one of my conversions. That took longer than I expected.

Problem solving solution:
Converting from numerals to numbers was easy. I just looked at the current char and the next char to see if subtraction was need. If not, I added the value of the char to the total value.

I made converting from numbers to numerals a lot harder than necessary. I was trying to see if I could get the desired value using a combination of the current numeral and the next lowest numeral, but that require so much more work. It was after two hours that I realized that all I had to do was look for a 9 or a 4 in each digits place to see if a subtraction case was needed. After that, the code was much more simplistic. You will see that I approached a single digit at a time on my loop. That was kept the same the entire time.
