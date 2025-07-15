survarium::pvp_match_core *__thiscall survarium::pvp_match_core::`vector deleting destructor'(
        survarium::pvp_match_core *this,
        char a2)
{
  survarium::pvp_match_core::~pvp_match_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
