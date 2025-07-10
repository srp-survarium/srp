void __cdecl _tr_flush_block(internal_state *s, char *buf, unsigned int stored_len, int eof)
{
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // ebx
  int dummy; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int max_blindex; // [esp+Ch] [ebp-4h]

  max_blindex = 0;
  if ( s[33].dummy <= 0 )
  {
    v7 = stored_len + 5;
LABEL_8:
    v6 = v7;
    goto LABEL_9;
  }
  if ( stored_len && *(_DWORD *)(s->dummy + 44) == 2 )
    set_data_type(v4, s);
  build_tree(s, (tree_desc_s *)&s[710]);
  build_tree(s, (tree_desc_s *)&s[713]);
  v5 = build_bl_tree(s);
  v6 = (unsigned int)(s[1450].dummy + 10) >> 3;
  v7 = (unsigned int)(s[1451].dummy + 10) >> 3;
  max_blindex = v5;
  if ( v7 <= v6 )
    goto LABEL_8;
LABEL_9:
  if ( stored_len + 4 <= v6 && buf )
  {
    v8 = eof;
    _tr_stored_block(s, buf, stored_len, eof);
  }
  else if ( s[34].dummy == 4 || v7 == v6 )
  {
    dummy = s[1455].dummy;
    v8 = eof;
    v16 = eof + 2;
    if ( dummy <= 13 )
    {
      LOWORD(s[1454].dummy) |= v16 << dummy;
      s[1455].dummy = dummy + 3;
    }
    else
    {
      v17 = v16 << dummy;
      v18 = s[2].dummy;
      LOWORD(s[1454].dummy) |= v17;
      *(_BYTE *)(v18 + s[5].dummy++) = s[1454].dummy;
      *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
      v19 = s[1455].dummy;
      ++s[5].dummy;
      s[1455].dummy = v19 - 13;
      LOWORD(s[1454].dummy) = (unsigned __int16)v16 >> (16 - v19);
    }
    compress_block(s, (ct_data_s *)static_ltree, (ct_data_s *)static_dtree);
  }
  else
  {
    v10 = s[1455].dummy;
    v8 = eof;
    v11 = eof + 4;
    if ( v10 <= 13 )
    {
      LOWORD(s[1454].dummy) |= v11 << v10;
      s[1455].dummy = v10 + 3;
    }
    else
    {
      v12 = v11 << v10;
      v13 = s[2].dummy;
      LOWORD(s[1454].dummy) |= v12;
      *(_BYTE *)(v13 + s[5].dummy++) = s[1454].dummy;
      *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
      v14 = s[1455].dummy;
      ++s[5].dummy;
      s[1455].dummy = v14 - 13;
      LOWORD(s[1454].dummy) = (unsigned __int16)v11 >> (16 - v14);
    }
    send_all_trees(s, s[711].dummy + 1, s[714].dummy + 1, max_blindex + 1);
    compress_block(s, (ct_data_s *)&s[37], (ct_data_s *)&s[610]);
  }
  init_block(v9, s);
  if ( v8 )
    bi_windup(s);
}
