void __thiscall vostok::ai::planning::action_instance::initialize(
        vostok::ai::planning::action_instance *this,
        const vostok::fixed_vector<void const *,4> *values)
{
  if ( this->m_initialize_binder )
    this->m_initialize_binder(this, values);
}
