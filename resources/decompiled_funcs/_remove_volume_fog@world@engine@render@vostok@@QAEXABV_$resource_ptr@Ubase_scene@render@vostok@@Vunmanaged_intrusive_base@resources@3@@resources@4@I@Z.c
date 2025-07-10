void __thiscall vostok::render::engine::world::remove_volume_fog(
        vostok::render::engine::world *this,
        vostok::render::scene *in_scene,
        unsigned int id)
{
  vostok::render::scene::remove_volume_fog(in_scene, (vostok::render::scene *)in_scene->__vftable, id);
}
