void **__cdecl OBJ_NAME_get(const char *name, int type)
{
  int v2; // ebx
  void ***v4; // eax
  _DWORD v5[2]; // [esp+8h] [ebp-10h] BYREF
  const char *v6; // [esp+10h] [ebp-8h]

  v2 = 0;
  if ( !name || !names_lh && !OBJ_NAME_init((int)name, 0) )
    return 0;
  v5[0] = type & 0xFFFF7FFF;
  v6 = name;
  v4 = lh_retrieve((lhash_st *)names_lh, v5);
  if ( !v4 )
    return 0;
  while ( v4[1] && (type & 0x8000) == 0 )
  {
    if ( ++v2 <= 10 )
    {
      v6 = (const char *)v4[3];
      v4 = lh_retrieve((lhash_st *)names_lh, v5);
      if ( v4 )
        continue;
    }
    return 0;
  }
  return v4[3];
}
