void __thiscall vostok::fixed_vector<int,4096>::fixed_vector<int,4096>(vostok::fixed_vector<int,4096> *this)
{
  int *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_begin = v1;
  this->m_end = v1;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
}
