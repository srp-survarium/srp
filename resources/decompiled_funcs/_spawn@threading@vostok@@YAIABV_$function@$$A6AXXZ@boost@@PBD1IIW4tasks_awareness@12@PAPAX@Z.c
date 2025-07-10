unsigned int __usercall vostok::threading::spawn@<eax>(
        const boost::function<void __cdecl(void)> *function_to_call@<eax>,
        const char *thread_name_for_logging@<ecx>,
        const char *thread_name_for_debugger,
        unsigned int stack_size,
        vostok::threading::tasks_awareness hardware_thread)
{
  const char *v5; // esi
  unsigned int v6; // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::threading::thread_entry_params argument; // [esp+10h] [ebp-38h] BYREF

  v5 = thread_name_for_logging;
  if ( !thread_name_for_logging )
    v5 = thread_name_for_debugger;
  argument.function_to_call.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(&argument.function_to_call, function_to_call);
  argument.thread_name_for_logging = v5;
  argument.hardware_thread = stack_size;
  argument.thread_name_for_debugger = thread_name_for_debugger;
  argument.tasks_awareness = hardware_thread;
  argument.processed = 0;
  v6 = vostok::threading::spawn_internal(&argument);
  while ( !argument.processed )
  {
    if ( !SwitchToThread() )
      Sleep(0);
  }
  if ( argument.function_to_call.vtable )
  {
    if ( ((int)argument.function_to_call.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)argument.function_to_call.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&argument.function_to_call.functor, &argument.function_to_call.functor, 2);
    }
  }
  return v6;
}
