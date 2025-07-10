vostok::sound::sound_receiver *__thiscall vostok::sound::sound_receiver::`vector deleting destructor'(
        vostok::sound::sound_receiver *this,
        char a2)
{
  vostok::sound::sound_receiver::~sound_receiver(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
