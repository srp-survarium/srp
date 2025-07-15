void __thiscall vostok::render::engine::world::remove_unused_environment_cubemaps(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene)
{
  vostok::render::scene::remove_unused_environment_cubemaps(
    (vostok::render::scene *)scene->m_object,
    (vostok::render::scene *)scene->m_object);
}
