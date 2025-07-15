vostok::sound::sound_response *__thiscall vostok::sound::sound_response::`scalar deleting destructor'(
        vostok::sound::sound_response *this,
        char a2)
{
  vostok::sound::sound_response::~sound_response(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
