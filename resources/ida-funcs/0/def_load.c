int __usercall def_load@<eax>(int a1@<ebx>, conf_st *conf, char *name, int *line)
{
  bio_st *v4; // eax
  bio_st *v5; // esi
  int bio; // edi

  v4 = BIO_new_file(name, "rb");
  v5 = v4;
  if ( v4 )
  {
    bio = def_load_bio(conf, v4, line);
    BIO_free(bio, a1, v5);
    return bio;
  }
  else
  {
    if ( (ERR_peek_last_error() & 0xFFF) == 0x80 )
      ERR_put_error(a1, 0xEu, 120, 114, ".\\crypto\\conf\\conf_def.c", 197);
    else
      ERR_put_error(a1, 0xEu, 120, 2, ".\\crypto\\conf\\conf_def.c", 199);
    return 0;
  }
}
