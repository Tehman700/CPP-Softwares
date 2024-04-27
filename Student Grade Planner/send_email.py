import sys
import smtplib

my_email = "tehmanhassan@gmail.com"
password = "yujo itfu bjoc qwtx"
sum = sys.argv[1]
total_credits = sys.argv[2]
gpa = sys.argv[3]

message = f"Subject: Your GPA Results\n\n YOUR DETAILS ARE AS UNDER \n\nTotal Points: {sum}\nTotal Credit Hours: {total_credits}\nTotal GPA: {gpa}\n\n PROGRAMMING FUNDAMENTALS PROJECT \n\n Made by Tehman Hassan and Saira Batool"

connection = smtplib.SMTP("smtp.gmail.com")
connection.starttls()
connection.login(user=my_email, password=password)
connection.sendmail(from_addr=my_email, to_addrs=sys.argv[4], msg=message)
connection.close()
