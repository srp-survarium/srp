void __thiscall vostok::render::resource_manager::reload_modified_textures(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *thisa)
{
  vostok::fs_new::virtual_path_string *M_start; // eax
  vostok::fs_new::virtual_path_string *v3; // edi
  char *m_end; // esi
  unsigned __int8 *m_begin; // eax
  unsigned int v6; // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::effect_cook,vostok::resources::query_result_for_cook *,vostok::render::res_effect *,vostok::render::effect_compile_data *,vostok::resources::queries_result &>,boost::_bi::list5<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::res_effect *>,boost::_bi::value<vostok::render::effect_compile_data *>,boost::arg<1> > > v9; // [esp-10h] [ebp-2A8h]
  vostok::variant<32> *user_data; // [esp+Ch] [ebp-28Ch] BYREF
  vostok::render::vector<vostok::fs_new::virtual_path_string> textures_to_reload; // [esp+10h] [ebp-288h] BYREF
  __int64 v12; // [esp+1Ch] [ebp-27Ch]
  __int64 v13; // [esp+24h] [ebp-274h]
  vostok::resources::request requests; // [esp+2Ch] [ebp-26Ch] BYREF
  void (__thiscall *v15)(vostok::render::resource_manager *, vostok::resources::queries_result *, unsigned int, bool, vostok::resources::managed_resource *); // [esp+34h] [ebp-264h]
  __int128 v16; // [esp+38h] [ebp-260h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+48h] [ebp-250h] BYREF
  vostok::fs_new::virtual_path_string path_add; // [esp+68h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+180h] [ebp-118h] BYREF

  stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>(
    (stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *)this,
    &textures_to_reload._M_impl._M_start,
    &thisa->m_textures_to_reload._M_impl);
  M_start = textures_to_reload._M_impl._M_start;
  v3 = textures_to_reload._M_impl._M_start;
  if ( textures_to_reload._M_impl._M_start != textures_to_reload._M_impl._M_finish )
  {
    do
    {
      m_end = v3->m_string.m_end;
      path.m_string.m_max_end = &path.m_separator;
      path_add.m_string.m_max_end = &path_add.m_separator;
      m_begin = (unsigned __int8 *)v3->m_string.m_begin;
      v6 = m_end - v3->m_string.m_begin;
      path.m_string.m_begin = path.m_string.m_buffer;
      path.m_string.m_end = path.m_string.m_buffer;
      path.m_string.m_buffer[0] = 0;
      path.m_separator = 47;
      path_add.m_string.m_begin = path_add.m_string.m_buffer;
      path_add.m_string.m_end = path_add.m_string.m_buffer;
      memcpy((unsigned __int8 *)path_add.m_string.m_buffer, m_begin, v6);
      path_add.m_string.m_end += v6;
      *path_add.m_string.m_end = 0;
      path_add.m_separator = 47;
      vostok::fs_new::path_string_impl::assignf(&path, "%s/%s.dds", "resources/textures", path_add.m_string.m_begin);
      v12 = (unsigned int)thisa;
      *(_QWORD *)&v16 = (unsigned int)thisa;
      LOBYTE(v13) = 1;
      HIDWORD(v13) = -1;
      *((_QWORD *)&v16 + 1) = v13;
      v15 = vostok::render::resource_manager::on_texture_loaded;
      v9.f_.f_ = (void (__thiscall *)(vostok::render::effect_cook *, vostok::resources::query_result_for_cook *, vostok::render::res_effect *, vostok::render::effect_compile_data *, vostok::resources::queries_result *))thisa;
      v9.l_.boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > = *(boost::_bi::storage2<boost::_bi::value<vostok::render::effect_cook *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > *)((char *)&v16 + 4);
      callback.vtable = 0;
      v9.l_.a3_.t_ = (vostok::render::res_effect *)-1;
      if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state>,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_state_cook_template<survarium::double_barreled_weapon_core_aimed_idle_state> *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>(
             &callback.functor,
             (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::resource_manager::on_texture_loaded,
             v9) )
      {
        callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int>,boost::_bi::list5<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<int>,boost::_bi::value<bool>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable
                                                                 + 1);
      }
      else
      {
        callback.vtable = 0;
      }
      requests.path = path.m_string.m_begin;
      requests.id = texture_wrapper_class;
      user_data = 0;
      vostok::resources::query_resources(
        &requests,
        1u,
        &callback,
        (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
        (const vostok::variant<32> **)&user_data,
        0,
        assert_on_fail_true);
      if ( callback.vtable )
      {
        if ( ((int)callback.vtable & 1) == 0 )
        {
          v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
          if ( v7 )
            v7(&callback.functor, &callback.functor, 2);
        }
      }
      ++v3;
    }
    while ( v3 != textures_to_reload._M_impl._M_finish );
    M_start = textures_to_reload._M_impl._M_start;
  }
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
}
