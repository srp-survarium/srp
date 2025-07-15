survarium::victory_item_cook *__thiscall survarium::sound_player_cook::`vector deleting destructor'(
        survarium::victory_item_cook *this,
        char a2)
{
  this->__vftable = (survarium::victory_item_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
