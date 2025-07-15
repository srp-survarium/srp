void __thiscall vostok::resources::unmanaged_allocation_cook::create_resource(
        vostok::resources::unmanaged_allocation_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  char *m_data; // esi
  vostok::resources::query_result_for_cook *v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v7; // [esp-Ch] [ebp-14h] BYREF
  const vostok::resources::memory_type *v8; // [esp-8h] [ebp-10h]
  unsigned int m_size; // [esp-4h] [ebp-Ch]

  m_data = in_out_unmanaged_resource_buffer.m_data;
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(
      (vostok::resources::unmanaged_resource *)this,
      in_out_unmanaged_resource_buffer.m_data,
      fs_iterator_class);
    *(_DWORD *)in_out_unmanaged_resource_buffer.m_data = &vostok::resources::unmanaged_allocation_resource::`vftable';
    *((_DWORD *)in_out_unmanaged_resource_buffer.m_data + 66) = raw_file_data.m_size;
  }
  else
  {
    m_data = 0;
  }
  m_size = in_out_unmanaged_resource_buffer.m_size;
  v8 = &vostok::resources::unmanaged_memory;
  v7.m_object = (survarium::pure_game_effect_emitter_base *)this;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v7,
    (survarium::pure_game_effect_emitter_base *)m_data);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v5,
    in_out_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v7.m_object,
    v8,
    m_size);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v6,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
