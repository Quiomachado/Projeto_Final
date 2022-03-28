switch(input[i]){
    case 'a':
    case 'e':
    case 'i':
    case 'l':
    case 'n':
    case 'o':
    case 'r':
    case 's':
    case 't':
    case 'u':
        count++;
        break;
    case 'd':
    case 'g':
        count+=2;
        break;
    case 'b':
    case 'c':
    case 'm':
    case 'p':
        count+=3;
        break;
    case 'f':
    case 'h':
    case 'v':
    case 'w':
    case 'y':
        count+=4;
        break;
    case 'k':
        count+=5;
        break;
    case 'j':
    case 'x':
        count+=8;
        break;
    case 'q':
    case 'z':
        count+=10;
        break;
}