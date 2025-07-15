vostok::animation::mixing::n_ary_tree_serializer *__thiscall vostok::animation::mixing::n_ary_tree_serializer::`scalar deleting destructor'(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        char a2)
{
  this->m_floats_stream.m_end = this->m_floats_stream.m_begin;
  this->m_times_in_ms_stream.m_end = this->m_times_in_ms_stream.m_begin;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
