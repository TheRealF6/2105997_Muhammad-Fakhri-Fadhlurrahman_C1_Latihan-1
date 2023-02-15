file1 = open("data_mhs.dat","w")
L = ["Ardi 2101210 Ilkom FPMIPA \n","Aldo 2102210 Ilkom FPMIPA \n","Abdi 2103210 Ilkom FPMIPA \n"] 
  
# \n is placed to indicate EOL (End of Line)
file1.write("Anto 2121212 Pilkom FPMIPA \n")
file1.writelines(L)
file1.close() #to change file access modes
  
file1 = open("data_mhs.dat","r+") 
  
print("Data Mahasiswa")
print(file1.read())
print()