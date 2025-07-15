void __thiscall vostok::ai::selectors::sound_target_selector::fill_targets_list(
        vostok::ai::selectors::sound_target_selector *this)
{
  this->clear_targets(this);
  vostok::ai::brain_unit::get_available_sounds(this->m_brain_unit, &this->m_selected_sounds);
  stlp_std::sort<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
    this->m_selected_sounds.m_begin,
    this->m_selected_sounds.m_end,
    vostok::ai::selectors::sort_by_name);
}
