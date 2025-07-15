void __thiscall vostok::ai::sensors::damage_sensor::on_perceive_hit(
        vostok::ai::sensors::damage_sensor *this,
        const vostok::ai::sensed_hit_object *sensed_hit)
{
  float extent_of_damage; // [esp+4h] [ebp-50h]
  unsigned int current_time_in_ms; // [esp+8h] [ebp-4Ch]
  vostok::math::float3 v5; // [esp+Ch] [ebp-48h]
  float z; // [esp+20h] [ebp-34h]
  const vostok::ai::game_object *object; // [esp+28h] [ebp-2Ch]
  vostok::ai::sensors::sensed_object hit_object; // [esp+2Ch] [ebp-28h] BYREF

  object = sensed_hit->object;
  extent_of_damage = sensed_hit->extent_of_damage;
  current_time_in_ms = vostok::ai::ai_world::get_current_time_in_ms(this->m_world);
  *(_QWORD *)&v5.x = *(_QWORD *)&sensed_hit->direction.x;
  v5.z = sensed_hit->direction.z;
  z = sensed_hit->own_position.z;
  *(_QWORD *)&hit_object.position.x = *(_QWORD *)&sensed_hit->own_position.x;
  hit_object.position.z = z;
  hit_object.direction = v5;
  hit_object.object = object;
  hit_object.update_time = current_time_in_ms;
  hit_object.type = sensed_object_type_hit;
  hit_object.confidence = extent_of_damage;
  vostok::ai::brain_unit::on_sensed_hit(this->m_brain_unit, &hit_object);
}
