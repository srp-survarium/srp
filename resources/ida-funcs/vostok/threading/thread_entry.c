void __cdecl vostok::threading::thread_entry(
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *argument)
{
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *v1; // esi
  unsigned int v2; // kr00_4
  void *v3; // esp
  unsigned int v4; // kr04_4
  void *v5; // esp
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function0<bool> *v7; // [esp-4h] [ebp-58h]
  char v8[16]; // [esp+0h] [ebp-54h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-44h] BYREF
  boost::detail::function::vtable_base *vtable; // [esp+30h] [ebp-24h]
  boost::detail::function::vtable_base *v11; // [esp+34h] [ebp-20h]
  unsigned int hardware_thread; // [esp+38h] [ebp-1Ch]
  vostok::threading::tasks_awareness v13; // [esp+3Ch] [ebp-18h]
  void *v14; // [esp+40h] [ebp-14h]
  char v15; // [esp+44h] [ebp-10h]
  volatile __int32 *v16; // [esp+4Ch] [ebp-8h]

  v1 = argument;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(argument, &f);
  vtable = v1[1].vtable;
  v11 = (&v1[1].vtable)[1];
  hardware_thread = (unsigned int)v1[1].functor.obj_ptr;
  v13 = (vostok::threading::tasks_awareness)v1[1].functor.vostok_pointer_size_alignment[1];
  v16 = (volatile __int32 *)&v1[1].functor.vostok_pointer_size_alignment[2];
  v14 = v1[1].functor.vostok_pointer_size_alignment[2];
  v15 = *(&v1[1].functor.data + 12);
  v2 = strlen((const char *)(&v1[1].vtable)[1]);
  v3 = alloca(v2 + 1);
  vostok::strings::copy(v8, v2 + 1, (char *)(&v1[1].vtable)[1]);
  v4 = strlen((const char *)v1[1].vtable);
  v5 = alloca(v4 + 1);
  vostok::strings::copy(v8, v4 + 1, (char *)v1[1].vtable);
  vostok::threading::tls_set_value(s_thread_logging_name_tls_key, v8);
  _InterlockedExchange((volatile __int32 *)&argument, vostok::debug::is_debugger_present());
  _InterlockedExchange(v16, 1);
  vostok::threading::set_current_thread_affinity((char *)hardware_thread);
  vostok::threading::on_thread_spawn(v13);
  boost::function0<void>::operator()(v7, &f);
  vostok::threading::free_current_thread_logging_name();
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, (int *)&f);
}
