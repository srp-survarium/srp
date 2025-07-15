vostok::sound::sound_collection_cook *__thiscall vostok::sound::sound_collection_cook::`vector deleting destructor'(
        vostok::sound::sound_collection_cook *this,
        char a2)
{
  vostok::sound::sound_collection_cook::~sound_collection_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
