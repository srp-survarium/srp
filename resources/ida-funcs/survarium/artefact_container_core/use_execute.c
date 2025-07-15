char __thiscall survarium::artefact_container_core::use_execute(
        survarium::artefact_container_core *this,
        survarium::usable_object_user_data *user)
{
  survarium::game_camera *v2; // ecx
  survarium::inventory_holder *v3; // eax
  float value; // [esp+0h] [ebp-5Ch]
  unsigned int v6; // [esp+14h] [ebp-48h]
  vostok::sound::encoded_sound_interface *(__thiscall *v8)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+34h] [ebp-28h]
  unsigned int left_ms; // [esp+50h] [ebp-Ch]
  float artsearch_time; // [esp+54h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  left_ms = user->current_time_ms - user->start_using_time_ms;
  artsearch_time = (double)this->m_artefact_search_time_ms * user->booster_artcont_time_factor;
  if ( artsearch_time <= 0.0 )
    v6 = 0;
  else
    v6 = (__int64)artsearch_time;
  value = (double)left_ms / (double)v6 * 100.0;
  user->current_progress = vostok::math::floor(value);
  if ( left_ms >= v6 )
  {
    if ( this->m_owner )
      survarium::generic_anomaly_core::on_artefact_container_use(this->m_owner, this);
    user->start_using_time_ms = user->current_time_ms;
    if ( this->m_artefact.m_object )
      v8 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
    else
      v8 = 0;
    if ( v8 )
    {
      v3 = (survarium::inventory_holder *)((int (__thiscall *)(survarium::collision_user *, unsigned int, _DWORD, unsigned int, _DWORD))user->owner->cast_to_inventory_holder)(
                                            user->owner,
                                            v6,
                                            0,
                                            left_ms,
                                            0);
      survarium::artefact_container_core::transfer_artefact(this, v3);
    }
  }
  return 1;
}
