void __cdecl vostok::buffer_vector<void const *>::destroy(const void **begin, const void **const *end)
{
  while ( begin != *end )
    ++begin;
}


void __usercall vostok::buffer_vector<vostok::apc::callback>::destroy(
        vostok::apc::callback *begin@<eax>,
        vostok::apc::callback **end)
{
  vostok::apc::callback *v2; // esi
  boost::detail::function::function_buffer *p_functor; // edi
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  v2 = begin;
  if ( begin != *end )
  {
    p_functor = &begin->m_callback.functor;
    do
    {
      vtable = v2->m_callback.vtable;
      if ( v2->m_callback.vtable )
      {
        if ( ((unsigned __int8)vtable & 1) == 0 )
        {
          v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
          if ( v5 )
            v5(p_functor, p_functor, 2);
        }
        v2->m_callback.vtable = 0;
      }
      ++v2;
      p_functor += 2;
    }
    while ( v2 != *end );
  }
}


void __cdecl vostok::buffer_vector<vostok::ai::planning::plan_item>::destroy(vostok::ai::planning::plan_item *p)
{
  const void **i; // [esp+4h] [ebp-4h]

  for ( i = p->parameters.m_begin; i != p->parameters.m_end; ++i )
    ;
  p->parameters.m_end = p->parameters.m_begin;
}


void __cdecl vostok::buffer_vector<vostok::render::texture_slot>::destroy(
        vostok::render::texture_slot *begin,
        vostok::render::texture_slot *const *end)
{
  vostok::render::texture_slot *v2; // ebx
  vostok::render::texture_slot *const *i; // ebp
  vostok::render::res_texture *m_object; // eax
  const vostok::render::res_texture *v6; // esi
  survarium::options_tab *v7; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v8; // eax
  _BYTE v9[20]; // [esp-4h] [ebp-14h] BYREF

  v2 = begin;
  for ( i = end; v2 != *i; ++v2 )
  {
    m_object = v2->texture.m_object;
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v6 = v2->texture.m_object;
        if ( v6->m_is_registered )
        {
          v7 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          end = (vostok::render::texture_slot *const *)v6->m_name.m_string.m_begin;
          v8 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                 (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&end,
                 (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                 (const char **)&end);
          if ( v8 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v7 )
          {
            stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
              (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)v9,
              (int)v7,
              (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v8);
            vostok::render::resource_manager::release_impl(*(vostok::render::resource_manager **)&v9[4], v6);
          }
        }
      }
    }
  }
}


void __cdecl vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
        vostok::tasks::thread_tls *begin,
        vostok::tasks::thread_tls **end)
{
  vostok::tasks::thread_tls *v2; // ebp
  boost::detail::function::function_buffer *p_functor; // esi
  unsigned int obj_ptr; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  v2 = begin;
  if ( begin != *end )
  {
    p_functor = &begin->user_thread_root_task.m_function.functor;
    do
    {
      CloseHandle(p_functor[2].bound_memfunc_ptr.obj_ptr);
      CloseHandle(p_functor[2].vostok_pointer_size_alignment[2]);
      CloseHandle(p_functor[2].obj_ptr);
      obj_ptr = (unsigned int)p_functor[-1].bound_memfunc_ptr.obj_ptr;
      if ( obj_ptr )
      {
        if ( (obj_ptr & 1) == 0 )
        {
          v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))(obj_ptr & 0xFFFFFFFE);
          if ( v5 )
            v5(p_functor, p_functor, 2);
        }
        p_functor[-1].bound_memfunc_ptr.obj_ptr = 0;
      }
      CloseHandle(p_functor[-6].bound_memfunc_ptr.obj_ptr);
      ++v2;
      p_functor += 15;
    }
    while ( v2 != *end );
  }
}


void __usercall vostok::buffer_vector<vostok::variant<32>>::destroy(
        vostok::variant<32> *begin@<eax>,
        vostok::variant<32> **end@<edi>)
{
  vostok::variant<32> *i; // esi
  vostok::detail::abstract_type_helper *m_helper; // ecx

  for ( i = begin; i != *end; ++i )
  {
    m_helper = i->m_helper;
    if ( m_helper )
    {
      m_helper->destroy(m_helper, i->m_storage);
      i->m_helper = 0;
    }
  }
}


void __usercall vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::destroy(
        vostok::render::vector<vostok::math::frustum> *begin@<eax>,
        vostok::render::vector<vostok::math::frustum> **end)
{
  vostok::render::vector<vostok::math::frustum> *i; // edi
  vostok::math::frustum *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  for ( i = begin; i != *end; ++i )
  {
    M_start = i->_M_impl._M_start;
    if ( i->_M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
    }
  }
}
