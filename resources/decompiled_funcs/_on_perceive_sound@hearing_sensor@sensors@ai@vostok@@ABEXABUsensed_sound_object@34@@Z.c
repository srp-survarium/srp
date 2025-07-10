void __thiscall vostok::ai::sensors::hearing_sensor::on_perceive_sound(
        vostok::ai::sensors::hearing_sensor *this,
        const vostok::ai::sensed_sound_object *perceived_sound)
{
  const vostok::math::float3 *v2; // eax
  vostok::math::float3 *v3; // eax
  float v5; // [esp+18h] [ebp-68h]
  unsigned int current_time_in_ms; // [esp+1Ch] [ebp-64h]
  vostok::math::float3 v7; // [esp+20h] [ebp-60h]
  float z; // [esp+34h] [ebp-4Ch]
  _BYTE v9[12]; // [esp+3Ch] [ebp-44h] BYREF
  vostok::math::float3 v10; // [esp+48h] [ebp-38h] BYREF
  const vostok::ai::game_object *object; // [esp+54h] [ebp-2Ch]
  vostok::ai::sensors::sensed_object sound_object; // [esp+58h] [ebp-28h] BYREF

  object = perceived_sound->object;
  v5 = (double)perceived_sound->power / 100.0;
  current_time_in_ms = vostok::ai::ai_world::get_current_time_in_ms(this->m_world);
  *(_QWORD *)&v7.x = *(_QWORD *)&perceived_sound->position.x;
  v7.z = perceived_sound->position.z;
  vostok::math::float3::float3(&v10, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  v3 = this->m_npc->get_position(this->m_npc, v9, v2);
  z = v3->z;
  *(_QWORD *)&sound_object.position.x = *(_QWORD *)&v3->x;
  sound_object.position.z = z;
  sound_object.direction = v7;
  sound_object.object = object;
  sound_object.update_time = current_time_in_ms;
  sound_object.type = sensed_object_type_sound;
  sound_object.confidence = v5;
  vostok::ai::brain_unit::on_sensed_sound(this->m_brain_unit, &sound_object);
}
