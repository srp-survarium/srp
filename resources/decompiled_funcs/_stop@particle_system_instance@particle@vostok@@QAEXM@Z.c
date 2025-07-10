void __thiscall vostok::particle::particle_system_instance::stop(
        vostok::particle::particle_system_instance *this,
        float time)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v2; // [esp-4h] [ebp-14h] BYREF
  float v3; // [esp+0h] [ebp-10h]
  vostok::particle::particle_system_instance *thisa; // [esp+4h] [ebp-Ch]

  thisa = this;
  v3 = time;
  v2.m_object = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v2,
    (vostok::configs::binary_config *)this);
  ((void (__thiscall *)(vostok::particle::particle_world *, vostok::resources::unmanaged_resource *, _DWORD))thisa->m_particle_world->stop)(
    thisa->m_particle_world,
    v2.m_object,
    LODWORD(v3));
}
