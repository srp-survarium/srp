void __usercall vostok::ai::fsm::clear_transitions(vostok::ai::fsm *this@<ecx>, int a2@<eax>)
{
  _DWORD *i; // edi
  int *v3; // esi
  int v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ebx
  vostok::memory::doug_lea_allocator *v6; // ecx
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  for ( i = *(_DWORD **)(a2 + 8); i; i = (_DWORD *)i[1] )
  {
    while ( i[4] )
    {
      v3 = (int *)i[4];
      --i[2];
      v4 = v3[9];
      i[4] = v4;
      if ( !v4 )
        i[5] = 0;
      v3[9] = 0;
      v5 = vostok::ai::g_allocator;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        v3);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)v3, v7, v8, v9);
    }
  }
}
