//cpp

char const* get_letter_grade_using_if(int grade)
{
    if ((grade >= 90) && (grade <= 100))
    {
        return "A";
    }
    else if ((grade >= 80) && (grade <= 89))
    {
        return "B";
    }
    else if ((grade >= 70) && (grade <= 79))
    {
        return "C";
    }
    else if ((grade >= 60) && (grade <= 69))
    {
        return "D";
    }
    else
    {
        return "F";
    }
}

char const* get_letter_grade_using_switch(int grade)
{
    int q = grade / 10;

    switch (q) {
        case 10:
        case 9:
            return "A";
            break;
        case 8:
            return "B";
            break;
        case 7:
            return "C";
            break;
        case 6:
            return "D";
            break;
        default:
            return "F";
            break;
    }
}