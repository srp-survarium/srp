unsigned int __thiscall vostok::threading::core_count(void *this)
{
  if ( !s_logical_core_count )
    vostok::threading::initialize_core_count();
  return s_logical_core_count;
}
