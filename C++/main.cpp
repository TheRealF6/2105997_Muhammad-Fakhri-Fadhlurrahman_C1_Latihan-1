#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct mahasiswa
{
	string nama;
	string nim;
	string prodi;
    string fakultas;
};

int main()
{	
    string command;

    while(command != "STOP")
	{
		cout << "Masukkan perintah : ";
		cin >> command;

    	if(command == "TAMPIL")
		{
			mahasiswa rekaman;
			ifstream mhs;
			mhs.open("data_mhs.dat");
	
			cout << "[]-----[DAFTAR DATA MAHASISWA]-----[]\n\n";
			mhs >> rekaman.nama >> rekaman.nim >> rekaman.prodi >> rekaman.fakultas;

			if(rekaman.nama == "-")
			{
				cout << "Data tidak tersedia.\n";
			}
			else
			{
				cout << "=========================\n";

				do
				{
					/* proses */
					cout << "Nama : " << rekaman.nama << endl;
					cout << "NIM : " << rekaman.nim << endl;
					cout << "Program Studi : " << rekaman.prodi << endl;
					cout << "Fakultas : " << rekaman.fakultas << endl;
					cout << "=========================\n";
			
					/* iterasi */
					mhs >> rekaman.nama >> rekaman.nim >> rekaman.prodi >> rekaman.fakultas;
				}

				while(rekaman.nim != "-");
			}

			mhs.close();
    	}

		else if(command == "BUAT")
		{
			mahasiswa rekaman;
			ofstream mhs;
			mhs.open("data_mhs.dat");

			cout << "Masukkan data mahasiswa :\n";
	    	cout << "Nama : ";
			cin >> rekaman.nama;
	
			while(rekaman.nama != "-")
			{
				/* proses */
				cout << "NIM : ";
				cin >> rekaman.nim;
				cout << "Program Studi : ";
				cin >> rekaman.prodi;
        		cout << "Fakultas : ";
				cin >> rekaman.fakultas;
		
				mhs << rekaman.nama << " " << rekaman.nim << " " << rekaman.prodi << " " << rekaman.fakultas << endl;
		
				/* iterasi */
				cout << "Nama : ";
				cin >> rekaman.nama;
			}
	
			mhs << "- - - -";
			mhs.close();
    	}

        if(command == "TAMBAH")
		{
			int n = 0;
	
			mahasiswa temp[100];
			mahasiswa rekaman, baru;
	
			fstream mhs;
			mhs.open("data_mhs.dat");
	
			mhs >> rekaman.nama >> rekaman.nim >> rekaman.prodi >> rekaman.fakultas;
	
			if(rekaman.nim == "-")
			{
				cout << "Data tidak tersedia.\n";
			}
			else
			{
				do
				{
					temp[n].nama = rekaman.nama;
					temp[n].nim = rekaman.nim;
					temp[n].prodi = rekaman.prodi;
					temp[n].fakultas = rekaman.fakultas;
					n++;
					mhs >> rekaman.nama >> rekaman.nim >> rekaman.prodi >> rekaman.fakultas;
				}
				while(rekaman.nama != "-");
			}
		
			mhs.close();
		
			cout << "Masukkan data mahasiswa :\n";
			cout << "Nama : ";
			cin >> rekaman.nama;
			cout << "NIM : ";
			cin >> rekaman.nim;
			cout << "Program Studi : ";
			cin >> rekaman.prodi;
    		cout << "Fakultas : ";
			cin >> rekaman.fakultas;
		
			//kondisi memasukkan ke dalam array
			if(baru.nim < temp[0].nama)
			{
				//rekaman baru di paling depan
				//geser semua isi array ke belakang
				int i;

				for(i = (n - 1); i >= 0; i--)
				{
					temp[i+1].nama = temp[i].nama;
					temp[i+1].nim = temp[i].nim;
					temp[i+1].prodi = temp[i].prodi;
					temp[i+1].fakultas = temp[i].fakultas;
				}
				n++;

				temp[0].nama = baru.nama;
				temp[0].nim = baru.nim;
				temp[0].prodi = baru.prodi;
				temp[0].fakultas = baru.fakultas;
			}
			else if(baru.nama > temp[n - 1].nama)
			{
				//rekaman baru di belakang
				temp[n].nama = baru.nama;
				temp[n].nim = baru.nim;
				temp[n].prodi = baru.prodi;
				temp[n].fakultas = baru.fakultas;
                n++;
            }
            else
			{
				//rekaman baru memiliki posisi di tengah
				int i = 0;
				int stop = 0;

				//cari posisi
				while((i < n) && (stop == 0))
				{
					if(temp[i].nama > baru.nama)
					{
						stop = 1;
					}
					else
					{
						i++;
					}
				}

				int j;

				for(j = (n - 1); j >= i; j--)
				{
					temp[j+1].nama = temp[j].nama;
					temp[j+1].nim = temp[j].nim;
					temp[j+1].prodi = temp[j].prodi;
					temp[j+1].fakultas = temp[j].fakultas;
				}

				temp[i].nama = baru.nama;
				temp[i].nim = baru.nim;
				temp[i].prodi = baru.prodi;
				temp[i].fakultas = baru.fakultas;
				n++;
			}

            //flush ke file
			int i;
			for(i = 0; i < n; i++)
			{
				mhs << temp[i].nama << " " << temp[i].nim << " " << temp[i].prodi << " " << temp[i].fakultas << endl;
			}
		
			mhs << "- - - -";
			mhs.close();
    	}
    }
	
	return 0;
}