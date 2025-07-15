void __usercall vostok::threading::set_current_thread_affinity(char *hardware_thread@<eax>)
{
  char *Value; // eax

  if ( !s_thread_affinity_tls_key )
    vostok::threading::initialize_thread_affinity_tls_key();
  Value = (char *)TlsGetValue(s_thread_affinity_tls_key);
  if ( !Value || Value - 1 != hardware_thread )
  {
    vostok::threading::tls_set_value(s_thread_affinity_tls_key, hardware_thread + 1);
    if ( !s_logical_to_physical_core_index )
      vostok::threading::initialize_core_affinity();
  }
}
