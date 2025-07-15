void __usercall vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::decrease_opened(
        vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type> *this@<ecx>,
        int a2@<eax>)
{
  survarium::animations_search_service::vertex_type **v2; // esi
  survarium::animations_search_service::vertex_type **i; // eax
  vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::predicate v4; // [esp+0h] [ebp-Ch]
  int __topIndex; // [esp+8h] [ebp-4h]

  v2 = *(survarium::animations_search_service::vertex_type ***)(a2 + 8);
  for ( i = v2; *i != (survarium::animations_search_service::vertex_type *)this; ++i )
    ;
  LOBYTE(__topIndex) = 0;
  stlp_std::__push_heap<survarium::animations_search_service::vertex_type * *,int,survarium::animations_search_service::vertex_type *,vostok::ai::priority_queue::binary_heap::impl<survarium::animations_search_service::vertex_manager_impl_type>::predicate>(
    v2,
    i + 1 - v2 - 1,
    __topIndex,
    *i,
    v4);
}


void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::decrease_opened(
        vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type> *this,
        vostok::ai::planning::search_base::vertex_type *vertex,
        const unsigned int *value)
{
  vostok::ai::planning::search_base::vertex_type **i; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( i = this->m_heap_head; *i != vertex; ++i )
    ;
  stlp_std::push_heap<vostok::ai::planning::search_base::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::ai::planning::search_base::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    i + 1,
    0);
}


void __thiscall vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::decrease_opened(
        vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type> *this,
        vostok::sound::search::search_service::vertex_type *vertex,
        const float *value)
{
  vostok::sound::search::search_service::vertex_type **i; // [esp+8h] [ebp-4h]

  for ( i = this->m_heap_head; *i != vertex; ++i )
    ;
  stlp_std::push_heap<vostok::sound::search::search_service::vertex_type * *,vostok::ai::priority_queue::binary_heap::impl<vostok::sound::search::search_service::vertex_manager_impl_type>::predicate>(
    this->m_heap_head,
    i + 1,
    0);
}
