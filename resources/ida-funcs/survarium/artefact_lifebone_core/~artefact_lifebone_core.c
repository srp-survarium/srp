void __thiscall survarium::artefact_lifebone_core::~artefact_lifebone_core(survarium::artefact_lifebone_core *this)
{
  this->survarium::artefact_base::survarium::inventory_item::survarium::interactive_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::artefact_lifebone_core_vtbl *)&survarium::artefact_lifebone_core::`vftable'{for `survarium::artefact_base'};
  this->survarium::damage_protector::__vftable = (survarium::damage_protector_vtbl *)&survarium::artefact_lifebone_core::`vftable'{for `survarium::damage_protector'};
  `vector destructor iterator'(
    (char *)this->m_damage_protectors,
    0x50u,
    4,
    (void (__thiscall *)(void *))survarium::damage_protector::~damage_protector);
  survarium::damage_protector::~damage_protector(&this->survarium::damage_protector);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_action_behaviuor);
  survarium::interactive_object::~interactive_object(this);
}
