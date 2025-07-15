void __userpurge survarium::human_npc::tick(
        survarium::human_npc *this@<esi>,
        vostok::animation::subscribed_channel **current_time_in_ms@<edi>,
        bool is_game_paused)
{
  unsigned int m_last_tick_time_in_ms; // eax
  unsigned int v4; // ebx
  survarium::human_npc *v5; // ecx
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v6; // [esp+0h] [ebp-8h]

  m_last_tick_time_in_ms = this->m_last_tick_time_in_ms;
  if ( (unsigned int)current_time_in_ms <= m_last_tick_time_in_ms )
    v4 = 0;
  else
    v4 = (unsigned int)current_time_in_ms - m_last_tick_time_in_ms;
  if ( !is_game_paused )
  {
    this->m_physics_world->move(
      this->m_physics_world,
      this->m_model_instance.m_object->m_damage_collision->m_body,
      &this->m_transform);
    vostok::sound::sound_receiver::set_position(
      &this->vostok::sound::sound_receiver,
      (const vostok::math::float3 *)&this->m_transform.lines[3]);
    survarium::damage_model::tick(
      this->m_model_instance.m_object->m_damage_model.m_object,
      v4,
      (const unsigned int)current_time_in_ms);
    survarium::human_npc::tick_animation_player(current_time_in_ms, this);
  }
  if ( this->debug_draw_allowed(this) )
    survarium::human_npc::draw(v5, (int)this, v6);
  this->m_last_tick_time_in_ms = (unsigned int)current_time_in_ms;
}
