void __usercall vostok::render::resource_manager::release_impl(
        vostok::render::resource_manager *this@<eax>,
        vostok::render::res_texture *texture@<edi>,
        unsigned int a3@<ecx>,
        const char *a4@<ebx>,
        const char *a5@<esi>)
{
  vostok::render::texture_storage *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // ebx
  vostok::memory::doug_lea_allocator *v8; // ecx

  v5 = *(vostok::render::texture_storage **)((char *)&this->sh_created + (_DWORD)&loc_948DA + 2);
  if ( v5 )
    vostok::render::texture_storage::try_release(v5, texture->m_surface);
  v6 = vostok::render::g_allocator;
  if ( texture )
  {
    v7 = __RTCastToVoid((void **)&texture->__vftable);
    ((void (__thiscall *)(vostok::render::res_texture *, _DWORD))texture->~vostok::render::res_texture)(texture, 0);
    vostok::memory::doug_lea_allocator::free_impl(v8, (int)v6, v7, a5, a4, a3);
  }
}


void __userpurge vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        const vostok::render::res_xs_hw<vostok::render::gs_data> *xs_hw)
{
  const vostok::render::res_xs_hw<vostok::render::gs_data> *v3; // ebx
  int v4; // edi
  stlp_std::priv::_Rb_tree_node_base **v5; // esi
  stlp_std::priv::_Rb_tree_node_base *i; // eax
  stlp_std::priv::_Rb_tree_node_base *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  const char *v9; // [esp+0h] [ebp-10h]
  const char *v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]
  const vostok::render::resource_manager_call_destructor_predicate *v12; // [esp+Ch] [ebp-4h]

  v3 = xs_hw;
  if ( xs_hw->m_is_registered )
  {
    v4 = a2 + 557148;
    v5 = (stlp_std::priv::_Rb_tree_node_base **)(a2 + 557156);
    for ( i = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 557156);
          i != (stlp_std::priv::_Rb_tree_node_base *)v4;
          i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
    {
      if ( (const vostok::render::res_xs_hw<vostok::render::gs_data> *)i[2]._M_left == v3 )
      {
        v7 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
               i,
               (stlp_std::priv::_Rb_tree_node_base **)(v4 + 4),
               v5,
               (stlp_std::priv::_Rb_tree_node_base **)(v4 + 12));
        vostok::memory::doug_lea_allocator::free_impl(
          v8,
          (int)vostok::render::g_allocator,
          (char *)&v7->_M_color,
          v9,
          v10,
          v11);
        --*(_DWORD *)(v4 + 16);
        break;
      }
    }
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::res_xs_hw<vostok::render::gs_data> const,vostok::render::resource_manager_call_destructor_predicate>(
      vostok::render::g_allocator,
      &xs_hw,
      v9,
      v10,
      v11,
      v12);
  }
}


void __userpurge vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_xs_hw<vostok::render::gs_data> *xs_hw)
{
  vostok::render::res_xs_hw<vostok::render::gs_data> *v3; // ebx
  int v4; // edi
  stlp_std::priv::_Rb_tree_node_base **v5; // esi
  stlp_std::priv::_Rb_tree_node_base *i; // eax
  stlp_std::priv::_Rb_tree_node_base *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  const char *v9; // [esp+0h] [ebp-10h]
  const char *v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]
  const vostok::render::resource_manager_call_destructor_predicate *v12; // [esp+Ch] [ebp-4h]

  v3 = xs_hw;
  if ( xs_hw->m_is_registered )
  {
    v4 = a2 + 557172;
    v5 = (stlp_std::priv::_Rb_tree_node_base **)(a2 + 557180);
    for ( i = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 557180);
          i != (stlp_std::priv::_Rb_tree_node_base *)v4;
          i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
    {
      if ( (vostok::render::res_xs_hw<vostok::render::gs_data> *)i[2]._M_left == v3 )
      {
        v7 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
               i,
               (stlp_std::priv::_Rb_tree_node_base **)(v4 + 4),
               v5,
               (stlp_std::priv::_Rb_tree_node_base **)(v4 + 12));
        vostok::memory::doug_lea_allocator::free_impl(
          v8,
          (int)vostok::render::g_allocator,
          (char *)&v7->_M_color,
          v9,
          v10,
          v11);
        --*(_DWORD *)(v4 + 16);
        break;
      }
    }
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::res_xs_hw<vostok::render::gs_data> const,vostok::render::resource_manager_call_destructor_predicate>(
      vostok::render::g_allocator,
      (const vostok::render::res_xs_hw<vostok::render::gs_data> **)&xs_hw,
      v9,
      v10,
      v11,
      v12);
  }
}


void __userpurge vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        const vostok::render::res_xs_hw<vostok::render::vs_data> *xs_hw)
{
  const vostok::render::res_xs_hw<vostok::render::vs_data> *v3; // ebx
  int v4; // edi
  stlp_std::priv::_Rb_tree_node_base **v5; // esi
  stlp_std::priv::_Rb_tree_node_base *i; // eax
  stlp_std::priv::_Rb_tree_node_base *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  const char *v9; // [esp+0h] [ebp-10h]
  const char *v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]
  const vostok::render::resource_manager_call_destructor_predicate *v12; // [esp+Ch] [ebp-4h]

  v3 = xs_hw;
  if ( xs_hw->m_is_registered )
  {
    v4 = a2 + 557124;
    v5 = (stlp_std::priv::_Rb_tree_node_base **)(a2 + 557132);
    for ( i = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 557132);
          i != (stlp_std::priv::_Rb_tree_node_base *)v4;
          i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
    {
      if ( (const vostok::render::res_xs_hw<vostok::render::vs_data> *)i[2]._M_left == v3 )
      {
        v7 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
               i,
               (stlp_std::priv::_Rb_tree_node_base **)(v4 + 4),
               v5,
               (stlp_std::priv::_Rb_tree_node_base **)(v4 + 12));
        vostok::memory::doug_lea_allocator::free_impl(
          v8,
          (int)vostok::render::g_allocator,
          (char *)&v7->_M_color,
          v9,
          v10,
          v11);
        --*(_DWORD *)(v4 + 16);
        break;
      }
    }
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::res_xs_hw<vostok::render::vs_data> const,vostok::render::resource_manager_call_destructor_predicate>(
      vostok::render::g_allocator,
      &xs_hw,
      v9,
      v10,
      v11,
      v12);
  }
}
