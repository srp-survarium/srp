void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__pos,
        const char *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  char *v7; // [esp+4h] [ebp-88h]
  unsigned __int8 *__new_finisha; // [esp+80h] [ebp-Ch]
  unsigned __int8 *__new_finish; // [esp+80h] [ebp-Ch]
  char *__new_start; // [esp+84h] [ebp-8h]
  unsigned int __len; // [esp+88h] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_compute_next_size(this, __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  __new_finisha = stlp_std::priv::__copy_trivial(
                    (unsigned __int8 *)this->_M_start,
                    (unsigned __int8 *)__pos,
                    (unsigned __int8 *)__new_start);
  memset(__new_finisha, *__x, __fill_len);
  __new_finish = &__new_finisha[__fill_len];
  if ( !__atend )
    __new_finish = stlp_std::priv::__copy_trivial(
                     (unsigned __int8 *)__pos,
                     (unsigned __int8 *)this->_M_finish,
                     __new_finish);
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_clear(this);
  v7 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = (char *)__new_finish;
  this->_M_end_of_storage._M_data = v7;
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *this@<esi>,
        unsigned __int8 *__pos@<eax>,
        stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *a3@<ecx>,
        unsigned __int8 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int *v8; // eax
  unsigned __int8 *v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  unsigned __int8 *v12; // edi
  unsigned int v13; // ecx
  unsigned int v14; // [esp+0h] [ebp-18h]
  int v15; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  unsigned int size; // [esp+14h] [ebp-4h]

  size = stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_compute_next_size(
           a3,
           v14);
  v16 = size;
  v15 = 1;
  v8 = (unsigned int *)&v15;
  if ( size )
    v8 = &v16;
  v9 = (unsigned __int8 *)this->_M_end_of_storage.m_allocator->call_realloc(this->_M_end_of_storage.m_allocator, 0, *v8);
  v10 = __pos - this->_M_start;
  if ( v10 )
  {
    memmove(v9, this->_M_start, v10);
    v12 = (unsigned __int8 *)(v10 + v11);
  }
  else
  {
    v12 = v9;
  }
  *v12 = *__x;
  this->_M_end_of_storage.m_allocator->call_free(this->_M_end_of_storage.m_allocator, this->_M_start);
  v13 = size;
  this->_M_finish = v12 + 1;
  this->_M_start = v9;
  this->_M_end_of_storage._M_data = &v9[v13];
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *this@<ecx>,
        int a2@<edi>,
        unsigned __int16 *__pos,
        const unsigned __int16 *__x,
        const stlp_std::__true_type *__formal,
        bool __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // edx
  char *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // eax
  const stlp_std::__true_type *i; // ecx
  unsigned __int8 *v14; // ebx
  unsigned int v15; // esi
  int v16; // eax
  unsigned __int8 *v17; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short> > *v19; // [esp+0h] [ebp-Ch]
  unsigned int __xa; // [esp+14h] [ebp+8h]
  unsigned __int16 *__new_start; // [esp+18h] [ebp+Ch]

  __xa = stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_compute_next_size(
           this,
           (unsigned int)__formal);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short>>::allocate(
                            v19,
                            __xa);
  v10 = (char *)__pos - *(_DWORD *)a2;
  __new_start = (unsigned __int16 *)v9;
  if ( __pos == *(unsigned __int16 **)a2 )
  {
    v12 = v9;
  }
  else
  {
    memmove(v9, *(unsigned __int8 **)a2, (unsigned int)v10);
    v9 = (unsigned __int8 *)__new_start;
    v12 = (unsigned __int8 *)&v10[v11];
  }
  for ( i = __formal; i; v12 += 2 )
  {
    *(_WORD *)v12 = *__x;
    --i;
  }
  v14 = v12;
  if ( !__fill_len )
  {
    v15 = *(_DWORD *)(a2 + 4) - (_DWORD)__pos;
    if ( v15 )
    {
      memmove(v12, (unsigned __int8 *)__pos, v15);
      v9 = (unsigned __int8 *)__new_start;
      v14 = (unsigned __int8 *)(v15 + v16);
    }
  }
  v17 = *(unsigned __int8 **)a2;
  if ( *(_DWORD *)a2 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v17);
    v9 = (unsigned __int8 *)__new_start;
  }
  *(_DWORD *)(a2 + 4) = v14;
  *(_DWORD *)a2 = v9;
  *(_DWORD *)(a2 + 8) = &v9[2 * __xa];
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        unsigned __int8 *__pos,
        const unsigned __int16 *__x,
        unsigned int __formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // ebx
  unsigned int *p_formal; // eax
  unsigned __int8 *v9; // ebp
  char *v10; // edi
  int v11; // eax
  unsigned __int8 *v12; // eax
  unsigned int i; // ecx
  unsigned int v14; // edi
  unsigned __int8 *v15; // ebx
  int v16; // eax
  unsigned __int8 *v17; // edx
  unsigned int v18; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  v7 = __formal;
  size = stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)this,
           __formal);
  v18 = size;
  __formal = 1;
  p_formal = &__formal;
  if ( size )
    p_formal = &v18;
  v9 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, unsigned int))(*(_DWORD *)a2[2] + 20))(
                            a2[2],
                            0,
                            2 * *p_formal);
  v10 = (char *)(__pos - *a2);
  if ( __pos == *a2 )
  {
    v12 = v9;
  }
  else
  {
    memmove(v9, *a2, __pos - *a2);
    v12 = (unsigned __int8 *)&v10[v11];
  }
  for ( i = v7; i; v12 += 2 )
  {
    *(_WORD *)v12 = *__x;
    --i;
  }
  v14 = a2[1] - __pos;
  v15 = v12;
  if ( v14 )
  {
    memmove(v12, __pos, v14);
    v15 = (unsigned __int8 *)(v14 + v16);
  }
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  v17 = &v9[2 * size];
  *a2 = v9;
  a2[1] = v15;
  a2[3] = v17;
}


