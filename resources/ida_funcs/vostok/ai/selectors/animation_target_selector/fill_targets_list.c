void __thiscall vostok::ai::selectors::animation_target_selector::fill_targets_list(
        vostok::ai::selectors::animation_target_selector *this)
{
  this->clear_targets(this);
  vostok::ai::brain_unit::get_available_animations(this->m_brain_unit, &this->m_selected_animations);
  stlp_std::sort<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
    (const vostok::ai::sound_item **)this->m_selected_animations.m_begin,
    (const vostok::ai::sound_item **)this->m_selected_animations.m_end,
    (bool (__cdecl *)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))vostok::ai::selectors::sort_by_name_0);
}
