void __thiscall survarium::bullet_manager::bullets_memory_allocated(
        survarium::bullet_manager *this,
        vostok::resources::queries_result *queries)
{
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // eax
  vostok::resources::query_result_for_user *v3; // ecx
  survarium::game_camera *v4; // ecx
  volatile int m_initialized; // edx
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *m_variable; // ecx
  BOOL v7; // ecx
  survarium::game_camera *v8; // ecx
  void *v9; // eax
  volatile int v10; // edx
  BOOL v11; // ecx
  survarium::game_camera *v12; // ecx
  void *v13; // [esp+8h] [ebp-118h]
  bool v14; // [esp+Fh] [ebp-111h]
  unsigned __int8 *k; // [esp+1Ch] [ebp-104h]
  survarium::bullet **v17; // [esp+28h] [ebp-F8h]
  survarium::bullet **v18; // [esp+2Ch] [ebp-F4h]
  survarium::game_camera *m_max_bullets_count; // [esp+30h] [ebp-F0h]
  survarium::bullet **j; // [esp+50h] [ebp-D0h]
  survarium::bullet **m_end; // [esp+5Ch] [ebp-C4h]
  survarium::bullet **m_begin; // [esp+60h] [ebp-C0h]
  void *_Where; // [esp+8Ch] [ebp-94h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // [esp+BCh] [ebp-64h]
  vostok::ai::sound_player *object; // [esp+C0h] [ebp-60h]
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *v26; // [esp+C4h] [ebp-5Ch]
  survarium::bullet *v27; // [esp+C8h] [ebp-58h]
  void *value; // [esp+CCh] [ebp-54h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v29; // [esp+D0h] [ebp-50h] BYREF
  char v30; // [esp+D7h] [ebp-49h]
  unsigned __int8 *v31; // [esp+D8h] [ebp-48h]
  unsigned __int8 *v32; // [esp+DCh] [ebp-44h]
  survarium::bullet *old_bullet; // [esp+E0h] [ebp-40h] BYREF
  unsigned int i; // [esp+E4h] [ebp-3Ch]
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> new_bullets_allocator; // [esp+E8h] [ebp-38h] BYREF
  vostok::buffer_vector<survarium::bullet *> new_bullets_list; // [esp+F8h] [ebp-28h]
  survarium::bullet_manager::bullet_functor_mt_allocator new_mt_allocator; // [esp+100h] [ebp-20h] BYREF
  bool is_realocation; // [esp+117h] [ebp-9h]
  unsigned __int8 *pointer; // [esp+118h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> new_bullets_memory_ptr; // [esp+11Ch] [ebp-4h] BYREF

  v30 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v2 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](queries, 0);
  unmanaged_resource = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v3, v2, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29);
  object = (vostok::ai::sound_player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(unmanaged_resource);
  vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> *)&new_bullets_memory_ptr,
    object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
  survarium::weapon_user_dead_state::finalize(v4);
  pointer = new_bullets_memory_ptr.m_object->buffer;
  m_initialized = this->m_bullets_allocator_ref.m_initialized;
  m_variable = (vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *)(m_initialized != 0);
  v14 = 0;
  if ( m_initialized )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_variable);
    m_variable = this->m_bullets_allocator_ref.m_variable;
    if ( m_variable->m_allocated_count << 7 )
      v14 = 1;
  }
  LOBYTE(m_variable) = v14;
  is_realocation = v14;
  if ( v14 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_variable);
    for ( i = (this->m_bullets_allocator_ref.m_variable->m_allocated_count << 7) / 0x84u; i > this->m_max_bullets_count; --i )
      survarium::bullet_manager::destroy_one_bullet(this);
    vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>(
      &new_bullets_allocator,
      (vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *)pointer,
      this->m_max_bullets_count << 7);
    pointer += 128 * this->m_max_bullets_count;
    new_bullets_list.m_begin = (survarium::bullet **)pointer;
    new_bullets_list.m_end = (survarium::bullet **)pointer;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
    while ( 1 )
    {
      v7 = this->m_bullets.m_begin == this->m_bullets.m_end;
      if ( this->m_bullets.m_begin == this->m_bullets.m_end )
        break;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v7);
      old_bullet = *this->m_bullets.m_begin;
      _Where = vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::malloc_impl(
                 &new_bullets_allocator,
                 0x80u);
      v27 = (survarium::bullet *)operator new(0x80u, _Where);
      if ( v27 )
      {
        survarium::bullet::bullet(v27, (survarium::game_camera *)old_bullet);
        v13 = v9;
      }
      else
      {
        v13 = 0;
      }
      value = v13;
      survarium::weapon_user_dead_state::finalize(v8);
      vostok::buffer_vector<void const *>::construct((const void **)new_bullets_list.m_end++, (const void **)&value);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)new_bullets_list.m_end);
      vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>,survarium::bullet,vostok::memory::detail::call_destructor_predicate>(
        this->m_bullets_allocator_ref.m_variable,
        &old_bullet);
    }
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v7);
    vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::swap(
      &new_bullets_allocator,
      this->m_bullets_allocator_ref.m_variable);
    m_begin = this->m_bullets.m_begin;
    this->m_bullets.m_begin = new_bullets_list.m_begin;
    new_bullets_list.m_begin = m_begin;
    m_end = this->m_bullets.m_end;
    this->m_bullets.m_end = new_bullets_list.m_end;
    new_bullets_list.m_end = m_end;
    for ( j = new_bullets_list.m_begin; j != new_bullets_list.m_end; ++j )
      ;
    new_bullets_list.m_end = new_bullets_list.m_begin;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&new_bullets_allocator);
  }
  else
  {
    v10 = this->m_bullets_allocator_ref.m_initialized;
    v11 = v10 != 0;
    if ( v10 )
      vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>>::destroy(&this->m_bullets_allocator_ref);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v11);
    v26 = (vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *)operator new(
                                                                                                0x10u,
                                                                                                &this->m_bullets_allocator_ref);
    if ( v26 )
      vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::single_size_buffer_allocator<128,vostok::threading::simple_lock>(
        v26,
        (vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *)pointer,
        this->m_max_bullets_count << 7);
    survarium::weapon_user_dead_state::finalize(v12);
    vostok::threading::interlocked_exchange_pointer(&this->m_bullets_allocator_ref.m_initialized, 1);
    pointer += 128 * this->m_max_bullets_count;
    m_max_bullets_count = (survarium::game_camera *)this->m_max_bullets_count;
    v31 = pointer;
    v32 = pointer;
    survarium::weapon_user_dead_state::finalize(m_max_bullets_count);
    v18 = this->m_bullets.m_begin;
    this->m_bullets.m_begin = (survarium::bullet **)v31;
    v31 = (unsigned __int8 *)v18;
    v17 = this->m_bullets.m_end;
    this->m_bullets.m_end = (survarium::bullet **)v32;
    v32 = (unsigned __int8 *)v17;
    for ( k = v31; k != v32; k += 4 )
      ;
    v32 = v31;
  }
  pointer += 4 * this->m_max_bullets_count;
  survarium::bullet_manager::bullet_functor_mt_allocator::bullet_functor_mt_allocator(
    &new_mt_allocator,
    (survarium::bullet_manager::bullet_functor *)pointer,
    528 * this->m_max_bullets_count);
  stlp_std::swap<vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72>>(
    &this->m_mt_stack_allocator.m_bullet_functors,
    &new_mt_allocator.m_bullet_functors);
  stlp_std::swap<vostok::size_policy>(
    (vostok::size_policy *)&this->m_mt_stack_allocator.m_buffer,
    (vostok::size_policy *)&new_mt_allocator.m_buffer);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&new_mt_allocator);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_bullets_memory_ptr,
    &new_bullets_memory_ptr);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&new_bullets_memory_ptr);
}
