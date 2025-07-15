unsigned int __thiscall vostok::flags_type<enum vostok::resources::unmanaged_resource::flag_enum,vostok::threading::single_threading_policy>::set(
        vostok::flags_type<enum vostok::resources::unmanaged_resource::flag_enum,vostok::threading::single_threading_policy> *this,
        vostok::enum_flags<enum vostok::resources::unmanaged_resource::flag_enum> flags)
{
  unsigned int result; // eax

  result = this->m_flags;
  this->m_flags |= flags.m_flags;
  return result;
}
