char *__usercall DSO_convert_filename@<eax>(int a1@<ebx>, dso_st *dso, char *filename)
{
  char *v4; // edi
  char *(__cdecl *name_converter)(dso_st *, const char *); // ecx
  char *v6; // esi

  if ( !dso )
  {
    ERR_put_error(a1, 0x25u, 126, 67, ".\\crypto\\dso\\dso_lib.c", 419);
    return 0;
  }
  v4 = filename;
  if ( !filename )
  {
    v4 = dso->filename;
    if ( !v4 )
    {
      ERR_put_error(a1, 0x25u, 126, 111, ".\\crypto\\dso\\dso_lib.c", 426);
      return 0;
    }
  }
  if ( (dso->flags & 1) != 0
    || (name_converter = dso->name_converter) == 0 && (name_converter = dso->meth->dso_name_converter) == 0
    || (v6 = name_converter(dso, v4)) == 0 )
  {
    v6 = (char *)CRYPTO_malloc(strlen(v4) + 1, ".\\crypto\\dso\\dso_lib.c", 438);
    if ( !v6 )
    {
      ERR_put_error(a1, 0x25u, 126, 65, ".\\crypto\\dso\\dso_lib.c", 442);
      return 0;
    }
    BUF_strlcpy(v6, v4, strlen(v4) + 1);
  }
  return v6;
}
