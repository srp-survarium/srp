vostok::resources::resource_base *__thiscall vostok::resources::resource_base::`vector deleting destructor'(
        vostok::resources::resource_base *this,
        char a2)
{
  vostok::resources::resource_base::~resource_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
