void __usercall vostok::vfs::vfs_iterator::vfs_iterator(vostok::vfs::vfs_iterator *this@<ecx>, int a2@<eax>)
{
  if ( ((int)this[3].m_hashset & 0x800) == 0x800 )
  {
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 8) = 0;
  }
}
