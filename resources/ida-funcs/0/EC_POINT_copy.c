int __usercall EC_POINT_copy@<eax>(int a1@<ebx>, ec_point_st *dest, const ec_point_st *src)
{
  int (__cdecl *point_copy)(ec_point_st *, const ec_point_st *); // esi

  point_copy = dest->meth->point_copy;
  if ( point_copy )
  {
    if ( dest->meth == src->meth )
    {
      if ( dest == src )
        return 1;
      else
        return point_copy(dest, src);
    }
    else
    {
      ERR_put_error(a1, 0x10u, 114, 101, ".\\crypto\\ec\\ec_lib.c", 759);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x10u, 114, 66, ".\\crypto\\ec\\ec_lib.c", 754);
    return 0;
  }
}
