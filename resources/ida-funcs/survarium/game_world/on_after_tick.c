void __thiscall survarium::game_world::on_after_tick(survarium::game_world *this)
{
  vostok::math::half *v2; // ecx
  const vostok::math::float3 *v3; // [esp+0h] [ebp-4h]

  survarium::base_game_scene::on_after_tick(this);
  this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
  vostok::sound::world_user::set_listener_properties_interlocked(
    &this->m_sound_scene,
    v2,
    (vostok::math::float3 *)&this->m_inverted_view_matrix.lines[3],
    (const vostok::math::float3 *)&this->m_inverted_view_matrix.lines[2],
    (const vostok::math::float3 *)&this->m_inverted_view_matrix.lines[1],
    v3);
}
