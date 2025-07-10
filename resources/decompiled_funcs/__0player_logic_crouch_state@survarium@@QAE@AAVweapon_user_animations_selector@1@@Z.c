void __thiscall survarium::player_logic_crouch_state::player_logic_crouch_state(
        survarium::player_logic_crouch_state *this,
        survarium::weapon_user_animations_selector *owner)
{
  survarium::player_logic_base_state::player_logic_base_state(this, owner, type_crouch);
  this->__vftable = (survarium::player_logic_crouch_state_vtbl *)&survarium::player_logic_crouch_state::`vftable';
}
