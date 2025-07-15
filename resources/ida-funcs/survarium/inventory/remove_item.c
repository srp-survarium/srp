void __usercall survarium::inventory::remove_item(
        survarium::inventory *this@<edi>,
        const survarium::profile_slot_enum slot@<eax>)
{
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v2; // esi
  vostok::particle::particle_system_instance_impl *m_object; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+4h] [ebp-4h] BYREF

  v2 = &this->m_slots.elems[slot];
  v2->m_object->removed_from_inventory(v2->m_object);
  v2->m_object->set_inventory(v2->m_object, 0, max_slots_count);
  m_object = (vostok::particle::particle_system_instance_impl *)v2->m_object;
  v2->m_object = 0;
  v4.m_object = m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  this->m_need_to_recalculate_weight = 1;
}
