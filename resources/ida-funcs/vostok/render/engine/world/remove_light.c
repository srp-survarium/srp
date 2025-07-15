void __thiscall vostok::render::engine::world::remove_light(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int id)
{
  vostok::render::scene::remove_light((vostok::render::scene *)in_scene->m_object, id);
}
