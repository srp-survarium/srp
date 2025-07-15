void __thiscall vostok::sound::sound_world::remove_scene_from_active(
        vostok::sound::sound_world *this,
        vostok::sound::sound_scene *scene)
{
  vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
    &this->m_active_scenes,
    scene);
}
