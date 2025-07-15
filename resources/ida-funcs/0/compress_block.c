void __usercall compress_block(internal_state *s@<eax>, ct_data_s *ltree, ct_data_s *dtree)
{
  ct_data_s *v3; // ebx
  unsigned int v4; // ecx
  int v5; // ebp
  int v6; // esi
  int dummy; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned int v14; // edx
  int freq; // edi
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // edi
  int v20; // esi
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  unsigned int v26; // ebp
  int v27; // edi
  unsigned int dad; // edx
  int v29; // ecx
  unsigned __int16 v30; // si
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // esi
  int v35; // ecx
  unsigned int v36; // ebp
  unsigned int v37; // edx
  int v38; // ecx
  int v39; // edx
  int v40; // edi
  int v41; // ecx
  unsigned __int16 v42; // si
  int v43; // edx
  int v44; // ecx
  int v45; // edx
  int len; // [esp+10h] [ebp-Ch]
  unsigned int code; // [esp+14h] [ebp-8h]
  unsigned int codea; // [esp+14h] [ebp-8h]
  unsigned int lx; // [esp+18h] [ebp-4h]

  v3 = ltree;
  v4 = 0;
  if ( s[1448].dummy )
  {
    do
    {
      v5 = *(unsigned __int16 *)(s[1449].dummy + 2 * v4);
      v6 = *(unsigned __int8 *)(v4 + s[1446].dummy);
      lx = v4 + 1;
      dummy = s[1455].dummy;
      if ( v5 )
      {
        v14 = _length_code[v6];
        len = v3[v14 + 257].dl.dad;
        code = v14;
        if ( dummy <= 16 - len )
        {
          LOWORD(s[1454].dummy) |= ltree[v14 + 257].fc.freq << dummy;
          s[1455].dummy = len + dummy;
        }
        else
        {
          freq = ltree[v14 + 257].fc.freq;
          v16 = freq << dummy;
          v17 = s[2].dummy;
          LOWORD(s[1454].dummy) |= v16;
          *(_BYTE *)(v17 + s[5].dummy++) = s[1454].dummy;
          *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
          v18 = s[1455].dummy;
          ++s[5].dummy;
          LOWORD(freq) = (unsigned __int16)freq >> (16 - v18);
          s[1455].dummy = v18 + len - 16;
          v14 = code;
          LOWORD(s[1454].dummy) = freq;
        }
        v19 = extra_lbits[v14];
        v3 = ltree;
        if ( v19 )
        {
          v20 = v6 - base_length[v14];
          v21 = s[1455].dummy;
          if ( v21 <= 16 - v19 )
          {
            LOWORD(s[1454].dummy) |= v20 << v21;
            v25 = v19 + v21;
          }
          else
          {
            v22 = v20 << v21;
            v23 = s[2].dummy;
            LOWORD(s[1454].dummy) |= v22;
            *(_BYTE *)(v23 + s[5].dummy++) = s[1454].dummy;
            *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
            v24 = s[1455].dummy;
            ++s[5].dummy;
            v3 = ltree;
            v25 = v24 + v19 - 16;
            LOWORD(s[1454].dummy) = (unsigned __int16)v20 >> (16 - v24);
          }
          s[1455].dummy = v25;
        }
        v26 = v5 - 1;
        if ( v26 >= 0x100 )
          v27 = (unsigned __int8)byte_7332C8[v26 >> 7];
        else
          v27 = _dist_code[v26];
        dad = dtree[v27].dl.dad;
        v29 = s[1455].dummy;
        codea = dad;
        if ( v29 <= (int)(16 - dad) )
        {
          LOWORD(s[1454].dummy) |= dtree[v27].fc.freq << v29;
          s[1455].dummy = dad + v29;
        }
        else
        {
          v30 = dtree[v27].fc.freq;
          v31 = v30 << v29;
          v32 = s[2].dummy;
          LOWORD(s[1454].dummy) |= v31;
          *(_BYTE *)(v32 + s[5].dummy++) = s[1454].dummy;
          *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
          v33 = s[1455].dummy;
          ++s[5].dummy;
          v3 = ltree;
          s[1455].dummy = v33 + codea - 16;
          LOWORD(s[1454].dummy) = v30 >> (16 - v33);
        }
        v34 = extra_dbits[v27];
        if ( !v34 )
          goto LABEL_25;
        v35 = s[1455].dummy;
        v36 = v26 - base_dist[v27];
        if ( v35 <= 16 - v34 )
        {
          LOWORD(s[1454].dummy) |= v36 << v35;
          v13 = v34 + v35;
        }
        else
        {
          v37 = v36 << v35;
          v38 = s[2].dummy;
          LOWORD(s[1454].dummy) |= v37;
          *(_BYTE *)(v38 + s[5].dummy++) = s[1454].dummy;
          *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
          v39 = s[1455].dummy;
          ++s[5].dummy;
          v13 = v39 + v34 - 16;
          LOWORD(s[1454].dummy) = (unsigned __int16)v36 >> (16 - v39);
        }
      }
      else
      {
        v8 = v3[v6].dl.dad;
        if ( dummy <= 16 - v8 )
        {
          LOWORD(s[1454].dummy) |= v3[v6].fc.freq << dummy;
          v13 = v8 + dummy;
        }
        else
        {
          v9 = v3[v6].fc.freq;
          v10 = v9 << dummy;
          v11 = s[2].dummy;
          LOWORD(s[1454].dummy) |= v10;
          *(_BYTE *)(v11 + s[5].dummy++) = s[1454].dummy;
          *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
          v12 = s[1455].dummy;
          ++s[5].dummy;
          v13 = v12 + v8 - 16;
          LOWORD(s[1454].dummy) = (unsigned __int16)v9 >> (16 - v12);
        }
      }
      s[1455].dummy = v13;
LABEL_25:
      v4 = lx;
    }
    while ( lx < s[1448].dummy );
  }
  v40 = v3[256].dl.dad;
  v41 = s[1455].dummy;
  if ( v41 <= 16 - v40 )
  {
    LOWORD(s[1454].dummy) |= v3[256].fc.freq << v41;
    s[1455].dummy = v40 + v41;
  }
  else
  {
    v42 = v3[256].fc.freq;
    v43 = v42 << v41;
    v44 = s[2].dummy;
    LOWORD(s[1454].dummy) |= v43;
    *(_BYTE *)(v44 + s[5].dummy++) = s[1454].dummy;
    *(_BYTE *)(s[2].dummy + s[5].dummy) = BYTE1(s[1454].dummy);
    v45 = s[1455].dummy;
    ++s[5].dummy;
    s[1455].dummy = v45 + v40 - 16;
    LOWORD(s[1454].dummy) = v42 >> (16 - v45);
  }
  s[1453].dummy = v3[256].dl.dad;
}
