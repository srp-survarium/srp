vostok::render::speed_tree_allocator *__thiscall SpeedTree::CAllocator::`vector deleting destructor'(
        vostok::render::speed_tree_allocator *this,
        char a2)
{
  this->__vftable = (vostok::render::speed_tree_allocator_vtbl *)&SpeedTree::CAllocator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
