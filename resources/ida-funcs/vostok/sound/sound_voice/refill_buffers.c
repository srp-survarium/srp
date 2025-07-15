void __usercall vostok::sound::sound_voice::refill_buffers(vostok::sound::sound_voice *this@<ecx>, int a2@<esi>)
{
  vostok::sound::sound_buffer_factory **v2; // edi
  vostok::sound::sound_buffer_factory *v3; // eax
  unsigned int v4; // [esp+14h] [ebp-1Ch]
  unsigned __int64 v5; // [esp+18h] [ebp-18h]
  _BYTE v6[4]; // [esp+20h] [ebp-10h] BYREF
  unsigned int v7; // [esp+24h] [ebp-Ch]

  v5 = *(_QWORD *)(*(_DWORD *)(a2 + 32) + 264);
  (*(void (__stdcall **)(_DWORD, _BYTE *))(**(_DWORD **)(*(_DWORD *)(a2 + 20) + 16) + 100))(
    *(_DWORD *)(*(_DWORD *)(a2 + 20) + 16),
    v6);
  v4 = v7;
  if ( v7 < 3 )
  {
    v2 = (vostok::sound::sound_buffer_factory **)(a2 + 28);
    do
    {
      if ( (unsigned int)*v2 >= v5 )
        break;
      v3 = vostok::sound::sound_buffer_factory::new_sound_buffer(
             *v2,
             *(vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 280) + 200),
             (vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *)(a2 + 32),
             (vostok::resources::resource_link *)*v2,
             (unsigned int *)(a2 + 28));
      (*(void (__stdcall **)(_DWORD, boost::intrusive::set<vostok::sound::sound_buffer,boost::intrusive::compare<vostok::sound::sound_buffer_compare_predicate>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> *, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 20) + 16) + 84))(
        *(_DWORD *)(*(_DWORD *)(a2 + 20) + 16),
        &v3->m_cached_sound_buffers + 1,
        0);
      if ( v5 == (unsigned int)*v2 && *(_DWORD *)(*(_DWORD *)(a2 + 24) + 16) == 1 )
        *v2 = 0;
      ++v4;
    }
    while ( v4 < 3 );
  }
}
