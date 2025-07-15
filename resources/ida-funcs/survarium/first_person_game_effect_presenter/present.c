void __thiscall survarium::first_person_game_effect_presenter::present(
        survarium::first_person_game_effect_presenter *this,
        survarium::base_player *player)
{
  this->m_post_process_presenter.present(&this->m_post_process_presenter, player);
  this->m_hud_presenter.present(&this->m_hud_presenter, player);
  this->m_sound_presenter.present(&this->m_sound_presenter, player);
}
