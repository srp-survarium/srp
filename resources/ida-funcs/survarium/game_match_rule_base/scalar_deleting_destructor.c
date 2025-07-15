survarium::game_match_rule_base *__thiscall survarium::game_match_rule_base::`scalar deleting destructor'(
        survarium::game_match_rule_base *this,
        char a2)
{
  survarium::game_match_rule_base::~game_match_rule_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
