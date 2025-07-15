survarium::sound_game_effect_presenter *__thiscall survarium::sound_game_effect_presenter::`scalar deleting destructor'(
        survarium::sound_game_effect_presenter *this,
        char a2)
{
  survarium::sound_game_effect_presenter::~sound_game_effect_presenter(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
