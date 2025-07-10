app_mem_info_st *__cdecl pop_info()
{
  app_mem_info_st *result; // eax
  app_mem_info_st *v1; // esi
  app_mem_info_st *next; // edi
  lhash_st *v3; // eax
  crypto_threadid_st id; // [esp+0h] [ebp-1Ch] BYREF

  result = 0;
  if ( amih )
  {
    CRYPTO_THREADID_current(&id);
    result = (app_mem_info_st *)lh_delete((lhash_st *)amih, &id);
    v1 = result;
    if ( result )
    {
      next = result->next;
      if ( next )
      {
        v3 = (lhash_st *)amih;
        ++next->references;
        lh_insert(v3, next);
      }
      if ( --v1->references <= 0 )
      {
        v1->next = 0;
        if ( next )
          --next->references;
        CRYPTO_free(v1);
      }
      return v1;
    }
  }
  return result;
}
