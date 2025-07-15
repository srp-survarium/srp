vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *this@<edi>,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *object@<esi>)
{
  vostok::resources::unmanaged_allocation_resource *m_object; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+4h] [ebp-4h] BYREF

  m_object = 0;
  v4.m_object = 0;
  if ( object->m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
    m_object = object->m_object;
    if ( object->m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4.m_object = (vostok::particle::particle_system_instance_impl *)this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  return this;
}


vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object@<edi>,
        vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  survarium::artefact_base **v3; // eax
  survarium::artefact_base *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::particle::particle_system_instance_impl **a2@<esi>)
{
  vostok::particle::particle_system_instance_impl *v2; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+4h] [ebp-4h] BYREF

  v2 = *a2;
  *a2 = 0;
  v4.m_object = v2;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  return (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)a2;
}


vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  vostok::particle::particle_system_instance_impl **v3; // eax
  vostok::particle::particle_system_instance_impl *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        vostok::particle::particle_system_instance_impl *object@<edi>)
{
  vostok::particle::particle_system_instance_impl *m_object; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+4h] [ebp-4h] BYREF

  v4.m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
    v4.m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
  m_object = v4.m_object;
  v4.m_object = (vostok::particle::particle_system_instance_impl *)this->m_object;
  this->m_object = (survarium::player *)m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  return this;
}


vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__userpurge vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *this)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v2; // ebx
  vostok::resources::managed_resource **v3; // eax
  vostok::resources::managed_resource *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *this@<esi>,
        vostok::resources::managed_resource *object@<edi>)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v4; // [esp+4h] [ebp-4h] BYREF

  v4.m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
    v4.m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
  m_object = v4.m_object;
  v4.m_object = this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  return this;
}


vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *__usercall vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource>::operator=@<eax>(
        vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *this@<edi>,
        const vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *object@<esi>)
{
  survarium::rifle_scope *m_object; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+0h] [ebp-4h] BYREF

  m_object = 0;
  v4.m_object = 0;
  if ( object->m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
    m_object = object->m_object;
    if ( object->m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4.m_object = (vostok::particle::particle_system_instance_impl *)this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  return this;
}


vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  survarium::simple_game_project **v3; // eax
  survarium::simple_game_project *v4; // ecx

  v2 = this;
  vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  vostok::resources::unmanaged_resource **v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


void __usercall vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        vostok::particle::particle_system_instance_impl *object@<edi>)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v2; // [esp+0h] [ebp-4h] BYREF

  v2.m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v2);
    v2.m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
  JUMPOUT(0x11410);
}


vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        int *a2@<esi>,
        vostok::resources::vfs_sub_fat_resource *object)
{
  int *v3; // eax
  int v4; // ecx

  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object,
    object);
  v4 = *v3;
  *v3 = *a2;
  *a2 = v4;
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object);
  return (vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)a2;
}


vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  survarium::victory_items_container_core **v3; // eax
  survarium::victory_items_container_core *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  return v2;
}


vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  survarium::weapon_core_base_state **v3; // eax
  survarium::weapon_core_base_state *v4; // ecx

  v2 = this;
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  v4 = *v3;
  *v3 = v2->m_object;
  v2->m_object = v4;
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  return v2;
}
