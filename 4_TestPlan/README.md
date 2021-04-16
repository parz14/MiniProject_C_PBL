# Test Plan:

## High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|
|  H_01       | Generation of document after execution| all input information | genbill.txt | SUCCESS |
|  H_02       | Array of structure based on number of inputs| Enter no. of item : `3` | dynamic allocation of `3` blocks of the size of structure| SUCCESS|
|  H_03       | Asking user for review of I/P details| `Y` for yes, `N` for no  | `Y`= display all I/P details, `N`= details saved!| PASS|
| H_04 | Items price and quantity calculation | info entered in item details | calculate total price and quantity| SUCCESS| 


## Low level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |   
|-------------|--------------------------------------------------------------|------------|-------------|----------------|
|  L_01, H_03       | Change I/P details| `Y` for yes, `N` for no  | `Y`= enter new details, `N`= details saved!| PASS|
|  L_02, H_04       | Discount calculation in total price| `Y` for apply discount, `N` for no discount  | `Y`= final price= total price(with applied discount), `N`= final price= total price| PASS|
