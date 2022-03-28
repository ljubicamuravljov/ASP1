
class node:
    def __init__(self,kvadrat=None,level=None,skup=None):
        self.kvadrat=kvadrat
        self.otac=None
        self.sinovi=[]
        self.level=level
        self.skup=skup
    
class tree:
    def __init__(self):
        self.root=None
  
def proverastanja(kvadrat,suma):
    for el in kvadrat:
        suma1=0
        flag=0
        for i in range(len(el)):
            suma1+=el[i]
            if el[i]==0:
                flag=1
            if i!=len(kvadrat)-1:
                if suma1>=suma:return 'ne' 
            else: 
                if flag==1:
                    if suma1>=suma:return 'ne'
                else:
                    if suma1!=suma: return'ne'
        

    for i in range(len(kvadrat)):
        suma1=0
        flag=0
        for j in range(len(kvadrat)):
            if kvadrat [j][i]==0:
                flag=1
            suma1+=kvadrat[j][i]
            if j!=len(kvadrat)-1:
                if suma1>=suma:return 'ne' 
            else: 
                if flag==1:
                    if suma1>=suma:return 'ne'
                else:
                    if suma1!=suma: return'ne' 
    suma1=0   
    flag=0
    for i in range(len(kvadrat)):
        if kvadrat[i][i]==0:
            flag=1
        suma1+=kvadrat[i][i]
        if i!=len(kvadrat)-1:
            if suma1>suma:return 'ne' 
        else: 
            if flag==1:
                if suma1>=suma:return 'ne'
            else:
                if suma1!=suma: return'ne'

    suma1=0
    flag=0
    for i in range(len(kvadrat)):
        if kvadrat[i][len(kvadrat)-i-1]==0:
            flag=1
        suma1+=kvadrat[i][len(kvadrat)-i-1]
        if i!=len(kvadrat)-1:
            if suma1>=suma:return 'ne' 
        else: 
            if flag==1:
                if suma1>=suma:return 'ne'
            
            else:
                if suma1!=suma: return'ne'
def dodavanjesinova(cvor,suma):
    for ell in cvor.skup:
        skup2=[]
        kvadrat2=[]
        for el in cvor.skup:
            if el!=ell:
                skup2.append(el)
        for el in cvor.kvadrat:
            pom=[]
            for b in el:
                pom.append(b)
            kvadrat2.append(pom)
        flag=0

        for el in kvadrat2:
            i=0
            while i<len(el):
                if el[i]==0:
                    el[i]=ell
                    flag=1
                    break
                i+=1
            if flag==1:
                break
        if proverastanja(kvadrat2,suma)!='ne':
            sin=node(kvadrat2,cvor.level+1,skup2)
            sin.otac=cvor
            cvor.sinovi.append(sin)
        else:
            continue

    return cvor.sinovi
def pravljenjestabla2(stablo,skup,suma):
    temp=stablo.root
    lista=[temp]
    c=0
    while True:
        c+=1
        pomnivo=[]
        for el in lista:
            if proverastanja(el.kvadrat,suma)!='ne':
                braca=dodavanjesinova(el,suma)
                for ell in braca:
                    pomnivo.append(ell)
            else:
                continue
        lista=pomnivo[:]
        for el in lista:
            if proverastanja(el.kvadrat,suma)!='ne':continue 
            else: return 'ne moze se napraviti magicni kvadrat'
        if c==len(skup):
            break
def preordstamp(stablo):
    stek=[]
    tekst=''
    cvor=stablo.root
  
    while cvor.sinovi!=[]:
        pomm=cvor.sinovi[-1]
        cvor=cvor.sinovi[-1]
    cvor=stablo.root
    for el in cvor.kvadrat:
                pom=''
                for a in el:
                    pom+=str(a)+' '
                tekst+="\t"*cvor.level+pom+"\n"
                
    stek.append(cvor)
    cvor=cvor.sinovi[0]
    while True:
        
        while cvor.sinovi!=[]:
            stek.append(cvor)
            for el in cvor.kvadrat:
                    pom=''
                    for a in el:
                        pom+=str(a)+' '
                    tekst+="\t"*cvor.level+pom+"\n"
                    
            cvor=cvor.sinovi[0]
        for el in cvor.kvadrat:
                pom=''
                for a in el:
                    pom+=str(a)+' '
                tekst+="\t"*cvor.level+pom+"\n"
                
        
        
        tekst+='\n'
        
        while True:
            flag=0
            if cvor!=pomm:
                if cvor==stek[-1].sinovi[-1]:
                    cvor=stek[-1]
                    stek.remove(stek[-1])
                    continue
                else:
                    try:
                        cvor=stek[-1].sinovi[stek[-1].sinovi.index(cvor)+1]
                        flag=1
                    except IndexError:
                        flag=1
                        break
                if flag==1:
                    break
         
       
            else:
                trrr=''
                for el in cvor.kvadrat:
                    pom=''
                    for a in el:
                        pom+=str(a)+' '
                    trrr+="\t"*cvor.level+pom+"\n"
                    
                    
                    if trrr not in tekst:
                        tekst+=trrr
                        
                return tekst
     
