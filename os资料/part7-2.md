##### VM(虚拟内存)

> **cpu执行过程**：所有进程(虚拟地址)
>
> **地址转换**？虚拟与物理地址
>
> > 连续空间分配：动态增长？进程大小

***

##### MMU实现

**目标**：地址翻译 -> 查找表 -> 空间开销太大-> 减少映射条目（从虚拟地址映射到物理地址）

**思想**：粗粒度映射 一块地址范围建一个映射

​			4k（12bits）是一个page -> 分页 -> 页表（逻辑页到物理页映射）

![image-20220420111430936](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20220420111430936.png)





页表项的结构：

​	地址映射

​	状态（访问权限，是否在内存）

页表的结构：

​		32位：分成3部分 10 10 12

​				20位->物理地址

​				二级映射：10位-> 2^10个地址

​				12：offset

​		哈希表:

​		![image-20220425141329805](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20220425141329805.png)

​				

哈希碰撞：

扩张

范围查找



访问性能：

​	大页 large page

​		缺点：碎片化，对重删率的影响

​	缓存 caching

​		Translation lookaside buffer (TLB) ->翻译工作，记录了缓存条目

​			pros：TLB is fast

​						TLB is small

​						访问局限性

​						Effective memory-access time有效内存访问时间

请求调页

pagefault->开销

重新执行指令

置换->外存访问



swap area 交换分区最小要为实际物理内存

swap in 和 swap out 存在io过程

交换区在外存



最大存储：交换分区 + 物理内存 - 内核



fork exec

cow copy-on-write:要写的时候才copy

请求调页系统的性能

​	有效访问时间

![image-20220425152016256](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20220425152016256.png)

![image-20220425152035867](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20220425152035867.png)



页面置换算法：

解决选择页面->性能：page fault次数，减少

最优算法：

​	假设知道所有的访问顺序：

​	swap out之后访问最少的

实际算法：FIFO -> 性能差

优化？

​	思想：局部性，-> 换出不常用

​	LRU -> replace the page that is least-recently used

​		实现：硬件加软件

LRU近似：二次机会

​		fifo+访问位（设置给二次机会）看访问位是否置1或置0

​		时钟扫一圈：如果全为1，即全被访问，则将第一个设为0并替换，即退化成普通fifo

​		比较：alg o（n） ->CPU MEM/DISK 网络

页面置换性能：物理页框数量上升 -> 性能好（pf减小）

​							belady‘s异常：物理页框上升，pf上升

​							堆栈算法：不会出现belady's异常 特点：n页框时页面集合<=n+1页框

页框分配：约束->多进程，全局/局部

​	分配的方法：等量m/n 按比例 优先权

![image-20220427102804293](C:\Users\宋玮\AppData\Roaming\Typora\typora-user-images\image-20220427102804293.png)

​	

抖动（多道程序例子）-> CPU/内存

​	解决方法

​		工作集：估计的需求量 求和WSsi > M抖动可能会发生

​		PFR调节

内核内存分配：

​	小的内存消长 -> SLAB

内存映射文件：
