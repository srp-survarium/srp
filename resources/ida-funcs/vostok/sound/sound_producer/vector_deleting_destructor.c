vostok::sound::sound_producer *__thiscall vostok::sound::sound_producer::`vector deleting destructor'(
        vostok::sound::sound_producer *this,
        char a2)
{
  vostok::sound::sound_producer::~sound_producer(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
