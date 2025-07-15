void __thiscall survarium::first_person_game_effect_presenter::clear(
        survarium::first_person_game_effect_presenter *this)
{
  this->m_post_process_presenter.clear(&this->m_post_process_presenter);
  this->m_hud_presenter.clear(&this->m_hud_presenter);
  this->m_sound_presenter.clear(&this->m_sound_presenter);
}
