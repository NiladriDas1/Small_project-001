# Small_project-001
This project repository are based on Small piece  of code that work for big included idea's to in implement 
<h1>Automatic datatype in C</h1><br>
<div>
  This small project that help me out to make a auto detect datatype include you can use  these in any kind of project just call    the DATASET & define the pointer ,this data set as like worked of keyword.
  ex: <br>
  <br>//dont need to call any stdio.h,other hadder file just single file can handell entire datatype <br>
  <br>git clone "repo link"<br>Place the folder in the project area <br> Call the function:<br>
  <li>DATASET : Define the automatic datatype through the Pointer </li><div>DATASET *DATA; //VARIABLE NAME IS DATA </div>
  <li>input(char *arg):It's support the Null argument & give the user auto data enter option</li><div>input(NULL):Provide user give UI input or input("etc.. type of value")</div>
  <li>processInput(const char *input): Provide direct input option </li><div>processInput("etc.. type of value")</div>
  <li>printAllocatedData(DATASET *result): Print the all data has store in DATASET of variable</li><div>printAllocatedData("DATASET VARIABLE NAME SHOULD BE PLACE HERE")</div>
  <br>
  <br>#include  "data_controller.h"<br>
    int main(){  
    <br>DATASET *DATA=input("2838hELLO"); //calling the DATASET
    <br>printAllocatedData(DATA);//Print any kind of data type that has decleare through dataset
    <br>free(DATA); 
    <br>return 0;
  <br>}
</div>
