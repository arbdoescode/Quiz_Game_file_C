Arb Koçi

Note:The c++ is at the main.cpp file, everything except main, question and README are unnecessary(theres a problem with MacBook zip files)

When you run the program it will show the intro, and a sign that says the number of users registered in page, it updates overtime and it shows 1 in the beginning because there exists an admin account.
It asks to press “L” to log in or “R” to register ,it doesn’t matter if used caps lock letters , it will work
in both scenarios. 
When u register you will input the name, surname, age, username(don’t  use existing ones cause it won’t allow you and will ask you again) and a password. After every registration
it will you to log in, if you press “N” it will print a warming quote and exit the program, if you press “Y” it will send u to the log in menu, where you will log in(use an existing username and corresponding password or it will keep asking you to try again till you get right). 
After u log in it will send you to the user menu when u have “1”Start the contest “2”Check stats “3”Check categories “4”Log out.
	1- When u start will give u some instructions to press “1” for first alternative and “2” for second.
	    To start the test you need to press ENTER. One the beginning will be printed your ID ,test ID
	    and exact time when test started, and than you will solve questions one by one till the end.
	    After you will finish it will show your score.An “test.txt” file will appear if not existing and it
	    will save all the tests that will be taken in that page.
	2-It will show the score of tests from the earliest to oldest(you will have access only on your 
	   tests, you won’t be able to see other users tests) and will ask you if you want to check the 	   sheet, if you press “N” will go back to user menu, if “Y” type the ID of the sheet that u want 	   and it will appear in terminal.
	3-Will send you to another menu where will be shown 3 choices(4 if u add questions with 	   admin) choose your categories and will tell you your overall performance of that type of 
	   questions.
	4-Send you to main page when you can add more users or log in to existing ones.
If the page hits 3 users or more it will show another switch in which if you press “T” will show the first 5 users of page and their scores.

If you log in with the username “admin” and password “godmode” you will be pended int a different menu. You have 5 choices :
	1-Adds a question and answer to the file that saves them “questions.txt” and the questions that 	   the users will be taking after will be longer.
	2-Shows the list of all users with their full name, age and overall scores.
	3-All you need to put is the name of user and it will show all their information, including
 	   username and password(if someone forgets them)
	4-Will compare which contester has better rate with the algorithmic equation that I have 	  
 made(it’s just average), and will show the table of sorting the best contester and the worst with their scores.
	5-You will choose between one of the three categories of subjects, and it will show the user that has finished with the best scores.
	6-It logs out and sends you to main page.

If you want to kill the program, type “exit” or anything that you want, as long that it is not “L”,”R” or “T”
It will do the job.
