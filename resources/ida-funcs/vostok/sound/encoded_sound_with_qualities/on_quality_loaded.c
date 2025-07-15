void __thiscall vostok::sound::encoded_sound_with_qualities::on_quality_loaded(
        vostok::sound::encoded_sound_with_qualities *this,
        vostok::resources::query_result_for_cook *resources)
{
  vostok::resources::query_result_for_cook *v3; // ecx
  int v4; // ebx
  unsigned int m_target_quality_level; // eax
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v6; // edi
  survarium::pure_game_effect_emitter_base *m_object; // esi
  vostok::particle::particle_system_instance_impl *v8; // ecx
  vostok::sound::encoded_sound_with_qualities *v9; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp-8h] [ebp-2Ch] BYREF
  vostok::threading::simple_lock *v11; // [esp-4h] [ebp-28h]
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v12; // [esp+10h] [ebp-14h]
  vostok::sound::encoded_sound_with_qualities *v13; // [esp+14h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp+18h] [ebp-Ch] BYREF
  vostok::threading::simple_lock *v15; // [esp+1Ch] [ebp-8h]
  char v16; // [esp+23h] [ebp-1h]

  v3 = resources;
  v4 = (int)&resources->m_children_resources.m_last[-1].quality_value + 3;
  m_target_quality_level = this->m_target_quality_level;
  v13 = this;
  v16 = 0;
  if ( v4 >= 0 )
  {
    v15 = (vostok::threading::simple_lock *)(v4 + m_target_quality_level);
    v6 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&resources->m_tasks_finished_callback.functor.vostok_pointer_size_alignment[184 * v4 + 3];
    v12 = v6;
    do
    {
      if ( vostok::resources::query_result_for_user::is_successful(v3, (int)&v6[-55]) )
      {
        v16 = 1;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v14,
          v6);
        m_object = v14.m_object;
        resources = 0;
        if ( v14.m_object )
        {
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resources);
          resources = (vostok::resources::query_result_for_cook *)m_object;
          _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
        v11 = v15;
        v10.m_object = v8;
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v10,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resources);
        vostok::sound::encoded_sound_with_qualities::add_quality(v9, v13, v10.m_object, v11);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resources);
        this = v13;
      }
      --v4;
      v15 = (vostok::threading::simple_lock *)((char *)v15 - 1);
      v6 = v12 - 184;
      v12 -= 184;
    }
    while ( v4 >= 0 );
  }
  if ( this->m_parent_query )
  {
    vostok::resources::query_result_for_cook::finish_query(
      v3,
      (vostok::resources::cook_base::result_enum)(2 * (v16 != 0) + 1),
      assert_on_fail_true);
    this->m_parent_query = 0;
  }
  this->m_increasing_quality = 0;
}
