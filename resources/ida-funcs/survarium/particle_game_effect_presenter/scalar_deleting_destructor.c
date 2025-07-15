survarium::particle_game_effect_presenter *__thiscall survarium::particle_game_effect_presenter::`scalar deleting destructor'(
        survarium::particle_game_effect_presenter *this,
        char a2)
{
  survarium::particle_game_effect_presenter::~particle_game_effect_presenter(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
