void __thiscall vostok::ai::planning::specified_problem::fill_parameter_targets(
        vostok::ai::planning::specified_problem *this,
        const vostok::ai::planning::action_parameter *const parameter)
{
  vostok::ai::selectors::target_selector_base *selector; // [esp+4h] [ebp-4h]

  selector = vostok::ai::planning::specified_problem::get_parameter_selector(this, parameter);
  if ( selector )
    ((void (__thiscall *)(vostok::ai::selectors::target_selector_base *, vostok::ai::planning::specified_problem *))selector->fill_targets_list)(
      selector,
      this);
}
