Guild-Wars-2-chat-separator
===========================

A small program for separating messages into segments sized for GW2 chat. 

The MMORPG by ArenaNet, Guild Wars 2, has a relatively low character-count limit in its chat box (199 chars).
So I decided to make a small program, just for the fun of it, that would read a message input from the console and 
output the message in segements sized for the chat limitation. This tool is mostly intede for Role-play purposes in that
it retains the mesage pre-fix (e.g. /e for emote, or /s for say) since Guild Wars 2 does not save /e as a default chat 
channel. 

-- HOW TO USE THE PROGRAM --
The program is named "GW2 chat separator.exe" located in the "Release" folder. 
The program operatoes through the console input and output, and though I recommend using the program with cmd target modifiers it can be used with manual typing in the cmd console. 

To use cmd target modifiers, open a cmd console to the folder containing the executable named above. Then use the input following the syntax: 

"GW2 chat separator.exe" < {message file} > {output file} 

Here {message file} denotes the name of a text file that contains the message (in a single paragraph!) and {output file} denotes the text file to output the result to (will create the file if it does not already exist - in which case the existing file will be overriden). For instance running the program could look like this:

"GW2 chat separator.exe" < message.txt > output.txt 

which would read the input from the message.txt file in the same folder as the .exe, and output it in the output.txt file in the same folder. 

If you wish to use it without these cmd target modifiers, open a cmd console and navigate to the folder holding the .exe. Run it and type in the input message. The output message will then be printed in the console for you to copy from. Note that running the .exe directly will close the program as soon as it has finished executing, not allowing you time to copy (or even see) the ouput. 

-- NOTE:
The program expects a chat command prefix (e.g. /e or /emote or /s etc) which it will duplicate in front of every segment the message is split into. This prefix MUST be separated from the message by a white-space. In other words, write the input message to the program excatly as you would inside Guild Wars 2 if it had no character limit to the chat messages.
