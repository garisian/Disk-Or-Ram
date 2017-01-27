# Disk Or Ram

After bring accustomed to my i7 linux laptop, there were times where I were forced to run our code in our university labs to test speed. Little did I know that the speed of my program increased dramatically and initially froze the computers. At that point I realized that I took advantage the free space and RAM power and that my code is impractical in the real world. 
 
This sparked my curiosity and I wanted to see how much of an impact free memory has on sorting when it comes to Big Data. 


# 2PPMS

After lots of experimentation, I realized that the solution I came up with was very similar to Two-Pass Multiway Merge Sort. By creating a simple schema (UIDI: int, UID2: int), the records are packed into disk blocks, without any additional block header information.

# Twitter Dataset

A binary file of approximately 700mb was used as the experimental dataset. It follows the logic of an user with an id user_id follows the user with the id followed_id, creating the pair (user_id, followed_id). So the basic idea is that the binary file is just a huge list of pairs. An assumption that there was enough memory to store the existing file with the  additional 30mb (including memory used to run the program). The binary file is completely unsorted and has no patterns. 


# Process
1) Given the space amount, the amount of space needed to record 1 group (UIDI: int, UID2: int) in memory was calculated. Given that, I was able to figure out how many records could be saved on disk without having any memory issues. 

2) After figuring out the amount of records that can be save, I went though the binary file and created that many records and stored it in data. Those records were sorted and then rewritten into the original binary file. After that process was done, the next few were extracted, sorted, rewritten,  and the process continues until the entire file is just segments of sorted data.

3) If we know 5 records were sorted and rewritten, record number 1 is the lowest of the first 5, record 6 is the lowest of 6-10, etc. Essentially we know the positions of all of the lowest records. By putting them all into a min-heap tree, we are able to extract the minimum, and then repopulate the min-heap with the next element from that run. 

4) Once the whole process is done, the entire list will be sorted. 


# Results

You can run the code using /path-to-program- -v disk_sort <input file> <mem> <block size> <number of runs>. Essentially I designed it so I can experiment with different CPU memories, block sizes, and block sizes for each pair. 

So it turns out that this sorting algorithm almost has the same runtime as C's provided sorting algorithms and Unix's sorting algorithm. 
