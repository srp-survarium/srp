void __cdecl EC_POINT_free(ec_point_st *point)
{
  void (__cdecl *point_finish)(ec_point_st *); // eax

  if ( point )
  {
    point_finish = point->meth->point_finish;
    if ( point_finish )
      point_finish(point);
    CRYPTO_free((void *)point);
  }
}
