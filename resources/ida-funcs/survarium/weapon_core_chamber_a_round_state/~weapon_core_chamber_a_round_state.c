void __usercall survarium::weapon_core_chamber_a_round_state::~weapon_core_chamber_a_round_state(
        survarium::weapon_core_chamber_a_round_state *this@<ecx>,
        int a2@<esi>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 356));
  `vector destructor iterator'(
    (char *)(a2 + 324),
    4u,
    8,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)(a2 + 24));
}
