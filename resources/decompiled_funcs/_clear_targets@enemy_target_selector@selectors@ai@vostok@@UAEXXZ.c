void __thiscall vostok::ai::selectors::enemy_target_selector::clear_targets(
        vostok::ai::selectors::enemy_target_selector *this)
{
  stlp_std::pair<vostok::ai::npc const *,float> *i; // [esp+8h] [ebp-4h]

  for ( i = this->m_selected_enemies.m_begin; i != this->m_selected_enemies.m_end; ++i )
    ;
  this->m_selected_enemies.m_end = this->m_selected_enemies.m_begin;
}
