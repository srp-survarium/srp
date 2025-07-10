void __cdecl vostok::debug::set_thread_stack_guarantee()
{
  survarium::game_camera *v0; // ecx
  survarium::game_camera *v1; // ecx
  HMODULE kernel32; // [esp+4h] [ebp-Ch]
  unsigned int stack_size; // [esp+8h] [ebp-8h] BYREF
  int result; // [esp+Ch] [ebp-4h]

  stack_size = 0x8000;
  if ( !LOBYTE(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_cursor_ui.m_object) )
  {
    LOBYTE(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_cursor_ui.m_object) = 1;
    kernel32 = LoadLibraryA("kernel32.dll");
    survarium::weapon_user_dead_state::finalize(v0);
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options_ui.m_object = (survarium::flash_movie_resource *)GetProcAddress(kernel32, "SetThreadStackGuarantee");
  }
  if ( `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options_ui.m_object )
  {
    result = ((int (__stdcall *)(unsigned int *))`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options_ui.m_object)(&stack_size);
    survarium::weapon_user_dead_state::finalize(v1);
  }
}
