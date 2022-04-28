# cs135contract

Contract course project for CS 135 fall 2021 semester at the University of Nevada Reno

How to run ///// In order to run the project, download hangman.c and compile. You can choose to download any of the 4 .txt files which contain a phrase to guess and a hint, or you can write your own .txt file. The first line should be the phrase to guess in all lower case and the second line should read "Hint: " followed by the hint phrase. Execute with this .txt file.

Description ///// This project is a terminal-based gamed of hangman in C. There were a few restrictions put it place by my professor, one of them being staying away from strings and instead using only char arrays. I also had to demonstrate an understanding of command line arguments and file I/O. I initially created this project in December 2021 but did not create a git repository for it at the time.

Expected performance ///// Upon running, the terminal should display "***WELCOME TO HANGMAN*** Enter your guess one character at a time (lowercase). You are allowed six mitakes! After that, it's GAME OVER. Good luck!" followed by an empty hangman, a hint, underscores representing the phrase to guess, and a reminder of the previous letter you already guessed. As you play, the phrase should either fill with the correctly-guessed letter, or the hangman display will fill with the next part of the body. At the end, you should see a win or lose outcome and it will exit.
