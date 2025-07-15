void __usercall vostok::resources::resources_manager::add_to_generate_if_no_file_queue(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::query_result *query@<eax>)
{
  vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::push_back(
    (vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)((char *)this + (_DWORD)&loc_201D7 + 1),
    query);
  vostok::threading::interlocked_or(&query->m_flags, 0x20u);
}
