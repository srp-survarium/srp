vostok::animation::animation_collection *__thiscall vostok::animation::animation_collection::`scalar deleting destructor'(
        vostok::animation::animation_collection *this,
        char a2)
{
  vostok::animation::animation_collection::~animation_collection(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
