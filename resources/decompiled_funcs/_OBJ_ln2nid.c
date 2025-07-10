int __cdecl OBJ_ln2nid(const char *s)
{
  void **v1; // eax
  int v3; // ecx
  int v4; // ebp
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  _DWORD data[2]; // [esp+0h] [ebp-20h] BYREF
  char v9; // [esp+8h] [ebp-18h] BYREF
  const char *v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+24h] [ebp+4h]

  v10 = s;
  if ( added )
  {
    data[0] = 2;
    data[1] = &v9;
    v1 = lh_retrieve((lhash_st *)added, data);
    if ( v1 )
      return *((_DWORD *)v1[1] + 2);
  }
  v3 = 886;
  v4 = 0;
  v11 = 886;
  do
  {
    v5 = (v3 + v4) / 2;
    v6 = &ln_objs[v5];
    v7 = strcmp(v10, nid_objs[*v6].ln);
    if ( v7 >= 0 )
    {
      if ( v7 <= 0 )
        break;
      v4 = v5 + 1;
    }
    else
    {
      v11 = v5;
    }
    v3 = v11;
  }
  while ( v4 < v11 );
  if ( !v7 && v6 )
    return nid_objs[*v6].nid;
  else
    return 0;
}
