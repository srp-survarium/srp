unsigned int __usercall vostok::resources::resource_quality::calculate_max_child_quality_level@<eax>(
        vostok::resources::resource_quality *this@<ecx>,
        vostok::threading::simple_lock *a2@<esi>)
{
  unsigned int v3; // edi
  vostok::threading::simple_lock *v4; // ebx
  volatile int i; // eax
  unsigned int v6; // ecx

  if ( a2[13].m_thread_id == 1 )
    return 0;
  v3 = -1;
  if ( a2 == (vostok::threading::simple_lock *)-36 )
    v4 = 0;
  else
    v4 = a2 + 5;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, v4);
  for ( i = a2[6].m_thread_id; i; i = *(_DWORD *)(i + 4) )
  {
    v6 = *(_DWORD *)(i + 8);
    if ( v6 != -1 )
      v3 = v6 + (v3 < v6 ? v3 - v6 : 0);
  }
  if ( v4->m_lock-- == 1 )
    _InterlockedExchange(&v4->m_thread_id, 0);
  return v3;
}
