void __cdecl Scaleform::Render::ConvertIndices_NonOpt(
        unsigned __int16 *pdest,
        unsigned __int16 *psource,
        unsigned int count,
        unsigned __int16 delta)
{
  unsigned __int16 *v4; // ecx
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  unsigned __int16 *i; // esi

  v4 = pdest;
  if ( (count & 3) == 1 )
  {
    v6 = psource;
  }
  else if ( (count & 3) == 2 )
  {
    *pdest = delta + *psource;
    v4 = pdest + 1;
    v6 = psource + 1;
  }
  else
  {
    v5 = psource;
    if ( (count & 3) != 3 )
      goto LABEL_8;
    *pdest = delta + *psource;
    pdest[1] = delta + psource[1];
    v4 = pdest + 2;
    v6 = psource + 2;
  }
  *v4++ = delta + *v6;
  v5 = v6 + 1;
LABEL_8:
  for ( i = &v5[count & 0xFFFFFFFC]; v5 < i; v4 += 4 )
  {
    *v4 = delta + *v5;
    v4[1] = delta + v5[1];
    v4[2] = delta + v5[2];
    v4[3] = delta + v5[3];
    v5 += 4;
  }
}
