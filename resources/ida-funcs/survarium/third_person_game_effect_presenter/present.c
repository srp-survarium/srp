void __thiscall survarium::third_person_game_effect_presenter::present(
        survarium::third_person_game_effect_presenter *this,
        survarium::base_player *player)
{
  this->m_particle_presenter.present(&this->m_particle_presenter, player);
  this->m_sound_presenter.present(&this->m_sound_presenter, player);
}
