survarium::single_player_respawn_rule *__thiscall survarium::single_player_respawn_rule::`scalar deleting destructor'(
        survarium::single_player_respawn_rule *this,
        char a2)
{
  survarium::single_player_respawn_rule::~single_player_respawn_rule(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
