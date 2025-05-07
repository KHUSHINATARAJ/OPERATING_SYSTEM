#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

// Function to allocate memory sequentially for a file
bool allocateSequential(int fileNumber, int fileSize, int disk[], int startBlock) {
    int endBlock = startBlock + fileSize - 1;

    // Check if the allocation exceeds the disk size
    if (endBlock >= MAX_BLOCKS) {
        printf("Error: Not enough space for file %d.\n", fileNumber);
        return false;
    }

    // Check if the required blocks are free
    for (int i = startBlock; i <= endBlock; i++) {
        if (disk[i] != 0) {
            printf("Error: Block %d is already occupied.\n", i);
            return false;
        }
    }

    // Allocate the blocks
    for (int i = startBlock; i <= endBlock; i++) {
        disk[i] = fileNumber;
    }
    return true;
}

// Function to display the current state of the disk
void displayDisk(int disk[]) {
    printf("\nDisk Status:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("%d ", disk[i]);
        if ((i + 1) % 10 == 0) { // Print 10 blocks per line
            printf("\n");
        }
    }
}

int main() {
    int disk[MAX_BLOCKS] = {0}; // Initialize the disk with all blocks free
    int numFiles;

    printf("Enter the number of files to allocate (max %d): ", MAX_FILES);
    scanf("%d", &numFiles);

    if (numFiles > MAX_FILES || numFiles <= 0) {
        printf("Error: Number of files must be between 1 and %d.\n", MAX_FILES);
        return 1;
    }

    for (int i = 1; i <= numFiles; i++) {
        int fileSize, startBlock;
        printf("\nEnter details for File %d:\n", i);
        printf("File size: ");
        scanf("%d", &fileSize);
        printf("Starting block: ");
        scanf("%d", &startBlock);

        if (allocateSequential(i, fileSize, disk, startBlock)) {
            printf("File %d allocated successfully.\n", i);
        } else {
            printf("File %d allocation failed.\n", i);
        }

        displayDisk(disk); // Show the disk status after each allocation
    }

    return 0;
}