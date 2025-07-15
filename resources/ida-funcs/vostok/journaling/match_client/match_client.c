void __thiscall vostok::journaling::match_client::match_client(
        vostok::journaling::match_client *this,
        vostok::network::world *world,
        int a3)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  _DWORD v4[2]; // [esp-20h] [ebp-60h] BYREF
  void *v5; // [esp-18h] [ebp-58h]
  __int64 v6; // [esp-14h] [ebp-54h]
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *v7; // [esp-Ch] [ebp-4Ch]
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *v8; // [esp-8h] [ebp-48h]
  unsigned int v9; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> const &)> on_out_of_memory; // [esp+10h] [ebp-30h] BYREF
  void (__thiscall *v11)(vostok::journaling::match_client *); // [esp+30h] [ebp-10h]
  int v12; // [esp+34h] [ebp-Ch]
  __int64 v13; // [esp+38h] [ebp-8h]

  world[3].__vftable = 0;
  world->__vftable = (vostok::network::world_vtbl *)&survarium::base_match_client::`vftable';
  LOBYTE(world[2].__vftable) = 0;
  survarium::match_options::match_options((survarium::match_options *)this, (int)&world[4]);
  on_out_of_memory.vtable = 0;
  v9 = 1364;
  v8 = (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *)&world[7476];
  v7 = (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)&world[7818];
  world->__vftable = (vostok::network::world_vtbl *)&vostok::journaling::match_client::`vftable';
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>(
    &on_out_of_memory,
    v7,
    v8,
    v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&on_out_of_memory);
  world[7832].__vftable = (vostok::network::world_vtbl *)vostok::network_core::new_udp_match_packet((vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)&world[7818]);
  v12 = 0;
  v11 = vostok::journaling::match_client::on_dispatch_callbacks;
  LODWORD(v13) = world;
  on_out_of_memory.functor.vostok_pointer_size_alignment[2] = vostok::journaling::match_client::on_dispatch_callbacks;
  on_out_of_memory.functor.vostok_pointer_size_alignment[3] = 0;
  world[7834].__vftable = 0;
  *((_QWORD *)&on_out_of_memory.functor.data + 2) = v13;
  v4[0] = 0;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v4[0] = 0;
  }
  else
  {
    if ( v4 != (_DWORD *)-8 )
    {
      v5 = on_out_of_memory.functor.vostok_pointer_size_alignment[2];
      v6 = *(_QWORD *)(&on_out_of_memory.functor.data + 12);
      v7 = (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)on_out_of_memory.functor.vostok_pointer_size_alignment[5];
    }
    v4[0] = (char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::journaling::match_client>,boost::_bi::list1<boost::_bi::value<vostok::journaling::match_client *>>>>'::`2'::stored_vtable
          + 1;
  }
  (*(void (__thiscall **)(int, _DWORD, _DWORD, void *, _DWORD, _DWORD, vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *, vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *, unsigned int))(*(_DWORD *)a3 + 20))(
    a3,
    v4[0],
    v4[1],
    v5,
    v6,
    HIDWORD(v6),
    v7,
    v8,
    v9);
}
