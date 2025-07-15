survarium::hud_game_effect_emitter *__thiscall survarium::random_permutation_game_effect_emitter::`scalar deleting destructor'(
        survarium::hud_game_effect_emitter *this,
        char a2)
{
  this->__vftable = (survarium::hud_game_effect_emitter_vtbl *)&survarium::pure_game_effect_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
