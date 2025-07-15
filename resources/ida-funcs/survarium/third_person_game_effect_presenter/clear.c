void __thiscall survarium::third_person_game_effect_presenter::clear(
        survarium::third_person_game_effect_presenter *this)
{
  this->m_particle_presenter.clear(&this->m_particle_presenter);
  this->m_sound_presenter.clear(&this->m_sound_presenter);
}
