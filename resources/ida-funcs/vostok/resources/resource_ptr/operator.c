vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *this,
        vostok::configs::binary_config *object)
{
  vostok::render::base_scene_view *m_object; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+Ch] [ebp-4h] BYREF

  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    object);
  m_object = this->m_object;
  this->m_object = (vostok::render::base_scene_view *)v5.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  return this;
}


vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  vostok::resources::unmanaged_resource *v3; // ecx
  vostok::resources::unmanaged_resource *v4; // eax

  v2 = 0;
  if ( this )
  {
    v2 = this;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this[52], 1u);
  }
  v3 = (vostok::resources::unmanaged_resource *)v2;
  v4 = *a2;
  *a2 = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  return (vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *)a2;
}


vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *object)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this,
    (const vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)object);
  return this;
}


vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *object)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+Ch] [ebp-4h] BYREF

  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    object);
  m_object = this->m_object;
  this->m_object = v5.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  return this;
}


vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        vostok::configs::binary_config *object@<eax>)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+8h] [ebp-4h] BYREF

  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    object);
  m_object = this->m_object;
  this->m_object = v4.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  return this;
}


vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *object)
{
  vostok::physics::bt_collision_shape *m_object; // eax
  vostok::physics::bt_collision_shape *v4; // ecx
  vostok::physics::bt_collision_shape *v5; // eax

  m_object = 0;
  if ( object->m_object )
  {
    m_object = object->m_object;
    _InterlockedExchangeAdd(&object->m_object->m_reference_count, 1u);
  }
  v4 = m_object;
  v5 = this->m_object;
  this->m_object = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  return this;
}


vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  survarium::human_npc *m_object; // eax

  v2 = this;
  this = 0;
  vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  m_object = v2->m_object;
  v2->m_object = (survarium::human_npc *)this;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      &m_object->survarium::game_object_);
  return v2;
}


vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *this@<esi>,
        vostok::resources::managed_resource *object@<eax>)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v4; // [esp+0h] [ebp-4h] BYREF

  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    object);
  m_object = v4.m_object;
  v4.m_object = this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v4);
  return this;
}


vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::animation::skeleton *m_object; // ecx
  vostok::animation::skeleton *v3; // eax
  vostok::resources::unmanaged_resource *v4; // edx

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = *a2;
  *a2 = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  return (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)a2;
}


vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::resources::unmanaged_resource *v2; // eax

  v2 = *a2;
  *a2 = 0;
  if ( v2 && !_InterlockedExchangeAdd(&v2->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v2->vostok::resources::unmanaged_intrusive_base, v2);
  return (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)a2;
}


vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *__usercall vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource>::operator=@<eax>(
        vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  survarium::rifle_scope *m_object; // ecx
  survarium::rifle_scope *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  vostok::resources::unmanaged_resource *v5; // eax

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = v3;
  v5 = *a2;
  *a2 = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  return (vostok::resources::resource_ptr<survarium::rifle_scope,vostok::resources::unmanaged_resource> *)a2;
}


vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *object)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    this,
    object);
  return this;
}


vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        vostok::configs::binary_config *object@<eax>)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+0h] [ebp-4h] BYREF

  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    object);
  m_object = this->m_object;
  this->m_object = v4.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  return this;
}


vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *__usercall vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<esi>)
{
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v3; // ecx
  vostok::resources::unmanaged_resource *v4; // eax

  v2 = 0;
  if ( this )
  {
    v2 = this;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this[52], 1u);
  }
  v3 = v2;
  v4 = *a2;
  *a2 = (vostok::resources::unmanaged_resource *)v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  return (vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)a2;
}
