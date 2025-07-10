void __usercall survarium::weapon_core_chamber_a_round_aimed_state_base::~weapon_core_chamber_a_round_aimed_state_base(
        survarium::weapon_core_show_state_base *this@<ecx>,
        int a2@<esi>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 312));
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)(a2 + 24));
}
