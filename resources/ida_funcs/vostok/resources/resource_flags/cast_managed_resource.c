vostok::resources::managed_resource *__thiscall vostok::resources::resource_flags::cast_managed_resource(
        vostok::resources::resource_flags *this)
{
  return (unsigned __int8)((this->m_flags.m_flags & 1) - 1) == 0 ? (vostok::resources::managed_resource *)this : 0;
}
