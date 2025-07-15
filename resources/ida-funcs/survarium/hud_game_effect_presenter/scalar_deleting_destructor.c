survarium::hud_game_effect_presenter *__thiscall survarium::hud_game_effect_presenter::`scalar deleting destructor'(
        survarium::hud_game_effect_presenter *this,
        char a2)
{
  survarium::hud_game_effect_presenter::~hud_game_effect_presenter(
    this,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
