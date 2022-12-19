# CS210 Clock

- Summarize the project and what problem it was solving.
  - I was tasked with creating a clock as part of an interview process for Chada Tech. The clock had to meet international standard ISO 8601. It also had to be displayed in 12 and 24 hour format on their website for clients. I had to code a clock that displayed both formats simultaneously as well as allow the client the ability to adjust the time if they wanted to. 

- What did you do particularly well?
  - I did well at creating a clock that would get the local system time to initialize the program. I also did well at making user adjusted time changes look seamless.

- Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  - I could likely make a single function instead of two that would handle the clock screen refreshing. I would also make a separate class file to handle the clock instead of having everything in one cpp file.

- Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  - The most challengeing pieces were the functions to handle clearing the screen and hiding the cursor. When I was building the clock, I used system("CLS") to refresh the screen, but I didn't like the blinking effect that came with it. I did a deep dive search for resources to solve this issue and found a way to not have the screen or cursor blink when the screen updated the clock. I'll be adding programming language documentation as well relevant YouTube videos to my support network.

- What skills from this project will be particularly transferable to other projects or course work?
  - The biggest skill that will be transferable is how to separate classes into separate files. This will allow my future programs to be more maintainable and adaptable.
  
- How did you make this program maintainable, readable, and adaptable?
  - I created a class for the program that makes it maintainable and adaptable. I also included white spaces, comments, as well as appropriately named variables and functions so it's readable. For the future, I would create the class in a separate file or files to make it more maintainable and adaptable. 
