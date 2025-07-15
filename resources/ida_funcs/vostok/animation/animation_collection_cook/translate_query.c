void __thiscall vostok::animation::animation_collection_cook::translate_query(
        vostok::animation::animation_collection_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // eax
  vostok::variant<32> *v4; // edi
  vostok::detail::abstract_type_helper *m_helper; // ecx
  vostok::animation::animation_collection_cook *v6; // ecx
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v8; // ecx
  char *m_requery_path; // eax
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::animation_collection_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::animation_collection_cook *>,boost::arg<1> > > v11; // [esp-10h] [ebp-168h] BYREF
  int v12; // [esp+0h] [ebp-158h]
  vostok::animation::animation_collection_cook_user_data data; // [esp+10h] [ebp-148h] BYREF
  vostok::resources::request requests; // [esp+18h] [ebp-140h] BYREF
  __int64 v15; // [esp+20h] [ebp-138h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+28h] [ebp-130h] BYREF
  vostok::fixed_string<260> config_path; // [esp+48h] [ebp-110h] BYREF
  const vostok::variant<32> *vars0; // [esp+158h] [ebp+0h] BYREF

  m_user_data = parent->m_user_data;
  if ( m_user_data )
  {
    data.cfg_ptr.m_object = 0;
    vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>(m_user_data, &data);
    v4 = parent->m_user_data;
    if ( v4 )
    {
      m_helper = v4->m_helper;
      if ( m_helper )
      {
        m_helper->destroy(m_helper, v4->m_storage);
        v4->m_helper = 0;
      }
    }
    *((_DWORD *)&v11.l_ + 1) = parent;
    v11.l_.a1_.t_ = (vostok::animation::animation_collection_cook *)data.val;
    parent->m_user_data = 0;
    HIDWORD(v11.f_.f_) = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.f_.f_
    + 1,
      &data.cfg_ptr);
    vostok::animation::animation_collection_cook::request_items(
      v6,
      &vars0,
      v4->m_helper_storage,
      (const char *)parent,
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)this,
      (vostok::resources::unmanaged_resource *)HIDWORD(v11.f_.f_),
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)v11.l_.a1_.t_,
      *((int *)&v11.l_ + 1));
    m_object = data.cfg_ptr.m_object;
    if ( data.cfg_ptr.m_object )
    {
      v8 = &data.cfg_ptr.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&data.cfg_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v8, m_object);
    }
  }
  else
  {
    config_path.m_begin = config_path.m_buffer;
    m_requery_path = parent->m_requery_path;
    config_path.m_end = config_path.m_buffer;
    config_path.m_max_end = (char *)&vars0;
    config_path.m_buffer[0] = 0;
    if ( !m_requery_path )
      m_requery_path = parent->m_request_path;
    vostok::buffer_string::assignf(
      &config_path,
      "%s%s%s",
      "resources/animations/collections/",
      m_requery_path,
      ".anim_collection");
    v11.f_.f_ = (void (__thiscall *__ptr64)(vostok::animation::animation_collection_cook *, vostok::resources::queries_result *))(unsigned int)vostok::animation::animation_collection_cook::collection_config_loaded;
    LODWORD(v15) = this;
    *(_QWORD *)&v11.l_.a1_.t_ = v15;
    boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
      0,
      (int)&callback,
      (int)parent,
      v11,
      v12);
    requests.path = config_path.m_begin;
    requests.id = binary_config_class_impl;
    data.val = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      &vostok::memory::g_resources_unmanaged_allocator,
      (const vostok::variant<32> **)&data,
      parent,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&callback.functor, &callback.functor, 2);
      }
    }
  }
}
