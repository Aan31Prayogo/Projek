def step1(a=None):
    a=2
    #print("ini step 1")
    print("a1: ",a)
    return a

def step2(a=None):
    #print("ini step 2")
    a=a+1
    print("a2: ",a)
    return a

def step3(a=None):
    #print("ini step3")
    a=a+2
    print("a3: ",a)
    return a

def run():
    k=0
    List =  [step1,step2,step3]
    for func in List:
       b=func(k)
       k=b
if __name__=="__main__":
    run()