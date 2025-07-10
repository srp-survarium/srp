vostok::sound::sound_collection *__thiscall vostok::sound::sound_collection::`scalar deleting destructor'(
        vostok::sound::sound_collection *this,
        char a2)
{
  vostok::sound::sound_collection::~sound_collection(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
