void __usercall vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<esi>,
        survarium::player_params_modifier *object@<edi>,
        vostok::threading::mutex *a3@<ecx>)
{
  vostok::threading::mutex *v3; // ebx

  v3 = 0;
  object->next = 0;
  if ( this )
    v3 = &this->vostok::threading::mutex;
  vostok::threading::mutex::lock(a3, (_RTL_CRITICAL_SECTION *)v3);
  ++this->m_size;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v3);
}
