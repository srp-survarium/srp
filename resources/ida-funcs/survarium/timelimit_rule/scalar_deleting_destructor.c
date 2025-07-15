survarium::timelimit_rule *__thiscall survarium::timelimit_rule::`scalar deleting destructor'(
        survarium::timelimit_rule *this,
        char a2)
{
  survarium::timelimit_rule::~timelimit_rule(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
