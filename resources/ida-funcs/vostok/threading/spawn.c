unsigned int __usercall vostok::threading::spawn@<eax>(
        boost::function<void __cdecl(void)> *function_to_call@<ecx>,
        const char *thread_name_for_logging@<eax>,
        const char *thread_name_for_debugger,
        unsigned int stack_size,
        bool hardware_thread)
{
  const char *v5; // esi
  unsigned int v6; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  unsigned int v8; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // [esp-4h] [ebp-48h]
  vostok::threading::thread_entry_params v11; // [esp+8h] [ebp-3Ch] BYREF

  v5 = thread_name_for_logging;
  if ( !thread_name_for_logging )
    v5 = thread_name_for_debugger;
  v11.function_to_call.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(
    function_to_call,
    (boost::function1<void,vostok::physics::contact_point const &> *)&v11);
  v11.tasks_awareness = tasks_aware;
  v11.hardware_thread = stack_size;
  v11.enable_fpe = hardware_thread;
  v11.thread_name_for_logging = v5;
  v11.thread_name_for_debugger = thread_name_for_debugger;
  v11.processed = 0;
  v6 = vostok::threading::spawn_internal(&v11, 0x800000u);
  v7 = v10;
  v8 = v6;
  while ( !v11.processed )
    vostok::threading::yield(0);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v11);
  return v8;
}
