#!/usr/bin/env python
# coding: utf-8

# In[2]:


import math
ETA=0.5 
def weighted_sum(x,y):
    total=0    
    for i,j in zip(x,y):
        total+=i*j    
    return total 

def signoid(x):
    return (1/(1+math.exp(-1*x))) 

def determine_layer_output(inputs,list_of_weight):
    node_outputs=[]    
    for weights in list_of_weight:
        node_input=weighted_sum(inputs,weights)
        node_output=signoid(node_input) 
        node_outputs.append(node_output)
    return node_outputs 

def error_measure(x,y):
    error=0    
    for i,j in zip(x,y):
        error=error+(((i-j)*(i-j))/2)  
    return error 

def calculate_delta_level2(x,y): 
    deltas=[]    
    for i,j in zip(x,y): 
        delta=i*(1-i)*(j-i) 
        deltas.append(delta) 
    return deltas 

def calculate_delta_level1(list_of_weight,d,h): 
    deltas=[]   
    for i in range(len(list_of_weight[0])-1):
        sum=0       
        for j in range( len(list_of_weight) ):  
            sum+=list_of_weight[j][i]*d[j]    
            de=h[i]*(1-h[i])*sum              
        deltas.append(de)     
    return deltas 


def weight_update_layer2(list_of_weight,deltas,x): 
    for i in range(len(list_of_weight)):      
        for j in range(len(list_of_weight[i])):      
            list_of_weight[i][j]=list_of_weight[i][j]+(ETA*deltas[i]*x[j])   
    return list_of_weight 

def weight_update_layer1(list_of_weight,deltas,x):
    for i in range(len(list_of_weight)): 
        for j in range(len(list_of_weight[i])):  
            list_of_weight[i][j]=list_of_weight[i][j]+(ETA*deltas[i]*x[j])     
    return list_of_weight  

#main execution section start
in_l_1=[0.05 ,0.1, 1] 
w_l_1=[[0.15, 0.20, 0.35], 
       [0.25, 0.30, 0.35]] 
w_l_2=[[0.40, 0.45, 0.60],   
       [0.50, 0.55, 0.60]] 

iteration=1
n=1000

while iteration <= n:
    #forwardpass start
    h=determine_layer_output(in_l_1, w_l_1)
    #print(h) 

    in_l_2=[h[0] ,h[1], 1]


    target_output=[0.01, 0.99]
    output=determine_layer_output(in_l_2, w_l_2) 
    error=error_measure(target_output, output)  
    print(error)
    #forwardpass end 
    #backpass start 

    deltas2=calculate_delta_level2(output, target_output) 
    #print(deltas)
    w_l_2=weight_update_layer2(w_l_2,deltas2,in_l_2) 
    #print(w_l_2) 
    deltas1=calculate_delta_level1(w_l_2,deltas2,in_l_2) 
    w_l_1=weight_update_layer1(w_l_1,deltas1,in_l_1) 
    
    iteration=iteration+1
    #print(w_l_1) 
    #backpass end
    

#sum=weighted_sum(wl1,wh1) 
#h1=signoid(sum) 
#sum=weighted_sum(x,wh2) 
#h2=signoid(sum)  
#wl2=[h1,h2,1] 
#wo1=[0.40, 0.45, 0.60] 
#wo2=[0.50, 0.55, 0.60] 
#sum=weighted_sum(wl2,wo1)
#o1=signoid(sum) 
#sum=weighted_sum(wl2,wo2)
#o2=signoid(sum) 
#print(h1,h2,o1,o2) 
#[h1,h2] [0.5932699921071872, 0.596884378259767]
#[o1,o2][0.7513650695523157, 0.7729284653214625]
#e1 0.2983711087600027 #w5 0.35891647971788465 


# In[ ]:




