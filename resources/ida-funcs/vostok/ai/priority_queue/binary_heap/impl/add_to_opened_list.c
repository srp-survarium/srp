void __usercall vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::add_to_opened_list(
        vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type> *this@<ecx>,
        int a2@<eax>)
{
  float **v2; // edx
  float *v3; // edx
  vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type> **v4; // edx
  int v5; // edx
  vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::predicate v6; // [esp+0h] [ebp-Ch]
  int __topIndex; // [esp+8h] [ebp-4h]

  LOBYTE(this[2].m_heap_tail) = 1;
  v2 = *(float ***)(a2 + 8);
  if ( *v2 && (v3 = *v2, (float)(*(float *)&this->m_heap + *(float *)&this->m_manager) <= (float)(v3[1] + *v3)) )
  {
    **(_DWORD **)(a2 + 12) = v3;
    v4 = *(vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type> ***)(a2 + 8);
  }
  else
  {
    v4 = *(vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type> ***)(a2 + 12);
  }
  *v4 = this;
  v5 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(a2 + 12) = v5 + 4;
  LOBYTE(__topIndex) = 0;
  stlp_std::__push_heap<survarium::animations_search_service::vertex_type * *,int,survarium::animations_search_service::vertex_type *,vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::predicate>(
    *(survarium::animations_search_service::vertex_type ***)(a2 + 8),
    ((v5 - *(_DWORD *)(a2 + 8)) >> 2) - 1,
    __topIndex,
    *(survarium::animations_search_service::vertex_type **)(v5 - 4),
    v6);
}


void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::add_to_opened_list(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this,
        vostok::ai::planning::search_base::vertex_type *vertex)
{
  vostok::ai::planning::search_base::vertex_type **__last; // [esp+0h] [ebp-18h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vertex->m_opened = 1;
  if ( *this->m_heap_head && (*this->m_heap_head)->m_h + **(_DWORD **)this->m_heap_head >= vertex->m_h + vertex->m_g )
  {
    *this->m_heap_tail = *this->m_heap_head;
    *this->m_heap_head = vertex;
  }
  else
  {
    *this->m_heap_tail = vertex;
  }
  __last = this->m_heap_tail;
  this->m_heap_tail = __last + 1;
  stlp_std::push_heap<vostok::ai::planning::search_base::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}


void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::add_to_opened_list(
        vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type> *this,
        vostok::sound::search::search_service::vertex_type *vertex)
{
  vostok::sound::search::search_service::vertex_type **__last; // [esp+0h] [ebp-18h]

  vertex->m_opened = 1;
  if ( *this->m_heap_head
    && (float)(vertex->m_g + vertex->m_h) <= (float)(**(float **)this->m_heap_head + (*this->m_heap_head)->m_h) )
  {
    *this->m_heap_tail = *this->m_heap_head;
    *this->m_heap_head = vertex;
  }
  else
  {
    *this->m_heap_tail = vertex;
  }
  __last = this->m_heap_tail;
  this->m_heap_tail = __last + 1;
  stlp_std::push_heap<vostok::sound::search::search_service::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}
