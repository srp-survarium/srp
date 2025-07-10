BOOL __thiscall vostok::vfs::base_folder_node<1>::has_some_lock(vostok::vfs::base_folder_node<1> *this)
{
  return *(_DWORD *)&this->m_readers_writers_counters.m_counters.0 != 0;
}
