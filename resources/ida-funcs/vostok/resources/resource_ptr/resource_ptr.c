void __usercall vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        const vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *other@<edi>)
{
  survarium::booby_trap_core *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        vostok::particle::particle_system_instance_impl *object@<edi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __usercall vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        const vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *other@<edi>)
{
  survarium::generic_anomaly_core *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        const vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> *other@<edi>)
{
  survarium::grenade_core *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>(
        vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  survarium::simple_game_project *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *this,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    this,
    other);
  return this;
}


void __usercall vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        survarium::pure_game_effect_emitter_base *object@<edi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __thiscall vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *this)
{
  this->m_object = 0;
}


void __thiscall vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *this,
        vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object,
        vostok::resources::vfs_sub_fat_resource *objecta)
{
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    object,
    objecta);
}


void __usercall vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        survarium::weapon_core *object@<edi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __usercall vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        survarium::weapon_core_base_state *object@<edi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}
