void __usercall survarium::client_player_history_item::client_player_history_item(
        survarium::client_player_history_item *this@<ecx>,
        int a2@<esi>)
{
  survarium::player_input::player_input((survarium::player_input *)a2);
  survarium::weapon_state::weapon_state((survarium::weapon_state *)(a2 + 88));
}
