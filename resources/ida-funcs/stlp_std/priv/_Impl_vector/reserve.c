void __thiscall stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::reserve(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *this,
        unsigned int __n,
        unsigned int __na)
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // edi
  int v6; // ebp
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ebp
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short> > *v12; // [esp+0h] [ebp-10h]
  unsigned int __old_size; // [esp+14h] [ebp+4h]

  v4 = *(unsigned __int8 **)__n;
  if ( (*(_DWORD *)(__n + 8) - *(_DWORD *)__n) >> 1 < __na )
  {
    if ( __na > 0x7FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v5 = *(unsigned __int8 **)(__n + 4);
    v6 = (v5 - v4) >> 1;
    __old_size = v6;
    v7 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short>>::allocate(
                              __na,
                              v12);
    if ( v4 )
    {
      v8 = v7;
      if ( v5 != v4 )
        memcpy(v7, v4, v5 - v4);
      v9 = *(unsigned __int8 **)__n;
      v10 = v8;
      if ( *(_DWORD *)__n )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
      }
      v6 = __old_size;
    }
    else
    {
      v10 = v7;
    }
    *(_DWORD *)__n = v10;
    *(_DWORD *)(__n + 4) = &v10[2 * v6];
    *(_DWORD *)(__n + 8) = &v10[2 * __na];
  }
}


