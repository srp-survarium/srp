int __usercall CRYPTO_cleanup_all_ex_data@<eax>(unsigned int a1@<edi>)
{
  if ( !impl )
  {
    CRYPTO_lock(a1, 9, 2, ".\\crypto\\ex_data.c", 203);
    if ( !impl )
      impl = &impl_default;
    CRYPTO_lock(a1, 10, 2, ".\\crypto\\ex_data.c", 206);
  }
  return ((int (*)(void))impl->cb_cleanup)();
}
