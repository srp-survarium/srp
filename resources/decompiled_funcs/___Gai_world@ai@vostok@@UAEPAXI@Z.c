vostok::ai::ai_world *__thiscall vostok::ai::ai_world::`scalar deleting destructor'(
        vostok::ai::ai_world *this,
        char a2)
{
  vostok::ai::ai_world::~ai_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
