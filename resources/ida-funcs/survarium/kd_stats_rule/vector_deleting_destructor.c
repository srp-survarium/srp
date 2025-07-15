survarium::kd_stats_rule *__thiscall survarium::kd_stats_rule::`vector deleting destructor'(
        survarium::kd_stats_rule *this,
        char a2)
{
  survarium::kd_stats_rule::~kd_stats_rule(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
