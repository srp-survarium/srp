stlp_std::priv::_Rb_tree_node_base *__userpurge vostok::render::resource_manager::find_texture@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        const char *name)
{
  stlp_std::priv::_Rb_tree_node_base *v3; // esi
  stlp_std::priv::_Rb_tree_node_base *v4; // eax

  v3 = (stlp_std::priv::_Rb_tree_node_base *)(a2 + 557220);
  v4 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
         (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)this,
         (const char *const *)(a2 + 557220),
         &name);
  if ( v4 == v3 )
    return 0;
  else
    return v4[18]._M_parent;
}
