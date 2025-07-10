void __usercall survarium::game::create_login_menu(survarium::game *this@<ecx>, survarium::game *a2@<esi>)
{
  survarium::login_menu *v2; // ecx
  survarium::login_menu *v3; // eax

  v2 = (survarium::login_menu *)vostok::memory::doug_lea_allocator::malloc_impl(
                                  (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                  0xD0u);
  if ( v2 )
  {
    survarium::login_menu::login_menu(v2, a2);
    a2->m_login_menu = v3;
  }
  else
  {
    a2->m_login_menu = 0;
  }
}
