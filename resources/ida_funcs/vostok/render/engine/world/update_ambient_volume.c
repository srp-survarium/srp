void __thiscall vostok::render::engine::world::update_ambient_volume(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        vostok::render::scene *id,
        const vostok::render::ambient_volume_properties *properties)
{
  vostok::render::scene::update_ambient_volume(id, (int)in_scene->m_object, (unsigned int)id, properties);
}