def postorder(stablo):
    stek=[]
    cvor=stablo.root
    cvor=cvor.sinovi[0]
    while True:
        
        while cvor.sinovi!=[]:
            
            cvor=cvor.sinovi[0]
        stek.append(cvor)


        while True:
            flag=0
            if cvor==stablo.root:
                
                return stek
                break

            if cvor!= cvor.otac.sinovi[-1]:
                cvor=cvor.otac.sinovi[cvor.otac.sinovi.index(cvor)+1]
                
                break
            else:
                cvor=cvor.otac
                stek.append(cvor)
                
    return stek[:-1]
def proverasavrsen(kvadrat,n,suma):
    pom=[0,1,2,3]
    k=n
    t=-n
    
    for i in range(n-1):
        p=t
        suma1=0
        suma2=0
        
        for j in range(n):
            suma1+=kvadrat[j][k-1-j]
            
            suma2+=kvadrat[j][p]
            
            p+=1
            
        if suma1!=suma or suma2!=suma:
            return 'ne'
        k-=1
        t+=1
        

def meni():
    listael=[]
    
    suma,flag=0,0
    while True:
        print('GLAVNI MENI')
        print('\n1. Unos pocetnog stanja kvadrata\n2. Unos skupa vrednosti\n3. Kreiranje stabla\n4. Ispis stabla:\n5.Provera savrsen\n6. Izlaz')
        a=input('Uneti redni broj iz menija: ')
        
        
        if a=='1':
            kvadrat=[]

            flag=1
            n=int(input('Uneti dimenziju kvadrata: '))        
            for i in range(n):
                red=input().split(',')
                for j in range(len(red)):
                    if red[j]==' ': 
                        
                        red[j]=0
                    else:
                        red[j]=int(red[j])
                        listael.append(red[j])
                    suma+=red[j]
                    
                kvadrat.append(red)           
            continue
        if a=='2':
            skup=[]
            if flag!=1:
              print('Prvo unesite pocetno stanje kvadrata')
              continue
            else:
                skup=input('Uneti skup vrednosti: ').split(',')
                for i in range(len(skup)):
                    skup[i]=int(skup[i])
                    suma+=skup[i]
                    listael.append(skup[i])
                listael.sort()
                if len(listael)!=n*n:
                    print('Niste uneli odgovarajuci broj elemenata. ')
                    continue
                
                if suma%n!=0:
                    print('Od unetih brojeva se ne moze napraviti magicni kvadrat.')
                    continue
                else:
                    suma=suma/n
                flag=2
        if a=='3':
            if flag!=2:
                print('Prvo unesite skup vrednosti')
            else:
                if proverastanja(kvadrat,suma)=='ne':
                    print('Pogresno unet kvadrat')
                    continue
                koren=node(kvadrat,0,skup)
                flag=3
                stablo=tree()
                stablo.root=koren
                pravljenjestabla2(stablo,skup,suma)
            continue
        
        if a=='4':
            if flag!=3:
                print('Prvo napravite stablo')
            else:
                pom=input('a. Ispis celog stabla \n b. Ispis magicnih kvadrata: ')
                if pom=='a':
                    print(preordstamp(stablo))
                    continue
                if pom=='b':
                    stek=(postorder(stablo))
                    flag=4
                    magicni=[]
                    for el in stek:
                        if el.level==len(skup):
                            for ell in el.kvadrat:
                                print(ell)
                            print('\n')
                            magicni.append(el)
                    continue
        if a=='5':
            if flag!=4:
                print('Prvo ispisite magicne kvadrate')
            else:
                for el in magicni:
                    if proverasavrsen(el.kvadrat,n,suma)!='ne':
                        for ell in el.kvadrat:
                            print(ell)
                        print('\n')
            continue
        if a=='6':
            print('Dovidjenja')
            exit()

meni()