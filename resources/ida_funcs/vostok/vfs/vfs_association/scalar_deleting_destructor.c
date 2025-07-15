vostok::vfs::vfs_association *__thiscall vostok::vfs::vfs_association::`scalar deleting destructor'(
        vostok::vfs::vfs_association *this,
        char a2)
{
  this->__vftable = (vostok::vfs::vfs_association_vtbl *)&vostok::vfs::vfs_association::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
