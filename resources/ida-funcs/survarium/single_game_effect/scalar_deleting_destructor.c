survarium::hud_game_effect *__thiscall survarium::single_game_effect::`scalar deleting destructor'(
        survarium::hud_game_effect *this,
        char a2)
{
  survarium::game_effect::~game_effect(&this->survarium::single_game_effect);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
