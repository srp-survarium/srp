vostok::ai::planning::propositional_planner *__thiscall vostok::ai::planning::propositional_planner::`vector deleting destructor'(
        vostok::ai::planning::propositional_planner *this,
        char a2)
{
  vostok::ai::planning::propositional_planner::~propositional_planner(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
