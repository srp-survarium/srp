void __thiscall vostok::render::skeleton_combined_model_cook::translate_query(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::render::skeleton_combined_model_cook *v4; // ecx
  char *m_requery_path; // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v7; // [esp-8h] [ebp-160h]
  vostok::render::skeleton_combined_cook_data *cook_data; // [esp+10h] [ebp-148h] BYREF
  vostok::resources::request requests; // [esp+14h] [ebp-144h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string config_path; // [esp+40h] [ebp-118h] BYREF

  m_user_data = parent->m_user_data;
  if ( m_user_data
    && (cook_data = 0,
        vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>(
          (vostok::variant<32> *)this,
          (int)m_user_data,
          &cook_data),
        cook_data) )
  {
    vostok::render::skeleton_combined_model_cook::query_resources_by_data(v4, this, parent, cook_data);
  }
  else
  {
    config_path.m_string.m_max_end = &config_path.m_separator;
    m_requery_path = parent->m_requery_path;
    config_path.m_string.m_begin = config_path.m_string.m_buffer;
    config_path.m_string.m_end = config_path.m_string.m_buffer;
    config_path.m_string.m_buffer[0] = 0;
    config_path.m_separator = 47;
    if ( !m_requery_path )
      m_requery_path = parent->m_request_path;
    vostok::fs_new::path_string_impl::assignf(&config_path, "resources/models/%s.combined_skin", m_requery_path);
    requests.id = (vostok::resources::class_id_enum)this;
    requests.path = (const char *)vostok::render::skeleton_combined_model_cook::on_config_loaded;
    v7.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))this;
    callback.vtable = 0;
    v7.l_.a1_.t_ = (survarium::animated_model_instance_cook *)parent;
    if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
           &callback.functor,
           (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::skeleton_combined_model_cook::on_config_loaded,
           v7) )
    {
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    else
    {
      callback.vtable = 0;
    }
    requests.path = config_path.m_string.m_begin;
    requests.id = binary_config_class_impl;
    cook_data = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      &callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)&cook_data,
      parent,
      assert_on_fail_true);
    if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&callback.functor, &callback.functor, 2);
    }
  }
}
