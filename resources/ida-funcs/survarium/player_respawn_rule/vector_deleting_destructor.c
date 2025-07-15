survarium::player_respawn_rule *__thiscall survarium::player_respawn_rule::`vector deleting destructor'(
        survarium::player_respawn_rule *this,
        char a2)
{
  survarium::player_respawn_rule::~player_respawn_rule(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
