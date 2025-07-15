vostok::physics::bullet_character_controller *__thiscall vostok::physics::bullet_character_controller::`vector deleting destructor'(
        vostok::physics::bullet_character_controller *this,
        char a2)
{
  vostok::physics::bullet_character_controller::~bullet_character_controller(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
