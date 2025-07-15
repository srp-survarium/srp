survarium::timelimit_rule_core *__thiscall survarium::timelimit_rule_core::`scalar deleting destructor'(
        survarium::timelimit_rule_core *this,
        char a2)
{
  survarium::timelimit_rule_core::~timelimit_rule_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
