#include <stdio.h>


int main(int argc, char *argv[]){
    
    if(argc != 2){
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    
    
    // Open input file
    
    FILE *card = fopen(argv[1], "r");
    
    if(card == NULL){
        fprintf(stderr,"Could not open %s.\n", argv[1]);
        return 2;
    }
    
    unsigned char buffer[512];
    
    // add output file
    
    int imageCount = 0;
    FILE *image = NULL;
    
    while(fread(buffer, 512, 1, card) == 1){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if(image!=NULL){
                fclose(image);
            }
            char name[8];
            sprintf(name, "%03d.jpg", imageCount);
            image=fopen(name, "w");
            imageCount++;
                    }
        if(image!=NULL){
            fwrite(buffer, 512, 1, image);
        }
        
        
    }
    fclose(image);
    fclose(card);
    return 0;
    
    
}