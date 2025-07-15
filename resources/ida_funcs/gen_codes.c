void __usercall gen_codes(ct_data_s *tree@<edi>, int max_code@<ebx>, char *bl_count@<edx>)
{
  unsigned __int16 v3; // cx
  int v4; // eax
  int v5; // edx
  int i; // esi
  int dad; // edx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // ebp
  unsigned __int16 next_code[16]; // [esp+4h] [ebp-20h] BYREF

  v3 = 0;
  v4 = 1;
  v5 = bl_count - (char *)&next_code[1];
  do
  {
    v3 = 2 * (v3 + *(unsigned __int16 *)((char *)&next_code[v4] + v5));
    next_code[v4++] = v3;
  }
  while ( v4 <= 15 );
  for ( i = 0; i <= max_code; ++i )
  {
    dad = tree[i].dl.dad;
    if ( tree[i].dl.dad )
    {
      v8 = next_code[dad];
      v9 = v8;
      next_code[dad] = v8 + 1;
      v10 = 0;
      do
      {
        v11 = v9 & 1;
        --dad;
        v9 >>= 1;
        v10 = 2 * (v11 | v10);
      }
      while ( dad > 0 );
      tree[i].fc.freq = v10 >> 1;
    }
  }
}
