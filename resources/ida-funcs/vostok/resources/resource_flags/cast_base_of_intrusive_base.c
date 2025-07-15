vostok::resources::base_of_intrusive_base *__thiscall vostok::resources::resource_flags::cast_base_of_intrusive_base(
        vostok::resources::resource_flags *this)
{
  if ( ((unsigned __int8)((this->m_flags.m_flags & 1) - 1) == 0 ? (unsigned int)this : 0) != 0 )
    return (unsigned __int8)((this->m_flags.m_flags & 1) - 1) == 0
         ? (vostok::resources::base_of_intrusive_base *)&this[18].type
         : (vostok::resources::base_of_intrusive_base *)220;
  if ( ((unsigned __int8)((this->m_flags.m_flags & 4) - 4) == 0 ? (unsigned int)this : 0) != 0 )
    return (unsigned __int8)((this->m_flags.m_flags & 4) - 4) == 0
         ? (vostok::resources::base_of_intrusive_base *)&this[17].type
         : (vostok::resources::base_of_intrusive_base *)208;
  return 0;
}
