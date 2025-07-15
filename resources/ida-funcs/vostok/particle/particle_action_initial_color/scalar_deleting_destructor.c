vostok::particle::particle_action_initial_color *__thiscall vostok::particle::particle_action_initial_color::`scalar deleting destructor'(
        vostok::particle::particle_action_initial_color *this,
        char a2)
{
  vostok::particle::curve_line_points<vostok::math::float4_pod,1>::clear(&this->m_init_color);
  this->__vftable = (vostok::particle::particle_action_initial_color_vtbl *)&vostok::particle::particle_modifier::`vftable';
  this->__vftable = (vostok::particle::particle_action_initial_color_vtbl *)&vostok::particle::particle_action::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