void __userpurge stlp_std::priv::_Impl_vector<int,survarium::std_allocator<int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void const *,survarium::std_allocator<void const *> > *this@<edi>,
        const void **__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *a3@<ecx>,
        const void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int size; // ebp
  unsigned __int8 *v9; // ebx
  unsigned int v10; // esi
  int v11; // eax
  const void **v12; // eax
  const void **M_start; // eax
  void *v14; // esi
  unsigned int v15; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v16; // [esp+0h] [ebp-Ch]
  const void **__xa; // [esp+10h] [ebp+4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           a3,
           v15);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate(
                            v16,
                            size);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (const void **)(v10 + v11);
  }
  else
  {
    v12 = (const void **)v9;
  }
  *v12 = *__x;
  __xa = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    v14 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v14, M_start);
  }
  this->_M_start = (const void **)v9;
  this->_M_finish = __xa;
  this->_M_end_of_storage._M_data = (const void **)&v9[4 * size];
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned __int8 *__pos,
        unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v6; // eax
  unsigned int *v8; // [esp+4h] [ebp-74h]
  unsigned __int8 *__new_finish; // [esp+6Ch] [ebp-Ch]
  unsigned int *__new_start; // [esp+70h] [ebp-8h]
  unsigned int __len; // [esp+74h] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>::_M_compute_next_size(
            this,
            __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::ai::std_allocator<unsigned int>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  v6 = stlp_std::priv::__copy_trivial((unsigned __int8 *)this->_M_start, __pos, (unsigned __int8 *)__new_start);
  __new_finish = (unsigned __int8 *)stlp_std::priv::__fill_n<unsigned int *,unsigned int,unsigned int>(
                                      __fill_len,
                                      __x,
                                      (unsigned int *)v6);
  if ( !__atend )
    __new_finish = stlp_std::priv::__copy_trivial(__pos, (unsigned __int8 *)this->_M_finish, __new_finish);
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_clear(this);
  v8 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = (unsigned int *)__new_finish;
  this->_M_end_of_storage._M_data = v8;
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int> > *this@<edi>,
        char *__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *a3@<ecx>,
        const unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v8; // ebx
  unsigned int v9; // esi
  int v10; // eax
  unsigned __int8 *v11; // eax
  unsigned int *v12; // ebp
  unsigned int *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v15; // [esp+0h] [ebp-10h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v16; // [esp+0h] [ebp-10h]
  unsigned int size; // [esp+Ch] [ebp-4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           a3,
           v15);
  v8 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                            size,
                            v16);
  v9 = __pos - (char *)this->_M_start;
  if ( v9 )
  {
    memmove(v8, (unsigned __int8 *)this->_M_start, v9);
    v11 = (unsigned __int8 *)(v9 + v10);
  }
  else
  {
    v11 = v8;
  }
  *(_DWORD *)v11 = *__x;
  v12 = (unsigned int *)(v11 + 4);
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  this->_M_finish = v12;
  this->_M_start = (unsigned int *)v8;
  this->_M_end_of_storage._M_data = (unsigned int *)&v8[4 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *this@<ecx>,
        unsigned int **a2@<edi>,
        unsigned int *__pos,
        const unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edx
  char *v11; // esi
  int v12; // eax
  const stlp_std::__true_type *i; // ecx
  unsigned int v14; // esi
  unsigned __int8 *v15; // ebx
  int v16; // eax
  unsigned __int8 *v17; // eax
  void *v18; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v19; // [esp+0h] [ebp-Ch]
  unsigned int __xa; // [esp+14h] [ebp+8h]
  unsigned int *__new_start; // [esp+18h] [ebp+Ch]

  __xa = stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_compute_next_size(
           this,
           a2,
           (unsigned int)__formal);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate(
                            __xa,
                            v19);
  v10 = (unsigned __int8 *)__pos;
  v11 = (char *)((char *)__pos - (char *)*a2);
  __new_start = (unsigned int *)v9;
  if ( __pos != *a2 )
  {
    memmove(v9, (unsigned __int8 *)*a2, (unsigned int)v11);
    v10 = (unsigned __int8 *)__pos;
    v9 = (unsigned __int8 *)&v11[v12];
  }
  for ( i = __formal; i; v9 += 4 )
  {
    *(_DWORD *)v9 = *__x;
    --i;
  }
  v14 = (char *)a2[1] - (char *)v10;
  v15 = v9;
  if ( v14 )
  {
    memmove(v9, v10, v14);
    v15 = (unsigned __int8 *)(v14 + v16);
  }
  v17 = (unsigned __int8 *)*a2;
  if ( *a2 )
  {
    v18 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v18, v17);
  }
  a2[1] = (unsigned int *)v15;
  *a2 = __new_start;
  a2[2] = &__new_start[__xa];
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __pos,
        const unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int *v7; // ebx
  unsigned int size; // ebp
  int *p_pos; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  v7 = (unsigned int *)__pos;
  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)this,
           v15);
  v16 = size;
  __pos = 1;
  p_pos = &__pos;
  if ( size )
    p_pos = (int *)&v16;
  v10 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             4 * *p_pos);
  v11 = (char *)v7 - (char *)*a2;
  if ( v11 )
  {
    memmove(v10, *a2, v11);
    v13 = (unsigned __int8 *)(v11 + v12);
  }
  else
  {
    v13 = v10;
  }
  *(_DWORD *)v13 = *__x;
  v14 = v13 + 4;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  *a2 = v10;
  a2[1] = v14;
  a2[3] = &v10[4 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float> > *this@<edi>,
        float *__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *a3@<ecx>,
        float *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v8; // ebx
  unsigned int v9; // esi
  int v10; // eax
  float *v11; // eax
  float *v12; // ebp
  float *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v15; // [esp+0h] [ebp-10h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v16; // [esp+0h] [ebp-10h]
  unsigned int size; // [esp+Ch] [ebp-4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           a3,
           v15);
  v8 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                            size,
                            v16);
  v9 = (char *)__pos - (char *)this->_M_start;
  if ( v9 )
  {
    memmove(v8, (unsigned __int8 *)this->_M_start, v9);
    v11 = (float *)(v9 + v10);
  }
  else
  {
    v11 = (float *)v8;
  }
  v12 = v11 + 1;
  *v11 = *__x;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  this->_M_finish = v12;
  this->_M_start = (float *)v8;
  this->_M_end_of_storage._M_data = (float *)&v8[4 * size];
}


