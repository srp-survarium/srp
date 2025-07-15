void __userpurge survarium::inventory::take_artefact(
        survarium::inventory *this@<ecx>,
        survarium::inventory *a2@<eax>,
        const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *item)
{
  unsigned __int8 m_artefact_slots_count; // al
  int v5; // ebx
  unsigned __int8 v6; // cl
  bool v7; // cc
  int v8; // edi
  vostok::particle::particle_system_instance_impl **v9; // eax
  vostok::particle::particle_system_instance_impl *v10; // ecx
  survarium::profile_slot_enum v11; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 v13; // [esp+13h] [ebp-1h]

  m_artefact_slots_count = a2->m_artefact_slots_count;
  v5 = ((char *)a2->m_artefact_slots - (char *)a2 - 272) >> 2;
  v6 = 0;
  if ( m_artefact_slots_count )
  {
    while ( a2->m_artefact_slots[v6].m_object )
    {
      if ( ++v6 >= m_artefact_slots_count )
        goto LABEL_4;
    }
    v11 = v5 + v6;
  }
  else
  {
LABEL_4:
    survarium::inventory::remove_item(
      a2,
      (const survarium::profile_slot_enum)(((char *)a2->m_artefact_slots - (char *)a2 - 272) >> 2));
    v7 = a2->m_artefact_slots_count <= 1u;
    v13 = 1;
    if ( !v7 )
    {
      do
      {
        v8 = v13;
        survarium::inventory::set_item(
          a2,
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&a2->m_artefact_slots[v8],
          (survarium::profile_slot_enum)(v13 + v5 - 1));
        v9 = (vostok::particle::particle_system_instance_impl **)&a2->m_artefact_slots[v8];
        v10 = *v9;
        *v9 = 0;
        v12.m_object = v10;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
        ++v13;
      }
      while ( v13 < a2->m_artefact_slots_count );
    }
    v11 = a2->m_artefact_slots_count + v5 - 1;
  }
  survarium::inventory::set_item(a2, item, v11);
  ((void (__thiscall *)(vostok::particle::particle_system_instance_impl *))item->m_object->__vftable[1].link_child_resource)(item->m_object);
}
