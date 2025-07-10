vostok::collision::sphere_geometry_instance *__thiscall vostok::collision::box_geometry_instance::`scalar deleting destructor'(
        vostok::collision::sphere_geometry_instance *this,
        char a2)
{
  this->__vftable = (vostok::collision::sphere_geometry_instance_vtbl *)&vostok::collision::geometry_instance::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
