void __thiscall survarium::project_cooker_simple::on_game_project_loaded(
        survarium::project_cooker_simple *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent,
        vostok::fs_new::virtual_path_string project_name)
{
  vostok::resources::queries_result *m_object; // esi
  vostok::particle::particle_system_instance_impl *v6; // ecx
  survarium::project_cooker_simple *v7; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp-Ch] [ebp-20h] BYREF
  vostok::resources::creation_request *v9; // [esp-8h] [ebp-1Ch]
  char *m_begin; // [esp-4h] [ebp-18h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp+10h] [ebp-4h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v11,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::resources::queries_result *)v11.m_object;
  data = 0;
  if ( v11.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = m_object;
    _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11);
  m_begin = project_name.m_string.m_begin;
  v9 = (vostok::resources::creation_request *)parent;
  v8.m_object = v6;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v8,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  survarium::project_cooker_simple::create_game_objects(
    v7,
    (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)this,
    (vostok::resources::query_result_for_cook *)v8.m_object,
    v9,
    (int)m_begin);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
}
