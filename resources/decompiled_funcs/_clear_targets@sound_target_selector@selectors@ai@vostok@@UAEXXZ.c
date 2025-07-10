void __thiscall vostok::ai::selectors::sound_target_selector::clear_targets(
        vostok::ai::selectors::sound_target_selector *this)
{
  const vostok::ai::sound_item **i; // [esp+8h] [ebp-4h]

  for ( i = this->m_selected_sounds.m_begin; i != this->m_selected_sounds.m_end; ++i )
    ;
  this->m_selected_sounds.m_end = this->m_selected_sounds.m_begin;
}
