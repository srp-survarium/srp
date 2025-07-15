survarium::game_object_static *__thiscall vostok::resources::helper_unmanaged_resource::`scalar deleting destructor'(
        survarium::game_object_static *this,
        char a2)
{
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
