vostok::render::render_collision_object<vostok::render::render_model_instance_impl> *__thiscall vostok::collision::aabb_object::`scalar deleting destructor'(
        vostok::render::render_collision_object<vostok::render::render_model_instance_impl> *this,
        char a2)
{
  this->__vftable = (vostok::render::render_collision_object<vostok::render::render_model_instance_impl>_vtbl *)&vostok::collision::object::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
