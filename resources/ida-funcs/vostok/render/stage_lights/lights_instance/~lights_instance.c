// attributes: thunk
void __thiscall vostok::render::stage_lights::lights_instance::~lights_instance(
        vostok::render::stage_lights::lights_instance *this)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&this->m_instance_vb);
}