void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        float *__pos,
        float *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  int v6; // eax
  int v7; // eax
  float *v8; // [esp+0h] [ebp-B0h]
  float *v9; // [esp+4h] [ebp-ACh]
  float *v11; // [esp+Ch] [ebp-A4h]
  float *M_finish; // [esp+64h] [ebp-4Ch]
  unsigned int v13; // [esp+68h] [ebp-48h]
  int count; // [esp+78h] [ebp-38h]
  float *__new_finish; // [esp+A4h] [ebp-Ch]
  float *__new_start; // [esp+A8h] [ebp-8h]
  unsigned int __len; // [esp+ACh] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_compute_next_size(this, __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<float *,float,vostok::vectora_allocator<float>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  count = (char *)__pos - (char *)this->_M_start;
  if ( __pos == this->_M_start )
  {
    v9 = __new_start;
  }
  else
  {
    memmove((unsigned __int8 *)__new_start, (unsigned __int8 *)this->_M_start, count);
    v9 = (float *)(count + v6);
  }
  memset32(v9, COERCE_INT(*__x), __fill_len);
  __new_finish = &v9[__fill_len];
  if ( !__atend )
  {
    M_finish = this->_M_finish;
    v13 = (char *)M_finish - (char *)__pos;
    if ( M_finish == __pos )
    {
      v8 = &v9[__fill_len];
    }
    else
    {
      memmove((unsigned __int8 *)&v9[__fill_len], (unsigned __int8 *)__pos, v13);
      v8 = (float *)(v13 + v7);
    }
    __new_finish = v8;
  }
  stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_clear(this);
  v11 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = __new_finish;
  this->_M_end_of_storage._M_data = v11;
}


