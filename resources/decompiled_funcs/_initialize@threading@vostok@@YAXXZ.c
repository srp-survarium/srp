void __cdecl vostok::threading::initialize()
{
  if ( !s_logical_to_physical_core_index )
    vostok::threading::initialize_core_affinity();
}
