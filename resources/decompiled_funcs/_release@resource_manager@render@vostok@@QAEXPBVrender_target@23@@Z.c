void __thiscall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *rt,
        const char *name)
{
  char *v3; // ebp
  volatile signed __int32 *v4; // ecx
  int v5; // eax
  const vostok::render::render_target *v6; // eax
  vostok::render::grass_render_model *m_object; // esi
  vostok::render::render_target *v8; // ecx
  int v9; // [esp-4h] [ebp-10h] BYREF

  v3 = (char *)name;
  if ( name[56] )
  {
    v4 = (volatile signed __int32 *)*((_DWORD *)name + 1);
    v5 = 0;
    if ( v4
      && (v5 = *((_DWORD *)name + 1),
          _InterlockedExchangeAdd(v4, 1u),
          vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
    {
      name = (const char *)(v5 + 16);
    }
    else
    {
      name = 0;
    }
    if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)v5, 0xFFFFFFFF) )
    {
      v9 = v5;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v5,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
    v6 = (const vostok::render::render_target *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                                                  (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&name,
                                                  (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&rt->m_rt_registry,
                                                  &name);
    if ( v6 != (const vostok::render::render_target *)&rt->m_rt_registry )
    {
      stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
        (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v9,
        (int)&rt->m_rt_registry,
        (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v6);
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::render_target::~render_target(v8, v3);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v3);
    }
  }
}
