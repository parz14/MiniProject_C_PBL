# Requirements

## Introduction

* The main motive of this project is to understand and apply the learning of C and System / Software development life cycle (SDLC), In order to create projects with code features like: readable, portable, less prone to errors, easy to extend the features, adherence to coding standards and industry best practices.

* This project uses **data file handling** concepts of C programming to generate reciepts / invoices from a sample template based on some information required as user input. Large documentations with repeated entity values can be easily generated using this application of C language.

* *This project doesn't add or enhances any feature of existing application / utility / algorithm etc. It's just an application of programming concepts for learning purposes.*

## Research

### About Data File Handling

On an abstract level, a file is a collection of bytes stored on a storage device, which is generally a disk or other storage device. The collection of bytes may be interpreted, for example, as characters, words, lines, paragraphs and pages from a textual document; fields and records belonging to a database; or pixels from a graphical image. The meaning of the file is determined by the data structures and operations used by a program to process the file.

![Kind of files](https://www.mycplus.com/mycplus/wp-content/uploads/2008/09/file_handling_c.png)

* [source](https://www.mycplus.com/tutorials/c-programming-tutorials/file-handling/)

## Defining Our System

![basicstructure](https://user-images.githubusercontent.com/80450214/114393129-4ee6c880-9bb7-11eb-9e76-96546518ebc4.png)

### Explanation

* For this system user will enter the required data which is needed to be printed or available in reciept / document.
* Input data need to be arranged in order as per template file which is designed in a specific format.
* Output document is generated with all the information in required format. 
* Such applications are generally found in shopping malls, general stores, drive thrus etc.

## SWOT Analysis

![Automated Reciept generator](https://user-images.githubusercontent.com/80450214/114418283-fc65d600-9bcf-11eb-9e9c-fb5075601151.png)

## Detail Requirements

### 1. High level Requirements

| ID | Description | Status |
|-----|-----|-----|
|`hlr01` | Data input to be printed or available in reciept / document | Implemented |
| `hlr02` | Review of input details | Implemented |
| `hlr03` | Automatic total price calculation in bill templates | Implemented |

### 2. Low level Requirements

| ID | Description | HLR associativity | Status |
|-----|-----|-----|-----|
|`llr01` | User can choose between available templates | `hlr01` | Implemented |
|`llr02` | All the input data will depend on type or format of pre designed template | `hlr01` | Implemented |
| `llr03` | Option to change i.e, add or delete the input data | `hlr02` | Implemented |
| `llr04` | Allow user to calculate total price with discounts if applicable  | `hlr03` | Implemented |
