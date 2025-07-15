vostok::resources::resource_children *__thiscall vostok::resources::resource_children::`vector deleting destructor'(
        vostok::resources::resource_children *this,
        char a2)
{
  this->__vftable = (vostok::resources::resource_children_vtbl *)&vostok::vfs::vfs_association::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
