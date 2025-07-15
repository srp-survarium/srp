survarium::game_effect_emitter *__thiscall survarium::game_effect_emitter::`scalar deleting destructor'(
        survarium::game_effect_emitter *this,
        char a2)
{
  survarium::game_effect_emitter::~game_effect_emitter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
