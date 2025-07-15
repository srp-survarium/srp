void __thiscall survarium::items_cook::on_config_ready(
        survarium::items_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  survarium::pure_game_effect_emitter_base *pointer; // ebx
  vostok::particle::particle_system_instance_impl *v5; // ecx
  survarium::items_cook *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp-8h] [ebp-38h] BYREF
  vostok::resources::query_result_for_cook *v8; // [esp-4h] [ebp-34h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+Ch] [ebp-24h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v10; // [esp+10h] [ebp-20h] BYREF
  int v11; // [esp+14h] [ebp-1Ch]
  vostok::configs::binary_config_value v12; // [esp+18h] [ebp-18h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v10,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v10.m_object;
  v9.m_object = 0;
  if ( v10.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
    v9.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
  qmemcpy(
    (void *)&v12,
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)v9.m_object->m_lods[0].m_template.m_object,
      "data"),
    sizeof(v12));
  v8 = parent;
  pointer = (survarium::pure_game_effect_emitter_base *)vostok::configs::binary_config_value::operator[](&v12, "type")->data.pointer;
  v11 = 0;
  v7.m_object = v5;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v7,
    &v9);
  survarium::items_cook::create_item_and_finish_query(v6, pointer, v7, v8);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
}
