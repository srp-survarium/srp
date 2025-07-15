void __thiscall vostok::ai::selectors::animation_target_selector::clear_targets(
        vostok::ai::selectors::animation_target_selector *this)
{
  const vostok::ai::animation_item **i; // [esp+8h] [ebp-4h]

  for ( i = this->m_selected_animations.m_begin; i != this->m_selected_animations.m_end; ++i )
    ;
  this->m_selected_animations.m_end = this->m_selected_animations.m_begin;
}
