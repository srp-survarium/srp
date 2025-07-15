vostok::collision::animated_object *__thiscall vostok::collision::animated_object::`scalar deleting destructor'(
        vostok::collision::animated_object *this,
        char a2)
{
  vostok::collision::animated_object::~animated_object(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
