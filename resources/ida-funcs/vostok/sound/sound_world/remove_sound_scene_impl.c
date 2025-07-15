void __thiscall vostok::sound::sound_world::remove_sound_scene_impl(
        vostok::sound::sound_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> scene)
{
  vostok::sound::sound_scene::stop((vostok::sound::sound_scene *)this, (vostok::sound::sound_scene *)scene.m_object);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&scene);
}
