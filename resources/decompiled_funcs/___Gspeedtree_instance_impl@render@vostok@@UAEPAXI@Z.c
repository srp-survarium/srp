vostok::render::speedtree_instance_impl *__thiscall vostok::render::speedtree_instance_impl::`scalar deleting destructor'(
        vostok::render::speedtree_instance_impl *this,
        char a2)
{
  vostok::render::speedtree_instance_impl::~speedtree_instance_impl(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
