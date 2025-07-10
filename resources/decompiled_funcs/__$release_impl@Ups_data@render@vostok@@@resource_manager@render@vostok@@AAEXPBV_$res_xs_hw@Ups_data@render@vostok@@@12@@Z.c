void __usercall vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::ps_data> *xs_hw@<eax>)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  vostok::render::map<vostok::render::resource_manager::shader_name_config_pair,vostok::render::res_xs_hw<vostok::render::ps_data> *,stlp_std::less<vostok::render::resource_manager::shader_name_config_pair> > *p_m_ps_hw_registry; // edi
  vostok::render::grass_render_model *m_object; // edi
  int v6; // [esp-4h] [ebp-10h] BYREF

  if ( xs_hw->m_is_registered )
  {
    M_left = this->m_ps_hw_registry._M_t._M_header._M_data._M_left;
    p_m_ps_hw_registry = &this->m_ps_hw_registry;
    while ( M_left != (stlp_std::priv::_Rb_tree_node_base *)p_m_ps_hw_registry )
    {
      if ( (vostok::render::res_xs_hw<vostok::render::ps_data> *)M_left[2]._M_left == xs_hw )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v6,
          (int)p_m_ps_hw_registry,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)M_left);
        break;
      }
      M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
    }
    m_object = vostok::render::g_allocator.m_object;
    vostok::render::res_xs_hw<vostok::render::ps_data>::~res_xs_hw<vostok::render::ps_data>((vostok::render::res_xs_hw<vostok::render::ps_data> *)this);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), xs_hw);
  }
}
