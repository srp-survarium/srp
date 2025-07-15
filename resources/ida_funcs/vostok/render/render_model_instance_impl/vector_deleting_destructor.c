vostok::render::render_model_instance_impl *__thiscall vostok::render::render_model_instance_impl::`vector deleting destructor'(
        vostok::render::render_model_instance_impl *this,
        char a2)
{
  this->m_collision_object.__vftable = (vostok::render::render_collision_object<vostok::render::render_model_instance_impl>_vtbl *)&vostok::collision::object::`vftable';
  this->__vftable = (vostok::render::render_model_instance_impl_vtbl *)&vostok::render::render_model_instance::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
