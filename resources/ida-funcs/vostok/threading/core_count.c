unsigned int __cdecl vostok::threading::core_count()
{
  unsigned int result; // eax

  result = s_logical_core_count;
  if ( !s_logical_core_count )
  {
    vostok::threading::initialize_core_count();
    return s_logical_core_count;
  }
  return result;
}
