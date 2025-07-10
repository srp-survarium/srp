void __usercall vostok::resources::queries_result::mark_inconsistent_qualities_as_failed(
        vostok::resources::queries_result *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // ebx
  void *v3; // esp
  unsigned int v4; // eax
  unsigned int *v5; // ecx
  int v6; // edx
  bool v7; // sf
  int v8; // edx
  int v9; // eax
  _DWORD *i; // ecx
  int v11; // eax
  bool v12; // zf
  int v13; // eax
  unsigned int v14; // ecx
  _DWORD *v15; // eax
  unsigned int v16[2]; // [esp+0h] [ebp-Ch] BYREF
  unsigned int v17; // [esp+8h] [ebp-4h]

  v2 = a2[14];
  v3 = alloca(4 * v2);
  v4 = 0;
  if ( v2 )
  {
    v5 = a2 + 190;
    do
    {
      v16[v4++] = *v5;
      v5 += 180;
    }
    while ( v4 < a2[14] );
  }
  stlp_std::sort<unsigned int *>(v16, (stlp_std::less<unsigned int>)a2, &v16[a2[14]]);
  v6 = a2[14];
  v7 = v6 - 1 < 0;
  v8 = v6 - 1;
  v17 = -1;
  if ( !v7 )
  {
    do
    {
      v9 = 0;
      for ( i = a2 + 190; *i != v16[v8]; i += 180 )
        ++v9;
      v11 = 180 * v9;
      v12 = a2[v11 + 84] == 0;
      v13 = (int)&a2[v11 + 20];
      if ( !v12 )
        break;
      if ( *(_DWORD *)(v13 + 260) == 1 )
        break;
      v17 = v8--;
    }
    while ( v8 >= 0 );
  }
  v14 = 0;
  if ( a2[14] )
  {
    v15 = a2 + 84;
    do
    {
      if ( v15[106] < v17 && !*v15 && v15[1] != 1 )
        *v15 = 13;
      ++v14;
      v15 += 180;
    }
    while ( v14 < a2[14] );
  }
}
