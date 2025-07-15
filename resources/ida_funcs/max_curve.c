void __usercall max_curve(float *c@<ecx>, float *c2@<eax>)
{
  float *v3; // ecx
  int v4; // edi
  float *v5; // edx
  int v6; // esi

  v3 = c + 1;
  v4 = (char *)c2 - (char *)c;
  v5 = c2 + 3;
  v6 = 14;
  do
  {
    if ( *(v3 - 1) < (double)*(v5 - 3) )
      *(v3 - 1) = *(v5 - 3);
    if ( *v3 < (double)*(float *)((char *)v3 + v4) )
      *v3 = *(float *)((char *)v3 + v4);
    if ( v3[1] < (double)*(v5 - 1) )
      v3[1] = *(v5 - 1);
    if ( v3[2] < (double)*v5 )
      v3[2] = *v5;
    v3 += 4;
    v5 += 4;
    --v6;
  }
  while ( v6 );
}
