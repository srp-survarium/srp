void __thiscall survarium::items_dictionary::~items_dictionary(survarium::items_dictionary *this)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  survarium::dictionary_item *m_items_dict; // eax
  unsigned int *p_faction_affinity; // ebx
  survarium::dictionary_item *v5; // ebp
  survarium::dictionary_item *v6; // edi
  survarium::quest_descriptor *m_quests; // eax
  survarium::items_compatibility *M_start; // ecx
  unsigned int item_level; // [esp+10h] [ebp-8h]
  vostok::memory::base_allocator *v10; // [esp+14h] [ebp-4h]

  m_allocator = this->m_allocator;
  this->__vftable = (survarium::items_dictionary_vtbl *)&survarium::items_dictionary::`vftable';
  m_items_dict = this->m_items_dict;
  v10 = m_allocator;
  if ( m_items_dict )
  {
    p_faction_affinity = &m_items_dict[-1].faction_affinity;
    v5 = this->m_items_dict;
    v6 = (survarium::dictionary_item *)((char *)m_items_dict
                                      + m_items_dict[-1].item_level * m_items_dict[-1].faction_affinity);
    item_level = m_items_dict[-1].item_level;
    if ( m_items_dict != v6 )
    {
      do
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v5->item_cfg);
        v5 = (survarium::dictionary_item *)((char *)v5 + item_level);
      }
      while ( v5 != v6 );
      m_allocator = v10;
    }
    m_allocator->call_free(
      m_allocator,
      p_faction_affinity,
      "survarium::items_dictionary::~items_dictionary",
      ".\\items_dictionary_cook.cpp",
      212u);
  }
  m_quests = this->m_quests;
  if ( m_quests )
    this->m_allocator->call_free(
      this->m_allocator,
      &m_quests[-1].task_descriptions_count,
      "survarium::items_dictionary::~items_dictionary",
      ".\\items_dictionary_cook.cpp",
      213u);
  M_start = this->m_item_compatibilities._M_impl._M_start;
  if ( M_start )
    this->m_item_compatibilities._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_item_compatibilities._M_impl._M_end_of_storage.m_allocator,
      M_start,
      "vostok::detail::std_allocator<struct survarium::items_compatibility>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102u);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_quests_config);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_dict_config);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->default_bodyparts_config);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
}
