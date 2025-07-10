vostok::resources::managed_resource *__thiscall vostok::resources::managed_resource::`vector deleting destructor'(
        vostok::resources::managed_resource *this,
        char a2)
{
  vostok::resources::managed_resource::~managed_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