void __thiscall stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float>>::reserve(
        stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float> > *this,
        unsigned int __n,
        unsigned int __na)
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // edi
  int v6; // ebp
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ebp
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v12; // [esp+0h] [ebp-10h]
  unsigned int __old_size; // [esp+14h] [ebp+4h]

  v4 = *(unsigned __int8 **)__n;
  if ( (*(_DWORD *)(__n + 8) - *(_DWORD *)__n) >> 2 < __na )
  {
    if ( __na > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v5 = *(unsigned __int8 **)(__n + 4);
    v6 = (v5 - v4) >> 2;
    __old_size = v6;
    v7 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                              __na,
                              v12);
    if ( v4 )
    {
      v8 = v7;
      if ( v5 != v4 )
        memcpy(v7, v4, v5 - v4);
      v9 = *(unsigned __int8 **)__n;
      v10 = v8;
      if ( *(_DWORD *)__n )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
      }
      v6 = __old_size;
    }
    else
    {
      v10 = v7;
    }
    *(_DWORD *)__n = v10;
    *(_DWORD *)(__n + 4) = &v10[4 * v6];
    *(_DWORD *)(__n + 8) = &v10[4 * __na];
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::reserve(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        unsigned int __n)
{
  void **M_start; // eax
  stlp_std::allocator<void *> *p_M_end_of_storage; // ebp
  void **M_finish; // ecx
  int v6; // ebx
  void **v7; // edi
  void **v8; // eax

  M_start = this->_M_start;
  p_M_end_of_storage = &this->_M_end_of_storage;
  if ( this->_M_end_of_storage._M_data - this->_M_start < __n )
  {
    if ( __n > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    M_finish = this->_M_finish;
    v6 = M_finish - M_start;
    if ( M_start )
    {
      v7 = stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_allocate_and_copy<void * *>(
             this,
             &__n,
             (stlp_std::locale::facet **)M_start,
             (stlp_std::locale::facet **)M_finish);
      stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(this);
    }
    else
    {
      v7 = stlp_std::allocator<void *>::_M_allocate(p_M_end_of_storage, __n, &__n);
    }
    v8 = &v7[__n];
    this->_M_start = v7;
    this->_M_finish = &v7[v6];
    *(_DWORD *)&p_M_end_of_storage->stlp_std::__stlport_class<stlp_std::allocator<void *> > = v8;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  vostok::ai::planning::world_state_property *v3; // ebx
  vostok::ai::planning::world_state_property *v4; // ebp
  int v5; // esi
  vostok::ai::planning::world_state_property *v6; // eax
  vostok::ai::planning::world_state_property *v7; // esi
  vostok::ai::planning::world_state_property *v8; // eax
  vostok::ai::planning::world_state_property *v9; // ebx
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v11; // [esp+0h] [ebp-10h]
  unsigned int __old_size; // [esp+Ch] [ebp-4h]

  v3 = *(vostok::ai::planning::world_state_property **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) >> 2 < __n )
  {
    if ( __n > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v4 = *(vostok::ai::planning::world_state_property **)(a2 + 4);
    v5 = ((char *)v4 - (char *)v3) >> 2;
    __old_size = v5;
    v6 = (vostok::ai::planning::world_state_property *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                                                         v11,
                                                         __n);
    if ( v3 )
    {
      v7 = v6;
      stlp_std::uninitialized_copy<void * *,void * *>(v3, v4, v6);
      v8 = *(vostok::ai::planning::world_state_property **)a2;
      v9 = v7;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
      }
      v5 = __old_size;
    }
    else
    {
      v9 = v6;
    }
    *(_DWORD *)a2 = v9;
    *(_DWORD *)(a2 + 4) = (char *)v9 + 4 * v5;
    *(_DWORD *)(a2 + 8) = (char *)v9 + 4 * __n;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this@<ecx>,
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *a2@<esi>,
        unsigned int __n)
{
  const void **M_start; // ecx
  int v4; // ebx
  const void **v5; // edi
  const void **v6; // ecx

  M_start = a2->_M_start;
  if ( a2->_M_end_of_storage._M_data - a2->_M_start < __n )
  {
    if ( __n > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v4 = a2->_M_finish - M_start;
    if ( M_start )
    {
      v5 = stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_allocate_and_copy<void const * *>(
             a2,
             &__n,
             M_start,
             a2->_M_finish);
      a2->_M_end_of_storage.m_allocator->call_free(a2->_M_end_of_storage.m_allocator, a2->_M_start);
    }
    else
    {
      v5 = stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *>>::allocate(
             __n,
             &__n,
             &a2->_M_end_of_storage);
    }
    v6 = &v5[__n];
    a2->_M_start = v5;
    a2->_M_finish = &v5[v4];
    a2->_M_end_of_storage._M_data = v6;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  vostok::render::batched_vertex_source *v3; // esi
  int v4; // ebx
  vostok::render::batched_vertex_source *v5; // ebp
  vostok::render::batched_vertex_source *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *v8; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v9; // [esp+0h] [ebp-10h]
  int *v10; // [esp+4h] [ebp-Ch]
  vostok::render::batched_vertex_source *__last; // [esp+Ch] [ebp-4h]

  v3 = *(vostok::render::batched_vertex_source **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 36 < __n )
  {
    if ( __n > 0x71C71C7 )
      stlp_std::__stl_throw_length_error("vector");
    __last = *(vostok::render::batched_vertex_source **)(a2 + 4);
    v4 = __last - v3;
    v5 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::allocate(
           v8,
           __n);
    if ( v3 )
    {
      stlp_std::priv::__ucopy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source *,int>(
        v3,
        __last,
        v5,
        v9,
        v10);
      v6 = *(vostok::render::batched_vertex_source **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)v6);
      }
    }
    *(_DWORD *)a2 = v5;
    *(_DWORD *)(a2 + 4) = &v5[v4];
    *(_DWORD *)(a2 + 8) = &v5[__n];
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::billboard_vertex,vostok::render::std_allocator<vostok::render::billboard_vertex> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // ebp
  int v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebp
  unsigned __int8 *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *v10; // [esp+0h] [ebp-10h]
  unsigned __int8 *v11; // [esp+Ch] [ebp-4h]

  v3 = *(unsigned __int8 **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 36 < __n )
  {
    if ( __n > 0x71C71C7 )
      stlp_std::__stl_throw_length_error("vector");
    v4 = *(unsigned __int8 **)(a2 + 4);
    v5 = (v4 - v3) / 36;
    v6 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::allocate(
                              v10,
                              __n);
    if ( v3 )
    {
      v11 = v6;
      if ( v4 != v3 )
      {
        memcpy(v6, v3, v4 - v3);
        v6 = v11;
      }
      v7 = v6;
      v8 = *(unsigned __int8 **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
      }
    }
    else
    {
      v7 = v6;
    }
    *(_DWORD *)(a2 + 4) = &v7[36 * v5];
    *(_DWORD *)a2 = v7;
    *(_DWORD *)(a2 + 8) = &v7[36 * __n];
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // ebp
  int v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebp
  unsigned __int8 *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *v10; // [esp+0h] [ebp-10h]
  unsigned __int8 *v11; // [esp+Ch] [ebp-4h]

  v3 = *(unsigned __int8 **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 20 < __n )
  {
    if ( __n > 0xCCCCCCC )
      stlp_std::__stl_throw_length_error("vector");
    v4 = *(unsigned __int8 **)(a2 + 4);
    v5 = (v4 - v3) / 20;
    v6 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc>>::allocate(
                              __n,
                              v10);
    if ( v3 )
    {
      v11 = v6;
      if ( v4 != v3 )
      {
        memcpy(v6, v3, v4 - v3);
        v6 = v11;
      }
      v7 = v6;
      v8 = *(unsigned __int8 **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
      }
    }
    else
    {
      v7 = v6;
    }
    *(_DWORD *)(a2 + 4) = &v7[20 * v5];
    *(_DWORD *)a2 = v7;
    *(_DWORD *)(a2 + 8) = &v7[20 * __n];
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex> > *this@<ecx>,
        vostok::render::shadow_vertex **a2@<edi>,
        unsigned int __n)
{
  vostok::render::shadow_vertex *v3; // eax
  int v5; // ebx
  vostok::render::shadow_vertex *v6; // esi
  vostok::render::shadow_vertex *v7; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex> > *v9; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v10; // [esp+0h] [ebp-10h]
  int *v11; // [esp+4h] [ebp-Ch]
  vostok::render::shadow_vertex *__last; // [esp+Ch] [ebp-4h]
  vostok::render::shadow_vertex *__tmp; // [esp+14h] [ebp+4h]
  vostok::render::shadow_vertex *__tmpa; // [esp+14h] [ebp+4h]

  v3 = *a2;
  __tmp = *a2;
  if ( a2[2] - *a2 < __n )
  {
    if ( __n > 0x7FFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    __last = a2[1];
    v5 = __last - v3;
    if ( v3 )
    {
      v6 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::allocate(
             __n,
             v9);
      stlp_std::priv::__ucopy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex *,int>(
        __tmp,
        __last,
        v6,
        v10,
        v11);
      v7 = *a2;
      __tmpa = v6;
      if ( *a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v7);
        v6 = __tmpa;
      }
    }
    else
    {
      v6 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::allocate(
             __n,
             v9);
    }
    *a2 = v6;
    a2[1] = &v6[v5];
    a2[2] = &v6[__n];
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect> > *this@<ecx>,
        vostok::render::culling::aab_rect **a2@<edi>,
        unsigned int __n)
{
  vostok::render::culling::aab_rect *v3; // eax
  int v5; // ebx
  vostok::render::culling::aab_rect *v6; // esi
  vostok::render::culling::aab_rect *v7; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *v9; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v10; // [esp+0h] [ebp-10h]
  int *v11; // [esp+4h] [ebp-Ch]
  vostok::render::culling::aab_rect *__first; // [esp+Ch] [ebp-4h]
  vostok::render::culling::aab_rect *__tmp; // [esp+14h] [ebp+4h]
  vostok::render::culling::aab_rect *__tmpa; // [esp+14h] [ebp+4h]

  v3 = *a2;
  __first = *a2;
  if ( a2[2] - *a2 < __n )
  {
    if ( __n > 0xFFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    __tmp = a2[1];
    v5 = __tmp - v3;
    if ( v3 )
    {
      v6 = (vostok::render::culling::aab_rect *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::allocate(
                                                  v9,
                                                  __n);
      stlp_std::priv::__ucopy<vostok::render::culling::aab_rect *,vostok::render::culling::aab_rect *,int>(
        __first,
        __tmp,
        v6,
        v10,
        v11);
      v7 = *a2;
      __tmpa = v6;
      if ( *a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v7);
        v6 = __tmpa;
      }
    }
    else
    {
      v6 = (vostok::render::culling::aab_rect *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::allocate(
                                                  v9,
                                                  __n);
    }
    *a2 = v6;
    a2[1] = &v6[v5];
    a2[2] = &v6[__n];
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // ebp
  int v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebp
  unsigned __int8 *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v10; // [esp+0h] [ebp-10h]
  unsigned __int8 *v11; // [esp+Ch] [ebp-4h]

  v3 = *(unsigned __int8 **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 120 < __n )
  {
    if ( __n > (unsigned int)&vostok::memory::s_CRT_arena[24588378] )
      stlp_std::__stl_throw_length_error("vector");
    v4 = *(unsigned __int8 **)(a2 + 4);
    v5 = (v4 - v3) / 120;
    v6 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::math::frustum *,vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::allocate(
                              __n,
                              v10);
    if ( v3 )
    {
      v11 = v6;
      if ( v4 != v3 )
      {
        memcpy(v6, v3, v4 - v3);
        v6 = v11;
      }
      v7 = v6;
      v8 = *(unsigned __int8 **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
      }
    }
    else
    {
      v7 = v6;
    }
    *(_DWORD *)(a2 + 4) = &v7[120 * v5];
    *(_DWORD *)a2 = v7;
    *(_DWORD *)(a2 + 8) = &v7[120 * __n];
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  const vostok::render::shader_constant *v3; // esi
  int v4; // ebx
  vostok::render::shader_constant *v5; // ebp
  vostok::render::shader_constant *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v8; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v9; // [esp+0h] [ebp-10h]
  int *v10; // [esp+4h] [ebp-Ch]
  vostok::render::shader_constant *__last; // [esp+Ch] [ebp-4h]

  v3 = *(const vostok::render::shader_constant **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 24 < __n )
  {
    if ( __n > 0xAAAAAAA )
      stlp_std::__stl_throw_length_error("vector");
    __last = *(vostok::render::shader_constant **)(a2 + 4);
    v4 = __last - v3;
    v5 = (vostok::render::shader_constant *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                                              __n,
                                              v8);
    if ( v3 )
    {
      stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
        v3,
        __last,
        v5,
        v9,
        v10);
      v6 = *(vostok::render::shader_constant **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      }
    }
    *(_DWORD *)a2 = v5;
    *(_DWORD *)(a2 + 4) = &v5[v4];
    *(_DWORD *)(a2 + 8) = &v5[__n];
  }
}
