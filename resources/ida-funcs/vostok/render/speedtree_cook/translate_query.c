void __thiscall vostok::render::speedtree_cook::translate_query(
        vostok::render::speedtree_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  char *m_request_path; // eax
  int *v4; // eax
  vostok::render::speedtree_data *v5; // ecx
  int v6; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v8; // [esp-8h] [ebp-288h]
  vostok::resources::request requests[2]; // [esp+10h] [ebp-270h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-260h] BYREF
  void (__thiscall *v12)(vostok::render::speedtree_cook *, vostok::resources::queries_result *, vostok::render::speedtree_data *); // [esp+44h] [ebp-23Ch]
  vostok::render::speedtree_cook *v13; // [esp+48h] [ebp-238h]
  vostok::fs_new::virtual_path_string model_path; // [esp+50h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string config_path; // [esp+168h] [ebp-118h] BYREF

  model_path.m_string.m_begin = model_path.m_string.m_buffer;
  m_requery_path = parent->m_requery_path;
  model_path.m_string.m_end = model_path.m_string.m_buffer;
  model_path.m_string.m_max_end = &model_path.m_separator;
  model_path.m_string.m_buffer[0] = 0;
  model_path.m_separator = 47;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  vostok::fs_new::path_string_impl::assignf(&model_path, "resources/speedtree/%s.srt", m_requery_path);
  config_path.m_string.m_max_end = &config_path.m_separator;
  m_request_path = parent->m_requery_path;
  config_path.m_string.m_begin = config_path.m_string.m_buffer;
  config_path.m_string.m_end = config_path.m_string.m_buffer;
  config_path.m_string.m_buffer[0] = 0;
  config_path.m_separator = 47;
  if ( !m_request_path )
    m_request_path = parent->m_request_path;
  vostok::fs_new::path_string_impl::assignf(&config_path, "resources/speedtree/%s.options", m_request_path);
  requests[0].path = model_path.m_string.m_begin;
  requests[0].id = raw_data_class;
  requests[1].path = config_path.m_string.m_begin;
  requests[1].id = binary_config_class_impl;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x598u);
  if ( v4 )
    vostok::render::speedtree_data::speedtree_data(v5, (int)v4);
  else
    v6 = 0;
  v13 = this;
  v12 = vostok::render::speedtree_cook::on_speedtree_raw_data_loaded;
  v8.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))this;
  *(_DWORD *)v6 = parent;
  *(_BYTE *)(v6 + 1428) = 0;
  callback.vtable = 0;
  v8.l_.a1_.t_ = (survarium::animated_model_instance_cook *)v6;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::speedtree_cook::on_speedtree_raw_data_loaded,
         v8) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::speedtree_cook,vostok::resources::queries_result &,vostok::render::speedtree_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::speedtree_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::speedtree_data *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resources(
    requests,
    2u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    0,
    parent,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v7 )
      v7(&callback.functor, &callback.functor, 2);
  }
}
