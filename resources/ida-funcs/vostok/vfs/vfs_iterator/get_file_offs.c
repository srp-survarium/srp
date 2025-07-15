unsigned __int64 __usercall vostok::vfs::vfs_iterator::get_file_offs@<edx:eax>(
        vostok::vfs::vfs_iterator *this@<ecx>,
        int a2@<eax>)
{
  vostok::vfs::base_node<1> *v2; // eax

  if ( *(_DWORD *)(a2 + 8) )
    v2 = *(vostok::vfs::base_node<1> **)(a2 + 8);
  else
    v2 = *(vostok::vfs::base_node<1> **)(a2 + 4);
  return vostok::vfs::get_file_offs<1>(v2);
}
