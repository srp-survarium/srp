void __userpurge vostok::sound::new_sound_propagator::execute_finished_callback(
        vostok::sound::new_sound_propagator *this@<ecx>,
        float xmm0_4_0@<xmm0>,
        int a2)
{
  int v3; // edi
  int v4; // eax
  unsigned int v5; // ecx
  vostok::sound::sound_scene *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  __int32 v10; // ebx
  unsigned int v11; // eax
  vostok::memory::doug_lea_allocator *v12; // eax
  int v13; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::sound::sound_instance_proxy_internal>,boost::_bi::value<unsigned int> > > v14; // [esp-14h] [ebp-68h]
  vostok::sound::create_sound_propagator_params params; // [esp+10h] [ebp-44h] BYREF
  void (__thiscall *v16)(vostok::sound::sound_instance_proxy_internal *, unsigned int); // [esp+38h] [ebp-1Ch]
  int v17; // [esp+3Ch] [ebp-18h]
  unsigned int v18; // [esp+40h] [ebp-14h]
  int v19; // [esp+44h] [ebp-10h]
  int v20; // [esp+4Ch] [ebp-8h]

  v20 = 0;
  v3 = a2;
  v4 = *(_DWORD *)(a2 + 8);
  if ( *(_DWORD *)(v4 + 44) == 1 )
  {
    v5 = *(_DWORD *)(v4 + 124);
    params.m_type = point;
    params.m_playback_id = v5;
    v6 = *(vostok::sound::sound_scene **)(v4 + 104);
    params.m_proxy = (vostok::sound::sound_instance_proxy_internal *)v4;
    params.m_continue_loop = 1;
    vostok::sound::sound_scene::emit_sound_propagators_impl(v6, xmm0_4_0, &params);
  }
  else
  {
    v7 = vostok::sound::g_allocator;
    v8 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_response> `RTTI Type Descriptor');
    v10 = (__int32)v7->call_malloc(
                     v7,
                     48u,
                     v8,
                     "vostok::sound::new_sound_propagator::execute_finished_callback",
                     ".\\sound_propagator.cpp",
                     173u);
    if ( v10 )
    {
      v11 = *(_DWORD *)(a2 + 8);
      v19 = *(_DWORD *)(a2 + 24);
      v18 = v11;
      v16 = vostok::sound::sound_instance_proxy_internal::execute_finished_callback;
      v17 = 0;
      HIDWORD(v14.f_.f_) = vostok::sound::sound_instance_proxy_internal::execute_finished_callback;
      v14.l_.a1_.t_ = 0;
      v14.l_.a2_.t_ = v11;
      LODWORD(v14.f_.f_) = &params.m_direction.z;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function<void __cdecl(void)> *)vostok::sound::sound_instance_proxy_internal::execute_finished_callback,
        v14,
        v19);
      v12 = vostok::sound::g_allocator;
      *(_DWORD *)(v10 + 8) = 0;
      *(_DWORD *)(v10 + 4) = v12;
      v20 = 1;
      *(_DWORD *)v10 = &vostok::sound::functor_command<vostok::sound::sound_response>::`vftable';
      boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&params.m_direction.elements[2],
        (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v10 + 16));
      v3 = a2;
    }
    else
    {
      v10 = 0;
    }
    if ( (v20 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v9,
        (int *)&params.m_direction.z);
    v13 = *(_DWORD *)(*(_DWORD *)(v3 + 8) + 100);
    *(_DWORD *)(v10 + 8) = 0;
    _InterlockedExchange((volatile __int32 *)(*(_DWORD *)v13 + 8), v10);
    *(_DWORD *)v13 = v10;
  }
}
