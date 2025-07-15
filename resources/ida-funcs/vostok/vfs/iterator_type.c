int __cdecl vostok::vfs::iterator_type(vostok::vfs::find_enum find_flags)
{
  return 2 - ((find_flags & 1) != 0);
}
