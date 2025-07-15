void __usercall vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::move_best_to_closed(
        vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type> *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  survarium::animations_search_service::vertex_type **v3; // eax
  int v4; // esi

  *(_BYTE *)(**(_DWORD **)(a2 + 8) + 44) = 0;
  LOBYTE(this) = 0;
  v2 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(a2 + 12) = v2 - 4;
  v3 = *(survarium::animations_search_service::vertex_type ***)(a2 + 8);
  v4 = *(_DWORD *)(v2 - 4);
  *(_DWORD *)(v2 - 4) = *v3;
  stlp_std::__adjust_heap<survarium::animations_search_service::vertex_type * *,int,survarium::animations_search_service::vertex_type *,vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::predicate>(
    v3,
    (v2 - (int)v3 - 4) >> 2,
    v4,
    (survarium::animations_search_service::vertex_type *)this);
}


void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::move_best_to_closed(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this)
{
  vostok::ai::planning::search_base::vertex_type **__last; // [esp+0h] [ebp-14h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  (*this->m_heap_head)->m_opened = 0;
  __last = this->m_heap_tail;
  this->m_heap_tail = __last - 1;
  stlp_std::pop_heap<vostok::ai::planning::search_base::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}


void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::move_best_to_closed(
        vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type> *this)
{
  vostok::sound::search::search_service::vertex_type **__last; // [esp+0h] [ebp-14h]

  (*this->m_heap_head)->m_opened = 0;
  __last = this->m_heap_tail;
  this->m_heap_tail = __last - 1;
  stlp_std::pop_heap<vostok::sound::search::search_service::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    __last,
    0);
}
