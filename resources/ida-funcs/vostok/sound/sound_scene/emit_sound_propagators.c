void __userpurge vostok::sound::sound_scene::emit_sound_propagators(
        unsigned int playback_id@<eax>,
        vostok::sound::sound_scene *this,
        boost::detail::function::vtable_base *proxy)
{
  int v3; // esi
  char *v4; // eax
  void (__cdecl *manager)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // eax
  vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *v6; // ecx
  __int32 v7; // eax
  void (__cdecl *v8)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v9; // [esp-48h] [ebp-BCh] BYREF
  _BYTE v10[44]; // [esp-28h] [ebp-9Ch] BYREF
  vostok::sound::sound_instance_proxy_internal *proxya; // [esp+14h] [ebp-60h]
  vostok::sound::world_user *user; // [esp+18h] [ebp-5Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v13; // [esp+1Ch] [ebp-58h] BYREF
  __int64 v14; // [esp+3Ch] [ebp-38h] BYREF
  unsigned __int64 v15; // [esp+44h] [ebp-30h]
  _DWORD v16[10]; // [esp+4Ch] [ebp-28h] BYREF

  v16[6] = playback_id;
  v13.vtable = (boost::detail::function::vtable_base *)vostok::sound::sound_scene::emit_sound_propagators_impl;
  v13.functor.obj_ptr = this;
  (&v13.vtable)[1] = 0;
  LODWORD(v14) = vostok::sound::sound_scene::emit_sound_propagators_impl;
  HIDWORD(v14) = 0;
  v15 = __PAIR64__((unsigned int)v13.functor.vostok_pointer_size_alignment[1], (unsigned int)this);
  *(_DWORD *)&v10[40] = &v14;
  v16[7] = proxy;
  v16[8] = 0;
  LOBYTE(v16[9]) = 0;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v13.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v13.functor.obj_ptr = v14;
    *((_QWORD *)&v13.functor.data + 1) = v15;
    v13.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  v3 = *((_DWORD *)proxy[25].manager + 71);
  v4 = type_info::raw_name(&vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> `RTTI Type Descriptor');
  user = (vostok::sound::world_user *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v3 + 16))(
                                        v3,
                                        128,
                                        v4,
                                        "vostok::sound::sound_scene::emit_sound_propagators",
                                        ".\\sound_scene_propagators.cpp",
                                        27);
  if ( user )
  {
    manager = proxy[25].manager;
    qmemcpy(&v10[4], v16, 0x28u);
    proxya = (vostok::sound::sound_instance_proxy_internal *)manager;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &v13,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&(&v9.vtable)[1]);
    v9.vtable = proxy;
    vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params>::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params>(
      v6,
      (vostok::sound::sound_instance_proxy_order *)user,
      (vostok::sound::world_user *)proxya,
      v9,
      *(vostok::sound::create_sound_propagator_params *)v10,
      *(int *)&v10[40]);
  }
  else
  {
    v7 = 0;
  }
  v8 = proxy[25].manager;
  *(_DWORD *)(v7 + 8) = 0;
  v8 = (void (__cdecl *)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type))((char *)v8 + 136);
  _InterlockedExchange((volatile __int32 *)(*(_DWORD *)v8 + 8), v7);
  *(_DWORD *)v8 = v7;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
    (int *)&v13);
}
