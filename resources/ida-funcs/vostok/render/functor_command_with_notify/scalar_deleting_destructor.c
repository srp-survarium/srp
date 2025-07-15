vostok::render::functor_command_with_notify *__thiscall vostok::render::functor_command_with_notify::`scalar deleting destructor'(
        vostok::render::functor_command_with_notify *this,
        char a2)
{
  vostok::render::functor_command_with_notify::~functor_command_with_notify(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
