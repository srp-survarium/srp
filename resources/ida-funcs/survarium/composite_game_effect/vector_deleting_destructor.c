survarium::composite_game_effect *__thiscall survarium::composite_game_effect::`vector deleting destructor'(
        survarium::composite_game_effect *this,
        char a2)
{
  this->__vftable = (survarium::composite_game_effect_vtbl *)&survarium::composite_game_effect::`vftable';
  survarium::game_effect::~game_effect(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
