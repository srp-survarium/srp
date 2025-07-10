void __thiscall survarium::animated_model_instance_cook::on_subresources_loaded(
        survarium::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  volatile int m_result; // eax
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::resources::unmanaged_resource *v4; // eax
  survarium::animated_model_instance *v5; // ebx
  vostok::configs::binary_config *v6; // edi
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v8; // eax
  vostok::render::animated_model_instance *v9; // ecx
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::configs::binary_config *v11; // esi
  vostok::configs::binary_config *v12; // edi
  vostok::configs::binary_config *v13; // eax
  vostok::physics::animated_model_instance *v14; // ecx
  vostok::resources::unmanaged_resource *v15; // eax
  vostok::configs::binary_config *v16; // edi
  vostok::collision::animated_object *v17; // eax
  void *v18; // eax
  vostok::animation::animation_player *v19; // ecx
  vostok::animation::animation_player *v20; // eax
  void (__cdecl *v21)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v22; // eax
  vostok::resources::unmanaged_intrusive_base *v23; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v24; // [esp+58Ch] [ebp-1B4h]
  int v25; // [esp+598h] [ebp-1A8h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+5A8h] [ebp-198h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v27; // [esp+5ACh] [ebp-194h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+5B0h] [ebp-190h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v29; // [esp+5B4h] [ebp-18Ch] BYREF
  vostok::resources::query_result_for_cook *v30; // [esp+5B8h] [ebp-188h]
  vostok::variant<32> *user_data; // [esp+5BCh] [ebp-184h] BYREF
  survarium::animated_model_instance_cook *v32; // [esp+5C0h] [ebp-180h]
  vostok::resources::request requests; // [esp+5C4h] [ebp-17Ch] BYREF
  __int64 v34; // [esp+5CCh] [ebp-174h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> v35; // [esp+5D8h] [ebp-168h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v36; // [esp+600h] [ebp-140h]
  int v37; // [esp+604h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+608h] [ebp-138h] BYREF
  vostok::fs_new::path_string_impl v39; // [esp+628h] [ebp-118h] BYREF

  m_result = data->m_result;
  m_parent_query = data->m_parent_query;
  v32 = this;
  v30 = m_parent_query;
  if ( m_result == 1 )
  {
    v4 = (vostok::resources::unmanaged_resource *)vostok::memory::g_resources_unmanaged_allocator.call_malloc(
                                                    &vostok::memory::g_resources_unmanaged_allocator,
                                                    288);
    v5 = (survarium::animated_model_instance *)v4;
    v6 = 0;
    if ( v4 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v4, 1u);
      v5->__vftable = (survarium::animated_model_instance_vtbl *)&survarium::animated_model_instance::`vftable';
      v5->m_render_model.m_object = 0;
      v5->m_physics_model.m_object = 0;
      v5->m_damage_model.m_object = 0;
    }
    else
    {
      v5 = 0;
    }
    v27.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v27,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v27.m_object;
    if ( v27.m_object )
    {
      v6 = v27.m_object;
      _InterlockedExchangeAdd(&v27.m_object->m_reference_count, 1u);
    }
    v8 = 0;
    if ( v6 )
    {
      v8 = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    v9 = (vostok::render::animated_model_instance *)v8;
    v10 = v5->m_render_model.m_object;
    v5->m_render_model.m_object = v9;
    if ( v10 )
    {
      if ( !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
      m_object = v27.m_object;
    }
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v26.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v26,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
    v11 = v26.m_object;
    v12 = 0;
    if ( v26.m_object )
    {
      v12 = v26.m_object;
      _InterlockedExchangeAdd(&v26.m_object->m_reference_count, 1u);
    }
    v13 = 0;
    if ( v12 )
    {
      v13 = v12;
      _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
    }
    v14 = (vostok::physics::animated_model_instance *)v13;
    v15 = v5->m_physics_model.m_object;
    v5->m_physics_model.m_object = v14;
    if ( v15 )
    {
      if ( !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
      v11 = v26.m_object;
    }
    if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
    if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
    v29.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v29,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[2].m_unmanaged_resource);
    v16 = v29.m_object;
    v28.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v28,
      v29.m_object);
    if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
    vostok::physics::new_animated_bt_hit_model(
      v28.m_object->m_root,
      &v5->m_physics_model.m_object->m_skeleton,
      &vostok::memory::g_resources_unmanaged_allocator);
    v5->m_damage_collision = v17;
    v18 = vostok::memory::g_resources_unmanaged_allocator.call_malloc(
            &vostok::memory::g_resources_unmanaged_allocator,
            34120);
    if ( v18 )
      vostok::animation::animation_player::animation_player(v19, (int)v18);
    else
      v20 = 0;
    v5->m_animation_player = v20;
    v39.m_string.m_max_end = &v39.m_separator;
    v39.m_string.m_begin = v39.m_string.m_buffer;
    v39.m_string.m_end = v39.m_string.m_buffer;
    v39.m_string.m_buffer[0] = 0;
    v39.m_separator = 47;
    vostok::fs_new::path_string_impl::assignf(
      &v39,
      "resources/gameplay/hit_params/%s.options",
      v5->m_render_model.m_object->m_hit_params.m_begin);
    v36 = 0;
    v37 = 0;
    v37 = vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::get();
    HIDWORD(v34) = v32;
    LODWORD(v34) = survarium::animated_model_instance_cook::on_hit_params_loaded;
    *(_QWORD *)&v24.f_.f_ = v34;
    v35.functor.obj_ptr = 0;
    v35.vtable = (boost::detail::function::vtable_base *)&vostok::detail::concrete_type_helper<enum survarium::affects_applying_type_enum>::`vftable';
    v36 = &v35;
    v24.l_.a3_.t_ = v5;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      &v35,
      (int)&callback,
      0,
      v24,
      v25);
    requests.path = v39.m_string.m_begin;
    user_data = (vostok::variant<32> *)&v35;
    requests.id = damage_model_class;
    vostok::resources::query_resources(
      &requests,
      1u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      &vostok::memory::g_resources_unmanaged_allocator,
      (const vostok::variant<32> **)&user_data,
      v30,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v21 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v21 )
          v21(&callback.functor, &callback.functor, 2);
      }
    }
    if ( v36 )
    {
      ((void (__thiscall *)(boost::function<void __cdecl(vostok::resources::queries_result &)> *, boost::detail::function::function_buffer *))v36->vtable[1].manager)(
        v36,
        &v35.functor);
      v36 = 0;
    }
    v22 = v28.m_object;
    v23 = &v28.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v28.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v23, v22);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
