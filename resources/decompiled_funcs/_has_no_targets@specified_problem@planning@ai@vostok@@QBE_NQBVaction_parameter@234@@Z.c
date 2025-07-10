BOOL __thiscall vostok::ai::planning::specified_problem::has_no_targets(
        vostok::ai::planning::specified_problem *this,
        const vostok::ai::planning::action_parameter *const parameter)
{
  bool v3; // [esp+3h] [ebp-Dh]
  vostok::ai::selectors::target_selector_base *selector; // [esp+8h] [ebp-8h]

  selector = vostok::ai::planning::specified_problem::get_parameter_selector(this, parameter);
  v3 = selector && selector->get_targets_count(selector);
  return !v3;
}
