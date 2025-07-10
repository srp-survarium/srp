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
