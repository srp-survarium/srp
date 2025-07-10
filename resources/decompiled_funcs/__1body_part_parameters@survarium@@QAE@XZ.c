void __thiscall survarium::body_part_parameters::~body_part_parameters(survarium::body_part_parameters *this)
{
  survarium::game_camera *v1; // ecx
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *i; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( i = this->m_affects.m_begin; i != this->m_affects.m_end; ++i )
    ;
  this->m_affects.m_end = this->m_affects.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_affects);
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
