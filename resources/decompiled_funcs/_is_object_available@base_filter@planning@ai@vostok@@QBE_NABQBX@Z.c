bool __thiscall vostok::ai::planning::base_filter::is_object_available(
        vostok::ai::planning::base_filter *this,
        const void *const *object)
{
  if ( this->m_is_inverted )
    return !this->is_passing_filter(this, object);
  else
    return this->is_passing_filter(this, object);
}
