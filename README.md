# World's Best Graphing Calculator
 
 > Authors: \<[Edward Xia](https://github.com/dfire42), [Justin Pham](https://github.com/pjsrcool), [Phoenix Winter](https://github.com/PhoenixWinter542)\>

## Project Description
We decide on coding a graphing calculator because we all hate using our own calculators. It does not have the processing power. To implement this graphing calculator, we plan to use c++ and Qt Creator for c++. We will also use middle school level algebra.
* [qt](https://www.qt.io/) - C++ IDE GUI toolkit

Main Features:
* - Graph an equation
    - x^1
    - x^2
- Hold multiple equations
- Display multiple equations simultaneously
- Simplify equations automatically
- GUI based interface
- Input: linear or quadratic equation
- Output: visual graph of the equation

Proposed Features:
* Multiple variable functions
* Higher exponents

Design Patterns
* Strategy:
  - 2 different functions to interpret the equation input by the user
  - This makes interpreting the user input much simpler than having a large function inside the input class.
* Iterator:
  - Used to traverse the list of stored equations
  - Each line is represented with 3 objects, so creating our own iterators will make traversing them much easier.
* Mediator:
  - By consolidating the control system to a single class, we can ensure that all function calls operate the same way
  - Or
  - Ensures all function calls perform the same operations
  - Simplifies 

## Class Diagram
 Strategy
 ![Alt text](Strategy_Interpret_User_Input.jpeg?raw=true "Strategy")
 Iterator
 ![Alt text](Iterator_Draw_Graph.jpeg?raw=true "Iterator")
 Mediator
 ![Alt text](Mediator_GUI.jpeg?raw=true "Mediator")

 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
