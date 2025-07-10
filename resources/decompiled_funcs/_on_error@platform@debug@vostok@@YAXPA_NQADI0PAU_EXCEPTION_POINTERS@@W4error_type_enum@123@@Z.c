void __usercall vostok::debug::platform::on_error(
        survarium::game_camera *a1@<ecx>,
        unsigned int a2@<ebx>,
        bool *do_debug_break,
        char *const message,
        survarium::game_camera *message_size,
        bool *ignore_always,
        _EXCEPTION_POINTERS *exception_information,
        vostok::debug::platform::error_type_enum error_type)
{
  _BYTE *v8; // eax
  vostok::memory::base_allocator *v9; // ecx
  void *v10; // esp
  vostok::memory::base_allocator *v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  _DWORD v15[3]; // [esp+0h] [ebp-C4h] BYREF
  const char *v16; // [esp+Ch] [ebp-B8h]
  _DWORD *v17; // [esp+10h] [ebp-B4h]
  unsigned int v18; // [esp+14h] [ebp-B0h]
  char *v19; // [esp+1Ch] [ebp-A8h]
  const char *v20; // [esp+20h] [ebp-A4h]
  boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,error_helper,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<error_helper *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7> > > v21; // [esp+2Ch] [ebp-98h]
  boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,vostok::debug::call_stack_size_calculator,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<vostok::debug::call_stack_size_calculator *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7> > > f; // [esp+44h] [ebp-80h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v23; // [esp+4Ch] [ebp-78h] BYREF
  boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int> v24; // [esp+54h] [ebp-70h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+74h] [ebp-50h] BYREF
  boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int> v26; // [esp+7Ch] [ebp-48h] BYREF
  char v27; // [esp+9Fh] [ebp-25h]
  unsigned int message_length; // [esp+A0h] [ebp-24h]
  char *buffer; // [esp+A4h] [ebp-20h]
  unsigned int buffer_size; // [esp+A8h] [ebp-1Ch]
  error_helper helper; // [esp+ACh] [ebp-18h] BYREF
  const char *endline; // [esp+BCh] [ebp-8h]
  vostok::debug::call_stack_size_calculator calculator; // [esp+C0h] [ebp-4h] BYREF

  v27 = 0;
  survarium::weapon_user_dead_state::finalize(a1);
  if ( *v8 )
    survarium::weapon_user_dead_state::finalize(message_size);
  if ( do_debug_break )
    *do_debug_break = 0;
  if ( vostok::debug::is_debugger_present() )
  {
    vostok::debug::on_error(message);
  }
  else
  {
    calculator.m_size = 0;
    f = (boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,vostok::debug::call_stack_size_calculator,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<vostok::debug::call_stack_size_calculator *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::debug::call_stack_size_calculator::predicate, (vostok::sound::sound_debug_stats *)&calculator);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
      &v26);
    boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,vostok::debug::call_stack_size_calculator,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<vostok::debug::call_stack_size_calculator *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7>>>>(
      &v26,
      f);
    vostok::debug::call_stack::iterate(
      v9,
      a2,
      0,
      0,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26,
      0);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v26);
    v20 = message;
    v19 = message + 1;
    v20 += strlen(v20) + 1;
    v18 = v20 - (message + 1);
    message_length = v18;
    buffer_size = v18 + 4 * calculator.m_size + 4096;
    v10 = alloca(buffer_size);
    v17 = v15;
    buffer = (char *)v15;
    memcpy((unsigned __int8 *)v15, (unsigned __int8 *)message, v18);
    buffer += message_length;
    helper.m_ignore_level_count = error_type != error_type_assert ? 0 : 3;
    helper.m_start_buffer = buffer;
    helper.m_buffer = buffer;
    helper.m_buffer_size = (unsigned int)message_size - (buffer - message);
    v21 = (boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,error_helper,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<error_helper *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v23, (void (__thiscall *)(vostok::sound::sound_debug_stats *))error_helper::predicate, (vostok::sound::sound_debug_stats *)&helper);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v21.f_.f_,
      &v24);
    boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf7<bool,error_helper,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>,boost::_bi::list8<boost::_bi::value<error_helper *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>,boost::arg<5>,boost::arg<6>,boost::arg<7>>>>(
      &v24,
      v21);
    vostok::debug::call_stack::iterate(
      v11,
      a2,
      exception_information,
      0,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v24,
      0);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v24);
    v16 = message;
    v15[2] = message + 1;
    v16 += strlen(v16);
    v15[0] = ++v16 - (message + 1);
    buffer = (char *)(v16 - 1);
    strncpy_s(vostok::debug::g_assertion_message, 0x1000u, message, 0x1000u);
    endline = "\r\n";
    if ( error_type )
    {
      v14 = sprintf_s(
              buffer,
              (unsigned int)message_size - (buffer - message),
              "%s%sPress OK to abort execution%s",
              endline,
              endline,
              endline);
    }
    else
    {
      v12 = sprintf_s(
              buffer,
              (unsigned int)message_size - (buffer - message),
              "%s%sPress CANCEL to abort execution%s",
              endline,
              endline,
              endline);
      buffer += v12;
      v13 = sprintf_s(
              buffer,
              (unsigned int)message_size - (buffer - message),
              "Press TRY AGAIN to continue execution%s",
              endline);
      buffer += v13;
      v14 = sprintf_s(
              buffer,
              (unsigned int)message_size - (buffer - message),
              "Press CONTINUE to continue execution and ignore all the errors of this type%s%s",
              endline,
              endline);
    }
    buffer += v14;
    if ( error_type != error_type_unhandled_exception )
    {
      if ( do_debug_break )
        *do_debug_break = 1;
      vostok::debug::on_error(message);
    }
  }
}
