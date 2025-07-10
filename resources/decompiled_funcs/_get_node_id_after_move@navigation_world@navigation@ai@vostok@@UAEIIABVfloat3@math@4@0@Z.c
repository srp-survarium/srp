unsigned int __thiscall vostok::ai::navigation::navigation_world::get_node_id_after_move(
        vostok::ai::navigation::navigation_world *this,
        unsigned int previous_triangle_id,
        survarium::game_camera *previous_position,
        const vostok::math::float3 *new_position)
{
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize(previous_position);
  return this->get_node_id_at(this, new_position);
}
