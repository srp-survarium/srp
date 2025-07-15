char *__cdecl DSO_convert_filename(dso_st *dso, char *filename)
{
  char *v3; // edi
  char *(__cdecl *name_converter)(dso_st *, const char *); // ecx
  char *v5; // esi

  if ( !dso )
  {
    ERR_put_error(0x25u, 126, 67, ".\\crypto\\dso\\dso_lib.c", 419);
    return 0;
  }
  v3 = filename;
  if ( !filename )
  {
    v3 = dso->filename;
    if ( !v3 )
    {
      ERR_put_error(0x25u, 126, 111, ".\\crypto\\dso\\dso_lib.c", 426);
      return 0;
    }
  }
  if ( (dso->flags & 1) != 0
    || (name_converter = dso->name_converter) == 0 && (name_converter = dso->meth->dso_name_converter) == 0
    || (v5 = name_converter(dso, v3)) == 0 )
  {
    v5 = (char *)CRYPTO_malloc(strlen(v3) + 1, ".\\crypto\\dso\\dso_lib.c", 438);
    if ( !v5 )
    {
      ERR_put_error(0x25u, 126, 65, ".\\crypto\\dso\\dso_lib.c", 442);
      return 0;
    }
    BUF_strlcpy(v5, v3, strlen(v3) + 1);
  }
  return v5;
}
