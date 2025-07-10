void __usercall survarium::game::create_lobby_menu(survarium::game *this@<ecx>, survarium::game *a2@<esi>)
{
  survarium::lobby_menu *v2; // ecx
  survarium::lobby_menu *v3; // eax

  v2 = (survarium::lobby_menu *)vostok::memory::doug_lea_allocator::malloc_impl(
                                  (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                  0x12Cu);
  if ( v2 )
  {
    survarium::lobby_menu::lobby_menu(v2, a2);
    a2->m_lobby_menu = v3;
  }
  else
  {
    a2->m_lobby_menu = 0;
  }
}
