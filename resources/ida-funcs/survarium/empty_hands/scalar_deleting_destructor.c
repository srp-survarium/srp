survarium::empty_hands *__thiscall survarium::empty_hands::`scalar deleting destructor'(
        survarium::empty_hands *this,
        char a2)
{
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
