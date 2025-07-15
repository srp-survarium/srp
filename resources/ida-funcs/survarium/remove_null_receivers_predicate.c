bool __cdecl survarium::remove_null_receivers_predicate(const survarium::hit_receiver_info *info)
{
  return info->m_receiver == 0;
}
