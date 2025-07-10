void __thiscall vostok::ai::planning::action_instance::execute(
        vostok::ai::planning::action_instance *this,
        const vostok::fixed_vector<void const *,4> *values)
{
  if ( this->m_execute_binder )
    this->m_execute_binder(this, values);
}