void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void **__pos,
        void *const *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v6; // eax
  void **v8; // [esp+4h] [ebp-6Ch]
  void **__new_finish; // [esp+64h] [ebp-Ch]
  void **__new_start; // [esp+68h] [ebp-8h]
  unsigned int __len; // [esp+6Ch] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_compute_next_size(this, __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<void * *,void *,stlp_std::allocator<void *>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  v6 = stlp_std::priv::__copy_trivial(
         (unsigned __int8 *)this->_M_start,
         (unsigned __int8 *)__pos,
         (unsigned __int8 *)__new_start);
  __new_finish = stlp_std::priv::__fill_n<void * *,unsigned int,void *>((void **)v6, __fill_len, __x);
  if ( !__atend )
    __new_finish = (void **)stlp_std::priv::__copy_trivial(
                              (unsigned __int8 *)__pos,
                              (unsigned __int8 *)this->_M_finish,
                              (unsigned __int8 *)__new_finish);
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(this);
  v8 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = __new_finish;
  this->_M_end_of_storage._M_data = v8;
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        void **__pos,
        void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v7; // ebx
  char *v8; // esi
  int v9; // eax
  void **v10; // eax
  unsigned __int8 *v11; // ebp
  unsigned int v12; // esi
  int v13; // eax
  unsigned __int8 *v14; // eax
  void *m_arena; // esi
  stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *> > *v16; // [esp+0h] [ebp-10h]
  unsigned int size; // [esp+Ch] [ebp-4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)this,
           a2);
  v7 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *>>::allocate(
                            v16,
                            size);
  v8 = (char *)((char *)__pos - (char *)*a2);
  if ( __pos == (void **)*a2 )
  {
    v10 = (void **)v7;
  }
  else
  {
    memmove(v7, *a2, (char *)__pos - (char *)*a2);
    v10 = (void **)&v8[v9];
  }
  *v10 = *__x;
  v11 = (unsigned __int8 *)(v10 + 1);
  v12 = a2[1] - (unsigned __int8 *)__pos;
  if ( v12 )
  {
    memmove(v11, (unsigned __int8 *)__pos, v12);
    v11 = (unsigned __int8 *)(v12 + v13);
  }
  v14 = *a2;
  if ( *a2 )
  {
    m_arena = vostok::input::g_allocator->m_arena;
    vostok::input::g_allocator->m_out_of_memory = 0;
    vostok_mspace_free(m_arena, v14);
  }
  a2[1] = v11;
  *a2 = v7;
  a2[2] = &v7[4 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        void **__pos,
        void *const *__x,
        const stlp_std::__true_type *__formal,
        bool __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // edx
  char *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // eax
  const stlp_std::__true_type *i; // ecx
  unsigned __int8 *v14; // ebx
  unsigned int v15; // esi
  int v16; // eax
  unsigned __int8 *v17; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v19; // [esp+0h] [ebp-Ch]
  unsigned int __xa; // [esp+14h] [ebp+8h]
  void **__new_start; // [esp+18h] [ebp+Ch]

  __xa = stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *)this,
           (unsigned int)__formal);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                            v19,
                            __xa);
  v10 = (char *)__pos - *(_DWORD *)a2;
  __new_start = (void **)v9;
  if ( __pos == *(void ***)a2 )
  {
    v12 = v9;
  }
  else
  {
    memmove(v9, *(unsigned __int8 **)a2, (unsigned int)v10);
    v9 = (unsigned __int8 *)__new_start;
    v12 = (unsigned __int8 *)&v10[v11];
  }
  for ( i = __formal; i; v12 += 4 )
  {
    *(void **)v12 = *__x;
    --i;
  }
  v14 = v12;
  if ( !__fill_len )
  {
    v15 = *(_DWORD *)(a2 + 4) - (_DWORD)__pos;
    if ( v15 )
    {
      memmove(v12, (unsigned __int8 *)__pos, v15);
      v9 = (unsigned __int8 *)__new_start;
      v14 = (unsigned __int8 *)(v15 + v16);
    }
  }
  v17 = *(unsigned __int8 **)a2;
  if ( *(_DWORD *)a2 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v17);
    v9 = (unsigned __int8 *)__new_start;
  }
  *(_DWORD *)(a2 + 4) = v14;
  *(_DWORD *)a2 = v9;
  *(_DWORD *)(a2 + 8) = &v9[4 * __xa];
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *> > *this@<edi>,
        void **__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *a3@<ecx>,
        void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int size; // ebp
  unsigned __int8 *v9; // ebx
  unsigned int v10; // esi
  int v11; // eax
  void **v12; // eax
  void **M_start; // eax
  unsigned int v14; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *> > *v15; // [esp+0h] [ebp-Ch]
  void **__xa; // [esp+10h] [ebp+4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           a3,
           v14);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *>>::allocate(
                            v15,
                            size);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (void **)(v10 + v11);
  }
  else
  {
    v12 = (void **)v9;
  }
  *v12 = *__x;
  __xa = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
    vostok_mspace_free(vostok::memory::g_resources_helper_allocator.m_arena, M_start);
  }
  this->_M_start = (void **)v9;
  this->_M_finish = __xa;
  this->_M_end_of_storage._M_data = (void **)&v9[4 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        void **__pos,
        void *const *__x,
        const stlp_std::__true_type *__formal,
        bool __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // edx
  char *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // eax
  const stlp_std::__true_type *i; // ecx
  unsigned __int8 *v14; // ebx
  unsigned int v15; // esi
  int v16; // eax
  unsigned __int8 *v17; // eax
  void *v18; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v19; // [esp+0h] [ebp-Ch]
  unsigned int __xa; // [esp+14h] [ebp+8h]
  void **__new_start; // [esp+18h] [ebp+Ch]

  __xa = stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *)this,
           a2,
           (unsigned int)__formal);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate(
                            v19,
                            __xa);
  v10 = (char *)((char *)__pos - (char *)*a2);
  __new_start = (void **)v9;
  if ( __pos == (void **)*a2 )
  {
    v12 = v9;
  }
  else
  {
    memmove(v9, *a2, (unsigned int)v10);
    v9 = (unsigned __int8 *)__new_start;
    v12 = (unsigned __int8 *)&v10[v11];
  }
  for ( i = __formal; i; v12 += 4 )
  {
    *(void **)v12 = *__x;
    --i;
  }
  v14 = v12;
  if ( !__fill_len )
  {
    v15 = a2[1] - (unsigned __int8 *)__pos;
    if ( v15 )
    {
      memmove(v12, (unsigned __int8 *)__pos, v15);
      v9 = (unsigned __int8 *)__new_start;
      v14 = (unsigned __int8 *)(v15 + v16);
    }
  }
  v17 = *a2;
  if ( *a2 )
  {
    v18 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v18, v17);
    v9 = (unsigned __int8 *)__new_start;
  }
  a2[1] = v14;
  *a2 = v9;
  a2[2] = &v9[4 * __xa];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *this@<edi>,
        const vostok::render::trample_desc *__x@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *a3@<ecx>,
        vostok::render::trample_desc *__pos,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // ebp
  unsigned int v10; // ebx
  int v11; // eax
  unsigned __int8 *v12; // eax
  vostok::render::trample_desc *v13; // ebx
  vostok::render::trample_desc *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v16; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *v17; // [esp+0h] [ebp-Ch]
  unsigned int __posa; // [esp+10h] [ebp+4h]

  __posa = stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding>>::_M_compute_next_size(
             a3,
             v16);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc>>::allocate(
                            v17,
                            __posa);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (unsigned __int8 *)(v10 + v11);
  }
  else
  {
    v12 = v9;
  }
  *(_QWORD *)v12 = *(_QWORD *)&__x->position.x;
  *((_QWORD *)v12 + 1) = *(_QWORD *)&__x->position.elements[2];
  *((_DWORD *)v12 + 4) = LODWORD(__x->multiplier);
  v13 = (vostok::render::trample_desc *)(v12 + 20);
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  this->_M_start = (vostok::render::trample_desc *)v9;
  this->_M_finish = v13;
  this->_M_end_of_storage._M_data = (vostok::render::trample_desc *)&v9[20 * __posa];
}


