void __thiscall survarium::player_history_item::player_history_item(survarium::player_history_item *this)
{
  survarium::player_serialized_state *v2; // ecx

  survarium::player_serialized_state::player_serialized_state(&this->player_state, (int)this);
  survarium::player_serialized_state::player_serialized_state(v2, (int)&this->client_specific_state);
  this->animation_tree.m_object = 0;
}
