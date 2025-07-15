void __usercall pqdownheap(internal_state *s@<eax>, ct_data_s *tree@<edi>, int k)
{
  int dummy; // edx
  int v4; // ebp
  int v5; // ecx
  bool v6; // cc
  int v7; // esi
  int v8; // ebp
  unsigned __int16 freq; // dx
  unsigned __int16 v10; // bx
  int v11; // esi
  unsigned __int16 v12; // dx
  unsigned __int16 v13; // bx
  int v14; // edx
  int v; // [esp+8h] [ebp-4h]

  dummy = s[1300].dummy;
  v4 = s[k + 727].dummy;
  v5 = 2 * k;
  v6 = 2 * k < dummy;
  v = v4;
  if ( 2 * k > dummy )
  {
    s[k + 727].dummy = v4;
  }
  else
  {
    while ( 1 )
    {
      if ( v6 )
      {
        v7 = s[v5 + 728].dummy;
        v8 = s[v5 + 727].dummy;
        freq = tree[v7].fc.freq;
        v10 = tree[v8].fc.freq;
        if ( freq < v10 || freq == v10 && *((_BYTE *)&s[1302].dummy + v7) <= *((_BYTE *)&s[1302].dummy + v8) )
          ++v5;
        v4 = v;
      }
      v11 = s[v5 + 727].dummy;
      v12 = tree[v4].fc.freq;
      v13 = tree[v11].fc.freq;
      if ( v12 < v13 )
      {
LABEL_12:
        s[k + 727].dummy = v4;
        return;
      }
      if ( v12 == v13 && *((_BYTE *)&s[1302].dummy + v4) <= *((_BYTE *)&s[1302].dummy + v11) )
        break;
      s[k + 727].dummy = v11;
      v14 = s[1300].dummy;
      k = v5;
      v5 *= 2;
      v6 = v5 < v14;
      if ( v5 > v14 )
        goto LABEL_12;
    }
    s[k + 727].dummy = v4;
  }
}
