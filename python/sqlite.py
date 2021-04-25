import sqlite3
from sqlite3 import Error

def create_db(db_file):
    conn=None

    try:
        conn=sqlite3.connect(db_file)
        print(sqlite3.version)
    except Error as e:
        print("create DB Error =" + str(e))
    finally:
        if (conn):
            conn.close()

if __name__ == "__main__":
    try:
        create_db(r"E:\python\sqlite\example.db")
        print("Database finished")
    except Exception as e:
        print("Main Error" + str(e))