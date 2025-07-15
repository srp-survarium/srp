BOOL __usercall CRYPTO_is_mem_check_on@<eax>(int a1@<edi>, int a2@<ebx>)
{
  BOOL result; // eax
  BOOL v3; // esi
  crypto_threadid_st id; // [esp+0h] [ebp-8h] BYREF

  result = 0;
  if ( (mh_mode & 1) != 0 )
  {
    CRYPTO_THREADID_current(&id);
    CRYPTO_lock(a1, a2, 5, 20, ".\\crypto\\mem_dbg.c", 294);
    v3 = (mh_mode & 2) != 0 || CRYPTO_THREADID_cmp(&disabling_threadid, &id);
    CRYPTO_lock(a1, a2, 6, 20, ".\\crypto\\mem_dbg.c", 299);
    return v3;
  }
  return result;
}
