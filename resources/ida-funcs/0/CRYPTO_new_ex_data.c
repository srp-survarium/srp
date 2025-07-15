int __usercall CRYPTO_new_ex_data@<eax>(int a1@<edi>, int a2@<ebx>)
{
  if ( !impl )
  {
    CRYPTO_lock(a1, a2, 9, 2, ".\\crypto\\ex_data.c", 203);
    if ( !impl )
      impl = &impl_default;
    CRYPTO_lock(a1, a2, 10, 2, ".\\crypto\\ex_data.c", 206);
  }
  return ((int (*)(void))impl->cb_new_ex_data)();
}
