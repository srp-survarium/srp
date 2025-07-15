void __thiscall vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> *this,
        vostok::ai::sound_player *object)
{
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    this,
    object);
}


void __thiscall vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
        vostok::intrusive_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other)
{
  vostok::render::culling::portal_sector_structure *m_object; // edx

  this->m_object = 0;
  m_object = other->m_object;
  if ( other->m_object )
  {
    this->m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __thiscall vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *this,
        vostok::configs::binary_config *object)
{
  this->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    this,
    object);
}


void __usercall vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> **a2@<eax>)
{
  *a2 = 0;
  if ( this )
  {
    *a2 = this;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this[52], 1u);
  }
}


void __usercall vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
        vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<ecx>,
        survarium::inventory **a2@<eax>)
{
  survarium::inventory *m_object; // ecx

  *a2 = 0;
  m_object = this->m_object;
  if ( m_object )
  {
    *a2 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __thiscall vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *other)
{
  this->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    this,
    other);
}


void __thiscall vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *this,
        vostok::resources::managed_resource *object)
{
  this->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    this,
    object);
}


void __thiscall vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base> *other)
{
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    this,
    other);
}


void __usercall vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        const vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *other@<edi>,
        survarium::profile_player_character *a3@<ecx>)
{
  survarium::player *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(
      (vostok::memory::detail::call_destructor_predicate *)this,
      a3);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        survarium::player *object@<edi>,
        survarium::profile_player_character *a3@<ecx>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(
      (vostok::memory::detail::call_destructor_predicate *)this,
      a3);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __thiscall vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>(
        vostok::render::stage_lights::lights_instance *this)
{
  this->m_instance_vb.m_object = 0;
}


void __thiscall vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *other)
{
  this->m_object = 0;
  if ( this->m_object != other->m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = other->m_object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __thiscall vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *this,
        survarium::weapon_core_base_state *object)
{
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    this,
    object);
}
