int __thiscall vostok::ai::selectors::enemy_target_selector::get_targets_count(
        vostok::ai::selectors::weapon_target_selector *this)
{
  return this->m_selected_weapons.m_end - this->m_selected_weapons.m_begin;
}
