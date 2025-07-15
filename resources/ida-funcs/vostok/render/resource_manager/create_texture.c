stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::render::resource_manager::create_texture(
        vostok::render::resource_manager *this,
        char *physical_name,
        vostok::resources::query_result_for_cook *parent,
        vostok::render::resource_manager *mip_level_cut,
        vostok::render::resource_manager *use_pool,
        bool load_async,
        bool use_converter,
        unsigned int num_last_mips_used)
{
  vostok::render::resource_manager *v8; // ebx
  char *v9; // eax
  bool v10; // cf
  unsigned __int8 v11; // dl
  stlp_std::priv::_Rb_tree_node_base *result; // eax
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v13; // eax
  char *v14; // [esp+Ch] [ebp-4h] BYREF

  v8 = this;
  if ( !physical_name )
    goto LABEL_10;
  this = (vostok::render::resource_manager *)&stru_96A440.m_projection.lines[0].elements[1];
  v9 = physical_name;
  while ( 1 )
  {
    v10 = (unsigned __int8)*v9 < LOBYTE(this->sh_created);
    if ( *v9 != LOBYTE(this->sh_created) )
      break;
    if ( !*v9 )
      goto LABEL_7;
    v11 = v9[1];
    v10 = v11 < BYTE1(this->sh_created);
    if ( v11 != BYTE1(this->sh_created) )
      break;
    v9 += 2;
    this = (vostok::render::resource_manager *)((char *)this + 2);
    if ( !v11 )
    {
LABEL_7:
      result = 0;
      goto LABEL_9;
    }
  }
  result = (stlp_std::priv::_Rb_tree_node_base *)(-v10 - (v10 - 1));
LABEL_9:
  if ( result )
  {
LABEL_10:
    v14 = physical_name;
    v13 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
            (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)this,
            &v8->m_texture_registry._M_t,
            (const char **)&v14);
    if ( v13 == (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&v8->m_texture_registry )
      return vostok::render::resource_manager::load_texture(
               use_pool,
               v8,
               (vostok::resources::query_result_for_cook *)physical_name,
               parent,
               mip_level_cut,
               (bool)use_pool,
               load_async,
               use_converter,
               num_last_mips_used);
    result = v13[12]._M_header._M_data._M_parent;
    if ( !result )
      return vostok::render::resource_manager::load_texture(
               use_pool,
               v8,
               (vostok::resources::query_result_for_cook *)physical_name,
               parent,
               mip_level_cut,
               (bool)use_pool,
               load_async,
               use_converter,
               num_last_mips_used);
  }
  return result;
}
