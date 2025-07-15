asn1_object_st *__cdecl OBJ_nid2obj(unsigned int n)
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
        return (asn1_object_st *)v2[1];
      ERR_put_error(8u, 103, 101, ".\\crypto\\objects\\obj_dat.c", 315);
    }
  }
  else
  {
    if ( !n || nid_objs[n].nid )
      return (asn1_object_st *)&nid_objs[n];
    ERR_put_error(8u, 103, 101, ".\\crypto\\objects\\obj_dat.c", 298);
  }
  return 0;
}
