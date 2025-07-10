void __thiscall vostok::ai::selectors::weapon_target_selector::clear_targets(
        vostok::ai::selectors::weapon_target_selector *this)
{
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *i; // [esp+8h] [ebp-4h]

  for ( i = this->m_selected_weapons.m_begin; i != this->m_selected_weapons.m_end; ++i )
    ;
  this->m_selected_weapons.m_end = this->m_selected_weapons.m_begin;
}
