void __thiscall vostok::ai::selectors::enemy_target_selector::~enemy_target_selector(
        vostok::ai::selectors::weapon_target_selector *this)
{
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *i; // [esp+8h] [ebp-4h]

  for ( i = this->m_selected_weapons.m_begin; i != this->m_selected_weapons.m_end; ++i )
    ;
  this->m_selected_weapons.m_end = this->m_selected_weapons.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
