void __thiscall vostok::particle::particle_action_animated_source::set_defaults(
        vostok::particle::particle_action_animated_source *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_mask = -1;
  this->m_visibility = 1;
  this->m_right_up_leg = 1;
  this->m_left_up_leg = 1;
  this->m_right_leg = 1;
  this->m_left_leg = 1;
  this->m_right_foot = 1;
  this->m_left_foot = 1;
  this->m_right_arm = 1;
  this->m_left_arm = 1;
  this->m_right_fore_arm = 1;
  this->m_left_fore_arm = 1;
  this->m_front_spin = 1;
  this->m_front_chest = 1;
  this->m_head = 1;
  this->m_neck = 1;
  this->m_right_hand = 1;
  this->m_left_hand = 1;
  this->m_back_chest = 1;
  this->m_back_spin = 1;
  this->m_face = 1;
  vostok::math::curve_line_ranged_xyz_float::set_defaults(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    (int)&this->m_scale);
  this->m_use_random_permutation = 0;
  this->m_permutation_seed = 0;
  this->m_random_permutation_size = 0;
  this->m_random_permutation_index = 0;
}
