void __thiscall vostok::render::engine::world::on_renderer_configuration_config_loaded(
        vostok::render::engine::world *this,
        bool async_effects,
        vostok::configs::binary_config *data)
{
  vostok::resources::unmanaged_resource *v3; // ebx
  vostok::configs::binary_config *m_object; // esi
  survarium::game_action_id *M_start; // edi
  vostok::configs::binary_config_value *v6; // eax
  const char *v7; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v8; // [esp-Ch] [ebp-18h]
  vostok::console_commands::command_type v9; // [esp+0h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+4h] [ebp-8h] BYREF
  vostok::render::engine::world *v11; // [esp+8h] [ebp-4h]

  v11 = this;
  if ( data->m_parent_resources.m_lock == 1 )
  {
    v8 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(&data[1].m_reconstruction_size + 1);
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v8);
    v3 = data;
    v10.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v10,
      data);
    m_object = v10.m_object;
    M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
    v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   v10.m_object->m_root,
                                                   "options");
    vostok::render::options::load_from_config(v6, (vostok::render::options *)M_start);
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  }
  vostok::render::engine::world::reset_renderer(v11, async_effects);
  v7 = s_engine_0->get_user_data_directory(s_engine_0);
  vostok::console_commands::save("user.cfg", v7, v9, (vostok::memory::base_allocator *)v10.m_object);
}
