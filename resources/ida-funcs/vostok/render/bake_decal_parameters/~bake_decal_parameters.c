void __usercall vostok::render::bake_decal_parameters::~bake_decal_parameters(
        vostok::render::bake_decal_parameters *this@<ecx>,
        int a2@<esi>)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 944));
  vostok::render::bake_decal_parameters::texture_entry_desc::~texture_entry_desc((vostok::render::bake_decal_parameters::texture_entry_desc *)(a2 + 800));
  `vector destructor iterator'(
    (char *)a2,
    0x50u,
    10,
    (void (__thiscall *)(void *))vostok::render::bake_decal_parameters::texture_entry_desc::~texture_entry_desc);
}
