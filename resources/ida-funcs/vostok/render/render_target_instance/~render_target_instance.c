void __thiscall vostok::render::render_target_instance::~render_target_instance(
        vostok::render::render_target_instance *this)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->texture);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->target);
}
