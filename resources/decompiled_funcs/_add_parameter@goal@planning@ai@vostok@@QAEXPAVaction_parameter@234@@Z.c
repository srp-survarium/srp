void __thiscall vostok::ai::planning::goal::add_parameter(
        vostok::ai::planning::goal *this,
        vostok::ai::planning::action_parameter *parameter)
{
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    (vostok::buffer_vector<void const *> *)&this->m_parameters,
    (const void **)&parameter);
}
