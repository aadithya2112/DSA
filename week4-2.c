#include <stdio.h>

struct Box
{
    int length, width, height;
};

int canPassThroughTunnel(struct Box box, int tunnelHeight)
{
    return box.height <= tunnelHeight;
}

// Main function
int main()
{
    int n, tunnelHeight;

    // Input the number of boxes and tunnel height
    printf("Enter number of boxes: ");
    scanf("%d", &n);
    printf("Enter tunnel height: ");
    scanf("%d", &tunnelHeight);

    struct Box boxes[n];

    // Input the dimensions of each box
    for (int i = 0; i < n; i++)
    {
        printf("Enter dimensions of box %d (length width height): ", i + 1);
        scanf("%d %d %d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
    }

    // Output which boxes can pass through the tunnel
    printf("Boxes that can pass through the tunnel:\n");
    for (int i = 0; i < n; i++)
    {
        if (canPassThroughTunnel(boxes[i], tunnelHeight))
        {
            printf("Box %d: (%d, %d, %d)\n", i + 1, boxes[i].length, boxes[i].width, boxes[i].height);
        }
    }

    return 0;
}
