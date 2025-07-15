void __userpurge stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this@<ecx>,
        int a2@<esi>,
        char *__pos,
        const char *__x,
        unsigned int __formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // ecx
  unsigned int *p_allocated_n; // eax
  unsigned int v9; // eax
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // eax
  int v12; // ecx
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned int v15; // eax
  unsigned int __allocated_n; // [esp+8h] [ebp-8h] BYREF
  unsigned int v17; // [esp+Ch] [ebp-4h] BYREF

  v7 = *(_DWORD *)(a2 + 4) - *(_DWORD *)a2;
  v17 = __formal;
  __allocated_n = v7;
  if ( __formal > -1 - v7 )
    stlp_std::__stl_throw_length_error("vector");
  p_allocated_n = &__allocated_n;
  if ( __formal >= v7 )
    p_allocated_n = &v17;
  v9 = v7 + *p_allocated_n;
  if ( v9 < v7 )
    v9 = -1;
  __allocated_n = v9;
  v10 = (unsigned __int8 *)stlp_std::allocator<char>::_M_allocate(
                             (stlp_std::allocator<char> *)(a2 + 8),
                             v9,
                             &__allocated_n);
  v11 = stlp_std::priv::__copy_trivial(*(unsigned __int8 **)a2, (unsigned __int8 *)__pos, v10);
  v12 = *(unsigned __int8 *)__x;
  v17 = (unsigned int)v11;
  memset((int)v11, v12, __formal);
  v13 = stlp_std::priv::__copy_trivial(
          (unsigned __int8 *)__pos,
          *(unsigned __int8 **)(a2 + 4),
          (unsigned __int8 *)(__formal + v17));
  v14 = *(_DWORD *)(a2 + 8);
  v17 = (unsigned int)v13;
  stlp_std::allocator<char>::deallocate(
    (stlp_std::allocator<char> *)(a2 + 8),
    *(_STLP_atomic_freelist::item **)a2,
    v14 - *(_DWORD *)a2);
  *(_DWORD *)(a2 + 4) = v17;
  v15 = __allocated_n;
  *(_DWORD *)a2 = v10;
  *(_DWORD *)(a2 + 8) = &v10[v15];
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        unsigned __int8 *__pos,
        unsigned __int8 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // eax
  int *v8; // ecx
  unsigned int v9; // ecx
  int *v10; // edi
  char *v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // eax
  unsigned int v15; // [esp+8h] [ebp-Ch] BYREF
  int v16; // [esp+Ch] [ebp-8h] BYREF
  int v17; // [esp+10h] [ebp-4h] BYREF
  unsigned __int8 *v18; // [esp+1Ch] [ebp+8h]

  v7 = a2[1] - *a2;
  v16 = 1;
  v17 = v7;
  if ( v7 == -1 )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v17;
  if ( v7 <= 1 )
    v8 = &v16;
  v9 = v7 + *v8;
  v17 = v9;
  if ( v9 < v7 )
  {
    v17 = -1;
    v9 = -1;
  }
  v15 = v9;
  v16 = 1;
  v10 = &v16;
  if ( v9 )
    v10 = (int *)&v15;
  v11 = type_info::raw_name(&unsigned char `RTTI Type Descriptor');
  v12 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int, char *, const char *, const char *, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             *v10,
                             v11,
                             "vostok::detail::std_allocator<unsigned char>::allocate",
                             "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                             55);
  v13 = stlp_std::priv::__copy_trivial(*a2, __pos, v12);
  v18 = v13 + 1;
  *v13 = *__x;
  (*(void (__thiscall **)(unsigned __int8 *, _DWORD, const char *, const char *, int))(*(_DWORD *)a2[2] + 24))(
    a2[2],
    *a2,
    "vostok::detail::std_allocator<unsigned char>::deallocate",
    "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
    102);
  a2[1] = v18;
  v14 = &v12[v17];
  *a2 = v12;
  a2[3] = v14;
}


void __userpurge stlp_std::priv::_Impl_vector<int,survarium::std_allocator<int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<int,survarium::std_allocator<int> > *this@<ecx>,
        int a2@<edi>,
        unsigned __int8 *__pos,
        vostok::memory::doug_lea_allocator **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // eax
  unsigned int *v8; // esi
  unsigned int v9; // ebx
  unsigned int *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  unsigned __int8 *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  vostok::memory::doug_lea_allocator *v15; // esi
  unsigned int v16; // eax
  const char *v17; // [esp+0h] [ebp-10h]
  const char *v18; // [esp+0h] [ebp-10h]
  const char *v19; // [esp+4h] [ebp-Ch]
  const char *v20; // [esp+4h] [ebp-Ch]
  unsigned int v21; // [esp+8h] [ebp-8h] BYREF
  unsigned int v22; // [esp+Ch] [ebp-4h] BYREF
  unsigned __int8 *v23; // [esp+18h] [ebp+8h]

  v7 = (*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) >> 2;
  v21 = 1;
  v22 = v7;
  if ( v7 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v22;
  if ( v7 <= 1 )
    v8 = &v21;
  v9 = v7 + *v8;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
    v9 = 0x3FFFFFFF;
  v22 = v9;
  v21 = 1;
  v10 = &v21;
  if ( v9 )
    v10 = &v22;
  v11 = type_info::raw_name(&int `RTTI Type Descriptor');
  v21 = (unsigned int)vostok::memory::doug_lea_allocator::realloc_impl(
                        v12,
                        (int)survarium::g_allocator,
                        0,
                        4 * *v10,
                        v11,
                        v17,
                        v19,
                        v21);
  v13 = stlp_std::priv::__copy_trivial(*(unsigned __int8 **)a2, __pos, (unsigned __int8 *)v21);
  v14 = *__x;
  v15 = survarium::g_allocator;
  *(_DWORD *)v13 = *__x;
  v23 = v13 + 4;
  vostok::memory::doug_lea_allocator::free_impl(v14, (int)v15, *(char **)a2, v18, v20, v21);
  v16 = v21;
  *(_DWORD *)a2 = v21;
  *(_DWORD *)(a2 + 4) = v23;
  *(_DWORD *)(a2 + 8) = v16 + 4 * v9;
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *this@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::vectora_allocator<unsigned int> > *a2@<esi>,
        unsigned __int8 *__pos,
        const unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // ecx
  int *v8; // eax
  unsigned int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // eax
  unsigned int *v12; // ebx
  unsigned int *v13; // eax
  int v14; // [esp+8h] [ebp-8h] BYREF
  unsigned int v15; // [esp+Ch] [ebp-4h] BYREF

  v7 = ((char *)a2->_M_data - (char *)a2->m_allocator) >> 2;
  v14 = 1;
  v15 = v7;
  if ( v7 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  v8 = (int *)&v15;
  if ( v7 <= 1 )
    v8 = &v14;
  v9 = v7 + *v8;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
    v9 = 0x3FFFFFFF;
  v15 = v9;
  v10 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::vectora_allocator<unsigned int>>::allocate(
                             v9,
                             &v15,
                             a2 + 1);
  v11 = stlp_std::priv::__copy_trivial((unsigned __int8 *)a2->m_allocator, __pos, v10);
  *(_DWORD *)v11 = *__x;
  v12 = (unsigned int *)(v11 + 4);
  a2[1].m_allocator->call_free(
    a2[1].m_allocator,
    a2->m_allocator,
    "vostok::detail::std_allocator<unsigned int>::deallocate",
    "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
    102u);
  v13 = (unsigned int *)&v10[4 * v15];
  a2->m_allocator = (vostok::memory::base_allocator *)v10;
  a2->_M_data = v12;
  a2[1]._M_data = v13;
}


void __userpurge stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        float *__pos,
        const float *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // eax
  int *v8; // ecx
  unsigned int v9; // ecx
  int *v10; // ebx
  char *v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // eax
  double v14; // st7
  unsigned __int8 *v15; // eax
  unsigned int v16; // [esp+8h] [ebp-Ch] BYREF
  int v17; // [esp+Ch] [ebp-8h] BYREF
  int v18; // [esp+10h] [ebp-4h] BYREF
  unsigned __int8 *v19; // [esp+24h] [ebp+10h]

  v7 = (a2[1] - *a2) >> 2;
  v18 = (int)__formal;
  v17 = v7;
  if ( (unsigned int)__formal > 0x3FFFFFFF - v7 )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v17;
  if ( (unsigned int)__formal >= v7 )
    v8 = &v18;
  v9 = v7 + *v8;
  v17 = v9;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
  {
    v17 = 0x3FFFFFFF;
    v9 = 0x3FFFFFFF;
  }
  v16 = v9;
  v18 = 1;
  v10 = &v18;
  if ( v9 )
    v10 = (int *)&v16;
  v11 = type_info::raw_name(&float `RTTI Type Descriptor');
  v12 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int, char *, const char *, const char *, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             4 * *v10,
                             v11,
                             "vostok::detail::std_allocator<float>::allocate",
                             "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                             55);
  v18 = (int)__formal;
  v13 = stlp_std::priv::__copy_trivial(*a2, (unsigned __int8 *)__pos, v12);
  if ( __formal )
  {
    do
    {
      v14 = *__x;
      --v18;
      *(float *)v13 = v14;
      v13 += 4;
    }
    while ( v18 );
  }
  v19 = stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos, a2[1], v13);
  (*(void (__thiscall **)(unsigned __int8 *, _DWORD, const char *, const char *, int))(*(_DWORD *)a2[2] + 24))(
    a2[2],
    *a2,
    "vostok::detail::std_allocator<float>::deallocate",
    "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
    102);
  a2[1] = v19;
  v15 = &v12[4 * v17];
  *a2 = v12;
  a2[3] = v15;
}


void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void **__pos,
        void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  stlp_std::allocator<void *> *p_M_end_of_storage; // edi
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned int __allocated_n; // [esp+Ch] [ebp-4h] BYREF
  unsigned __int8 *__n; // [esp+24h] [ebp+14h]

  p_M_end_of_storage = &this->_M_end_of_storage;
  __allocated_n = stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_compute_next_size(
                    this,
                    __fill_len);
  v8 = (unsigned __int8 *)stlp_std::allocator<void *>::_M_allocate(p_M_end_of_storage, __allocated_n, &__allocated_n);
  v9 = stlp_std::priv::__copy_trivial((unsigned __int8 *)this->_M_start, (unsigned __int8 *)__pos, v8);
  v10 = (unsigned __int8 *)stlp_std::priv::__fill_n<void * *,unsigned int,void *>((void **)v9, __fill_len, __x);
  __n = v10;
  if ( !__atend )
    __n = stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos, (unsigned __int8 *)this->_M_finish, v10);
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(this);
  this->_M_finish = (void **)__n;
  *(_DWORD *)&p_M_end_of_storage->stlp_std::__stlport_class<stlp_std::allocator<void *> > = &v8[4 * __allocated_n];
  this->_M_start = (void **)v8;
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        void **__pos,
        void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // eax
  int *v8; // ecx
  unsigned int v9; // ecx
  int *v10; // ebx
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  unsigned __int8 *v13; // ebx
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // eax
  vostok::memory::doug_lea_allocator *v16; // ecx
  unsigned __int8 *v17; // eax
  const char *v18; // [esp+0h] [ebp-14h]
  const char *v19; // [esp+0h] [ebp-14h]
  const char *v20; // [esp+4h] [ebp-10h]
  const char *v21; // [esp+4h] [ebp-10h]
  unsigned int v22; // [esp+8h] [ebp-Ch] BYREF
  int v23; // [esp+Ch] [ebp-8h] BYREF
  int v24; // [esp+10h] [ebp-4h] BYREF
  unsigned __int8 *v25; // [esp+1Ch] [ebp+8h]

  v7 = (*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) >> 2;
  v23 = 1;
  v24 = v7;
  if ( v7 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v24;
  if ( v7 <= 1 )
    v8 = &v23;
  v9 = v7 + *v8;
  v24 = v9;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
  {
    v24 = 0x3FFFFFFF;
    v9 = 0x3FFFFFFF;
  }
  v22 = v9;
  v23 = 1;
  v10 = &v23;
  if ( v9 )
    v10 = (int *)&v22;
  v11 = type_info::raw_name(&void * `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::realloc_impl(
          v12,
          (int)vostok::input::g_allocator,
          0,
          4 * *v10,
          v11,
          v18,
          v20,
          v22);
  v14 = stlp_std::priv::__copy_trivial(*(unsigned __int8 **)a2, (unsigned __int8 *)__pos, v13);
  v15 = (unsigned __int8 *)stlp_std::priv::__fill_n<void * *,unsigned int,void *>((void **)v14, 1u, __x);
  v25 = stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos, *(unsigned __int8 **)(a2 + 4), v15);
  vostok::memory::doug_lea_allocator::free_impl(v16, (int)vostok::input::g_allocator, *(char **)a2, v19, v21, v22);
  *(_DWORD *)(a2 + 4) = v25;
  v17 = &v13[4 * v24];
  *(_DWORD *)a2 = v13;
  *(_DWORD *)(a2 + 8) = v17;
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        void **__pos,
        void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // eax
  int *v8; // ecx
  unsigned int v9; // ecx
  int *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  unsigned __int8 *v13; // ebx
  unsigned __int8 *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // ecx
  unsigned __int8 *v16; // eax
  const char *v17; // [esp+0h] [ebp-18h]
  const char *v18; // [esp+0h] [ebp-18h]
  const char *v19; // [esp+4h] [ebp-14h]
  const char *v20; // [esp+4h] [ebp-14h]
  unsigned int v21; // [esp+8h] [ebp-10h]
  unsigned int v22; // [esp+8h] [ebp-10h]
  unsigned int v23; // [esp+Ch] [ebp-Ch] BYREF
  int v24; // [esp+10h] [ebp-8h] BYREF
  int v25; // [esp+14h] [ebp-4h] BYREF
  void **v26; // [esp+20h] [ebp+8h]

  v7 = (*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) >> 2;
  v24 = 1;
  v25 = v7;
  if ( v7 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v25;
  if ( v7 <= 1 )
    v8 = &v24;
  v9 = v7 + *v8;
  v25 = v9;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
  {
    v25 = 0x3FFFFFFF;
    v9 = 0x3FFFFFFF;
  }
  v24 = 1;
  v23 = v9;
  v10 = &v24;
  if ( v9 )
    v10 = (int *)&v23;
  v11 = type_info::raw_name(&void * `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::realloc_impl(
          v12,
          (int)&vostok::memory::g_resources_helper_allocator,
          0,
          4 * *v10,
          v11,
          v17,
          v19,
          v21);
  v14 = stlp_std::priv::__copy_trivial(*(unsigned __int8 **)a2, (unsigned __int8 *)__pos, v13);
  v26 = stlp_std::priv::__fill_n<void * *,unsigned int,void *>((void **)v14, 1u, __x);
  vostok::memory::doug_lea_allocator::free_impl(
    v15,
    (int)&vostok::memory::g_resources_helper_allocator,
    *(char **)a2,
    v18,
    v20,
    v22);
  *(_DWORD *)(a2 + 4) = v26;
  v16 = &v13[4 * v25];
  *(_DWORD *)a2 = v13;
  *(_DWORD *)(a2 + 8) = v16;
}


void __userpurge stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        void **__pos,
        void **__x,
        const stlp_std::__true_type *__formal,
        char __fill_len,
        bool __atend)
{
  unsigned int v7; // eax
  unsigned int *v8; // edx
  unsigned int v9; // ebx
  unsigned int *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // ecx
  unsigned int v16; // eax
  const char *v17; // [esp+0h] [ebp-10h]
  const char *v18; // [esp+0h] [ebp-10h]
  const char *v19; // [esp+4h] [ebp-Ch]
  const char *v20; // [esp+4h] [ebp-Ch]
  unsigned int v21; // [esp+8h] [ebp-8h] BYREF
  unsigned int v22; // [esp+Ch] [ebp-4h] BYREF
  unsigned __int8 *v23; // [esp+20h] [ebp+10h]

  v7 = (*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) >> 2;
  v21 = (unsigned int)__formal;
  v22 = v7;
  if ( (unsigned int)__formal > 0x3FFFFFFF - v7 )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v22;
  if ( (unsigned int)__formal >= v7 )
    v8 = &v21;
  v9 = v7 + *v8;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
    v9 = 0x3FFFFFFF;
  v22 = v9;
  v21 = 1;
  v10 = &v21;
  if ( v9 )
    v10 = &v22;
  v11 = type_info::raw_name(&void * `RTTI Type Descriptor');
  v21 = (unsigned int)vostok::memory::doug_lea_allocator::realloc_impl(
                        v12,
                        (int)survarium::g_allocator,
                        0,
                        4 * *v10,
                        v11,
                        v17,
                        v19,
                        v21);
  v13 = stlp_std::priv::__copy_trivial(*(unsigned __int8 **)a2, (unsigned __int8 *)__pos, (unsigned __int8 *)v21);
  v14 = (unsigned __int8 *)stlp_std::priv::__fill_n<void * *,unsigned int,void *>(
                             (void **)v13,
                             (unsigned int)__formal,
                             __x);
  v23 = v14;
  if ( !__fill_len )
    v23 = stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos, *(unsigned __int8 **)(a2 + 4), v14);
  vostok::memory::doug_lea_allocator::free_impl(v15, (int)survarium::g_allocator, *(char **)a2, v18, v20, v21);
  v16 = v21;
  *(_DWORD *)a2 = v21;
  *(_DWORD *)(a2 + 4) = v23;
  *(_DWORD *)(a2 + 8) = v16 + 4 * v9;
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *a2@<esi>,
        void **__pos,
        void **__x,
        const stlp_std::__true_type *__formal,
        char __fill_len,
        bool __atend)
{
  unsigned int v7; // ecx
  unsigned int *p_allocated_n; // eax
  unsigned int v9; // eax
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // eax
  void **v13; // eax
  const stlp_std::__true_type *v14; // [esp+8h] [ebp-8h] BYREF
  unsigned int __allocated_n; // [esp+Ch] [ebp-4h] BYREF
  unsigned __int8 *__n; // [esp+20h] [ebp+10h]

  v7 = ((char *)a2->_M_data - (char *)a2->m_allocator) >> 2;
  v14 = __formal;
  __allocated_n = v7;
  if ( (unsigned int)__formal > 0x3FFFFFFF - v7 )
    stlp_std::__stl_throw_length_error("vector");
  p_allocated_n = &__allocated_n;
  if ( (unsigned int)__formal >= v7 )
    p_allocated_n = (unsigned int *)&v14;
  v9 = v7 + *p_allocated_n;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
    v9 = 0x3FFFFFFF;
  __allocated_n = v9;
  v10 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *>>::allocate(
                             v9,
                             &__allocated_n,
                             a2 + 1);
  v11 = stlp_std::priv::__copy_trivial((unsigned __int8 *)a2->m_allocator, (unsigned __int8 *)__pos, v10);
  v12 = (unsigned __int8 *)stlp_std::priv::__fill_n<void * *,unsigned int,void *>(
                             (void **)v11,
                             (unsigned int)__formal,
                             __x);
  __n = v12;
  if ( !__fill_len )
    __n = stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos, (unsigned __int8 *)a2->_M_data, v12);
  a2[1].m_allocator->call_free(
    a2[1].m_allocator,
    a2->m_allocator,
    "vostok::detail::std_allocator<void *>::deallocate",
    "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
    102u);
  a2->_M_data = (void **)__n;
  v13 = (void **)&v10[4 * __allocated_n];
  a2->m_allocator = (vostok::memory::base_allocator *)v10;
  a2[1]._M_data = v13;
}


