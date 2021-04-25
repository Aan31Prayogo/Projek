import sqlite3
from sqlite3 import Error

def create_db(db_file):
    conn=None
    try:
        conn=sqlite3.connect(db_file)
        print("Succes to Database")
    except Error as e:
        print("create DB Error =" + str(e))
    return conn

def create_task(conn,sql):
    try:
        cursor=conn.cursor()
        cursor.execute(sql)
        conn.commit()
        print("create Task Done")
    except Exception as e:
        print("create task Error ="+ str(e))

def select_task(conn):
    select_sql = """ SELECT * FROM mahasiswa;"""
    try:
        cursor = conn.cursor()
        cursor.execute(select_sql)
        row =cursor.fetchall()
        for rows in row:
            print(rows)
    except Exception as e:
        print("Error Select Task = ", + str(e))
    
def main():
    db=create_db(r"E:\python\sqlite\example.db")

    table_sql="""   CREATE TABLE  mahasiswa (
                    NRP INT PRIMARY KEY NOT NULL,
                    Nama VARCHAR [30] NOT NULL,
                    JK CHAR [1] NOT NULL,
                    Alamat VARCHAR [30] NOT NULL
                );"""
    
    insert_Sql=""" INSERT INTO mahasiswa (NRP,NAMA,jk,Alamat)
                    VALUES (3110161031,"M. Rizanto Juliarsyah", "L","Surabaya"),
                        (3110161034,"Kerent Vidia Madalena", "P","Kediri"),
                     (3110161038,"Abdul Khoifan", "L", "Gresik"),
                     (3110161054,"Yulian Surya Prayogo", "L", "Makassar");
                """
    
    update_sql= """UPDATE mahasiswa SET Nama = "Yulian Surya Prayogo" WHERE NRP = 3110161054;"""
    delete_sql = """DELETE FROM mahasiswa WHERE NRP=3110161031;"""
    update_table = """ALTER TABLE mahasiswa ADD NOT NULL Alamat;"""
    delete_table = """ALTER TABLE mahasiswa DROP Alamat;"""
    

    if db is not None:
        try:
            #create_task(db,select_sql)
            select_task(db)
        except Exception as e:
            print("create Task failed"+ str(e))
    else:
        print("Main program Error")
if __name__ == "__main__":
    main()
    
