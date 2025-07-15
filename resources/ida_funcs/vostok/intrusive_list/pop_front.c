survarium::object_weapon *__usercall vostok::intrusive_list<vostok::render::frame_histogram_info,vostok::render::frame_histogram_info *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front@<eax>(
        vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // edi
  int v3; // eax

  if ( !*(_DWORD *)(a2 + 36) )
    return 0;
  vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 8));
  if ( !*(_DWORD *)(a2 + 36) )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
    return 0;
  }
  v2 = *(_DWORD *)(a2 + 36);
  --*(_DWORD *)a2;
  v3 = *(_DWORD *)(v2 + 12);
  *(_DWORD *)(a2 + 36) = v3;
  if ( !v3 )
    *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
  return (survarium::object_weapon *)v2;
}


vostok::ai::fsm_state *__thiscall vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::ai::fsm_state *result; // eax
  vostok::ai::fsm_state *next; // edx

  if ( !this->m_first )
    return 0;
  result = this->m_first;
  --this->m_size;
  next = result->next;
  this->m_first = next;
  if ( !next )
    this->m_last = 0;
  result->next = 0;
  return result;
}


vostok::ai::fsm_state_transition *__thiscall vostok::intrusive_list<vostok::ai::fsm_state_transition,vostok::ai::fsm_state_transition *,36,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::fsm_state_transition,vostok::ai::fsm_state_transition *,36,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  BOOL v1; // ecx
  survarium::game_camera *v3; // ecx
  vostok::ai::fsm_state_transition *result; // [esp+14h] [ebp-8h]

  v1 = this->m_first == 0;
  if ( v1 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    v3 = (survarium::game_camera *)this;
    this->m_first = result->next;
    if ( !this->m_first )
    {
      v3 = (survarium::game_camera *)this;
      this->m_last = 0;
    }
    result->next = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    return result;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    return 0;
  }
}


vostok::vfs::mount_referer *__thiscall vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::vfs::mount_referer *result; // [esp+1Ch] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+20h] [ebp-8h] BYREF

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    this->m_first = result->next;
    if ( !this->m_first )
      this->m_last = 0;
    result->next = 0;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)result,
      (int)&raii);
    return result;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this,
      (int)&raii);
    return 0;
  }
}


vostok::vfs::node_to_expand *__thiscall vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  BOOL v1; // ecx
  survarium::game_camera *v3; // ecx
  vostok::vfs::node_to_expand *result; // [esp+14h] [ebp-8h]

  v1 = this->m_first == 0;
  if ( v1 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    v3 = (survarium::game_camera *)this;
    this->m_first = result->next;
    if ( !this->m_first )
    {
      v3 = (survarium::game_camera *)this;
      this->m_last = 0;
    }
    result->next = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    return result;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    return 0;
  }
}


vostok::ai::percept_memory_object *__thiscall vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v2; // ecx
  vostok::ai::percept_memory_object *result; // [esp+18h] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+1Ch] [ebp-8h] BYREF

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    v2 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this;
    this->m_first = result->next;
    if ( !this->m_first )
    {
      v2 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this;
      this->m_last = 0;
    }
    result->next = 0;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v2,
      (int)&raii);
    return result;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this,
      (int)&raii);
    return 0;
  }
}


vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *__thiscall vostok::intrusive_list<vostok::ai::planning::base_filter,vostok::ai::planning::base_filter *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v2; // ecx
  vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *result; // [esp+18h] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+1Ch] [ebp-8h] BYREF

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    v2 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this;
    this->m_first = result->next;
    if ( !this->m_first )
    {
      v2 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this;
      this->m_last = 0;
    }
    result->next = 0;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v2,
      (int)&raii);
    return result;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this,
      (int)&raii);
    return 0;
  }
}


vostok::ai::planning::generalized_action *__thiscall vostok::intrusive_list<survarium::landing_point,survarium::landing_point *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  BOOL v1; // ecx
  vostok::ai::planning::generalized_action *result; // [esp+18h] [ebp-8h]

  v1 = this->m_first == 0;
  if ( v1 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    this->m_first = result->next;
    if ( !this->m_first )
      this->m_last = 0;
    result->next = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)result);
    return result;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    return 0;
  }
}


vostok::resources::query_result *__usercall vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front@<eax>(
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // edi
  int v3; // eax

  if ( !*(_DWORD *)(a2 + 36) )
    return 0;
  vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 8));
  if ( !*(_DWORD *)(a2 + 36) )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
    return 0;
  }
  v2 = *(_DWORD *)(a2 + 36);
  --*(_DWORD *)a2;
  v3 = *(_DWORD *)(v2 + 600);
  *(_DWORD *)(a2 + 36) = v3;
  if ( !v3 )
    *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(v2 + 600) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
  return (vostok::resources::query_result *)v2;
}


vostok::sound::sound_buffer *__thiscall vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::sound::sound_buffer *result; // [esp+14h] [ebp-8h]

  if ( !this->m_first )
    return 0;
  --this->m_size;
  result = this->m_first;
  this->m_first = result->m_next;
  if ( !this->m_first )
    this->m_last = 0;
  result->m_next = 0;
  return result;
}
