void __thiscall vostok::vfs::physical_folder_node<1>::physical_folder_node<1>(
        vostok::vfs::physical_folder_node<1> *this)
{
  _DWORD v1[3]; // [esp+14h] [ebp-Ch] BYREF

  this->children_arena.m_data = 0;
  this->children_arena.m_size = 0;
  v1[1] = v1;
  v1[0] = 0;
  this->m_folder_flags.m_flags = 0;
  this->folder.m_first_child.max_storage = 0;
  this->folder.m_first_child.pointer = 0;
  this->folder.m_readers_writers_counters.m_counters.0 = 0;
  this->folder.m_readers_writers_counters.m_counters.0 = 0;
  vostok::vfs::base_node<1>::base_node<1>(&this->folder.base, 1u);
}
