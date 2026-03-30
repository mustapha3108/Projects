import numpy as np
import math
from flask import Flask, render_template, request
from itertools import zip_longest

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/huff', methods=['GET', 'POST'])
def huff():
    n=""
    putput=""
    err=""
    if request.method == 'POST':
        er = False
        prob = request.form['prob']
        symboles = request.form['sym']
        try:
            prob = [float(word.strip()) for word in prob.split(",")]
            symboles = [word.strip() for word in symboles.split(",")]
            if sum(prob) != 1 and er==False:
                er = True
        except (ValueError, TypeError):
            er= True
        if len(symboles) != len(set(symboles)):
            er = True
        if er==True:
            err="il y a une faute dans vos données s'il vous plait verifiez qu'ils sont sous la format demandée et qu'ils respectent les lois generaux"
            return render_template('huff.html', err=err)
        else:
            #trier les symboles et probabilitées
            sorted_pairs = sorted(zip(prob, symboles), key=lambda x: x[0], reverse=True)
            prob, symboles = zip(*sorted_pairs)
            prob = list(prob)
            symboles = list(symboles)
            print("Symboles et probabilités triés:")
            #concatener les symboles et leur probabilitées on une seul list
            for i in range(len(symboles)):
                print(symboles[i], "   ", prob[i])
            serpant = [f"{symboles[i]},{prob[i]}" for i in range(len(symboles))]
            world_serpant = [serpant]
            print("Liste initiale (serpant):")
            print(serpant)
            # Huffman 
            #creer les etapes comme des sous listes (addition des probabilitées et placements des symboles)
            l = 0
            while len(world_serpant[l]) > 2:
                x1, x2 = world_serpant[l][-1].split(',')
                y1, y2 = world_serpant[l][-2].split(',')
                z = [x1 + y1, round(float(x2) + float(y2),2)]
                new = world_serpant[l][:-2]
                inserted = False
                for i, v in enumerate(new):
                    p = v.split(',')
                    if z[1] >= float(p[1]):
                        new.insert(i, f"{z[0]},{z[1]}")
                        inserted = True
                        break
                if not inserted:
                    new.append(f"{z[0]},{z[1]}")
                world_serpant.append(new)
                l += 1
            #attacher les code binaire et calcule de r
            print(world_serpant)
            r=0
            putput=[]
            for ri,i in enumerate(world_serpant[0]):
                x,y=i.split(',')
                code=""
                for j in world_serpant:
                    for ij,jj in enumerate(j):
                        if x in jj and ij==len(j)-1: code="1"+code
                        if x in jj and ij==len(j)-2: code="0"+code
                mp=x + "  ==>  " + code
                print(mp)
                putput.append(mp)
                r=r+len(code)*prob[ri]
            #calcule de Hx et l'efficacité
            Hx=0
            for i in prob:
                Hx=Hx+i*math.log2(1/i)
            n=Hx/r
            n=round(n,2)
            render_template('huff.html', n=n, putput=putput)
    return render_template('huff.html', n=n, putput=putput, err=err)

@app.route('/fano', methods=['GET', 'POST'])
def fano():
    n=""
    putput=""
    err=""
    if request.method == 'POST':
        er = False
        prob = request.form['prob']
        symboles = request.form['sym']
        try:
            prob = [float(word.strip()) for word in prob.split(",")]
            symboles = [word.strip() for word in symboles.split(",")]
            if sum(prob) != 1 and er==False:
                er = True
        except (ValueError, TypeError):
            er= True
        if len(symboles) != len(set(symboles)):
            er = True
        if er==True:
            err="il y a une faute dans vos données s'il vous plait verifiez qu'ils sont sous la format demandée et qu'ils respectent les lois generaux"
            return render_template('huff.html', err=err)
        else:
            #trier les symboles et probabilitées
            sorted_pairs = sorted(zip(prob, symboles), key=lambda x: x[0], reverse=True)
            prob, symboles = zip(*sorted_pairs)
            prob = list(prob)
            symboles = list(symboles)
            #calcule de hx
            hx=0
            for i in prob:
                hx=hx+(i*math.log2(1/i))
            #ajouter "," a les symboles pour concatener leur code binaire
            for i in range(len(symboles)):
                symboles[i]=symboles[i]+","
            #shanon-fano
            x=0
            j=0
            k=len(prob)
            prob=[prob]
            symboles=[symboles]
            while j < k:
                if len(prob[j]) != 1:
                    for i in range(len(prob[j])):
                        if round(abs((sum(prob[j])/2)-(x+prob[j][i])),5) > round(abs((sum(prob[j])/2)-(x+prob[j][i]+prob[j][i+1])),5):
                            x=x+prob[j][i]
                        elif round(abs((sum(prob[j])/2)-(x+prob[j][i]))) <= round(abs((sum(prob[j])/2)-(x+prob[j][i]+prob[j][i+1]))):
                            code1=prob[j][:i+1]
                            sym1=symboles[j][:i+1]
                            code2=prob[j][i+1:]
                            sym2=symboles[j][i+1:]
                            for z in range(len(sym1)):
                                sym1[z]=sym1[z]+"0"
                            for z in range(len(sym2)):
                                sym2[z]=sym2[z]+"1"
                            del prob[j]
                            del symboles[j]
                            prob.append(code1)
                            prob.append(code2)
                            symboles.append(sym1)
                            symboles.append(sym2)
                            break
                    j=-1
                    x=0
                k=len(prob)
                j=j+1
            #calcule de R et l'efficacité
            R=0
            for i,j in enumerate(symboles):
                s,b=j[0].split(',')
                R=R+ len(b)*prob[i][0]
            n=hx/R
            n=round(n,2)
            putput=[]
            #affichage des resultas
            for i in range(len(symboles)):
                s,b=symboles[i][0].split(',')
                mp=s+ " ===> "+ b
                putput.append(mp)
            render_template('fan.html', n=n, putput=putput)
    return render_template('fan.html', n=n, putput=putput, err=err)

if __name__ == "__main__":
    app.run(debug=True)