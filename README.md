# Push_Swap

Это проект на сортировку. Требуется отсортировать стек челых чисел, используя определенный набор инструкций:

| instructions | Description   |
| -------------| -----------   |
| sa        |swap the first 2 elements at the top of stack a.                    
|sb	        |swap first two elements of stack B       
| ss        |sa and sb at the same time
|pa         |pops the first elememt on B and puts it on top of A    
| pb        |pops the first elememt on A and puts it on top of B   
| ra        |rotates stuck A up by one       
| rb        | rotates stuck B up by one      
| rr        |rotates both A and B up by one       
| rra       |rotates stuck A down by one     
| rrb       |rotates stuck B down by one     
| rrr       |rotates both A and B down by one

# Как запустить программу:
    make
    ./push_swap <args> or ./push_swap "<argc>"
 Программа выведет весь список инструкций который потребовался для сортировки. 
 Для пяти чисел количество инструкций не должно превышать 12.
 
 # Бонусная часть проекта:
 Бонусная часть заключается в написании своего чекера для проверки результата основной части. 
 Запуск программы:
    
     make bonus
     ./checker 
    <ввести список инструкций для сортировки>
Если стек отсортирован - программа выведет ОК.

Больше информации по проекту можно найти в [subject.pdf](https://github.com/RekaEva/Push_swap/blob/main/subject.pdf)
