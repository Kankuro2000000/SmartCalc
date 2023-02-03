<h1 align="center">
  📖SmartCalc
</h1>

<p align="center">
	<b><i>Solving examples with brackets</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

## 💡 About the project
The goal of this project is to write a calculator that handles the operations + - / * mod ^ cos sin tan acos asin atan sqrt ln log with brackets
	

## 🛠️ Usage

The program is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions
Folder Terminal_version contains the version for use in the terminal

Use make command to build the project
```shell
make
```
To use the calculator, run it with one parameter, the example to be solved
```shell
./smart_calc "cos(1) - 23.5/3 + 0.3^2"
cos(1)-23.5/3+0.3^2 = -7.20303
```

## 📋 Testing

You can use bash script for testing.
```shell
make
./tests.sh 
```
