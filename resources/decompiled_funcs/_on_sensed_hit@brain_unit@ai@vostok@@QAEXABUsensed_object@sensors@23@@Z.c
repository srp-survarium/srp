void __thiscall vostok::ai::brain_unit::on_sensed_hit(
        vostok::ai::brain_unit *this,
        const vostok::ai::sensors::sensed_object *hit_object)
{
  const vostok::math::float3 *v2; // eax
  vostok::math::float3 *v3; // eax
  vostok::ai::sound_player *m_object; // [esp+Ch] [ebp-3Ch]
  survarium::game_camera *v6; // [esp+14h] [ebp-34h]
  vostok::ai::game_object *hitting_object; // [esp+2Ch] [ebp-1Ch]
  _BYTE v8[12]; // [esp+30h] [ebp-18h] BYREF
  vostok::math::float3 v9; // [esp+3Ch] [ebp-Ch] BYREF

  hitting_object = (vostok::ai::game_object *)hit_object->object;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)hitting_object);
  vostok::ai::pre_perceptors_filter::on_hit_event(&this->m_behaviour.m_object->m_ignorance_filter, hitting_object);
  vostok::ai::subscriptions_manager<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object>::on_event(
    &this->m_perceptors_subscriptions_manager,
    hit_object);
  survarium::weapon_user_dead_state::finalize(v6);
  m_object = this->m_sound_player.m_object;
  vostok::math::float3::float3(&v9, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  v3 = this->m_npc->get_position(this->m_npc, v8, v2);
  m_object->play(m_object, sound_collection_type_npc_pain, 1, v3);
}
