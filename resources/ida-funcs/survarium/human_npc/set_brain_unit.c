void __usercall survarium::human_npc::set_brain_unit(
        survarium::human_npc *this@<ecx>,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *brain_unit@<eax>)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_brain_unit,
    brain_unit);
}
