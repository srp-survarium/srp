stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *__userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=@<eax>(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __x)
{
  const stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v3; // ebp
  void **v4; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v5; // eax
  unsigned __int8 *v6; // esi
  unsigned int v7; // ebx
  void **v8; // ebp
  unsigned __int8 *v9; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v11; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // ebp
  int v16; // eax
  unsigned __int8 *M_finish; // eax
  unsigned __int8 *v18; // ecx
  void *const *v19; // [esp+0h] [ebp-Ch]

  v3 = (const stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)__x;
  if ( __x == a2 )
    return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
  v4 = *(void ***)(__x + 4);
  v5 = *(stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > **)__x;
  v6 = *(unsigned __int8 **)a2;
  v7 = ((int)v4 - *(_DWORD *)__x) >> 2;
  if ( v7 > (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) >> 2 )
  {
    __x = (*(_DWORD *)(__x + 4) - *(_DWORD *)__x) >> 2;
    v8 = stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_allocate_and_copy<void * const *>(
           v5,
           &__x,
           v19,
           v4);
    v9 = *(unsigned __int8 **)a2;
    if ( *(_DWORD *)a2 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
    }
    v11 = &v8[__x];
    *(_DWORD *)(a2 + 4) = &v8[v7];
    *(_DWORD *)a2 = v8;
    *(_DWORD *)(a2 + 8) = v11;
    return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
  }
  v13 = (*(_DWORD *)(a2 + 4) - (int)v6) >> 2;
  if ( v13 < v7 )
  {
    if ( 4 * v13 )
      memmove(v6, (unsigned __int8 *)v5, 4 * v13);
    M_finish = (unsigned __int8 *)v3->_M_finish;
    v18 = (unsigned __int8 *)&v3->_M_start[(*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) >> 2];
    if ( M_finish != v18 )
      memcpy(*(unsigned __int8 **)(a2 + 4), v18, M_finish - v18);
    *(_DWORD *)(a2 + 4) = *(_DWORD *)a2 + 4 * v7;
    return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
  }
  v14 = (char *)v4 - (char *)v5;
  v15 = v14;
  if ( v14 )
  {
    memmove(v6, (unsigned __int8 *)v5, v14);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>((void **)(v15 + v16), *(void ***)(a2 + 4));
  }
  else
  {
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>((void **)v6, *(void ***)(a2 + 4));
  }
  *(_DWORD *)(a2 + 4) = *(_DWORD *)a2 + 4 * v7;
  return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
}


stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__thiscall stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *this,
        const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__x,
        const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__xa)
{
  unsigned __int8 *M_finish; // ebp
  unsigned __int8 *M_start; // esi
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  vostok::render::streaming_texture_instance *v7; // ecx
  vostok::render::streaming_texture_instance *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int8 *v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ebp
  unsigned int v14; // eax
  unsigned __int8 *v15; // esi
  unsigned __int8 *v16; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v17; // [esp+0h] [ebp-10h]
  const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__xb; // [esp+18h] [ebp+8h]

  if ( __xa == __x )
    return (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__x;
  M_finish = (unsigned __int8 *)__xa->_M_finish;
  M_start = (unsigned __int8 *)__xa->_M_start;
  v5 = (M_finish - (unsigned __int8 *)__xa->_M_start) / 24;
  if ( v5 <= __x->_M_end_of_storage._M_data - __x->_M_start )
  {
    v11 = (unsigned __int8 *)__x->_M_start;
    v12 = __x->_M_finish - __x->_M_start;
    if ( v12 < v5 )
    {
      v14 = 24 * v12;
      if ( v14 )
        memmove(v11, M_start, v14);
      v15 = (unsigned __int8 *)__xa->_M_finish;
      v16 = (unsigned __int8 *)&__xa->_M_start[__x->_M_finish - __x->_M_start];
      if ( v15 != v16 )
        memcpy((unsigned __int8 *)__x->_M_finish, v16, v15 - v16);
    }
    else
    {
      v13 = M_finish - M_start;
      if ( v13 )
        memmove(v11, M_start, v13);
    }
    __x->_M_finish = &__x->_M_start[v5];
    return (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__x;
  }
  v6 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                            v5,
                            v17);
  v7 = (vostok::render::streaming_texture_instance *)v6;
  __xb = (const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)v6;
  if ( M_finish != M_start )
  {
    memcpy(v6, M_start, M_finish - M_start);
    v7 = (vostok::render::streaming_texture_instance *)__xb;
  }
  v8 = __x->_M_start;
  if ( __x->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
    v7 = (vostok::render::streaming_texture_instance *)__xb;
  }
  __x->_M_end_of_storage._M_data = &v7[v5];
  __x->_M_start = v7;
  __x->_M_finish = &v7[v5];
  return (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__x;
}


stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *__thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *__x)
{
  vostok::ai::planning::pddl_world_state_property_impl *__val; // [esp+10h] [ebp-D8h]
  int i; // [esp+38h] [ebp-B0h]
  vostok::ai::planning::pddl_world_state_property_impl *__p; // [esp+3Ch] [ebp-ACh]
  stlp_std::random_access_iterator_tag v7; // [esp+63h] [ebp-85h] BYREF
  vostok::ai::planning::pddl_world_state_property_impl *M_finish; // [esp+64h] [ebp-84h]
  vostok::ai::planning::pddl_world_state_property_impl *__last; // [esp+B0h] [ebp-38h]
  vostok::ai::planning::pddl_world_state_property_impl *__first; // [esp+B4h] [ebp-34h]
  vostok::ai::planning::pddl_world_state_property_impl *__result; // [esp+D0h] [ebp-18h]
  char v12; // [esp+D5h] [ebp-13h]
  char v13; // [esp+D6h] [ebp-12h]
  stlp_std::__false_type __formal; // [esp+D7h] [ebp-11h] BYREF
  vostok::ai::planning::pddl_world_state_property_impl *__i; // [esp+D8h] [ebp-10h]
  vostok::ai::planning::pddl_world_state_property_impl *__tmp; // [esp+DCh] [ebp-Ch]
  unsigned int __len; // [esp+E0h] [ebp-8h] BYREF
  unsigned int __xlen; // [esp+E4h] [ebp-4h]

  if ( __x != this )
  {
    __xlen = __x->_M_finish - __x->_M_start;
    if ( __xlen <= this->_M_end_of_storage._M_data - this->_M_start )
    {
      if ( this->_M_finish - this->_M_start < __xlen )
      {
        v13 = 0;
        stlp_std::priv::__copy<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *,int>(
          __x->_M_start,
          &__x->_M_start[this->_M_finish - this->_M_start],
          this->_M_start,
          &v7,
          0);
        v12 = 0;
        __val = &__x->_M_start[this->_M_finish - this->_M_start];
        __p = this->_M_finish;
        for ( i = __x->_M_finish - __val; i > 0; --i )
          stlp_std::_Param_Construct<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::planning::pddl_world_state_property_impl>(
            __p++,
            __val++);
      }
      else
      {
        __formal = 0;
        __i = stlp_std::priv::__copy_ptrs<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
                __x->_M_start,
                __x->_M_finish,
                this->_M_start,
                &__formal);
        M_finish = this->_M_finish;
        stlp_std::__destroy_range<vostok::ai::planning::pddl_world_state_property_impl *,vostok::ai::planning::pddl_world_state_property_impl>(
          __i,
          M_finish,
          0);
      }
    }
    else
    {
      __len = __xlen;
      __last = __x->_M_finish;
      __first = __x->_M_start;
      __result = stlp_std::priv::_STLP_alloc_proxy<vostok::ai::planning::pddl_world_state_property_impl *,vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::allocate(
                   &this->_M_end_of_storage,
                   __xlen,
                   &__len);
      stlp_std::uninitialized_copy<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
        __first,
        __last,
        __result);
      __tmp = __result;
      stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_M_clear_after_move(this);
      this->_M_start = __result;
      this->_M_end_of_storage._M_data = &this->_M_start[__len];
    }
    this->_M_finish = &this->_M_start[__xlen];
  }
  return this;
}


stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__thiscall stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *this,
        const stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__x,
        const stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__xa)
{
  vostok::render::shader_constant *M_start; // esi
  vostok::render::shader_constant *v5; // ecx
  unsigned int v6; // edi
  vostok::render::shader_constant *v7; // ebp
  vostok::render::shader_constant *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v11; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v12; // [esp+0h] [ebp-10h]
  const vostok::render::shader_constant *__xb; // [esp+18h] [ebp+8h]

  if ( __xa == __x )
    return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
  M_start = __xa->_M_start;
  __xb = __xa->_M_finish;
  v5 = __x->_M_start;
  v6 = __xb - M_start;
  if ( v6 <= __x->_M_end_of_storage._M_data - __x->_M_start )
  {
    v11 = __x->_M_finish - v5;
    if ( v11 >= v6 )
    {
      stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
        __xb,
        v5,
        M_start);
      __x->_M_finish = &__x->_M_start[v6];
      return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
    }
    stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
      &M_start[v11],
      v5,
      M_start);
    stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
      __xa->_M_finish,
      __x->_M_finish,
      &__xa->_M_start[__x->_M_finish - __x->_M_start]);
    __x->_M_finish = &__x->_M_start[v6];
    return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
  }
  v7 = (vostok::render::shader_constant *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                                            __xb - M_start,
                                            v12);
  stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
    __xb,
    v7,
    M_start);
  v8 = __x->_M_start;
  if ( __x->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
  }
  __x->_M_end_of_storage._M_data = &v7[v6];
  __x->_M_start = v7;
  __x->_M_finish = &v7[v6];
  return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
}


stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *__thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *__x)
{
  vostok::ai::planning::world_state_property *__last; // [esp+68h] [ebp-38h]
  vostok::ai::planning::world_state_property *__first; // [esp+6Ch] [ebp-34h]
  vostok::ai::planning::world_state_property *__result; // [esp+88h] [ebp-18h]
  unsigned int __len; // [esp+98h] [ebp-8h] BYREF
  unsigned int __xlen; // [esp+9Ch] [ebp-4h]

  if ( __x != this )
  {
    __xlen = __x->_M_finish - __x->_M_start;
    if ( __xlen <= this->_M_end_of_storage._M_data - this->_M_start )
    {
      if ( this->_M_finish - this->_M_start < __xlen )
      {
        stlp_std::priv::__copy_trivial(
          (unsigned __int8 *)__x->_M_start,
          (unsigned __int8 *)&__x->_M_start[this->_M_finish - this->_M_start],
          (unsigned __int8 *)this->_M_start);
        stlp_std::priv::__ucopy_trivial(
          (unsigned __int8 *)&__x->_M_start[this->_M_finish - this->_M_start],
          (unsigned __int8 *)__x->_M_finish,
          (unsigned __int8 *)this->_M_finish);
      }
      else
      {
        stlp_std::priv::__copy_trivial(
          (unsigned __int8 *)__x->_M_start,
          (unsigned __int8 *)__x->_M_finish,
          (unsigned __int8 *)this->_M_start);
      }
    }
    else
    {
      __len = __xlen;
      __last = __x->_M_finish;
      __first = __x->_M_start;
      __result = stlp_std::priv::_STLP_alloc_proxy<vostok::ai::planning::world_state_property *,vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::allocate(
                   &this->_M_end_of_storage,
                   __xlen,
                   &__len);
      stlp_std::uninitialized_copy<void * *,void * *>(__first, __last, __result);
      stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_M_clear(this);
      this->_M_start = __result;
      this->_M_end_of_storage._M_data = &this->_M_start[__len];
    }
    this->_M_finish = &this->_M_start[__xlen];
  }
  return this;
}


unsigned int *__usercall stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[]@<eax>(
        vostok::buffer_vector<unsigned int> *this@<eax>,
        unsigned int index@<edx>)
{
  return &this->m_begin[index];
}
