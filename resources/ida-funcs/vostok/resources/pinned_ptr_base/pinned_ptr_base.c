void __thiscall vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
        vostok::resources::pinned_ptr_base<unsigned char const > *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::memory::managed_node *m_node; // eax
  const unsigned __int8 *v5; // ecx

  this->m_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->m_resource,
    &ptr);
  m_object = ptr.m_object;
  if ( ptr.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = ptr.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v5 = (const unsigned __int8 *)&m_node[1];
    m_object = ptr.m_object;
  }
  else
  {
    v5 = 0;
  }
  this->m_data = v5;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    this->m_size = m_object->m_memory_usage_self.size;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
  else
  {
    this->m_size = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
}


void __userpurge vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *this@<ecx>,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *a2@<esi>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::memory::managed_node *m_node; // eax
  vostok::resources::managed_resource *v5; // ecx

  a2->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    a2,
    &ptr);
  m_object = ptr.m_object;
  if ( ptr.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = ptr.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v5 = (vostok::resources::managed_resource *)&m_node[1];
    m_object = ptr.m_object;
  }
  else
  {
    v5 = 0;
  }
  a2[1].m_object = v5;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    a2[2].m_object = (vostok::resources::managed_resource *)m_object->m_memory_usage_self.size;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
  else
  {
    a2[2].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
  }
}


void __usercall vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>(
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *this@<esi>,
        const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *other@<edi>)
{
  vostok::memory::managed_node *m_node; // eax
  const unsigned __int8 *v3; // eax
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // [esp+0h] [ebp-8h]

  this->m_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->m_resource,
    v4);
  if ( other->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = other->m_resource.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v3 = (const unsigned __int8 *)&m_node[1];
  }
  else
  {
    v3 = 0;
  }
  this->m_data = v3;
  if ( other->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    this->m_size = other->m_resource.m_object->m_memory_usage_self.size;
  }
  else
  {
    this->m_size = 0;
  }
}


void __usercall vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *this@<esi>,
        const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *other@<edi>)
{
  vostok::memory::managed_node *m_node; // eax
  const unsigned __int8 *v3; // eax

  this->m_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->m_resource,
    &other->m_resource);
  if ( other->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_node = other->m_resource.m_object->m_node;
    _InterlockedExchangeAdd(&m_node->m_pin_count, 1u);
    v3 = (const unsigned __int8 *)&m_node[1];
  }
  else
  {
    v3 = 0;
  }
  this->m_data = v3;
  if ( other->m_resource.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    this->m_size = other->m_resource.m_object->m_memory_usage_self.size;
  }
  else
  {
    this->m_size = 0;
  }
}


void __thiscall vostok::resources::pinned_ptr_base<vostok::sound::sound_rms>::pinned_ptr_base<vostok::sound::sound_rms>(
        vostok::resources::pinned_ptr_base<vostok::sound::sound_rms> *this,
        const vostok::resources::pinned_ptr_base<vostok::sound::sound_rms> *other)
{
  unsigned int size; // [esp+0h] [ebp-30h]
  const unsigned __int8 *v3; // [esp+4h] [ebp-2Ch]
  vostok::render::skeleton_model_instance *(__thiscall *v5)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+18h] [ebp-18h]
  vostok::render::skeleton_model_instance *(__thiscall *v6)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+24h] [ebp-Ch]

  this->m_resource.m_object = 0;
  if ( this->m_resource.m_object != other->m_resource.m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_resource);
    this->m_resource.m_object = other->m_resource.m_object;
    if ( this->m_resource.m_object )
      vostok::threading::multi_threading_policy::increment<long volatile>(&this->m_resource.m_object->m_reference_count);
  }
  if ( other->m_resource.m_object )
    v6 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  else
    v6 = 0;
  if ( v6 )
    v3 = vostok::memory::managed_node_owner::pin(&other->m_resource.m_object->vostok::memory::managed_node_owner);
  else
    v3 = 0;
  this->m_data = v3;
  if ( other->m_resource.m_object )
    v5 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  else
    v5 = 0;
  if ( v5 )
    size = other->m_resource.m_object->m_memory_usage_self.size;
  else
    size = 0;
  this->m_size = size;
}


void __thiscall vostok::resources::pinned_ptr_base<vostok::sound::sound_rms>::pinned_ptr_base<vostok::sound::sound_rms>(
        vostok::resources::pinned_ptr_base<vostok::sound::sound_rms> *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  unsigned int size; // [esp+0h] [ebp-38h]
  const unsigned __int8 *v3; // [esp+4h] [ebp-34h]
  vostok::render::skeleton_model_instance *(__thiscall *v5)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+20h] [ebp-18h]
  vostok::render::skeleton_model_instance *(__thiscall *v6)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+2Ch] [ebp-Ch]

  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &this->m_resource,
    &ptr);
  if ( ptr.m_object )
    v6 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  else
    v6 = 0;
  if ( v6 )
    v3 = vostok::memory::managed_node_owner::pin(&ptr.m_object->vostok::memory::managed_node_owner);
  else
    v3 = 0;
  this->m_data = v3;
  if ( ptr.m_object )
    v5 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  else
    v5 = 0;
  if ( v5 )
    size = ptr.m_object->m_memory_usage_self.size;
  else
    size = 0;
  this->m_size = size;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ptr);
}
