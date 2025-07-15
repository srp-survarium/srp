void __thiscall vostok::ai::planning::action_instance::finalize(
        vostok::ai::planning::action_instance *this,
        const vostok::fixed_vector<void const *,4> *values)
{
  if ( this->m_finalize_binder )
    this->m_finalize_binder(this, values);
}
