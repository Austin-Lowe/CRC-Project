#include<stdio.h>
#include<string.h>

char poly[17] = "10000100110001101";

char input_file[30];
char answer[30];
char buffer[5];

char segment;

char crcfinal[16];

char mode;
char hex;

int i;
int z;
int j=0;
int t=0;
int num_hex_char = -1;


FILE *ifp;


void printstring(char array[], int num);
void printstring(char array[], int num)
{
     for(i=0; i<= num; i++)
     {
              printf("%c", array[i]);
     }
     
}

void to_binary(char hex);
void to_binary(char hex)
{
    switch(hex){
                
             case '0': strcpy(buffer,"0000"); break;
             case '1': strcpy(buffer,"0001"); break;
             case '2': strcpy(buffer,"0010"); break;
             case '3': strcpy(buffer,"0011"); break;
             case '4': strcpy(buffer,"0100"); break;
             case '5': strcpy(buffer,"0101"); break;
             case '6': strcpy(buffer,"0110"); break;
             case '7': strcpy(buffer,"0111"); break;
             case '8': strcpy(buffer,"1000"); break;
             case '9': strcpy(buffer,"1001"); break;
             case 'A': strcpy(buffer,"1010"); break;
             case 'B': strcpy(buffer,"1011"); break;
             case 'C': strcpy(buffer,"1100"); break;
             case 'D': strcpy(buffer,"1101"); break;
             case 'E': strcpy(buffer,"1110"); break;
             case 'F': strcpy(buffer,"1111"); break;
             case 'a': strcpy(buffer,"1010"); break;
             case 'b': strcpy(buffer,"1011"); break;
             case 'c': strcpy(buffer,"1100"); break;
             case 'd': strcpy(buffer,"1101"); break;
             case 'e': strcpy(buffer,"1110"); break;
             case 'f': strcpy(buffer,"1111"); break;
             default:  printf("\nInvalid hexadecimal digit %c ",hex);
             
             }
             
}

void to_hex(char array[]);
void to_hex(char array[])
{
     char hex_ans[5];
     char binary_seg[4];
     
     strcpy(binary_seg, array);
  
             if(strcmp(binary_seg,"0000") == 0)
             {
             printf("0");
             }            
             if(strcmp(binary_seg,"0001") == 0){
              printf("1");
              }
             if(strcmp(binary_seg,"0010") == 0){
                                      printf("2");
                                      }
             if(strcmp(binary_seg,"0011") == 0)
             {
                                      printf("3");
                                      }
             if(strcmp(binary_seg,"0100") == 0)
             {
                                      printf("4");
                                      }
             if(strcmp(binary_seg,"0101") == 0)
             {
                                      printf("5");
                                      }
             if(strcmp(binary_seg,"0110") == 0)
             {
                                      printf("6");
                                      }
             if(strcmp(binary_seg,"0111") == 0){
                                      printf("7");
                                      }
             if(strcmp(binary_seg,"1000") == 0){
                                      printf("8");
                                      }
             if(strcmp(binary_seg,"1001") == 0){
                                      printf("9");
                                      }
             if(strcmp(binary_seg,"1010 ") == 0){
                                      printf("A");
                                      }
             if(strcmp(binary_seg,"1011 ") == 0){
                                      printf("B");
                                      }
             if(strcmp(binary_seg,"1100 ") == 0){
                                      printf("C");
                                      }
             if(strcmp(binary_seg,"1101 ") == 0){
                                      printf("D");
                                      }
             if(strcmp(binary_seg,"1110") == 0){
                                      printf("E");
                                      }
             if(strcmp(binary_seg,"1111") == 0){
                                      printf("F");
                                      }

     
}

void xor(char binary_str[]);
void xor(char binary_str[])
{   
    for(z = 0; z<16; z++)
    {
         if(binary_str[t+z] == poly[z])
         {
              binary_str[t+z] = '0';
         }
         else
         {
             binary_str[t+z] = '1';
         }
         
     }
     if(mode == 'c'){
     printf("\n");
     printstring(binary_str, (num_hex_char * 4) + 16);
     printf("\n");
     }
     
     if(mode == 'v' || mode =='V'){
     printf("\n");
     printstring(binary_str, (num_hex_char * 4));
     printf("\n");
                    
}  
}



