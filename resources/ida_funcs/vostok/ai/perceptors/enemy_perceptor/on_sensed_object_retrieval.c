void __thiscall vostok::ai::perceptors::enemy_perceptor::on_sensed_object_retrieval(
        vostok::ai::perceptors::enemy_perceptor *this,
        const vostok::ai::sensors::sensed_object *memory_object)
{
  float confidence; // xmm0_4
  vostok::ai::sensors::sensed_object_types type; // [esp+0h] [ebp-1Ch]
  vostok::ai::brain_unit *m_brain_unit; // [esp+8h] [ebp-14h]
  vostok::ai::game_object *object; // [esp+14h] [ebp-8h]
  vostok::ai::percept_memory_object *memory_fact; // [esp+18h] [ebp-4h]

  object = (vostok::ai::game_object *)memory_object->object;
  m_brain_unit = this->m_brain_unit;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)object);
  if ( !vostok::ai::pre_perceptors_filter::is_object_ignored(
          &m_brain_unit->m_behaviour.m_object->m_ignorance_filter,
          object) )
  {
    type = memory_object->type;
    if ( type >= sensed_object_type_visual && (type <= sensed_object_type_sound || type == sensed_object_type_hit) )
    {
      confidence = memory_object->confidence;
      if ( confidence == *(float *)&clear_value )
        vostok::ai::working_memory::forget_all_about_object(this->m_working_memory, memory_object->object);
      memory_fact = vostok::ai::working_memory::create_memory_object(
                      this->m_working_memory,
                      confidence,
                      percept_memory_object_type_enemy);
      memory_fact->object = memory_object->object;
      memory_fact->owner_position = memory_object->position;
      memory_fact->target_position = memory_object->direction;
      memory_fact->update_time = memory_object->update_time;
      memory_fact->confidence = memory_object->confidence;
    }
  }
}
