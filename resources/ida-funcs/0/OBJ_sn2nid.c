void *__cdecl OBJ_sn2nid(const char *s)
{
  void ***v1; // eax
  int v3; // ecx
  int v4; // ebp
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  _DWORD v8[2]; // [esp+0h] [ebp-20h] BYREF
  const char *v9; // [esp+8h] [ebp-18h] BYREF
  int v10; // [esp+24h] [ebp+4h]

  v9 = s;
  if ( added )
  {
    v8[0] = 1;
    v8[1] = &v9;
    v1 = lh_retrieve((lhash_st *)added, v8);
    if ( v1 )
      return v1[1][2];
  }
  v3 = 886;
  v4 = 0;
  v10 = 886;
  do
  {
    v5 = (v3 + v4) / 2;
    v6 = &sn_objs[v5];
    v7 = strcmp(v9, nid_objs[*v6].sn);
    if ( v7 >= 0 )
    {
      if ( v7 <= 0 )
        break;
      v4 = v5 + 1;
    }
    else
    {
      v10 = v5;
    }
    v3 = v10;
  }
  while ( v4 < v10 );
  if ( !v7 && v6 )
    return (void *)nid_objs[*v6].nid;
  else
    return 0;
}
