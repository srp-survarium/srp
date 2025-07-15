survarium::weapon_user_animations_container *__thiscall survarium::weapon_user_animations_container::`vector deleting destructor'(
        survarium::weapon_user_animations_container *this,
        char a2)
{
  `vector destructor iterator'(
    (char *)this->m_animations,
    0x3A0u,
    2,
    (void (__thiscall *)(void *))survarium::weapon_user_animations_container::animations_collection::~animations_collection);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
