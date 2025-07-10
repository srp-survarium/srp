void __thiscall vostok::ai::sensors::vision_sensor::add_fact(
        vostok::ai::sensors::vision_sensor *this,
        vostok::ai::sensed_visual_object *visual_object)
{
  float v3; // [esp+4h] [ebp-50h]
  unsigned int current_time_in_ms; // [esp+8h] [ebp-4Ch]
  vostok::math::float3 local_point; // [esp+Ch] [ebp-48h]
  float z; // [esp+20h] [ebp-34h]
  const vostok::ai::game_object *object; // [esp+28h] [ebp-2Ch]
  vostok::ai::sensors::sensed_object visible_object; // [esp+2Ch] [ebp-28h] BYREF

  object = visual_object->object;
  v3 = visual_object->visibility_value / this->m_parameters.max_visibility;
  current_time_in_ms = vostok::ai::ai_world::get_current_time_in_ms(this->m_world);
  local_point = visual_object->local_point;
  z = visual_object->own_position.z;
  *(_QWORD *)&visible_object.position.x = *(_QWORD *)&visual_object->own_position.x;
  visible_object.position.z = z;
  visible_object.direction = local_point;
  visible_object.object = object;
  visible_object.update_time = current_time_in_ms;
  visible_object.type = sensed_object_type_visual;
  visible_object.confidence = v3;
  vostok::ai::brain_unit::on_seen_object(this->m_brain_unit, &visible_object);
}
