#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t get_next(char *prog)
{
    return atoi(strtok(prog, ","));
}

uint32_t run(uint32_t *prog, int64_t size)
{
    uint32_t pc = 0;
    bool halt = false;
    
    while (!halt && pc != size)
    {
        switch (prog[pc])
        {
            case 1: {
                uint32_t first = prog[pc + 1];
                uint32_t second = prog[pc + 2];
                uint32_t loc = prog[pc + 3];
                prog[loc] = prog[first] + prog[second];
            }
                pc += 4;
                break;
            case 2: {
                uint32_t first = prog[pc + 1];
                uint32_t second = prog[pc + 2];
                uint32_t loc = prog[pc + 3];
                prog[loc] = prog[first] * prog[second];
            }
                pc += 4;
                break;
            case 99:
                halt = true;
                pc++;
                break;
        }
    }

    return prog[0];
}

int main(void)
{
    uint32_t pc = 0;
    
    FILE *prog_file = NULL;

    if ((prog_file = fopen("DayTwo_Input.txt", "r")) == NULL)
    {
        printf("Welp, messed that up...\n");

        exit(EXIT_FAILURE);
    }

    fseek(prog_file, 0, SEEK_END);
    int64_t size = ftell(prog_file);
    fseek(prog_file, 0, SEEK_SET);

    char *progsrc = calloc(sizeof(char), size + 1);
    fread(progsrc, 1, size, prog_file);
    uint32_t *prog = malloc(sizeof(uint32_t) * size);
    
    char * token = strtok(progsrc, ",");
    while( token != NULL ) {
        prog[pc] = atoi(token); 
        token = strtok(NULL, ",");
        pc++;
    }
    
    uint32_t output = 0;
    
    for (int32_t noun = 0; noun < 99; noun++)
    {
        for (int32_t verb = 0; verb < 99; verb++)
        {
            uint32_t *iter = malloc(sizeof(uint32_t) * size);
            memcpy(iter, prog, sizeof(uint32_t) * size);

            iter[1] = noun;
            iter[2] = verb;

            output = run(iter, size);
            free(iter);
            if (output == 19690720)
            {
                printf("Noun %d Verb %d\n", noun, verb);
                printf("FOUND %d\n", 100 * noun + verb);
                goto cleanup;
            }
        }
    }

cleanup:
    free(progsrc);
    free(prog);
    fclose(prog_file);

    exit(EXIT_SUCCESS);
}