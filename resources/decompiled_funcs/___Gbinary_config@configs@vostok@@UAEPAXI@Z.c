vostok::configs::binary_config *__thiscall vostok::configs::binary_config::`scalar deleting destructor'(
        vostok::configs::binary_config *this,
        char a2)
{
  this->__vftable = (vostok::configs::binary_config_vtbl *)&vostok::configs::binary_config::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
