void __thiscall vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
        vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *this,
        vostok::vfs::mounter *object)
{
  survarium::game_camera *v2; // ecx
  vostok::vfs::mounter_base *v3; // [esp+4h] [ebp-38h]
  vostok::vfs::mounter_base *v4; // [esp+8h] [ebp-34h]
  vostok::vfs::mounter_base *v5; // [esp+14h] [ebp-28h]
  survarium::game_camera *v6; // [esp+18h] [ebp-24h]
  vostok::vfs::mounter_base *v7; // [esp+1Ch] [ebp-20h]
  vostok::vfs::mounter_base *v8; // [esp+20h] [ebp-1Ch]
  vostok::vfs::mounter *next; // [esp+2Ch] [ebp-10h]
  vostok::vfs::mounter *prev; // [esp+30h] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+34h] [ebp-8h] BYREF

  if ( this->m_first )
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->m_policy,
      (int)&raii);
    if ( object )
      v8 = &object->vostok::vfs::mounter_base;
    else
      v8 = 0;
    prev = v8->prev;
    if ( object )
      v7 = &object->vostok::vfs::mounter_base;
    else
      v7 = 0;
    next = v7->next;
    if ( object )
      v6 = (survarium::game_camera *)&object->vostok::vfs::mounter_base;
    else
      v6 = 0;
    v6->__vftable = 0;
    if ( object )
      v5 = &object->vostok::vfs::mounter_base;
    else
      v5 = 0;
    v5->next = 0;
    if ( prev )
    {
      v2 = (survarium::game_camera *)&prev->vostok::vfs::mounter_base;
      prev->next = next;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(v6);
      this->m_first = next;
    }
    if ( next )
    {
      next->prev = prev;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(v2);
      this->m_last = prev;
    }
    if ( object )
      v4 = &object->vostok::vfs::mounter_base;
    else
      v4 = 0;
    v4->prev = 0;
    if ( object )
      v3 = &object->vostok::vfs::mounter_base;
    else
      v3 = 0;
    v3->next = 0;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)v3,
      (int)&raii);
  }
}


void __usercall vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
        vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *this@<edi>,
        vostok::resources::query_result *object@<esi>)
{
  vostok::resources::query_result *m_prev_in_generate_if_no_file_queue; // eax
  vostok::resources::query_result *m_next_in_generate_if_no_file_queue; // ecx

  if ( this->m_first )
  {
    vostok::threading::mutex::lock(&this->m_policy);
    m_prev_in_generate_if_no_file_queue = object->m_prev_in_generate_if_no_file_queue;
    m_next_in_generate_if_no_file_queue = object->m_next_in_generate_if_no_file_queue;
    object->m_prev_in_generate_if_no_file_queue = 0;
    object->m_next_in_generate_if_no_file_queue = 0;
    if ( m_prev_in_generate_if_no_file_queue )
      m_prev_in_generate_if_no_file_queue->m_next_in_generate_if_no_file_queue = m_next_in_generate_if_no_file_queue;
    else
      this->m_first = m_next_in_generate_if_no_file_queue;
    if ( m_next_in_generate_if_no_file_queue )
      m_next_in_generate_if_no_file_queue->m_prev_in_generate_if_no_file_queue = m_prev_in_generate_if_no_file_queue;
    else
      this->m_last = m_prev_in_generate_if_no_file_queue;
    object->m_prev_in_generate_if_no_file_queue = 0;
    object->m_next_in_generate_if_no_file_queue = 0;
    boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull((survarium::jump_logic_state_landing *)this);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->m_policy);
  }
}


void __thiscall vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::erase(
        vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *this,
        vostok::vfs::vfs_mount *object)
{
  BOOL v2; // ecx
  survarium::game_camera *v3; // ecx
  vostok::vfs::vfs_mount *next; // [esp+Ch] [ebp-10h]
  vostok::vfs::vfs_mount *prev; // [esp+10h] [ebp-Ch]
  vostok::threading::simple_lock::mutex_raii raii; // [esp+14h] [ebp-8h] BYREF

  v2 = this->m_first == 0;
  if ( !v2 )
  {
    vostok::threading::simple_lock::mutex_raii::mutex_raii(&raii, &this->m_policy, (vostok::threading::simple_lock *)v2);
    prev = object->prev_mount_history;
    next = object->next_mount_history;
    object->prev_mount_history = 0;
    object->next_mount_history = 0;
    if ( prev )
    {
      v3 = (survarium::game_camera *)next;
      prev->next_mount_history = next;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)object);
      v3 = (survarium::game_camera *)next;
      this->m_first = next;
    }
    if ( next )
    {
      next->prev_mount_history = prev;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(v3);
      this->m_last = prev;
    }
    object->prev_mount_history = 0;
    object->next_mount_history = 0;
    vostok::threading::simple_lock::mutex_raii::clear(&raii);
  }
}
