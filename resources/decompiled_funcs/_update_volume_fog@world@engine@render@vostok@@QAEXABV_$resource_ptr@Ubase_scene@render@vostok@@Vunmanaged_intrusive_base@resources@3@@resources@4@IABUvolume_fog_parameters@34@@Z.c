void __thiscall vostok::render::engine::world::update_volume_fog(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        vostok::render::scene *id,
        const vostok::render::volume_fog_parameters *in_parameters)
{
  vostok::render::scene::update_volume_fog(id, (int)in_scene->m_object, (unsigned int)id, in_parameters);
}
