void __thiscall survarium::artefact_container_core::artefact_spawned(
        survarium::artefact_container_core *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result *v2; // eax
  vostok::resources::query_result_for_user *v3; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  survarium::game_camera *v5; // ecx
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *object; // [esp+10h] [ebp-24h]
  survarium::artefact_base *m_object; // [esp+18h] [ebp-1Ch]
  vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+1Ch] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> result; // [esp+28h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v11; // [esp+2Ch] [ebp-8h] BYREF
  char v12; // [esp+33h] [ebp-1h]

  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v2 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v3,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v2,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11);
  object = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
             &result,
             (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)unmanaged_resource);
  v9.m_object = 0;
  vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    object);
  m_object = v9.m_object;
  v9.m_object = this->m_artefact.m_object;
  this->m_artefact.m_object = m_object;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v9);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&result);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v11);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::inventory_item::set_amount((survarium::inventory_item *)1, (int)this->m_artefact.m_object);
}
