BOOL __cdecl vostok::vfs::folders_connected_by_overlap(
        vostok::vfs::base_node<1> *overlapper,
        vostok::vfs::base_node<1> *overlapped)
{
  while ( overlapper && (overlapper->m_flags & 1) == 1 && overlapper != overlapped )
    overlapper = overlapper->m_next_overlapped.pointer;
  return overlapper == overlapped;
}
