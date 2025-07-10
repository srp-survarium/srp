void __usercall send_all_trees(internal_state *s@<eax>, int lcodes, int dcodes, int blcodes)
{
  int dummy; // ecx
  int v5; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int i; // edi
  int v18; // ecx
  int v19; // edx
  unsigned __int16 dummy_high; // si
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  internal_state *v24; // eax

  dummy = s[1455].dummy;
  v5 = blcodes;
  if ( dummy <= 11 )
  {
    LOWORD(s[1454].dummy) |= (lcodes - 257) << dummy;
    s[1455].dummy = dummy + 5;
  }
  else
  {
    v6 = (lcodes - 257) << dummy;
    v7 = s[5].dummy;
    LOWORD(s[1454].dummy) |= v6;
    *(_BYTE *)(v7 + s[2].dummy) = s[1454].dummy;
    *(_BYTE *)(++s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
    v8 = s[1455].dummy;
    ++s[5].dummy;
    v5 = blcodes;
    s[1455].dummy = v8 - 11;
    LOWORD(s[1454].dummy) = (unsigned __int16)(lcodes - 257) >> (16 - v8);
  }
  v9 = s[1455].dummy;
  if ( v9 <= 11 )
  {
    LOWORD(s[1454].dummy) |= (dcodes - 1) << v9;
    s[1455].dummy = v9 + 5;
  }
  else
  {
    v10 = (dcodes - 1) << v9;
    v11 = s[5].dummy;
    LOWORD(s[1454].dummy) |= v10;
    *(_BYTE *)(v11 + s[2].dummy) = s[1454].dummy;
    *(_BYTE *)(++s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
    v12 = s[1455].dummy;
    ++s[5].dummy;
    s[1455].dummy = v12 - 11;
    LOWORD(s[1454].dummy) = (unsigned __int16)(dcodes - 1) >> (16 - v12);
  }
  v13 = s[1455].dummy;
  if ( v13 <= 12 )
  {
    LOWORD(s[1454].dummy) |= (v5 - 4) << v13;
    s[1455].dummy = v13 + 4;
  }
  else
  {
    v14 = (v5 - 4) << v13;
    v15 = s[5].dummy;
    LOWORD(s[1454].dummy) |= v14;
    *(_BYTE *)(v15 + s[2].dummy) = s[1454].dummy;
    *(_BYTE *)(++s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
    v16 = s[1455].dummy;
    ++s[5].dummy;
    s[1455].dummy = v16 - 12;
    LOWORD(s[1454].dummy) = (unsigned __int16)(v5 - 4) >> (16 - v16);
  }
  for ( i = 0; i < v5; ++i )
  {
    v18 = s[1455].dummy;
    v19 = bl_order[i];
    if ( v18 <= 13 )
    {
      LOWORD(s[1454].dummy) |= HIWORD(s[v19 + 671].dummy) << v18;
      s[1455].dummy = v18 + 3;
    }
    else
    {
      dummy_high = HIWORD(s[v19 + 671].dummy);
      v21 = dummy_high << v18;
      v22 = s[5].dummy;
      LOWORD(s[1454].dummy) |= v21;
      *(_BYTE *)(v22 + s[2].dummy) = s[1454].dummy;
      *(_BYTE *)(++s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
      v23 = s[1455].dummy;
      ++s[5].dummy;
      v5 = blcodes;
      s[1455].dummy = v23 - 13;
      LOWORD(s[1454].dummy) = dummy_high >> (16 - v23);
    }
  }
  send_tree(s, (ct_data_s *)&s[37], lcodes - 1);
  send_tree(v24, (ct_data_s *)&v24[610], dcodes - 1);
}
