void __thiscall vostok::render::engine::world::remove_lpv_occluder(
        vostok::render::engine::world *this,
        vostok::render::scene *in_scene,
        unsigned int id)
{
  vostok::render::scene::remove_lpv_occluder(in_scene, (vostok::render::scene *)in_scene->__vftable, id);
}
