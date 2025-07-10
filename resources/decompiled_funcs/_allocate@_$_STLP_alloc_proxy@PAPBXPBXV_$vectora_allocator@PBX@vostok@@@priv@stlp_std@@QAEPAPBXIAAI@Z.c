const void **__userpurge stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int *__allocated_n@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *> > *this)
{
  bool v3; // cf
  unsigned int *v4; // eax
  int v6; // [esp+0h] [ebp-8h] BYREF
  unsigned int v7; // [esp+4h] [ebp-4h] BYREF

  *__allocated_n = __n;
  v7 = __n;
  v3 = __n == 0;
  v6 = 1;
  v4 = (unsigned int *)&v6;
  if ( !v3 )
    v4 = &v7;
  return (const void **)((int (__stdcall *)(_DWORD, unsigned int))this->m_allocator->call_realloc)(0, 4 * *v4);
}
