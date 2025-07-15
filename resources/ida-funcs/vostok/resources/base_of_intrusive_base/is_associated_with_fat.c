char __thiscall vostok::resources::base_of_intrusive_base::is_associated_with_fat(
        vostok::resources::base_of_intrusive_base *this,
        vostok::vfs::vfs_hashset *object)
{
  vostok::vfs::vfs_iterator v3; // [esp-4h] [ebp-24h]

  v3.m_hashset = object;
  v3.m_node = *(vostok::vfs::base_node<1> **)&object->m_hashlocks[20].m_readers_writers_counter.readers_count;
  *(_QWORD *)&v3.m_link_target = *(volatile __int64 *)((char *)&object->m_hashlocks[20].m_readers_writers_counter.whole
                                                     + 4);
  return vostok::resources::is_associated_with(v3);
}
