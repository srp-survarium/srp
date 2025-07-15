void __usercall CRYPTO_free_ex_data(int a1@<edi>, int a2@<ebx>)
{
  if ( !impl )
  {
    CRYPTO_lock(a1, a2, 9, 2, ".\\crypto\\ex_data.c", 203);
    if ( !impl )
      impl = &impl_default;
    CRYPTO_lock(a1, a2, 10, 2, ".\\crypto\\ex_data.c", 206);
  }
  ((void (*)(void))impl->cb_free_ex_data)();
}
