#  Made By: Sagar Ghai and Ankur Sardar
# IIT Mandi

import sys
import os
from Tkinter import *
import tkFileDialog

filename=""
ip=""

def send():
	global filename
	global root
	command="./a.out 1 "+filename+" "+"random"+"&"
	h1=Label(root,text=filename).pack()
	os.system(command)
	os.system("clear")
	root.destroy()
	return

def rec():
	global filename
	global ip
	global root
	command="./a.out 2 "+filename+" "+ip
	h1=Label(root,text=filename).pack()
	os.system(command)
	root.destroy()
	return

def filerec():
	global filename
	global n
	filename=n.get()
	bs=Button(root,text="Recieve", command = rec).pack()


def iprec():
	global ip
	global s
	global n
	ip=s.get()
	h4=Label(root, text="Enter Filename").pack()
	select2=Entry(root, textvariable=n).pack()
	bs2=Button(root,text="next", command = filerec).pack()
	

def sender():
	global command
	global v
	global filename
	global ip
	global s
	choice=v.get()
	if choice==1: # run server command
		filename = tkFileDialog.askopenfilename()
		bc=Button(root,text="Send", command = send).pack()

	elif choice==2: # run client command
		h3=Label(root, text="Enter Sender IP").pack()
		select1=Entry(root, textvariable=s).pack()
		bs1=Button(root,text="next", command = iprec).pack()

root=Tk()
root.geometry("450x450+300+300")
root.wm_title("MINION 0.1")
s=StringVar()
n=StringVar()
h1=Label(root,text="File sharing made Fast and Easy!").pack()
h2=Label(root,text="Choose One!").pack()
v = IntVar()
Radiobutton(root, text="Send", variable=v, value=1).pack()
Radiobutton(root, text="Recieve", variable=v, value=2).pack()
b1=Button(root,text="Let's Go", command = sender).pack()
root.mainloop()