vostok::physics::bt_character_controller *__cdecl vostok::physics::create_character_controller(
        vostok::physics::bullet_physics_world *w)
{
  vostok::physics::bt_character_controller *result; // eax

  result = (vostok::physics::bt_character_controller *)(*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)LODWORD(survarium::g_allocator.f_.f_)
                                                                                          + 16))(
                                                         survarium::g_allocator.f_.f_,
                                                         12);
  if ( !result )
    return 0;
  result->m_active = 0;
  result->m_bt_physics_world = w;
  return result;
}
