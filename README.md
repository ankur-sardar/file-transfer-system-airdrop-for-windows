# file-transfer-system-airdrop-for-windows


Audio/Video Slides (Youtube public link): [click here](https://www.youtube.com/watch?v=qlAoMFWXEEM&feature=youtu.be)

PPT(in pdf format): [click here](https://drive.google.com/file/d/1EHDyd2dno58YGTTQSGycbTXnEvYKNXS_/view?usp=sharing)


## Introduction

Detailed project report [Click here](https://drive.google.com/file/d/1J6bqp6LI2IzUYWFZgzue78fnW0GExLX6/view?usp=sharing)


## Motivation

Sometimes it became difficult to transfer files across devices without adhering to the monopoly of pen drives. So something that can transfer files locally and imitate what pen drives do but without the hardware.


## Problem Statement

Design a small and efficient software to transfer files locally across devices without even touching any additional hardware


## Work Done

I have tried to accomplish the task by using a C script that creates a socket and starts receiving input connections. Further it Transfers the file chosen by the user in the form of small packets as messages. The receiver interprets these and collects them together into one single file. 
1. C Script that controls the background behaviour - Socket programming and file input output using any type of file (pdf, txt, mp3, mp4 etc)


2. GUI made using python Tkinter - a library that enables us to code the gui.



## Limitations

1. We are still working on how to transfer multiple files in one go.


2. Cannot automatically detect filename and extensions.



## How to Install

1. Unzip the minion.zip file and voila you are done.
2. The minion.py file is the one you need to run every time


## How to Run

1. Go to the folder with the minon.py and script executable
2.Run the following command $ python minion.py and follow the instructions on screen.



What are the learning outcome form this project
The project taught me the basics and advanced levels of socket programming. The project also taught the basics of networking as to how packets are transferred across the local network. 

Socket Programming and Python Tkinter


Sending packets of data across a network and over to clients.
