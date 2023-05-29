FILE *in = fopen(infile, "r");
if (in == NULL) {
    printf("Error opening input file.\n");
    return 1;
}

FILE *out = fopen(outfile, "w");
if (out == NULL) {
    printf("Error opening output file.\n");
    return 1;
}


