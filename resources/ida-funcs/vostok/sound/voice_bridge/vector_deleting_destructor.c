vostok::sound::voice_bridge *__thiscall vostok::sound::voice_bridge::`vector deleting destructor'(
        vostok::sound::voice_bridge *this,
        char a2)
{
  vostok::sound::voice_bridge::~voice_bridge(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
