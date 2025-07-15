survarium::base_game_effect_presenter *__thiscall survarium::base_game_effect_presenter::`vector deleting destructor'(
        survarium::base_game_effect_presenter *this,
        char a2)
{
  this->__vftable = (survarium::base_game_effect_presenter_vtbl *)&survarium::base_game_effect_presenter::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
