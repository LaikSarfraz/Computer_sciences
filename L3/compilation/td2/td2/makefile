
archive:
	cd .. ; tar cf /tmp/td2.tar td2 ; mv /tmp/td2.tar td2/

progs: q1 q2 q3 q4 q5
q1: min2-d.c min2.s
	gcc -g -Wall -m32 min2-d.c min2.s -o q1
q2: indexa-d.c indexa.s
	gcc -g -Wall -m32 indexa-d.c indexa.s -o q2
q3: rindexa-d.c rindexa.s
	gcc -g -Wall -m32 rindexa-d.c rindexa.s -o q3
q4: fact-d.c fact.s
	gcc -g -Wall -m32 fact-d.c fact.s -o q4
q5: fib-d.c fib.s
	gcc -g -Wall -m32 fib-d.c fib.s -o q5

td2-corr.pdf: td2-corr.tex
	for i in a b c ; do pdflatex td2-corr.tex ; done

clean:
	rm -fr q? a.out core *~ *.log *.aux *.dvi *.pdf *.tar
