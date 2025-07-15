int __usercall vostok::resources::queries_result::`scalar deleting destructor'@<eax>(
        vostok::resources::queries_result *this@<ecx>,
        int a2@<eax>)
{
  unsigned int v3; // ebx
  void (__thiscall ***v4)(_DWORD, _DWORD); // edi
  int i; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx

  v3 = 0;
  if ( *(_DWORD *)(a2 + 56) )
  {
    v4 = (void (__thiscall ***)(_DWORD, _DWORD))(a2 + 80);
    do
    {
      (**v4)(v4, 0);
      ++v3;
      v4 += 184;
    }
    while ( v3 < *(_DWORD *)(a2 + 56) );
  }
  for ( i = *(_DWORD *)(a2 + 56); i; --i )
    _InterlockedExchangeAdd(&s_resources_manager_buffer.m_pending_queries_count, 0xFFFFFFFF);
  `vector destructor iterator'(
    (char *)(a2 + 80),
    0x2E0u,
    0,
    (void (__thiscall *)(void *))vostok::resources::query_result::~query_result);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, (int *)a2);
  return a2;
}
