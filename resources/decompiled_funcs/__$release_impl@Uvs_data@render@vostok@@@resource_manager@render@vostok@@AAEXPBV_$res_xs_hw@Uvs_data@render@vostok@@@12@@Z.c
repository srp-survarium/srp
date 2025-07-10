void __userpurge vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        const vostok::render::res_xs_hw<vostok::render::vs_data> *xs_hw)
{
  const vostok::render::res_xs_hw<vostok::render::vs_data> *v3; // esi
  stlp_std::priv::_Rb_tree_node_base *v5; // eax
  int v6; // edi
  int v7; // [esp-4h] [ebp-Ch] BYREF
  const vostok::render::resource_manager_call_destructor_predicate *v8; // [esp+0h] [ebp-8h]

  v3 = xs_hw;
  if ( xs_hw->m_is_registered )
  {
    v5 = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 52);
    v6 = a2 + 44;
    while ( 1 )
    {
      if ( v5 == (stlp_std::priv::_Rb_tree_node_base *)v6 )
      {
        vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::res_xs_hw<vostok::render::vs_data> const,vostok::render::resource_manager_call_destructor_predicate>(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          &xs_hw,
          v8);
        return;
      }
      if ( (const vostok::render::res_xs_hw<vostok::render::vs_data> *)v5[2]._M_left == v3 )
        break;
      v5 = stlp_std::priv::_Rb_global<bool>::_M_increment(v5);
    }
    stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
      (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v7,
      v6,
      (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v5);
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::res_xs_hw<vostok::render::vs_data> const,vostok::render::resource_manager_call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
      &xs_hw,
      v8);
  }
}
