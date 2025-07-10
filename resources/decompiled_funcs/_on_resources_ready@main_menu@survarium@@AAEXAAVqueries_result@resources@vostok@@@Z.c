void __thiscall survarium::main_menu::on_resources_ready(
        survarium::main_menu *this,
        vostok::resources::queries_result *data)
{
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // ebx
  vostok::configs::binary_config *m_object; // edi
  vostok::resources::unmanaged_resource *v5; // eax
  vostok::resources::unmanaged_intrusive_base *p_m_target_quality_level; // ecx
  vostok::configs::binary_config *v7; // edi
  vostok::resources::unmanaged_resource *v8; // eax
  vostok::resources::unmanaged_intrusive_base *v9; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+14h] [ebp-4h] BYREF

  v2 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)data;
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v10.m_object;
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    v10.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene,
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&data);
  v5 = (vostok::resources::unmanaged_resource *)data;
  if ( data )
  {
    p_m_target_quality_level = (vostok::resources::unmanaged_intrusive_base *)&data->m_queries[0].m_target_quality_level;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&data->m_queries[0].m_target_quality_level, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(p_m_target_quality_level, v5);
  }
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    v2 + 255);
  v7 = v10.m_object;
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    v10.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene_view,
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&data);
  v8 = (vostok::resources::unmanaged_resource *)data;
  if ( data )
  {
    v9 = (vostok::resources::unmanaged_intrusive_base *)&data->m_queries[0].m_target_quality_level;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&data->m_queries[0].m_target_quality_level, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v9, v8);
  }
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
  }
}
