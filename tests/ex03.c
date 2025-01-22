/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** ex03.c
*/

int main(void)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);

    printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));

    delete(v1);
    delete(v2);
    delete(p1);
    delete(p2);
    return (0);
}
