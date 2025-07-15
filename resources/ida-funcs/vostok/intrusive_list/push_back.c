void __thiscall vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::particle::base_particle *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-8h] BYREF

  object->next = 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  vostok::size_policy::increment_size(v3, this);
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
    (int)&raii);
}


void __userpurge vostok::intrusive_list<vostok::render::frame_histogram_info,vostok::render::frame_histogram_info *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::render::frame_histogram_info,vostok::render::frame_histogram_info *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::render::frame_histogram_info *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->next = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 12) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __usercall vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this@<eax>,
        vostok::ai::fsm_state *object@<ecx>,
        bool *out_pushed_first@<esi>)
{
  object->next = 0;
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
}


void __thiscall vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::vfs::mount_referer *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-8h] BYREF

  object->next = 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  vostok::size_policy::increment_size(v3, this);
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
    (int)&raii);
}


void __thiscall vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        survarium::game_camera *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *thisa; // [esp+4h] [ebp-Ch]

  thisa = this;
  object->m_inverted_view_matrix.i.y = 0.0;
  if ( this )
    this = (vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)((char *)this + 4);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::size_policy::increment_size(v3, thisa);
  if ( out_pushed_first )
    *out_pushed_first = thisa->m_first == 0;
  if ( thisa->m_first )
    thisa->m_last->next = (vostok::vfs::node_to_expand *)object;
  else
    thisa->m_first = (vostok::vfs::node_to_expand *)object;
  thisa->m_last = (vostok::vfs::node_to_expand *)object;
  survarium::weapon_user_dead_state::finalize(object);
}


void __thiscall vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::percept_memory_object *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-8h] BYREF

  object->next = 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  vostok::size_policy::increment_size(v3, this);
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
    (int)&raii);
}


void __thiscall vostok::intrusive_list<vostok::ai::sound_item_wrapper,vostok::ai::sound_item_wrapper *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-8h] BYREF

  object->next = 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  vostok::size_policy::increment_size(v3, this);
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
    (int)&raii);
}


void __userpurge vostok::intrusive_list<vostok::strings::text_tree_column_item,vostok::strings::text_tree_column_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>,
        vostok::strings::text_tree_item *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_brother = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 8);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*(_DWORD *)a2;
  if ( *(_DWORD *)(a2 + 36) )
    **(_DWORD **)(a2 + 40) = object;
  else
    *(_DWORD *)(a2 + 36) = object;
  *(_DWORD *)(a2 + 40) = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __thiscall vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::brain_unit *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-8h] BYREF

  object->m_next_for_tick = 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  vostok::size_policy::increment_size(v3, this);
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->m_next_for_tick = object;
  else
    this->m_first = object;
  this->m_last = object;
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
    (int)&raii);
}


void __userpurge vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::fs_task *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 4) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __userpurge vostok::intrusive_list<vostok::resources::managed_resource,vostok::resources::managed_resource *,236,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::managed_resource,vostok::resources::managed_resource *,236,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::managed_resource *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_delay_delete = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 236) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __userpurge vostok::intrusive_list<vostok::resources::memory_type,vostok::resources::memory_type *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>,
        vostok::resources::unmanaged_resource_buffer *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_to_deallocate = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 8);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*(_DWORD *)a2;
  if ( *(_DWORD *)(a2 + 36) )
    **(_DWORD **)(a2 + 40) = object;
  else
    *(_DWORD *)(a2 + 36) = object;
  *(_DWORD *)(a2 + 40) = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __userpurge vostok::intrusive_list<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,16,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,16,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::name_registry_entry *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->next_to_delete = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 16) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __userpurge vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::queries_result *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_ready = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 36) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __userpurge vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,600,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::query_result *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_out_of_memory = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 600) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __userpurge vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::query_result *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  v4 = 0;
  object->m_next_in_device_manager = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 608) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __usercall vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  this[38].m_size = 0;
  ++*a2;
  if ( a2[2] )
    *(_DWORD *)(a2[3] + 608) = this;
  else
    a2[2] = this;
  a2[3] = this;
}


void __thiscall vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::receiver_collision *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // [esp+8h] [ebp-Ch]

  object->m_next = 0;
  if ( this )
    v4 = &this->vostok::threading::mutex;
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
  {
    this->m_last->m_next = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
  else
  {
    this->m_first = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
}


void __userpurge vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::resource_base *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  v4 = 0;
  object->m_next_for_query_finished_callback = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 180) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __userpurge vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::resource_link *object,
        bool *out_pushed_first)
{
  vostok::threading::simple_lock *v4; // edi
  bool v5; // zf

  object->next_link = 0;
  if ( a2 )
    v4 = (vostok::threading::simple_lock *)(a2 + 1);
  else
    v4 = 0;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, v4);
  ++*a2;
  if ( a2[4] )
  {
    *(_DWORD *)(a2[5] + 4) = object;
    a2[5] = object;
    v5 = v4->m_lock-- == 1;
    if ( !v5 )
      return;
  }
  else
  {
    a2[4] = object;
    a2[5] = object;
    v5 = v4->m_lock-- == 1;
    if ( !v5 )
      return;
  }
  _InterlockedExchange(&v4->m_thread_id, 0);
}


void __thiscall vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_buffer *object,
        bool *out_pushed_first)
{
  object->m_next = 0;
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->m_next = object;
  else
    this->m_first = object;
  this->m_last = object;
}


void __thiscall vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_scene *object,
        bool *out_pushed_first)
{
  object->m_next = 0;
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->m_next = object;
  else
    this->m_first = object;
  this->m_last = object;
}


void __thiscall vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_voice *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // [esp+8h] [ebp-Ch]

  object->m_next_for_active = 0;
  if ( this )
    v4 = &this->vostok::threading::mutex;
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
  {
    this->m_last->m_next_for_active = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
  else
  {
    this->m_first = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
}


void __thiscall vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_voice *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // [esp+8h] [ebp-Ch]

  object->m_next_for_delete = 0;
  if ( this )
    v4 = &this->vostok::threading::mutex;
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
  {
    this->m_last->m_next_for_delete = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
  else
  {
    this->m_first = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
}


void __thiscall vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::tasks::task_type *object,
        vostok::tasks::task_type *out_pushed_first)
{
  vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v2; // esi
  _RTL_CRITICAL_SECTION *v3; // edi

  v2 = s_task_type_list;
  out_pushed_first->m_next_task_type = 0;
  if ( v2 )
    v3 = (_RTL_CRITICAL_SECTION *)&v2->vostok::threading::mutex_tasks_unaware;
  else
    v3 = 0;
  EnterCriticalSection(v3);
  ++v2->m_size;
  if ( v2->m_first )
    v2->m_last->m_next_task_type = out_pushed_first;
  else
    v2->m_first = out_pushed_first;
  v2->m_last = out_pushed_first;
  LeaveCriticalSection(v3);
}


void __userpurge vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::unmanaged_resource *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_delay_delete = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 232) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}


void __thiscall vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::voice_bridge *object,
        bool *out_pushed_first)
{
  object->m_next = 0;
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->m_next = object;
  else
    this->m_first = object;
  this->m_last = object;
}
