void __usercall build_tree(internal_state *s@<esi>, tree_desc_s *desc)
{
  ct_data_s *dyn_tree; // edi
  static_tree_desc_s *stat_desc; // eax
  int dummy; // ecx
  int v5; // edx
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int i; // ebp
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // ebp
  int v14; // eax
  unsigned __int8 v15; // cl
  int max_code; // [esp+Ch] [ebp-8h]
  int elems; // [esp+10h] [ebp-4h]

  dyn_tree = desc->dyn_tree;
  stat_desc = desc->stat_desc;
  dummy = stat_desc[3].dummy;
  v5 = stat_desc->dummy;
  v6 = -1;
  v7 = 0;
  elems = dummy;
  max_code = -1;
  s[1300].dummy = 0;
  for ( s[1301].dummy = 573; v7 < dummy; ++v7 )
  {
    if ( dyn_tree[v7].fc.freq )
    {
      s[++s[1300].dummy + 727].dummy = v7;
      max_code = v7;
      *((_BYTE *)&s[1302].dummy + v7) = 0;
      v6 = v7;
    }
    else
    {
      dyn_tree[v7].dl.dad = 0;
    }
  }
  if ( s[1300].dummy < 2 )
  {
    do
    {
      if ( v6 >= 2 )
        v8 = 0;
      else
        v8 = ++v6;
      s[++s[1300].dummy + 727].dummy = v8;
      dyn_tree[v8].fc.freq = 1;
      *((_BYTE *)&s[1302].dummy + v8) = 0;
      --s[1450].dummy;
      if ( v5 )
        s[1451].dummy -= *(unsigned __int16 *)(v5 + 4 * v8 + 2);
    }
    while ( s[1300].dummy < 2 );
    max_code = v6;
  }
  desc->max_code = v6;
  for ( i = s[1300].dummy / 2; i >= 1; --i )
    pqdownheap(s, dyn_tree, i);
  v10 = elems;
  do
  {
    v11 = s[1300].dummy;
    v12 = s[v11 + 727].dummy;
    v13 = s[728].dummy;
    s[1300].dummy = v11 - 1;
    s[728].dummy = v12;
    pqdownheap(s, dyn_tree, 1);
    v14 = s[728].dummy;
    --s[1301].dummy;
    s[s[1301].dummy-- + 727].dummy = v13;
    s[s[1301].dummy + 727].dummy = v14;
    dyn_tree[v10].fc.freq = dyn_tree[v13].fc.freq + dyn_tree[v14].fc.freq;
    v15 = *((_BYTE *)&s[1302].dummy + v14);
    if ( *((_BYTE *)&s[1302].dummy + v13) >= v15 )
      v15 = *((_BYTE *)&s[1302].dummy + v13);
    *((_BYTE *)&s[1302].dummy + v10) = v15 + 1;
    dyn_tree[v14].dl.dad = v10;
    dyn_tree[v13].dl.dad = v10;
    s[728].dummy = v10++;
    pqdownheap(s, dyn_tree, 1);
  }
  while ( s[1300].dummy >= 2 );
  s[--s[1301].dummy + 727] = s[728];
  gen_bitlen(s, desc);
  gen_codes(dyn_tree, max_code, (char *)&s[719]);
}