void __userpurge stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __pos,
        const survarium::player_skill *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  survarium::player_skill *v7; // ebx
  unsigned int size; // ebp
  int *p_pos; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  survarium::player_skill *v13; // eax
  survarium::player_skill *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  v7 = (survarium::player_skill *)__pos;
  size = stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill>>::_M_compute_next_size(
           this,
           v15);
  v16 = size;
  __pos = 1;
  p_pos = &__pos;
  if ( size )
    p_pos = (int *)&v16;
  v10 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             2 * *p_pos);
  v11 = (char *)v7 - (char *)*a2;
  if ( v11 )
  {
    memmove(v10, *a2, v11);
    v13 = (survarium::player_skill *)(v11 + v12);
  }
  else
  {
    v13 = (survarium::player_skill *)v10;
  }
  *v13 = *__x;
  v14 = v13 + 1;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  *a2 = v10;
  a2[1] = &v14->skill_id;
  a2[3] = &v10[2 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __pos,
        const vostok::collision::ray_object_result *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  vostok::collision::ray_object_result *v7; // ebx
  unsigned int size; // ebp
  int *p_pos; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  vostok::collision::ray_object_result *v13; // eax
  vostok::collision::ray_object_result *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  v7 = (vostok::collision::ray_object_result *)__pos;
  size = stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record>>::_M_compute_next_size(
           this,
           v15);
  v16 = size;
  __pos = 1;
  p_pos = &__pos;
  if ( size )
    p_pos = (int *)&v16;
  v10 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             8 * *p_pos);
  v11 = (char *)v7 - (char *)*a2;
  if ( v11 )
  {
    memmove(v10, *a2, v11);
    v13 = (vostok::collision::ray_object_result *)(v11 + v12);
  }
  else
  {
    v13 = (vostok::collision::ray_object_result *)v10;
  }
  *v13 = *__x;
  v14 = v13 + 1;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  *a2 = v10;
  a2[1] = (unsigned __int8 *)v14;
  a2[3] = &v10[8 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *this@<ecx>,
        int *a2@<esi>,
        vostok::ui::undo_ *__pos,
        int __x,
        const stlp_std::__true_type *__formal,
        bool __fill_len,
        bool __atend)
{
  const vostok::ui::undo_ *v7; // ebx
  int *p_x; // eax
  int v9; // eax
  unsigned __int8 *v10; // edx
  int v11; // ebp
  char *v12; // edi
  int v13; // eax
  const stlp_std::__true_type *i; // ecx
  int v15; // edi
  unsigned int v16; // ebx
  int v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  v7 = (const vostok::ui::undo_ *)__x;
  size = stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *)this,
           a2,
           (unsigned int)__formal);
  v19 = size;
  __x = 1;
  p_x = &__x;
  if ( size )
    p_x = (int *)&v19;
  v9 = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)a2[2] + 20))(a2[2], 0, 8 * *p_x);
  v10 = (unsigned __int8 *)__pos;
  v11 = v9;
  v12 = (char *)__pos - *a2;
  if ( __pos != (vostok::ui::undo_ *)*a2 )
  {
    memmove((unsigned __int8 *)v9, (unsigned __int8 *)*a2, (unsigned int)__pos - *a2);
    v10 = (unsigned __int8 *)__pos;
    v9 = (int)&v12[v13];
  }
  for ( i = __formal; i; v9 += 8 )
  {
    *(_DWORD *)v9 = v7->text;
    *(_DWORD *)(v9 + 4) = *(_DWORD *)&v7->caret;
    --i;
  }
  v15 = v9;
  if ( !__fill_len )
  {
    v16 = a2[1] - (_DWORD)v10;
    if ( v16 )
    {
      memmove((unsigned __int8 *)v9, v10, v16);
      v15 = v16 + v17;
    }
  }
  (*(void (__thiscall **)(int, int))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  v18 = size;
  a2[1] = v15;
  *a2 = v11;
  a2[3] = v11 + 8 * v18;
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        vostok::render::ui::vertex *__pos,
        const D3D11_INPUT_ELEMENT_DESC *__x,
        unsigned int __formal,
        unsigned int __fill_len,
        bool __atend)
{
  const stlp_std::__true_type *v7; // ebp
  unsigned int *p_formal; // eax
  unsigned __int8 *v9; // ebx
  char *v10; // edi
  int v11; // eax
  D3D11_INPUT_ELEMENT_DESC *v12; // eax
  unsigned __int8 *v13; // ebp
  unsigned int v14; // edi
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  v7 = (const stlp_std::__true_type *)__formal;
  size = stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *)this,
           __formal);
  v17 = size;
  __formal = 1;
  p_formal = &__formal;
  if ( size )
    p_formal = &v17;
  v9 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, unsigned int))(*(_DWORD *)a2[2] + 20))(
                            a2[2],
                            0,
                            28 * *p_formal);
  v10 = (char *)((char *)__pos - (char *)*a2);
  if ( __pos == (vostok::render::ui::vertex *)*a2 )
  {
    v12 = (D3D11_INPUT_ELEMENT_DESC *)v9;
  }
  else
  {
    memmove(v9, *a2, (char *)__pos - (char *)*a2);
    v12 = (D3D11_INPUT_ELEMENT_DESC *)&v10[v11];
  }
  v13 = (unsigned __int8 *)stlp_std::priv::__fill_n<vostok::render::ui::vertex *,unsigned int,vostok::render::ui::vertex>(
                             v12,
                             (unsigned int)v7,
                             __x);
  v14 = a2[1] - (unsigned __int8 *)__pos;
  if ( v14 )
  {
    memmove(v13, (unsigned __int8 *)__pos, v14);
    v13 = (unsigned __int8 *)(v14 + v15);
  }
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  v16 = 7 * size;
  a2[1] = v13;
  *a2 = v9;
  a2[3] = &v9[4 * v16];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::math::float3,survarium::std_allocator<vostok::math::float3>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::math::float3,survarium::std_allocator<vostok::math::float3> > *this@<edi>,
        vostok::math::float3 *__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *a3@<ecx>,
        const vostok::math::float3 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int size; // ebp
  unsigned __int8 *v9; // ebx
  unsigned int v10; // esi
  int v11; // eax
  vostok::math::float3 *v12; // eax
  vostok::math::float3 *M_start; // eax
  void *v14; // esi
  unsigned int v15; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,survarium::std_allocator<vostok::math::float3> > *v16; // [esp+0h] [ebp-Ch]
  vostok::math::float3 *__xa; // [esp+10h] [ebp+4h]

  size = stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct>>::_M_compute_next_size(
           a3,
           v15);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,survarium::std_allocator<vostok::math::float3>>::allocate(
                            v16,
                            size);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (vostok::math::float3 *)(v10 + v11);
  }
  else
  {
    v12 = (vostok::math::float3 *)v9;
  }
  *v12 = *__x;
  __xa = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    v14 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v14, M_start);
  }
  this->_M_start = (vostok::math::float3 *)v9;
  this->_M_finish = __xa;
  this->_M_end_of_storage._M_data = (vostok::math::float3 *)&v9[12 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __pos,
        const vostok::math::float3 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  vostok::math::float3 *v7; // ebx
  unsigned int size; // ebp
  int *p_pos; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  v7 = (vostok::math::float3 *)__pos;
  size = stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct>>::_M_compute_next_size(
           this,
           v15);
  v16 = size;
  __pos = 1;
  p_pos = &__pos;
  if ( size )
    p_pos = (int *)&v16;
  v10 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             12 * *p_pos);
  v11 = (char *)v7 - (char *)*a2;
  if ( v11 )
  {
    memmove(v10, *a2, v11);
    v13 = (vostok::math::float3 *)(v11 + v12);
  }
  else
  {
    v13 = (vostok::math::float3 *)v10;
  }
  *v13 = *__x;
  v14 = v13 + 1;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  *a2 = v10;
  a2[1] = (unsigned __int8 *)v14;
  a2[3] = &v10[12 * size];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::_M_insert_overflow(
        vostok::math::frustum *__pos@<eax>,
        stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *a2@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum> > *this,
        const vostok::math::frustum *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // ebp
  unsigned int v10; // esi
  int v11; // eax
  vostok::math::frustum *v12; // eax
  vostok::math::frustum *v13; // edi
  vostok::math::frustum *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v16; // [esp+0h] [ebp-10h]
  unsigned int thisa; // [esp+14h] [ebp+4h]

  thisa = (unsigned int)stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>>>::_M_compute_next_size(
                          a2,
                          this);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::math::frustum *,vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::allocate(
                            thisa,
                            v16);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (vostok::math::frustum *)(v10 + v11);
  }
  else
  {
    v12 = (vostok::math::frustum *)v9;
  }
  qmemcpy(v12, __x, sizeof(vostok::math::frustum));
  v13 = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  this->_M_finish = v13;
  this->_M_start = (vostok::math::frustum *)v9;
  this->_M_end_of_storage._M_data = (vostok::math::frustum *)&v9[120 * thisa];
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this,
        unsigned __int64 *__pos,
        const unsigned __int64 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  int v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // [esp+0h] [ebp-B0h]
  unsigned __int8 *v9; // [esp+4h] [ebp-ACh]
  unsigned __int64 *v11; // [esp+Ch] [ebp-A4h]
  unsigned __int64 *M_finish; // [esp+64h] [ebp-4Ch]
  unsigned int v13; // [esp+68h] [ebp-48h]
  unsigned int v14; // [esp+6Ch] [ebp-44h]
  unsigned __int8 *v15; // [esp+70h] [ebp-40h]
  int count; // [esp+78h] [ebp-38h]
  unsigned __int64 *__new_finish; // [esp+A4h] [ebp-Ch]
  unsigned __int64 *__new_start; // [esp+A8h] [ebp-8h]
  unsigned int __len; // [esp+ACh] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_compute_next_size(
            this,
            __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<unsigned __int64 *,unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  count = (char *)__pos - (char *)this->_M_start;
  if ( __pos == this->_M_start )
  {
    v9 = (unsigned __int8 *)__new_start;
  }
  else
  {
    memmove((unsigned __int8 *)__new_start, (unsigned __int8 *)this->_M_start, count);
    v9 = (unsigned __int8 *)(count + v6);
  }
  v14 = __fill_len;
  v15 = v9;
  while ( v14 )
  {
    *(_QWORD *)v15 = *__x;
    --v14;
    v15 += 8;
  }
  __new_finish = (unsigned __int64 *)v15;
  if ( !__atend )
  {
    M_finish = this->_M_finish;
    v13 = (char *)M_finish - (char *)__pos;
    if ( M_finish == __pos )
    {
      v8 = v15;
    }
    else
    {
      memmove(v15, (unsigned __int8 *)__pos, v13);
      v8 = (unsigned __int8 *)(v13 + v7);
    }
    __new_finish = (unsigned __int64 *)v8;
  }
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::collision::bone_collision_data *,float>,vostok::vectora_allocator<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>::_M_clear(this);
  v11 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = __new_finish;
  this->_M_end_of_storage._M_data = v11;
}
