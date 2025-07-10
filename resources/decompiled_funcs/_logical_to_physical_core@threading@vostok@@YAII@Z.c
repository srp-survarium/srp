unsigned int __usercall vostok::threading::logical_to_physical_core@<eax>(unsigned int logical_core@<esi>)
{
  if ( !s_logical_to_physical_core_index )
    vostok::threading::initialize_core_affinity();
  return *((_DWORD *)s_logical_to_physical_core_index + logical_core);
}
