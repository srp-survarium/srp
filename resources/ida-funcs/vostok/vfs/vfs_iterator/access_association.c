void __userpurge vostok::vfs::vfs_iterator::access_association(
        vostok::vfs::vfs_iterator *this@<ecx>,
        int a2@<eax>,
        boost::function<void __cdecl(vostok::vfs::vfs_association * &)> *callback)
{
  vostok::vfs::base_node<1> *v3; // ecx
  const boost::function<void __cdecl(vostok::vfs::vfs_association * &)> *v4; // eax

  v3 = *(vostok::vfs::base_node<1> **)(a2 + 8);
  if ( v3 )
    v4 = *(const boost::function<void __cdecl(vostok::vfs::vfs_association * &)> **)(a2 + 8);
  else
    v4 = *(const boost::function<void __cdecl(vostok::vfs::vfs_association * &)> **)(a2 + 4);
  vostok::vfs::base_node<1>::access_association(v3, v4, callback);
}
