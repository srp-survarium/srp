int __cdecl BIO_set(bio_st *bio, bio_method_st *method)
{
  int (__cdecl *create)(bio_st *); // eax

  bio->method = method;
  bio->callback = 0;
  bio->cb_arg = 0;
  bio->init = 0;
  bio->shutdown = 1;
  bio->flags = 0;
  bio->retry_reason = 0;
  bio->num = 0;
  bio->ptr = 0;
  bio->prev_bio = 0;
  bio->next_bio = 0;
  bio->references = 1;
  bio->num_read = 0;
  bio->num_write = 0;
  CRYPTO_new_ex_data(0);
  create = method->create;
  if ( !create || create(bio) )
    return 1;
  CRYPTO_free_ex_data(0);
  return 0;
}
