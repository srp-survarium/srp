void __thiscall survarium::application::preinitialize(survarium::application *this, survarium::application *thisa)
{
  const char *CommandLineA; // eax
  vostok::engine::engine_world *v3; // ecx
  char *m_end; // ecx
  char *v5; // eax
  bool v6; // zf
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v8; // [esp+0h] [ebp-68h]
  vostok::threading::tasks_awareness v9; // [esp+0h] [ebp-68h]
  const char *v10; // [esp+4h] [ebp-64h]
  void **v11; // [esp+4h] [ebp-64h]
  boost::function<void __cdecl(void)> function_to_call; // [esp+8h] [ebp-60h] BYREF
  char temp[64]; // [esp+28h] [ebp-40h] BYREF

  CommandLineA = GetCommandLineA();
  vostok::engine::engine_world::engine_world(v3, (int)&s_world, &thisa->m_game_proxy, CommandLineA, v8, v10);
  _InterlockedExchange(&s_world.m_initialized, 1);
  decode_finger_print((char (*)[64])temp);
  m_end = temp;
  if ( s_finger_print_0.m_begin != temp )
  {
    s_finger_print_0.m_end = s_finger_print_0.m_begin;
    *s_finger_print_0.m_begin = 0;
    m_end = s_finger_print_0.m_end;
    v5 = temp;
    if ( temp[0] )
    {
      do
      {
        if ( m_end >= s_finger_print_0.m_max_end )
          break;
        *m_end = *v5;
        m_end = s_finger_print_0.m_end + 1;
        v6 = *++v5 == 0;
        ++s_finger_print_0.m_end;
      }
      while ( !v6 );
    }
    *m_end = 0;
  }
  if ( !vostok::engine::engine_world::command_line_no_splash_screen((vostok::engine::engine_world *)m_end) )
  {
    function_to_call.vtable = 0;
    if ( `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable )
      `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable(
        &function_to_call.functor,
        &function_to_call.functor,
        destroy_functor_tag);
    if ( splash_screen_main )
    {
      function_to_call.functor.obj_ptr = splash_screen_main;
      function_to_call.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable
                                                                       + 1);
    }
    else
    {
      function_to_call.vtable = 0;
    }
    vostok::threading::spawn(&function_to_call, "splash screen", "splash", 0, 1u, v9, v11);
    if ( function_to_call.vtable && ((int)function_to_call.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)function_to_call.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&function_to_call.functor, &function_to_call.functor, 2);
    }
  }
}
