unsigned int __cdecl def_load(conf_st *conf, const char *name, int *line)
{
  bio_st *v3; // eax
  bio_st *v4; // esi
  unsigned int bio; // edi

  v3 = BIO_new_file(name, "rb");
  v4 = v3;
  if ( v3 )
  {
    bio = def_load_bio(conf, v3, line);
    BIO_free(bio, v4);
    return bio;
  }
  else
  {
    if ( (ERR_peek_last_error() & 0xFFF) == 0x80 )
      ERR_put_error(0xEu, 120, 114, ".\\crypto\\conf\\conf_def.c", 197);
    else
      ERR_put_error(0xEu, 120, 2, ".\\crypto\\conf\\conf_def.c", 199);
    return 0;
  }
}
