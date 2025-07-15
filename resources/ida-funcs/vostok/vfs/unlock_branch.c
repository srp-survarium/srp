void __usercall vostok::vfs::unlock_branch(
        vostok::vfs::base_node<1> *node@<eax>,
        vostok::vfs::lock_type_enum lock_type)
{
  vostok::vfs::base_node<1> *v2; // esi
  vostok::vfs::base_node<1> *v3; // ecx

  v2 = node;
  if ( node )
  {
    do
    {
      vostok::vfs::unlock_node(v2, lock_type);
      if ( !v2->m_parent.pointer )
        break;
      lock_type = vostok::vfs::soften_lock(lock_type);
      v2 = v3;
    }
    while ( v3 );
  }
}
