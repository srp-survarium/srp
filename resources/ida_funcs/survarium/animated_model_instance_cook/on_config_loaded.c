void __thiscall survarium::animated_model_instance_cook::on_config_loaded(
        survarium::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config_value *v5; // esi
  int m_helper_storage; // esi
  vostok::variant<32> *v7; // ecx
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1> > > v11; // [esp+BE8h] [ebp-1B8h]
  const char *v12; // [esp+BECh] [ebp-1B4h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+C00h] [ebp-1A0h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+C04h] [ebp-19Ch] BYREF
  vostok::physics::world *out_value; // [esp+C08h] [ebp-198h] BYREF
  boost::function1<void,vostok::resources::queries_result &> *v16; // [esp+C0Ch] [ebp-194h]
  const void *pointer; // [esp+C10h] [ebp-190h]
  vostok::variant<32> *user_data[3]; // [esp+C14h] [ebp-18Ch] BYREF
  vostok::resources::request v19; // [esp+C20h] [ebp-180h] BYREF
  const void *v20; // [esp+C28h] [ebp-178h]
  int v21; // [esp+C2Ch] [ebp-174h]
  char *m_begin; // [esp+C30h] [ebp-170h]
  int v23; // [esp+C34h] [ebp-16Ch]
  _DWORD v24[2]; // [esp+C38h] [ebp-168h] BYREF
  vostok::physics::world *v25; // [esp+C40h] [ebp-160h] BYREF
  _DWORD *v26; // [esp+C60h] [ebp-140h]
  int v27; // [esp+C64h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+C68h] [ebp-138h] BYREF
  vostok::fs_new::path_string_impl v29; // [esp+C88h] [ebp-118h] BYREF

  v16 = (boost::function1<void,vostok::resources::queries_result &> *)this;
  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = data->m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v13.m_object;
    v14.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v14,
      v13.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   v14.m_object->m_root,
                                                   "models");
    v13.m_object = (vostok::configs::binary_config *)vostok::configs::binary_config_value::operator[](
                                                       v5,
                                                       "render_animated_model")->data.pointer;
    pointer = vostok::configs::binary_config_value::operator[](v5, "physics_animated_model")->data.pointer;
    v12 = (const char *)vostok::configs::binary_config_value::operator[](v5, "damage_collision_object")->data.pointer;
    v29.m_string.m_end = v29.m_string.m_buffer;
    v29.m_string.m_begin = v29.m_string.m_buffer;
    v29.m_string.m_max_end = &v29.m_separator;
    v29.m_string.m_buffer[0] = 0;
    v29.m_separator = 47;
    vostok::fs_new::path_string_impl::assignf(&v29, "resources/models/%s.skinned_model/hit_targets", v12);
    m_helper_storage = (int)m_parent_query->m_user_data->m_helper_storage;
    out_value = 0;
    vostok::variant<32>::try_get<vostok::physics::world *>(v7, m_helper_storage, &out_value);
    v26 = 0;
    v27 = 0;
    v27 = vostok::detail::type_to_int<vostok::physics::world *>::get();
    v25 = out_value;
    user_data[1] = (vostok::variant<32> *)v24;
    v19.path = (const char *)v13.m_object;
    m_begin = v29.m_string.m_begin;
    v26 = v24;
    v11.l_.a1_.t_ = (survarium::animated_model_instance_cook *)v16;
    v11.f_.f_ = survarium::animated_model_instance_cook::on_subresources_loaded;
    v24[0] = &vostok::detail::concrete_type_helper<vostok::physics::world *>::`vftable';
    user_data[0] = 0;
    user_data[2] = 0;
    v19.id = render_animated_model_instance_class;
    v20 = pointer;
    v21 = 102;
    v23 = 34;
    callback.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>>>>(
      v16,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1> > > *)&callback,
      v11);
    vostok::resources::query_resources(
      &v19,
      3u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      &vostok::memory::g_resources_unmanaged_allocator,
      (const vostok::variant<32> **)user_data,
      m_parent_query,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&callback.functor, &callback.functor, 2);
      }
    }
    if ( v26 )
    {
      (*(void (__thiscall **)(_DWORD *, vostok::physics::world **))(*v26 + 4))(v26, &v25);
      v26 = 0;
    }
    v9 = v14.m_object;
    v10 = &v14.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v14.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v10, v9);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (int)m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
