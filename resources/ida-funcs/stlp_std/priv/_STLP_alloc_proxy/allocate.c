_STLP_atomic_freelist::item *__userpurge stlp_std::priv::_STLP_alloc_proxy<unsigned char *,unsigned char,stlp_std::allocator<unsigned char>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int a2@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<unsigned char *,unsigned char,stlp_std::allocator<unsigned char> > *this,
        unsigned int *__allocated_n)
{
  _STLP_atomic_freelist::item *result; // eax
  unsigned int v5; // [esp+0h] [ebp-4h] BYREF

  v5 = a2;
  if ( !__n )
    return 0;
  v5 = __n;
  result = stlp_std::__node_alloc::allocate(&v5);
  this->_M_data = (unsigned __int8 *)v5;
  return result;
}


unsigned int *__userpurge stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::vectora_allocator<unsigned int>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int *__allocated_n@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::vectora_allocator<unsigned int> > *this)
{
  int *v3; // esi
  char *v4; // eax
  unsigned int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  *__allocated_n = __n;
  v6 = __n;
  v7 = 1;
  v3 = &v7;
  if ( __n )
    v3 = (int *)&v6;
  v4 = type_info::raw_name(&unsigned int `RTTI Type Descriptor');
  return (unsigned int *)((int (__stdcall *)(_DWORD, int, char *, const char *, const char *, int))this->m_allocator->call_realloc)(
                           0,
                           4 * *v3,
                           v4,
                           "vostok::detail::std_allocator<unsigned int>::allocate",
                           "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                           55);
}


void **__userpurge stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int *__allocated_n@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *this)
{
  int *v3; // esi
  char *v4; // eax
  unsigned int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  *__allocated_n = __n;
  v6 = __n;
  v7 = 1;
  v3 = &v7;
  if ( __n )
    v3 = (int *)&v6;
  v4 = type_info::raw_name(&void * `RTTI Type Descriptor');
  return (void **)((int (__stdcall *)(_DWORD, int, char *, const char *, const char *, int))this->m_allocator->call_realloc)(
                    0,
                    4 * *v3,
                    v4,
                    "vostok::detail::std_allocator<void *>::allocate",
                    "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                    55);
}


const void **__usercall stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,survarium::std_allocator<void const *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int *__allocated_n@<ecx>)
{
  int *v2; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h] BYREF

  *__allocated_n = __n;
  v8 = __n;
  v9 = 1;
  v2 = &v9;
  if ( __n )
    v2 = (int *)&v8;
  v3 = type_info::raw_name(&void const * `RTTI Type Descriptor');
  return (const void **)vostok::memory::doug_lea_allocator::realloc_impl(
                          v4,
                          (int)survarium::g_allocator,
                          0,
                          4 * *v2,
                          v3,
                          v6,
                          v7,
                          v8);
}


const void **__userpurge stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int *__allocated_n@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *> > *this)
{
  int *v3; // esi
  char *v4; // eax
  unsigned int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  *__allocated_n = __n;
  v6 = __n;
  v7 = 1;
  v3 = &v7;
  if ( __n )
    v3 = (int *)&v6;
  v4 = type_info::raw_name(&void const * `RTTI Type Descriptor');
  return (const void **)((int (__stdcall *)(_DWORD, int, char *, const char *, const char *, int))this->m_allocator->call_realloc)(
                          0,
                          4 * *v3,
                          v4,
                          "vostok::detail::std_allocator<void const *>::allocate",
                          "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                          55);
}


vostok::math::float3 *__userpurge stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,vostok::vectora_allocator<vostok::math::float3>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int *__allocated_n@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *this)
{
  int *v3; // esi
  char *v4; // eax
  unsigned int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  *__allocated_n = __n;
  v6 = __n;
  v7 = 1;
  v3 = &v7;
  if ( __n )
    v3 = (int *)&v6;
  v4 = type_info::raw_name(&vostok::math::float3 `RTTI Type Descriptor');
  return (vostok::math::float3 *)((int (__stdcall *)(_DWORD, int, char *, const char *, const char *, int))this->m_allocator->call_realloc)(
                                   0,
                                   12 * *v3,
                                   v4,
                                   "vostok::detail::std_allocator<class vostok::math::float3>::allocate",
                                   "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                                   55);
}
