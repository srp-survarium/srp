vostok::collision::aabb_object *__thiscall vostok::collision::aabb_object::`scalar deleting destructor'(
        vostok::collision::aabb_object *this,
        char a2)
{
  this->__vftable = (vostok::collision::aabb_object_vtbl *)&vostok::collision::object::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
