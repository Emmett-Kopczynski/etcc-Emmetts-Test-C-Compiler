# etcc : Emmett's-Test-C-Compiler
<hr />
<br />

<h2>Basic Dependencies</h2>
<p>
gcc <br />
make <br />
NOTE :: built to run on a Linux machine with x86_64 CPU Architecture <br />
</p>

<br />
<br />

<h2>Usage</h2>
<p> 
etcc ~ emmetts test c compiler :: not recommended for usage in large projects<br />
<br />
Usage ::<br />
     &emsp;&emsp;etcc &nbsp; [flags] &nbsp; INPUT_FILE<br />
<br />
Flags : <br />
     &emsp;&emsp;-P : runs only the preprocessor<br />
<br />
     &emsp;&emsp;-S : emits an assembly file, but does not link or assemble it<br />
<br />
     &emsp;&emsp;--lex : Direts the compiler to run the lexer, but stop before parsing<br />
    <br />
    &emsp;&emsp;--parse : Directs the compiler to run the lexer and the parser, but stop before assembly generation<br />
    <br />
     &emsp;&emsp;--codegen : Directs the compiler run the lexer, the parser, and assembly generation, but stop before code emission<br />
</p>

<br />
<br />

<h2>Features and Explanations</h2>
<p>
  Currently, etcc is a very limited c compiler, limited to c code that returns an integer, <br />
  but there are plans to greatly expand it in the future. <br /> 
  <br />
  <br />
  
  Features to be added in the future include but are not limited to <br /> 
  - bit-wise operations <br />
  - decrement/increment operators <br />
  - arithmetic <br />
  - variables <br />
  - and more! <br />
  
  <br /> 
  <br />
  Preprocessing, Assembling, and Linking are all handled by gcc, etcc only handles compilation, and it does so in four steps: <br />
  <br />
  1: Lexing (Handled by the Lexer module) : Takes a preprocessed source file and converts it into a Queue of Tokens to be fed into the Parser <br />
  <br />
  2: Parsing (Handled by the Parser module) : Takes the Queue of Tokens fed to it by the Lexer and converts it into an Abstract Syntax Tree <br />
  <br />
  3 : Assembly Generation (Handled by the Codegen module) : Converts the Abstract Syntax Tree from the Parser into an Assembly Abstract Syntax Tree <br />
  <br />
  4 : Code Emission (Handled by the Emission module) : Goes through the Assembly Abstract Syntax Tree from the Codegen Module and prints out assembly code to a .s file <br />
</p>

<br />
<br />

<h2>Examples</h2>
<p>Here are some examples of code that etcc can compile </p>
<br />
<br />


<h5>Example 1</h5> 

C code

```
#define RETURN_VALUE 2

int main(void) {
  return RETURN_VALUE;
}
```

Generated Assembly

```
	.globl main&emsp;
main:
	movl $2, %eax
	ret


#this line indicates that we don't need an executable stack
.section .note.GNU-stack,"",@progbits
```

<br />

<h5>Example 2</h5> 

C code

```
/* dispite it's limitations, etcc can compile this mess*/
int 
                      main(
        void
)

{
    return 
    72
            ;
}
```

Generated Assembly

```
	.globl main
main:
	movl $72, %eax
	ret


#this line indicates that we don't need an executable stack
.section .note.GNU-stack,"",@progbits
```




