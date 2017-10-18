employeeList :project1.c
	gcc -o employeeList project1.c
	gcc -c functions.c


clean:
	rm -f *.o project1
	rm employeeList
	rm employeeTable.txt

demo: 
	./employeeList

