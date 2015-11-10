/* registres.c

   Utiliser plein de registres, si possible
*/
foo(){
  int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16;

  for(i0 = 0; i0 < 100000; i0++)
    for(i1 = 1; i1 < 100001; i1++)
      for(i2 = 2; i2 < 100002; i2++)
	for(i3 = 3; i3 < 100003; i3++)
	  for(i4 = 4; i4 < 100004; i4++)
	    for(i5 = 5; i5 < 100005; i5++)
	      for(i7 = 7; i7 < 100007; i7++)

	      for(i8 = 8; i8 < 100008; i8++)
				    bar();
}
