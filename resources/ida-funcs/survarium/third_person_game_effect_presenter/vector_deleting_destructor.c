survarium::third_person_game_effect_presenter *__thiscall survarium::third_person_game_effect_presenter::`vector deleting destructor'(
        survarium::third_person_game_effect_presenter *this,
        char a2)
{
  survarium::particle_game_effect_presenter *v3; // ecx

  survarium::sound_game_effect_presenter::~sound_game_effect_presenter(
    (survarium::sound_game_effect_presenter *)this,
    (int)&this->m_sound_presenter);
  survarium::particle_game_effect_presenter::~particle_game_effect_presenter(v3, (int)&this->m_particle_presenter);
  this->__vftable = (survarium::third_person_game_effect_presenter_vtbl *)&survarium::base_game_effect_presenter::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
