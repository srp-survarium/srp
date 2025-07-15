void __thiscall vostok::particle::particle_action_billboard::~particle_action_billboard(
        vostok::particle::particle_action_billboard *this)
{
  vostok::particle::curve_line_ranged_base *p_m_line; // [esp+4h] [ebp-2Ch]

  p_m_line = &this->m_subimage_index.m_line;
  vostok::particle::curve_line_points<float,0>::clear(&this->m_subimage_index.m_line.m_lower);
  vostok::particle::curve_line_points<float,0>::clear(&p_m_line->m_upper);
  this->__vftable = (vostok::particle::particle_action_billboard_vtbl *)&vostok::particle::particle_action_data_type::`vftable';
  this->__vftable = (vostok::particle::particle_action_billboard_vtbl *)&vostok::particle::particle_action::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
