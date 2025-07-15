void __usercall CRYPTO_free_ex_data(unsigned int a1@<edi>)
{
  if ( !impl )
  {
    CRYPTO_lock(a1, 9, 2, ".\\crypto\\ex_data.c", 203);
    if ( !impl )
      impl = &impl_default;
    CRYPTO_lock(a1, 10, 2, ".\\crypto\\ex_data.c", 206);
  }
  ((void (*)(void))impl->cb_free_ex_data)();
}
