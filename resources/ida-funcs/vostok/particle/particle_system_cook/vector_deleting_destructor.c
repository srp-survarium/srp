survarium::particle_game_effect_emitter_cook *__thiscall vostok::particle::particle_system_cook::`vector deleting destructor'(
        survarium::particle_game_effect_emitter_cook *this,
        char a2)
{
  this->__vftable = (survarium::particle_game_effect_emitter_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
