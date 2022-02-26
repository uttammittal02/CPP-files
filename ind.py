import datetime
import matplotlib.pyplot as plt 
import mpld3
import pandas as pd
import numpy as np
def generate_html_for_graph_xp(xp, date):
    
    dates = [date]
    while (len(dates) != len(xp)):
        dates.append(date + datetime.timedelta(days= 1))
    
    a = plt.stackplot(dates, xp, colors=['#001333'])
    
    plt.xlabel("Date")
    plt.ylabel("Total XP")
    plt.tick_params(axis='x', labelsize=4)
    plt.title("XP")
    plt.grid(True, color='#EFF3FF')# set graph grid color and control its pres
    ax = plt.axes()
    ax.set_facecolor('white') #set graph bg-color
    b = a[0].figure
    b.set_figwidth(10)
    b.set_figheight(10)
    
    code = mpld3.fig_to_html(b)
    
    return code


# file1 = open('trial.html', 'w')
# # L = ["This is Delhi \n", "This is Paris \n", "This is London \n"]
# # s = "Hello\n"
  
# # Writing a string to file
# file1.write(code)