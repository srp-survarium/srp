void __usercall process(
        unsigned int a1@<ebx>,
        bool *do_debug_break,
        vostok::process_error_enum process_error,
        bool *ignore_always,
        vostok::assert_enum assert_type,
        const char *reason,
        const char *expression,
        const char *description,
        const char *file,
        const char *function,
        unsigned int line)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v11; // ecx
  vostok::memory::base_allocator *v12; // ecx
  void *v13; // esp
  vostok::debug::engine *v14; // [esp+0h] [ebp-6Ch] BYREF
  vostok::debug::engine *v15; // [esp+4h] [ebp-68h]
  vostok::debug::engine **v16; // [esp+8h] [ebp-64h]
  vostok::debug::engine *v17; // [esp+Ch] [ebp-60h]
  int v18; // [esp+10h] [ebp-5Ch]
  boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,vostok::debug::call_stack_size_calculator,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<vostok::debug::call_stack_size_calculator *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7> > > f; // [esp+1Ch] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+2Ch] [ebp-40h] BYREF
  boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int> v21; // [esp+34h] [ebp-38h] BYREF
  vostok::debug::call_stack_size_calculator helper; // [esp+58h] [ebp-14h] BYREF
  unsigned int thread_id; // [esp+5Ch] [ebp-10h]
  unsigned int size_for_call_stack; // [esp+60h] [ebp-Ch]
  unsigned int max_message_length; // [esp+64h] [ebp-8h]
  char *message; // [esp+68h] [ebp-4h]

  if ( s_process_lock_thread_id == vostok::debug::current_thread_id() )
  {
    ++s_process_lock_count;
  }
  else
  {
    thread_id = vostok::debug::current_thread_id();
    while ( vostok::debug::interlocked_compare_exchange(&s_process_lock_thread_id, thread_id, 0) )
      vostok::debug::yield(0);
    s_process_lock_count = 1;
  }
  size_for_call_stack = 0;
  if ( !vostok::debug::debug_engine() || (v17 = vostok::debug::debug_engine(), !v17->is_testing(v17)) )
  {
    if ( !vostok::debug::is_debugger_present() )
    {
      vostok::debug::dump_call_stack(a1, "debug", 1, 2u, 0, 0, 0);
      helper.m_size = 0;
      f = (boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,vostok::debug::call_stack_size_calculator,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<vostok::debug::call_stack_size_calculator *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::debug::call_stack_size_calculator::predicate, (vostok::sound::sound_debug_stats *)&helper);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v11, &v21);
      boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,vostok::debug::call_stack_size_calculator,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<vostok::debug::call_stack_size_calculator *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7>>>>(
        &v21,
        f);
      vostok::debug::call_stack::iterate(
        v12,
        a1,
        0,
        0,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21,
        0);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v21);
      size_for_call_stack = helper.m_size;
    }
  }
  max_message_length = size_for_call_stack + 4096;
  v13 = alloca(size_for_call_stack + 4096);
  v16 = &v14;
  message = (char *)&v14;
  LOBYTE(v14) = 0;
  output((char *const)&v14, size_for_call_stack + 4096, (const char *)&buf);
  output(message, max_message_length, "Error occurred : %s", reason);
  output(message, max_message_length, "Expression    : %s", expression);
  if ( description )
    output(message, max_message_length, "Description   : %s", description);
  output(message, max_message_length, "File          : %s", file);
  output(message, max_message_length, "Line          : %d", line);
  output(message, max_message_length, "Function      : %s", function);
  v15 = vostok::debug::debug_engine();
  if ( v15->is_testing(v15) )
  {
    v14 = vostok::debug::debug_engine();
    v14->on_testing_exception(v14, assert_type, message, 0, 1);
  }
  else if ( process_error )
  {
    if ( process_error == process_error_to_message_box )
      v18 = strcpy_s(message, max_message_length, description);
    on_error(a1, process_error, do_debug_break, message, (survarium::game_camera *)max_message_length, ignore_always);
  }
  if ( !--s_process_lock_count )
    vostok::debug::interlocked_exchange(&s_process_lock_thread_id, 0);
}