void __userpurge stlp_std::priv::_Impl_vector<void const *,survarium::std_allocator<void const *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void const *,survarium::std_allocator<void const *> > *this@<ecx>,
        int a2@<edi>,
        const void **__pos,
        vostok::memory::doug_lea_allocator **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // ecx
  unsigned int *v8; // eax
  unsigned int v9; // eax
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  vostok::memory::doug_lea_allocator *v13; // esi
  unsigned __int8 *v14; // eax
  const char *v15; // [esp+0h] [ebp-10h]
  const char *v16; // [esp+4h] [ebp-Ch]
  unsigned int v17; // [esp+8h] [ebp-8h] BYREF
  unsigned int v18; // [esp+Ch] [ebp-4h] BYREF
  unsigned __int8 *v19; // [esp+18h] [ebp+8h]

  v7 = (*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) >> 2;
  v17 = 1;
  v18 = v7;
  if ( v7 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v18;
  if ( v7 <= 1 )
    v8 = &v17;
  v9 = v7 + *v8;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
    v9 = 0x3FFFFFFF;
  v18 = v9;
  v10 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,survarium::std_allocator<void const *>>::allocate(
                             v9,
                             &v18);
  v11 = stlp_std::priv::__copy_trivial(*(unsigned __int8 **)a2, (unsigned __int8 *)__pos, v10);
  v12 = *__x;
  v13 = survarium::g_allocator;
  *(_DWORD *)v11 = *__x;
  v19 = v11 + 4;
  vostok::memory::doug_lea_allocator::free_impl(v12, (int)v13, *(char **)a2, v15, v16, v17);
  *(_DWORD *)(a2 + 4) = v19;
  v14 = &v10[4 * v18];
  *(_DWORD *)a2 = v10;
  *(_DWORD *)(a2 + 8) = v14;
}


