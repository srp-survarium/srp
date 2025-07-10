void __thiscall survarium::player_logic_stand_state::player_logic_stand_state(
        survarium::player_logic_stand_state *this,
        survarium::weapon_user_animations_selector *owner)
{
  survarium::player_logic_base_state::player_logic_base_state(this, owner, type_stand);
  this->__vftable = (survarium::player_logic_stand_state_vtbl *)&survarium::player_logic_stand_state::`vftable';
}
