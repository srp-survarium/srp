void __thiscall vostok::particle::particle_world::change_material(
        vostok::particle::particle_world *this,
        vostok::particle::particle_emitter_instance *instance,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *material)
{
  vostok::particle::particle_emitter_instance::change_material(instance, material);
}