int main (void)
{
    printf("Would you like to Calculate or Verify a CRC Value?(C/V): ");
    scanf("%c", &mode);
    
    printf("\nWhat is the name of the input file: ");
    scanf("%s", &input_file);
    
    ifp = fopen(input_file, "r");
  
//Scan through file to find number of characters in file 
    while(fscanf(ifp, "%c", &hex) != EOF)
    {
         num_hex_char++;
         
    } 
    
    
    rewind(ifp);
//////////////////////////////////////////

    char array_hex[num_hex_char];
    char array_binary[num_hex_char * 4];

    i = 0;
    
//strcpy + strcat
fscanf(ifp, "%c", &hex);

strcpy(array_binary, buffer);
    
 while(fscanf(ifp, "%c", &hex) != EOF)
    {
         array_hex[i] = hex;
         to_binary(hex);
         strcat(array_binary,buffer);
         i++;
         
    } 
 
 printf("\nThe Input file(hex): ");
    
 printstring(array_hex, num_hex_char);
 
 printf("\nThe Input file(bin):\n");
 printf("%s", array_binary);
 
 
 printf("\n\nThe Polynomial that was used(bin): ");
 printstring(poly, 17);
    
           
    if(mode == 'C' || mode == 'c')
    {
            
            printf("\nWe will append sixteen zeros at the end of the binary input.\n\n");
            
            char augment_array[(num_hex_char * 4) + 16];
            strcpy(augment_array, array_binary);
            strcat(augment_array, "0000000000000000");
            
  system("PAUSE");
        
        while( t < (num_hex_char * 4))
        {
             if(augment_array[t] == '0')
             {
                 t++;
             }  
            if(augment_array[t] == '1')
            {
                 xor(augment_array);
            }
        
        
        }
        
            z=0;
            for(i=(num_hex_char * 4); i< (num_hex_char * 4)+16; i++)
            {
                    crcfinal[z] = augment_array[i];
                    z++;
                                
            }

            printf("\n\nThe computed CRC for this file is: ");
            
            printstring(crcfinal, 15);
            

            
            printf("(bin) = ");
            
           // to_hex(crcfinal);
            
            //printstring(hex_ans, 4);
            
            j=0;
                      while(j<16){
                        for(i=0;i<4;i++)
                                {
                                    buffer[i] = crcfinal[j];
                                    
                                   // printf("%c", buffer[i]);
                                    j++;
                                                     
                                    }
                                    to_hex(buffer);
                            }
            printf("(hex)\n");
            
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    if(mode == 'V' || mode == 'v')
    {
            printf("\nThe 16-bit CRC observed at the end of the file: ");
            for(i=num_hex_char-4; i <= num_hex_char; i++)
            {
                    printf("%c", array_hex[i]);                      
            }
            
            printf("\n");
            system("PAUSE");
            ////////////////////////////////////////
            
        while( t < (num_hex_char * 4)-16)
        {
             if(array_binary[t] == '0')
             {
                 t++;
             }  
            if(array_binary[t] == '1')
            {
                 xor(array_binary);
            }
        
        
        }
        
            z=0;
            for(i=(num_hex_char * 4)-16; i< (num_hex_char * 4); i++)
            {
                    crcfinal[z] = array_binary[i];
                    z++;
                                
            }

            printf("\n\nThe computed CRC for this file is: ");
            
            printstring(crcfinal, 15);
            
            printf("(bin) = ");
            
            j=0;
                      while(j<16){
                        for(i=0;i<4;i++)
                                {
                                    buffer[i] = crcfinal[j];
                                    
                                   // printf("%c", buffer[i]);
                                    j++;
                                                     
                                    }
                                    to_hex(buffer);
                            }
            
            printf("(hex)\n");
        
        
            
            
            printf("\nDid the CRC check pass?(Yes or No): ");
            scanf("%s", &answer);
            
    }
    
printf("\n");
system("PAUSE");
return 0;
}
