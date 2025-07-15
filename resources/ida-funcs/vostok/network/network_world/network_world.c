void __userpurge vostok::network::network_world::network_world(
        vostok::network::network_world *this@<ecx>,
        int a2@<edi>,
        vostok::network::engine *engine,
        vostok::memory::base_allocator *orders_allocator)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  boost::asio::io_service *v8; // ecx
  int v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // esi
  int v14; // eax
  char *v15; // eax
  boost::function<void __cdecl(void)> *v16; // ecx
  boost::function<void __cdecl(void)> *v17; // ecx
  char *v18; // esi
  DWORD CurrentThreadId; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v20; // ecx
  const char *v21; // [esp+0h] [ebp-58h]
  const char *v22; // [esp+0h] [ebp-58h]
  const char *v23; // [esp+0h] [ebp-58h]
  const char *v24; // [esp+0h] [ebp-58h]
  int v25; // [esp+0h] [ebp-58h]
  const char *v26; // [esp+4h] [ebp-54h]
  const char *v27; // [esp+4h] [ebp-54h]
  const char *v28; // [esp+4h] [ebp-54h]
  const char *v29; // [esp+4h] [ebp-54h]
  unsigned int v30; // [esp+8h] [ebp-50h]
  unsigned int v31; // [esp+8h] [ebp-50h]
  unsigned int v32; // [esp+8h] [ebp-50h]
  unsigned int v33; // [esp+8h] [ebp-50h]
  char v34; // [esp+Ch] [ebp-4Ch]
  char *v35; // [esp+10h] [ebp-48h]
  char *v36; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v37; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v38; // [esp+38h] [ebp-20h] BYREF

  v4 = vostok::network::g_allocator;
  v34 = 0;
  *(_DWORD *)a2 = &vostok::network::network_world::`vftable';
  v5 = type_info::raw_name(&boost::asio::io_service `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0xCu, v5, v21, v26, v30);
  if ( v7 )
    boost::asio::io_service::io_service(v8, (_RTL_CRITICAL_SECTION_DEBUG *)v7);
  else
    v9 = 0;
  v10 = vostok::network::g_allocator;
  *(_DWORD *)(a2 + 4) = v9;
  v11 = type_info::raw_name(&boost::asio::io_service::work `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(v12, (int)v10, 4u, v11, v22, v27, v31);
  if ( v13 )
  {
    v14 = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 8);
    *(_DWORD *)v13 = v14;
    InterlockedIncrement((volatile LONG *)(v14 + 24));
    v15 = v13;
  }
  else
  {
    v15 = 0;
  }
  *(_DWORD *)(a2 + 8) = v15;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 16) = -1;
  *(_DWORD *)(a2 + 20) = -1;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = -1;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 88) = -1;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = -1;
  *(_DWORD *)(a2 + 212) = 0;
  *(_DWORD *)(a2 + 156) = -1;
  *(_DWORD *)(a2 + 216) = 0;
  *(_DWORD *)(a2 + 220) = -1;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 224) = -1;
  *(_DWORD *)(a2 + 284) = orders_allocator;
  *(_DWORD *)(a2 + 288) = engine;
  *(_DWORD *)(a2 + 296) = 0;
  _InterlockedExchange((volatile __int32 *)(a2 + 156), GetCurrentThreadId());
  _InterlockedExchange((volatile __int32 *)(a2 + 220), GetCurrentThreadId());
  v35 = (char *)vostok::memory::new_helper<vostok::network::functor_response>::call<vostok::memory::doug_lea_allocator>(
                  vostok::network::g_allocator,
                  v23,
                  v28,
                  v32);
  if ( v35 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v16,
      &v38,
      (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl,
      (int)v24);
    *((_DWORD *)v35 + 1) = vostok::network::g_allocator;
    v34 = 1;
    *(_DWORD *)v35 = &vostok::network::functor_response::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v38,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v35 + 16));
  }
  else
  {
    v35 = 0;
  }
  v36 = (char *)vostok::memory::new_helper<vostok::network::functor_response>::call<vostok::memory::doug_lea_allocator>(
                  vostok::network::g_allocator,
                  v24,
                  v29,
                  v33);
  if ( v36 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v17,
      &v37,
      (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl,
      v25);
    v18 = v36;
    v34 |= 2u;
    *((_DWORD *)v36 + 1) = vostok::network::g_allocator;
    *(_DWORD *)v36 = &vostok::network::functor_response::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v37,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(v36 + 16));
  }
  else
  {
    v18 = 0;
  }
  _InterlockedExchange((volatile __int32 *)(a2 + 16), GetCurrentThreadId());
  *((_DWORD *)v35 + 2) = 0;
  *(_DWORD *)(a2 + 76) = v35;
  *(_DWORD *)(a2 + 12) = v35;
  CurrentThreadId = GetCurrentThreadId();
  v20 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)(a2 + 88);
  _InterlockedExchange((volatile __int32 *)(a2 + 88), CurrentThreadId);
  *((_DWORD *)v18 + 2) = 0;
  *(_DWORD *)(a2 + 144) = v18;
  *(_DWORD *)(a2 + 80) = v18;
  if ( (v34 & 2) != 0 )
  {
    v34 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v20,
      (int *)&v37);
  }
  if ( (v34 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v20,
      (int *)&v38);
}
