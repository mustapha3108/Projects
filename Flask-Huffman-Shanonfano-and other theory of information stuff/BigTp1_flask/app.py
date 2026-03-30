import numpy as np
import math
from flask import Flask, render_template, request
from itertools import zip_longest

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    h=""
    err=""
    if request.method == 'POST':
        er = False
        prob = request.form['prob']
        try:
            prob = [float(word.strip()) for word in prob.split(",")]
            if sum(prob) != 1 and er==False:
                er = True
        except (ValueError, TypeError):
            er = True
        if er==True:
            err="il y a une faute dans vos données s'il vous plait verifiez qu'ils sont sous la format demandée et qu'ils respectent les lois generaux"
            return render_template('huff.html', err=err)
        else:
            h=0
            for i in prob:
                if i !=0:
                    h=h+i*math.log2(1/i)
            return render_template('index.html', h=h)
    return render_template('index.html', h=h, err=err)

@app.route('/joint', methods=['GET', 'POST'])
def joint():
    Hxy=""
    Hxsy=""
    I=""
    err=""
    if request.method == 'POST':
        er = False
        source1 = request.form['prob1']
        source2 = request.form['prob2']
        prob3 = request.form['prob3']
        try:
            source1 = [float(word.strip()) for word in source1.split(",")]
            source2 = [float(word.strip()) for word in source2.split(",")]
            joint_prob = []
            prob = [word.strip() for word in prob3.split("&")]
            if len(prob) != len(source1):
                er=True
            for i in prob:
                probb = [float(word.strip()) for word in i.split(",")]
                if len(probb) != len(source2):
                    er = True
                joint_prob.append(probb)
            if sum(source1) != 1 or sum (source2) != 1:
                er = True
        except (ValueError, TypeError):
            er= True
        if er==True:
            err="il y a une faute dans vos données s'il vous plait verifiez qu'ils sont sous la format demandée et qu'ils respectent les lois generaux"
            return render_template('joint.html', err=err)
        else:
            elmnt=0
            elmnt2=0
            #l'entropie conjointe
            Hxy=0
            for elmnt in range(len(source1)):
                for elmnt2 in range(len(source2)):
                    Hxy=Hxy+joint_prob[elmnt][elmnt2]*math.log2(1/joint_prob[elmnt][elmnt2])
            print("l'entropie conjointe", Hxy)
            #l'entropie conditiennelle
            Hxsy=0
            for elmnt in range(len(source1)):
                for elmnt2 in range(len(source2)):
                    n=0
                    x=source2[elmnt2]
                    for i in range(len(source2)):
                        if source2[i]==x:
                            n=n+1
                    py=n/len(source2)
                    Hxsy=Hxsy+joint_prob[elmnt][elmnt2]*math.log2(1/(joint_prob[elmnt][elmnt2]/py))
            print("l'entropie conditiennelle", Hxsy, "bits/symbole")
            #quantité d'information mutuelle
            I=0
            for elmnt in range(len(source1)):
                for elmnt2 in range(len(source2)):
                    n=0
                    n2=0
                    elmnts=source1[elmnt]
                    elmnts2=source2[elmnt2]
                    for i in range(len(source2)):
                        if source2[i]==elmnts2:
                            n=n+1
                    for i in range(len(source1)):
                        if source1[i]==elmnts:
                            n2=n2+1
                    px=n2/len(source1)
                    py=n/len(source2)
                    I=I+joint_prob[elmnt][elmnt2]*math.log2(joint_prob[elmnt][elmnt2]/(px*py))
            print("la quantité d'information est:", I, "bits")
            I=round(I,2)
            Hxy=round(Hxy,2)
            Hxsy=round(Hxsy,2)
            render_template('joint.html', I=I, Hxy=Hxy, Hxsy=Hxsy)
    return render_template('joint.html',  I=I, Hxy=Hxy, Hxsy=Hxsy, err=err)

