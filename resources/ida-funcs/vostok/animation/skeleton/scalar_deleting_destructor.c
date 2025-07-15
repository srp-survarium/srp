vostok::animation::skeleton *__thiscall vostok::animation::skeleton::`scalar deleting destructor'(
        vostok::animation::skeleton *this,
        char a2)
{
  this->__vftable = (vostok::animation::skeleton_vtbl *)&vostok::animation::skeleton::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
