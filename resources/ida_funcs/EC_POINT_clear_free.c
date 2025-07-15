void __cdecl EC_POINT_clear_free(ec_point_st *point)
{
  void (__cdecl *point_clear_finish)(ec_point_st *); // ecx
  void (__cdecl *point_finish)(ec_point_st *); // eax

  if ( point )
  {
    point_clear_finish = point->meth->point_clear_finish;
    if ( point_clear_finish )
    {
      point_clear_finish(point);
    }
    else
    {
      point_finish = point->meth->point_finish;
      if ( point_finish )
        point_finish(point);
    }
    OPENSSL_cleanse(point, 68);
    CRYPTO_free((void *)point);
  }
}
