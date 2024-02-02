#include <stdio.h>
#include <stdlib.h>

int main()
{

    int op,base;
    char digit2;//binary(base2) inputs entered by user in option1
    int digit10;// decimal(base10) inputs entered by user in option1

    int D7=0,D6=0,D5=0,D4=0,D3=0,D2=0,D1=0,D0=0;//inputs
    int Y2=0,Y1=0,Y0=0;//outputs

    do{
        fflush(stdin);//menu
        printf("Welcome to Octal-to-Binary Encoder!\n\n");
        printf("(1) Compute and Display the outputs\n");
        printf("(2)Quit\n");
        printf("You choose: ");
        scanf("%d",&op);
        while(op!=1 && op!=2){
            fflush(stdin);
            printf("Please enter option either 1 or 2: ");
            scanf("%d",&op);
        }

        if(op==1){
            fflush(stdin);
            printf("You have chosen option 1\n\n");
            printf("Which base will you use to enter input (base 2 or base 10)? ");
            scanf("%d",&base);
            while(base!=2 && base!=10){
                fflush(stdin);
                printf("Please enter base either 2 or 10: ");
                scanf("%d",&base);
            }

            if(base==2){
                int digitCount=0;//digit counter of the text entered by user
                int error=0;
                int asciiValue;

                //printf("Please enter your input: ");

                while(!error){
                    printf("Please enter your input: ");
                    fflush(stdin);
                    do{
                        scanf("%c",&digit2);
                        asciiValue=digit2;
                        if(asciiValue!=48 && asciiValue!=49 && asciiValue!=10){//If entered value is not either a 0 or 1, error=1
                          printf("Please enter either 0 or 1!\n");
                          error=1;
                          break;
                        }
                        if(asciiValue!=10){//based on the digitCount, I assigned every input value with the input entered by user one by one.
                            digitCount++;

                            if(digitCount%8==1){
                                D7=digit2-48;
                            }
                            else if(digitCount%8==2){
                                D6=digit2-48;
                            }
                            else if(digitCount%8==3){
                                D5=digit2-48;
                            }
                            else if(digitCount%8==4){
                                D4=digit2-48;
                            }
                            else if(digitCount%8==5){
                                D3=digit2-48;
                            }
                            else if(digitCount%8==6){
                                D2=digit2-48;
                            }
                            else if(digitCount%8==7){
                                D1=digit2-48;
                            }
                            else if(digitCount%8==0){//when we are at last step(D0), I assigned every D value. So now, I can assign output values based on input(Ds) values
                                D0=digit2-48;
                                if(D4||D5||D6||D7){
                                    Y2=1;
                                }
                                else{
                                    Y2=0;
                                }
                                if(D2||D3||D6||D7){
                                    Y1=1;
                                }
                                else{
                                    Y1=0;
                                }
                                if(D1||D3||D5||D7){
                                    Y0=1;
                                }
                                else{
                                    Y0=0;
                                }
                            }
                        }



                    }while(digit2!=10);

                    if(error){
                        error=0;
                        digitCount=0;
                        continue;
                    }
                    else{//length errors
                        if(digitCount<8){

                            printf("You have entered less than 8 bits! Please try again!\n");
                            digitCount=0;
                        }
                        else if(digitCount>8){

                            printf("You have entered more than 8 bits! Please try again!\n");
                            digitCount=0;
                        }
                        else{

                            error=1;
                        }
                    }
                }


                printf("Y2 is %d  Y1 is %d  Y0 is %d\n\n",Y2,Y1,Y0);

            }

            else{//base==10



                printf("Please enter your input: ");
                fflush(stdin);
                scanf("%d",&digit10);
                while(digit10>255 || digit10<0){//make sure not to enter a negative value.
                    fflush(stdin);
                    printf("Decimal %d cannot be represented with 8 bits. Please try again!\n",digit10);
                    printf("Please enter your input: ");
                    scanf("%d",&digit10);
                }
                int rem;//this variable is the remainder when we take modulus 2 of the number
                int tempNumber=digit10;
                int binaryNumber=0;// this is our final conversion result
                int mult=1;//this is for multiplier
                int count=0;//this is the count of binary number elements

                while(tempNumber>0){//calculating the binary equavalent of the decimal value entered by user
                    rem=tempNumber%2;
                    binaryNumber=binaryNumber+(rem*mult);
                    mult*=10;
                    tempNumber/=2;
                    count++;

                }

                if(count==8){//assigning every bit of the binary value to inputs(Ds)
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=binaryNumber%10;
                    binaryNumber/=10;
                    D2=binaryNumber%10;
                    binaryNumber/=10;
                    D3=binaryNumber%10;
                    binaryNumber/=10;
                    D4=binaryNumber%10;
                    binaryNumber/=10;
                    D5=binaryNumber%10;
                    binaryNumber/=10;
                    D6=binaryNumber%10;
                    binaryNumber/=10;
                    D7=binaryNumber%10;
                    binaryNumber/=10;
                }
                else if(count==7){
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=binaryNumber%10;
                    binaryNumber/=10;
                    D2=binaryNumber%10;
                    binaryNumber/=10;
                    D3=binaryNumber%10;
                    binaryNumber/=10;
                    D4=binaryNumber%10;
                    binaryNumber/=10;
                    D5=binaryNumber%10;
                    binaryNumber/=10;
                    D6=binaryNumber%10;
                    binaryNumber/=10;
                    D7=0;
                }
                else if(count==6){
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=binaryNumber%10;
                    binaryNumber/=10;
                    D2=binaryNumber%10;
                    binaryNumber/=10;
                    D3=binaryNumber%10;
                    binaryNumber/=10;
                    D4=binaryNumber%10;
                    binaryNumber/=10;
                    D5=binaryNumber%10;
                    binaryNumber/=10;
                    D6=0;
                    D7=0;
                }
                else if(count==5){
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=binaryNumber%10;
                    binaryNumber/=10;
                    D2=binaryNumber%10;
                    binaryNumber/=10;
                    D3=binaryNumber%10;
                    binaryNumber/=10;
                    D4=binaryNumber%10;
                    binaryNumber/=10;
                    D5=0;
                    D6=0;
                    D7=0;
                }
                else if(count==4){
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=binaryNumber%10;
                    binaryNumber/=10;
                    D2=binaryNumber%10;
                    binaryNumber/=10;
                    D3=binaryNumber%10;
                    binaryNumber/=10;
                    D4=0;
                    D5=0;
                    D6=0;
                    D7=0;
                }
                else if(count==3){
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=binaryNumber%10;
                    binaryNumber/=10;
                    D2=binaryNumber%10;
                    binaryNumber/=10;
                    D3=0;
                    D4=0;
                    D5=0;
                    D6=0;
                    D7=0;
                }
                else if(count==2){
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=binaryNumber%10;
                    binaryNumber/=10;
                    D2=0;
                    D3=0;
                    D4=0;
                    D5=0;
                    D6=0;
                    D7=0;
                }
                else if(count==1){
                    D0=binaryNumber%10;
                    binaryNumber/=10;
                    D1=0;
                    D2=0;
                    D3=0;
                    D4=0;
                    D5=0;
                    D6=0;
                    D7=0;
                }
                else{
                    D0=0;
                    D1=0;
                    D2=0;
                    D3=0;
                    D4=0;
                    D5=0;
                    D6=0;
                    D7=0;
                }
                //after assiging Ds, I found the outputs(Ys)
                if(D4||D5||D6||D7){
                    Y2=1;
                }
                else{
                    Y2=0;
                }
                if(D2||D3||D6||D7){
                    Y1=1;
                }
                else{
                    Y1=0;
                }
                if(D1||D3||D5||D7){
                    Y0=1;
                }
                else{
                    Y0=0;
                }
                printf("Y2 is %d  Y1 is %d  Y0 is %d\n\n",Y2,Y1,Y0);




            }

        }


        else{
            printf("You have chosen option 2\n");
            printf("BYEE!!");
        }


    }while(op!=2);







    return 0;
}
