void __userpurge vostok::animation::animation_collection_cook::collection_config_loaded(
        vostok::animation::animation_collection_cook *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v7; // esi
  unsigned int v8; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v10; // eax
  vostok::animation::animation_collection_cook *v11; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp-Ch] [ebp-24h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v13; // [esp-8h] [ebp-20h]
  vostok::resources::query_result_for_cook *v14; // [esp-4h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+10h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+14h] [ebp-4h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  m_parent_query = data->m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v16.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v16,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v16.m_object;
    config_ptr.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &config_ptr,
      v16.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v7 = config_ptr.m_object;
    if ( BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3])
      || vostok::configs::binary_config_value::value_exists(config_ptr.m_object->m_root, "collection") )
    {
      v10 = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)vostok::configs::binary_config_value::operator[](v7->m_root, "collection");
      v14 = m_parent_query;
      v13 = v10;
      v12.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v12,
        &config_ptr);
      vostok::animation::animation_collection_cook::request_items(
        v11,
        (const vostok::variant<32> **)this,
        (const char *)m_parent_query,
        (const char *)v7,
        (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)this,
        v12.m_object,
        v13,
        (int)v14);
      if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
    }
    else
    {
      v8 = occurances_left_24;
      if ( occurances_left_24 == -1 )
        v8 = 10;
      v9 = (vostok::resources::query_result_for_cook *)v8;
      occurances_left_24 = v8 - 1;
      if ( v8 )
      {
        if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3]) )
        {
          LOBYTE(data) = 0;
          vostok::debug::on_error(
            a2,
            (bool *)&data,
            process_error_false,
            (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3]
          + 1,
            assert_untyped,
            "assertion_failed",
            "config_ptr->get_root().value_exists( \"collection\" )",
            ".\\animation_collection_cook.cpp",
            "vostok::animation::animation_collection_cook::collection_config_loaded",
            0x47u);
          if ( vostok::debug::is_debugger_present() || (_BYTE)data )
            __debugbreak();
        }
      }
      vostok::resources::query_result_for_cook::finish_query_impl(
        v9,
        result_error,
        assert_on_fail_true,
        error_type_cook_failed);
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
