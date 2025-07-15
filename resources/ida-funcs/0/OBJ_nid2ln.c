const char *__usercall OBJ_nid2ln@<eax>(int a1@<ebx>, unsigned int n)
{
  void ***v3; // eax
  _DWORD v4[2]; // [esp+0h] [ebp-20h] BYREF
  char v5; // [esp+8h] [ebp-18h] BYREF
  unsigned int v6; // [esp+10h] [ebp-10h]

  if ( n > 0x37C )
  {
    if ( added )
    {
      v6 = n;
      v4[0] = 3;
      v4[1] = &v5;
      v3 = lh_retrieve((lhash_st *)added, v4);
      if ( v3 )
        return (const char *)v3[1][1];
      ERR_put_error(a1, 8u, 102, 101, ".\\crypto\\objects\\obj_dat.c", 379);
    }
  }
  else
  {
    if ( !n || nid_objs[n].nid )
      return nid_objs[n].ln;
    ERR_put_error(a1, 8u, 102, 101, ".\\crypto\\objects\\obj_dat.c", 362);
  }
  return 0;
}
