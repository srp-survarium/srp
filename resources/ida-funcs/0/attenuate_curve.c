void __usercall attenuate_curve(float *c@<eax>, float att)
{
  double v2; // st7
  float *v3; // eax
  int v4; // ecx
  double v5; // st6

  v2 = att;
  v3 = c + 2;
  v4 = 7;
  do
  {
    v5 = *(v3 - 2);
    v3 += 8;
    --v4;
    *(v3 - 10) = v5 + v2;
    *(v3 - 9) = v2 + *(v3 - 9);
    *(v3 - 8) = *(v3 - 8) + v2;
    *(v3 - 7) = *(v3 - 7) + v2;
    *(v3 - 6) = *(v3 - 6) + v2;
    *(v3 - 5) = *(v3 - 5) + v2;
    *(v3 - 4) = v2 + *(v3 - 4);
    *(v3 - 3) = *(v3 - 3) + v2;
  }
  while ( v4 );
}
