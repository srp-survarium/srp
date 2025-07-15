vostok::memory::managed_node_owner *__thiscall vostok::memory::managed_node_owner::`vector deleting destructor'(
        vostok::memory::managed_node_owner *this,
        char a2)
{
  this->__vftable = (vostok::memory::managed_node_owner_vtbl *)&vostok::memory::managed_node_owner::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
