void __usercall flag_lossless(
        float *floor@<eax>,
        char *flag@<ecx>,
        int limit,
        float prepoint,
        float postpoint,
        float *mdct,
        int i,
        int jn)
{
  int v8; // edx
  double v9; // st7
  double v10; // st6
  int v11; // edi
  double v12; // rt0
  double v13; // rt1
  double v14; // st6
  double v15; // st7
  double v16; // rt2
  float point; // [esp+10h] [ebp-8h]
  float v18; // [esp+14h] [ebp-4h]

  v8 = 0;
  if ( jn > 0 )
  {
    v9 = postpoint;
    v10 = prepoint;
    v11 = (char *)floor - flag;
    while ( 1 )
    {
      if ( v8 < limit - i )
      {
        point = v10;
        v16 = v10;
        v14 = v9;
        v15 = v16;
      }
      else
      {
        v13 = v10;
        v14 = v9;
        v15 = v13;
        point = v14;
      }
      v18 = fabs(*(float *)&flag[v11 + (char *)mdct - (char *)floor]) / *(float *)&flag[v11];
      *(_DWORD *)flag = point <= (double)v18;
      ++v8;
      flag += 4;
      if ( v8 >= jn )
        break;
      v12 = v14;
      v10 = v15;
      v9 = v12;
    }
  }
}
