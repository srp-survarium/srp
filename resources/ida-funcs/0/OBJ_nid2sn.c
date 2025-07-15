const char *__cdecl OBJ_nid2sn(unsigned int n)
{
  void **v2; // eax
  _DWORD data[2]; // [esp+0h] [ebp-20h] BYREF
  char v4; // [esp+8h] [ebp-18h] BYREF
  unsigned int v5; // [esp+10h] [ebp-10h]

  if ( n > 0x37C )
  {
    if ( added )
    {
      v5 = n;
      data[0] = 3;
      data[1] = &v4;
      v2 = lh_retrieve((lhash_st *)added, data);
      if ( v2 )
        return *(const char **)v2[1];
      ERR_put_error(8u, 104, 101, ".\\crypto\\objects\\obj_dat.c", 347);
    }
  }
  else
  {
    if ( !n || nid_objs[n].nid )
      return nid_objs[n].sn;
    ERR_put_error(8u, 104, 101, ".\\crypto\\objects\\obj_dat.c", 330);
  }
  return 0;
}
