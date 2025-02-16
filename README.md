# FDM_C++
The repository contains codes that I wrote while practicing OOP. Following are the description along with some results of different files.

## FDM.cpp
The code solves the ODE dn/dt=-an analytically and using Finite Difference Method (forward differencing). It also calculates the absolute error between the two. Following graph shows the values calculated by two methods.
![Screenshot from 2023-10-07 16-49-27](https://github.com/mehulbakhshi02/OOP_Practice/assets/85863039/97680539-32b0-4b31-b2b5-0bf9f6a1216c)

## FDMMethod.cpp
The code solves the ODE dn/dt=-an using central differencing, forward differencing and backward differencing methods.

## 1DHT.cpp
The code determines steady state temperature distribution in a fin as shown in below. 
![Screenshot from 2023-10-07 15-30-02](https://github.com/mehulbakhshi02/OOP_Practice/assets/85863039/1682f1d8-44ba-47e4-8cdf-7006092136f1)

The code uses FDM with Drichelt and Neumann Boundary Conditions at the two ends. The below graph shows temperature distribution across the fin.
![Screenshot from 2023-10-07 16-59-55](https://github.com/mehulbakhshi02/OOP_Practice/assets/85863039/56b2b8ff-698b-49e2-b8a8-d47715779c5a)

## gauss_seidel.cpp
The code solves Ax=b using the gauss-seidel method.
