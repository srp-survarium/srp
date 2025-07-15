void __fastcall survarium::scheduler::unregister(
        survarium::scheduler *this,
        int a2,
        survarium::scheduler::identifier *identifier)
{
  unsigned int v3; // esi
  _DWORD *v4; // ebx
  int v5; // eax
  int v6; // esi
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // [esp+10h] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 40);
  if ( v3 >= (*(_DWORD *)identifier & 0x7FFFFFFFu) )
    *(_DWORD *)(a2 + 40) = v3 - 1;
  v4 = *(_DWORD **)(a2 + 4 * (*(unsigned int *)identifier >> 31) + 32);
  v5 = *v4 + 56 * (*(_DWORD *)identifier & 0x7FFFFFFF);
  v6 = v4[1] - 56;
  *(_DWORD *)v5 = *(_DWORD *)v6;
  v9 = v5;
  boost::function<void __cdecl (unsigned int,unsigned int)>::operator=(
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)(v6 + 8),
    (boost::function1<void,vostok::physics::contact_point const &> *)(v5 + 8));
  v7 = *(_DWORD **)v9;
  v6 += 40;
  *(_DWORD *)(v9 + 40) = *(_DWORD *)v6;
  v6 += 4;
  *(_DWORD *)(v9 + 44) = *(_DWORD *)v6;
  *(_DWORD *)(v9 + 48) = *(_DWORD *)(v6 + 4);
  v8 = (*(_DWORD *)identifier ^ *v7) & 0x7FFFFFFF;
  *v7 ^= v8;
  v4[1] -= 56;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
    (int *)(v4[1] + 8));
  *(_DWORD *)identifier &= ~0x80000000;
}
