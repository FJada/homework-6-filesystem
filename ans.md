# 1.What is the difference between an inode and a block?
## ANSWER: An inode is a data structure that eihter represents a file or a directory in a file system  and it contains store pointers to file blocks. whereas a block is a fixed size unit of storage on the disk and each blck has a unique block addresses 

# 2. What are the advantages of block indirection?
## ANSWER: block indirection allows for larger file sizes by allowing the storage to include more blocks without increasing the size of the inode. it also allows for diversity in how we can allocate blocks throguh different levels of indirection based of different storage needs

# 3. What are the disadvantages of block indirection?
## ANSWER: often requires a long search time if the files are large 
 
# 4. Why is it important that block size be a multiple of inode size?
## ANSWER: its important because it wont lead to waste in space/storage and will ensure performance wont be severely degraded for operations especially write to files

# 5. What tradeoff is made in selecting a larger or smaller block size?
## ANSWER: in choosing a smaller block size you can get better performance for small sporatic write operations or small writes to large files and it reduces unused space within each block but you also suffer from an increase in map tasks due to each map task being shorter and the system is unable to store larger files despite having enough blokcs to add up to the tile size due to meta data

## ANSWER: in choosing a larger block size you get to support larger files and having  but suffer from too much space is wasted, there is a decrease in parallelism, and a chance to slow down performance due to few map tasks being done at the cost of the operations being long, and a lack of meta data