void __userpurge stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *> > *a2@<esi>,
        const void **__pos,
        const void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // ecx
  unsigned int *p_allocated_n; // eax
  unsigned int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // eax
  const void **v12; // ebx
  const void **v13; // eax
  int v14; // [esp+8h] [ebp-8h] BYREF
  unsigned int __allocated_n; // [esp+Ch] [ebp-4h] BYREF

  v7 = ((char *)a2->_M_data - (char *)a2->m_allocator) >> 2;
  v14 = 1;
  __allocated_n = v7;
  if ( v7 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  p_allocated_n = &__allocated_n;
  if ( v7 <= 1 )
    p_allocated_n = (unsigned int *)&v14;
  v9 = v7 + *p_allocated_n;
  if ( v9 > 0x3FFFFFFF || v9 < v7 )
    v9 = 0x3FFFFFFF;
  __allocated_n = v9;
  v10 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *>>::allocate(
                             v9,
                             &__allocated_n,
                             a2 + 1);
  v11 = stlp_std::priv::__copy_trivial((unsigned __int8 *)a2->m_allocator, (unsigned __int8 *)__pos, v10);
  *(_DWORD *)v11 = *__x;
  v12 = (const void **)(v11 + 4);
  a2[1].m_allocator->call_free(
    a2[1].m_allocator,
    a2->m_allocator,
    "vostok::detail::std_allocator<void const *>::deallocate",
    "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
    102u);
  v13 = (const void **)&v10[4 * __allocated_n];
  a2->m_allocator = (vostok::memory::base_allocator *)v10;
  a2->_M_data = v12;
  a2[1]._M_data = v13;
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        vostok::ui::undo_ *__pos,
        const vostok::ui::undo_ *__x,
        const stlp_std::__true_type *__formal,
        char __fill_len,
        bool __atend)
{
  unsigned int v7; // eax
  int *v8; // ecx
  unsigned int v9; // ecx
  int *v10; // ebx
  char *v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // eax
  const char *text; // edx
  unsigned __int8 *v15; // eax
  unsigned int v16; // [esp+8h] [ebp-Ch] BYREF
  int v17; // [esp+Ch] [ebp-8h] BYREF
  int v18; // [esp+10h] [ebp-4h] BYREF
  unsigned __int8 *v19; // [esp+24h] [ebp+10h]

  v7 = (a2[1] - *a2) >> 3;
  v18 = (int)__formal;
  v17 = v7;
  if ( (unsigned int)__formal > 0x1FFFFFFF - v7 )
    stlp_std::__stl_throw_length_error("vector");
  v8 = &v17;
  if ( (unsigned int)__formal >= v7 )
    v8 = &v18;
  v9 = v7 + *v8;
  v17 = v9;
  if ( v9 > 0x1FFFFFFF || v9 < v7 )
  {
    v17 = 0x1FFFFFFF;
    v9 = 0x1FFFFFFF;
  }
  v16 = v9;
  v18 = 1;
  v10 = &v18;
  if ( v9 )
    v10 = (int *)&v16;
  v11 = type_info::raw_name(&vostok::ui::undo_ `RTTI Type Descriptor');
  v12 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int, char *, const char *, const char *, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             8 * *v10,
                             v11,
                             "vostok::detail::std_allocator<struct vostok::ui::undo_>::allocate",
                             "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                             55);
  v18 = (int)__formal;
  v13 = stlp_std::priv::__copy_trivial(*a2, (unsigned __int8 *)__pos, v12);
  if ( __formal )
  {
    do
    {
      text = __x->text;
      --v18;
      *(_DWORD *)v13 = text;
      *((_DWORD *)v13 + 1) = *(_DWORD *)&__x->caret;
      v13 += 8;
    }
    while ( v18 );
  }
  v19 = v13;
  if ( !__fill_len )
    v19 = stlp_std::priv::__copy_trivial((unsigned __int8 *)__pos, a2[1], v13);
  (*(void (__thiscall **)(unsigned __int8 *, _DWORD, const char *, const char *, int))(*(_DWORD *)a2[2] + 24))(
    a2[2],
    *a2,
    "vostok::detail::std_allocator<struct vostok::ui::undo_>::deallocate",
    "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
    102);
  a2[1] = v19;
  v15 = &v12[8 * v17];
  *a2 = v12;
  a2[3] = v15;
}
