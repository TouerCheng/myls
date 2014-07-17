my_ls:display_attribute.o  display.o  display_dir.o  display_single.o  main.o  my_err.o
	gcc -o my_ls display_attribute.o  display.o  display_dir.o  display_single.o  main.o  my_err.o
	make clean
display_attribute.o:  
display.o:  
display_dir.o:  
display_single.o:
main.o:  
my_err.o:
.PHONY:clean
clean:
	rm -f *.o
