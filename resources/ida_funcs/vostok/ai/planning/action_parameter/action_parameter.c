void __thiscall vostok::ai::planning::action_parameter::action_parameter(
        vostok::ai::planning::action_parameter *this,
        unsigned int type)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_type = type;
  this->m_iterate_only_first = 1;
  vostok::fixed_string<32>::fixed_string<32>(&this->m_selector_name);
}
