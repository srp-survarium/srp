vostok::render::render_target *__userpurge vostok::render::resource_manager::create_volume_render_target@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::resource_manager *name,
        unsigned int w,
        unsigned int h,
        unsigned int d,
        DXGI_FORMAT fmt,
        vostok::render::enum_rt_usage usage,
        D3D11_USAGE memory_usage)
{
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *p_M_t; // ebp
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v9; // eax
  vostok::render::render_target *v11; // eax
  vostok::render::render_target *v12; // edi
  volatile signed __int32 *p_m_reference_count; // eax
  vostok::strings::shared::manager *m_object; // esi
  char *v15; // eax
  vostok::render::enum_rt_usage v16; // [esp+0h] [ebp-140h]
  D3D11_USAGE v17; // [esp+4h] [ebp-13Ch]
  const char *namea; // [esp+14h] [ebp-12Ch] BYREF
  char *other; // [esp+18h] [ebp-128h] BYREF
  vostok::render::render_target *v20; // [esp+1Ch] [ebp-124h]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >,bool> v21; // [esp+20h] [ebp-120h] BYREF
  stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> v22; // [esp+28h] [ebp-118h] BYREF

  p_M_t = &name->m_rt_registry._M_t;
  namea = 0;
  v9 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
         (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)this,
         (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&name->m_rt_registry,
         &namea);
  if ( namea
    && v9 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)p_M_t )
  {
    return (vostok::render::render_target *)v9[12]._M_header._M_data._M_parent;
  }
  v11 = (vostok::render::render_target *)vostok::memory::doug_lea_allocator::malloc_impl(
                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                           0x40u);
  if ( v11 )
  {
    v11->m_reference_count = 0;
    v11->m_name.m_pointer.m_object = 0;
    v11->m_texture.m_object = 0;
    v11->m_is_registered = 0;
    v11->m_memory_usage = 0;
    v11->m_surface_3d = 0;
    v11->m_surface = 0;
    v11->m_rt = 0;
    v11->m_width = 0;
    v11->m_height = 0;
    v11->m_format = DXGI_FORMAT_UNKNOWN;
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  vostok::render::render_target::set_name(v12);
  v12->m_is_registered = 1;
  p_m_reference_count = &v12->m_name.m_pointer.m_object->m_reference_count;
  m_object = 0;
  if ( p_m_reference_count
    && (m_object = (vostok::strings::shared::manager *)v12->m_name.m_pointer.m_object,
        _InterlockedExchangeAdd(p_m_reference_count, 1u),
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
  {
    v15 = (char *)&m_object->m_mutex.m_mutex.m_mutex[2];
  }
  else
  {
    v15 = 0;
  }
  other = v15;
  v20 = v12;
  vostok::fs_new::virtual_path_string::virtual_path_string(
    (vostok::fs_new::virtual_path_string *)&v22.first,
    (const char **)&other);
  v22.second = v20;
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *>>>::insert_unique(
    &v22,
    p_M_t,
    &v21);
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)m_object, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(m_object, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::render::render_target::create_3d(w, h, v12, namea, d, fmt, v16, v17);
  return v12;
}
