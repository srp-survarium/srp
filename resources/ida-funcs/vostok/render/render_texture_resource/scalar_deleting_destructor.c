vostok::render::render_texture_resource *__thiscall vostok::render::render_texture_resource::`scalar deleting destructor'(
        vostok::render::render_texture_resource *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->texture);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
