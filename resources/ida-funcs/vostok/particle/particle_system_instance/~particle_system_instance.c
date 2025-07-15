void __usercall vostok::particle::particle_system_instance::~particle_system_instance(
        vostok::particle::particle_system_instance *this@<ecx>,
        int a2@<esi>)
{
  `vector destructor iterator'(
    (char *)(a2 + 264),
    0x20u,
    10,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
