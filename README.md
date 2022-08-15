# Random Password Generator

This super-simple program generates passwords of any length, using random ASCII characters.  I've seen other programs like this, but they tend to use actual random numbers (which can be so low they're non-printable or so high they're Unicode - both of which may not play nice with password managers).  I personally prefer to use 80, so I can still copy it from the terminal.  But if you wanted to, you could do something crazy like this:

`random-password-generator 2048 > someFile.txt`

And then open it in a GUI text editor where you can copy the whole thing.  I actually use this (with KeePass, obviously) and it's great.  The passwords it creates are stronger than anything I could come up with.  But obviously, this software is ***AS-IS*** - don't blame me or my program if you get hacked.
