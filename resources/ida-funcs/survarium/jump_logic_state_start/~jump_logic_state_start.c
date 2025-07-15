void __usercall survarium::jump_logic_state_start::~jump_logic_state_start(
        survarium::jump_logic_state_start *this@<ecx>,
        int a2@<edi>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 48));
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 44));
  survarium::jump_logic_base_state::~jump_logic_base_state((survarium::jump_logic_base_state *)a2);
}
