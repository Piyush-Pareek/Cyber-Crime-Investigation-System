Cyber Crime Investigation System
Welcome to the official repository for our Cyber Crime Investigation System. This project is a command-line application developed in C that uses various Data Structures and Algorithms to efficiently manage and analyze data related to criminal investigations.

Team Members
Piyush Pareek (@Piyush-Pareek)

Bhavya Jain (@bhavya-jain22)

Vansh Verma (@vanshverma27)

Project Goals
Case Management: Use a Priority Queue to manage and prioritize active cases, ensuring urgent cases are handled first.

Evidence Management: Implement a Hash Table for instant storage and retrieval of evidence logs by their unique ID.

Suspect Network Analysis: Build a Graph data structure (Adjacency List) to map and visualize connections between suspects.

IP Log Analysis: Utilize a Trie and Stack for efficient searching and analysis of network IP logs.

💻 Our Development Workflow
This is the most important section. To ensure we can all work together without creating conflicts, we must follow this process every time we write code.

1. One-Time Setup: Cloning the Repository
If you haven't already, you need to get the project files on your local computer.

# Clone the repository to your machine
git clone [https://github.com/Piyush-Pareek/Cyber-Crime-Investigation-System.git](https://github.com/Piyush-Pareek/Cyber-Crime-Investigation-System.git)

# Navigate into the project directory
cd Cyber-Crime-Investigation-System

2. The Daily Coding Cycle
Follow these steps for every task you work on. A task is one of the cards on our project board.

Step A: Get the Latest Code
Before you start writing, always make sure your local main branch is up-to-date with the GitHub repository.

# Switch to the main branch
git checkout main

# Pull the latest changes from GitHub
git pull origin main

Step B: Create Your Feature Branch
Never work directly on the main branch! Create a new branch for the specific feature you are working on. Use a clear naming convention: feature/yourname/what-you-are-doing.

# Example for Bhavya working on the 'add-case' function
git checkout -b feature/bhavya/add-case-function

Project Board Update: As soon as you create your branch, go to our Project Board and move your assigned task card from "Ready" to "In progress".

Step C: Write Your Code & Commit Your Changes
This is where you do your work! Write the code for your feature. Save your progress frequently using git commit.

# After making some changes, add the files to the staging area
git add .

# Save your changes with a clear, descriptive message
git commit -m "feat: Implement user input for adding new cases"

(Pro-tip: Commit small, logical chunks of work. It's easier to track changes that way.)

Step D: Push Your Branch to GitHub
When your feature is complete and tested, push your branch (with all its commits) to the GitHub repository.

# Push your specific branch. Git will give you this exact command the first time.
git push --set-upstream origin feature/bhavya/add-case-function

Step E: Create a Pull Request (PR)
A Pull Request is a formal request to merge your changes into the main branch.

Go to the repository on GitHub. You will see a green button to "Compare & pull request". Click it.

Give your PR a clear title (e.g., "Adds add_new_case() function").

In the description, briefly explain what you did.

On the right side, add the other two team members as "Reviewers".

Project Board Update: Now that your code is ready for review, move your task card from "In progress" to "In review".

3. Code Review and Merging
The assigned reviewers will look at your code. They might approve it or request changes.

If changes are requested: Make the changes on your local feature branch, commit them, and push them again. The Pull Request will update automatically.

Once approved: One of the reviewers will click the "Merge pull request" button. Your code is now officially part of the main project!

Project Board Update: The owner of the task moves the card from "In review" to "Done". Congratulations! 🎉

compiling and running
(This section will be updated once we have a Makefile.)

To compile the project, you will need a C compiler like GCC.

# Example compilation command (will be improved later)
gcc main.c case_management.c evidence_management.c suspect_network.c -o investigation_tool
