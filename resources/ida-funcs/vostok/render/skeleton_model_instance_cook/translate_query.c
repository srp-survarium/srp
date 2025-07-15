void __thiscall vostok::render::skeleton_model_instance_cook::translate_query(
        vostok::render::skeleton_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::render::skeleton_model_instance_cook_data *v3; // eax
  char *m_requery_path; // eax
  char *m_request_path; // eax
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v8; // [esp-8h] [ebp-280h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v9; // [esp-8h] [ebp-280h]
  vostok::resources::request requests; // [esp+Ch] [ebp-26Ch] BYREF
  vostok::render::skeleton_model_instance_cook_data *cook_data; // [esp+18h] [ebp-260h]
  vostok::variant<32> *v12; // [esp+1Ch] [ebp-25Ch] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-258h] BYREF
  vostok::variant<32> *user_data; // [esp+44h] [ebp-234h] BYREF
  vostok::fs_new::virtual_path_string skeleton_config_path; // [esp+48h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string render_model_path; // [esp+160h] [ebp-118h] BYREF

  v12 = (vostok::variant<32> *)this;
  v3 = (vostok::render::skeleton_model_instance_cook_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                              0x10u);
  if ( v3 )
  {
    v3->render_model_ready = 0;
    v3->skeleton_ready = 0;
    v3->parent_query = parent;
    v3->render_model.m_object = 0;
    v3->skeleton.m_object = 0;
    cook_data = v3;
  }
  else
  {
    cook_data = 0;
  }
  skeleton_config_path.m_string.m_begin = skeleton_config_path.m_string.m_buffer;
  skeleton_config_path.m_string.m_end = skeleton_config_path.m_string.m_buffer;
  skeleton_config_path.m_string.m_max_end = &skeleton_config_path.m_separator;
  skeleton_config_path.m_separator = 47;
  render_model_path.m_separator = 47;
  m_requery_path = parent->m_requery_path;
  render_model_path.m_string.m_begin = render_model_path.m_string.m_buffer;
  skeleton_config_path.m_string.m_buffer[0] = 0;
  render_model_path.m_string.m_end = render_model_path.m_string.m_buffer;
  render_model_path.m_string.m_max_end = &render_model_path.m_separator;
  render_model_path.m_string.m_buffer[0] = 0;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  vostok::fs_new::path_string_impl::assignf(
    &skeleton_config_path,
    "resources/models/%s.skinned_model/skeleton",
    m_requery_path);
  m_request_path = parent->m_requery_path;
  if ( !m_request_path )
    m_request_path = parent->m_request_path;
  vostok::fs_new::path_string_impl::assignf(&render_model_path, "%s.skinned_model/render", m_request_path);
  requests.id = (vostok::resources::class_id_enum)this;
  requests.path = (const char *)vostok::render::skeleton_model_instance_cook::on_skeleton_config_loaded;
  v8.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))this;
  callback.vtable = 0;
  v8.l_.a1_.t_ = (survarium::animated_model_instance_cook *)cook_data;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::skeleton_model_instance_cook::on_skeleton_config_loaded,
         v8) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_model_instance_cook,vostok::resources::queries_result &,vostok::render::skeleton_model_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::skeleton_model_instance_cook_data *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  requests.path = skeleton_config_path.m_string.m_begin;
  requests.id = binary_config_class_impl;
  user_data = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    (const vostok::variant<32> **)&user_data,
    parent,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&callback.functor, &callback.functor, 2);
    }
  }
  requests.id = (vostok::resources::class_id_enum)v12;
  requests.path = (const char *)vostok::render::skeleton_model_instance_cook::on_render_model_loaded;
  v9.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))v12;
  callback.vtable = 0;
  v9.l_.a1_.t_ = (survarium::animated_model_instance_cook *)cook_data;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::skeleton_model_instance_cook::on_render_model_loaded,
         v9) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_model_instance_cook,vostok::resources::queries_result &,vostok::render::skeleton_model_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::skeleton_model_instance_cook_data *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  requests.path = render_model_path.m_string.m_begin;
  requests.id = skeleton_render_model_instance_class;
  v12 = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    (const vostok::variant<32> **)&v12,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v7 )
      v7(&callback.functor, &callback.functor, 2);
  }
}
