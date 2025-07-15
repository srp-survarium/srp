BOOL __cdecl survarium::is_dead(survarium::base_player **user)
{
  return !(*user)->m_is_alive;
}
