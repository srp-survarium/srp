void __thiscall survarium::human_npc::on_sound_event(
        survarium::human_npc *this,
        const vostok::sound::sound_producer *sound_source)
{
  unsigned int *p_m_sound_type; // ecx
  vostok::math::float3 *(__thiscall *get_source_position)(vostok::sound::sound_producer *, vostok::math::float3 *, const vostok::math::float3 *); // eax
  int v5; // eax
  vostok::ai::sound_collection_types m_sound_type; // edx
  float v7; // ecx
  unsigned int m_sound_power; // eax
  vostok::resources::unmanaged_resource *m_prev_in_global_delay_delete_list; // ecx
  _DWORD v10[3]; // [esp+10h] [ebp-30h] BYREF
  vostok::math::float3 v11; // [esp+1Ch] [ebp-24h] BYREF
  vostok::ai::sensed_sound_object perceived_sound; // [esp+28h] [ebp-18h] BYREF

  p_m_sound_type = 0;
  perceived_sound.position.y = -4.2170408e37;
  this->m_affects_subscription.subscription_callback.functor.type.const_qualified = 1;
  perceived_sound.position.x = -4.2170408e37;
  perceived_sound.position.z = -4.2170408e37;
  perceived_sound.object = 0;
  perceived_sound.type = -33698355;
  perceived_sound.power = -33698355;
  if ( sound_source )
    p_m_sound_type = &sound_source[-1].m_sound_type;
  perceived_sound.object = (const vostok::ai::game_object *)(*(int (__thiscall **)(unsigned int *))(*p_m_sound_type + 24))(p_m_sound_type);
  get_source_position = sound_source->get_source_position;
  memset(v10, 0, sizeof(v10));
  v5 = (int)get_source_position(sound_source, &v11, (const vostok::math::float3 *)v10);
  m_sound_type = sound_source->m_sound_type;
  *(_QWORD *)&perceived_sound.position.x = *(_QWORD *)v5;
  v7 = *(float *)(v5 + 8);
  m_sound_power = sound_source->m_sound_power;
  perceived_sound.position.z = v7;
  m_prev_in_global_delay_delete_list = this->m_prev_in_global_delay_delete_list;
  perceived_sound.power = m_sound_power;
  perceived_sound.type = m_sound_type;
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *, vostok::ai::sensed_sound_object *))m_prev_in_global_delay_delete_list->__vftable[1].log_string)(
    m_prev_in_global_delay_delete_list,
    &this[-1].m_default_animation,
    &perceived_sound);
}
