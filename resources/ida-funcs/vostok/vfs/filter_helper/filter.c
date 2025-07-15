int __thiscall vostok::vfs::filter_helper::filter(
        vostok::vfs::filter_helper *this,
        const char *description,
        const char *physical_path,
        const char *virtual_path)
{
  int result; // eax

  LOBYTE(result) = this->current++ == this->index;
  return result;
}