@app.route('/conj', methods=['GET', 'POST'])
def conj():
    Hxy=""
    Hxsy=""
    I=""
    err=""
    if request.method == 'POST':
        er = False
        source1 = request.form['prob1']
        source2 = request.form['prob2']
        prob3 = request.form['prob3']
        try:
            source1 = [float(word.strip()) for word in source1.split(",")]
            source2 = [float(word.strip()) for word in source2.split(",")]
            conj_prob = []
            prob = [word.strip() for word in prob3.split("&")]
            if len(prob) != len(source1):
                er=True
            for i in prob:
                probb = [float(word.strip()) for word in i.split(",")]
                if len(probb) != len(source2):
                    er = True
                conj_prob.append(probb)
            if sum(source1) != 1 or sum (source2) != 1:
                er = True
            #bayes
            joint_prob = []
            for i in range(len(conj_prob)):
                z=[]
                for j in range(len(conj_prob[i])):
                    zz=conj_prob[i][j]*source2[j]
                    z.append(zz)
                joint_prob.append(z)
        except (ValueError, TypeError):
            er= True
        if er==True:
            err="il y a une faute dans vos données s'il vous plait verifiez qu'ils sont sous la format demandée et qu'ils respectent les lois generaux"
            return render_template('conj.html', err=err)
        else:
            elmnt=0
            elmnt2=0
            #l'entropie conjointe
            Hxy=0
            for elmnt in range(len(source1)):
                for elmnt2 in range(len(source2)):
                    Hxy=Hxy+joint_prob[elmnt][elmnt2]*math.log2(1/joint_prob[elmnt][elmnt2])
            print("l'entropie conjointe", Hxy)
            #l'entropie conditiennelle
            Hxsy=0
            for elmnt in range(len(source1)):
                for elmnt2 in range(len(source2)):
                    n=0
                    x=source2[elmnt2]
                    for i in range(len(source2)):
                        if source2[i]==x:
                            n=n+1
                    py=n/len(source2)
                    Hxsy=Hxsy+joint_prob[elmnt][elmnt2]*math.log2(1/(joint_prob[elmnt][elmnt2]/py))
            print("l'entropie conditiennelle", Hxsy, "bits/symbole")
            #quantité d'information mutuelle
            I=0
            for elmnt in range(len(source1)):
                for elmnt2 in range(len(source2)):
                    n=0
                    n2=0
                    elmnts=source1[elmnt]
                    elmnts2=source2[elmnt2]
                    for i in range(len(source2)):
                        if source2[i]==elmnts2:
                            n=n+1
                    for i in range(len(source1)):
                        if source1[i]==elmnts:
                            n2=n2+1
                    px=n2/len(source1)
                    py=n/len(source2)
                    I=I+joint_prob[elmnt][elmnt2]*math.log2(joint_prob[elmnt][elmnt2]/(px*py))
            print("la quantité d'information est:", I, "bits")
            I=round(I,2)
            Hxy=round(Hxy,2)
            Hxsy=round(Hxsy,2)
            render_template('conj.html', I=I, Hxy=Hxy, Hxsy=Hxsy)
    return render_template('conj.html',  I=I, Hxy=Hxy, Hxsy=Hxsy, err=err)


#fonctions pour la class prefix
def kraft(code):
    kraft=0
    iskraft=None
    for i in code:
        kraft=kraft+2**(-len(i))
    print("le resultat de kraft est: ", kraft)
    iskraft=True if kraft<=1 else False
    return iskraft
#calcule efficacité
def effective(code, prob):
    h=0
    l=0
    for i in range(len(code)):
        l=l+len(code[i])*prob[i]
        h=h+prob[i]*np.log2(1/prob[i])
    return h/l
#verifier si prefix
def prefix(code):
    prefix=True
    for i in range(len(code)):
        for x in range(len(code)):
            if i!=x and code[x].startswith(code[i]):
                prefix=False
                break
        if prefix==False:
            break
    return prefix
#essayer de decoder le message
def decode(code, mess):
    decodable=True
    i=0
    while i < len(mess):
        for x in code:
            if x == mess[i:i+len(x)]:
                i=i+len(x)
                break
        else:
            decodable=False
            break
    return decodable

@app.route('/prefixx', methods=['GET', 'POST'])
def prefixx():
    rr=""
    err=""
    if request.method == 'POST':
        er = False
        prob = request.form['prob']
        code = request.form['code']
        try:
            prob = [float(word.strip()) for word in prob.split(",")]
            code = [word.strip() for word in code.split(",")]
            if sum(prob) != 1 and er==False:
                er = True
            is_subset = all(set(element).issubset({'0', '1'}) for element in code)
            if is_subset == False:
                er = True
        except (ValueError, TypeError):
            er = True
        if er==True:
            err="il y a une faute dans vos données s'il vous plait verifiez qu'ils sont sous la format demandée et qu'ils respectent les lois generaux"
            return render_template('prefix.html', err=err)
        else:
            k=kraft(code)
            if k:
                p=prefix(code)
                if p:
                    iht = effective(code, prob)
                    rr = "Le code est prefix donc instantané et unique avec l'efficacité de: " + str(iht)
                else:
                    #utiliser une loop pour tester different ordre des element de code
                    mess="".join(np.random.choice(code, len(code)*2))
                    decoded=0
                    code2=code
                    #ordre decroissant pour avoir une meilleur chance pour decoder
                    code2.sort(key=len, reverse=True)
                    i=0
                    while i<len(code):
                        d=decode(code2, mess)
                        if d:
                            decoded=decoded+1
                            print("decoded: ", decoded)
                        #changer l'ordre de code
                        code2=np.roll(code2,1)
                        i=i+1
                    if decoded==1 :
                        rr="le code est unique"
                    elif decoded == len(code) :
                        rr="le code est instantané"
                    else :
                        rr="le code n'est ni unique ni instantané"
            else :
                rr="le code ne satifait pas kraft, donc ni prefix ni unique"
                mess="".join(np.random.choice(code, len(code)*2))
                decoded=0
                for i in range(len(code)):
                    d=decode(code, mess)
                    if d:
                        decoded=decoded+1
                        np.roll(code,1)
                if decoded == len(code) :
                    rr="le code est instantané"
                else:
                    rr="le code n'est pas instantané"
    return render_template('prefix.html', rr=rr, err=err)

if __name__ == "__main__":
    app.run(debug=True)