bool __thiscall vostok::resources::query_result::is_compressed(vostok::resources::query_result *this)
{
  return vostok::vfs::vfs_iterator::is_compressed(&this->m_fat_it);
}
