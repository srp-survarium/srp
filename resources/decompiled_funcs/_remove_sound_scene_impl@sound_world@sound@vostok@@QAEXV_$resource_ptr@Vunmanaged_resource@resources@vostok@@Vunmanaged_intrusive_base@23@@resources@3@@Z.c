void __thiscall vostok::sound::sound_world::remove_sound_scene_impl(
        vostok::sound::sound_world *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> scene)
{
  vostok::sound::sound_scene::stop((vostok::sound::sound_scene *)scene.m_object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&scene);
}
