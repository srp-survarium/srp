void __userpurge vostok::resources::resources_manager::remove_from_generate_if_no_file_queue(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::resources_manager *this)
{
  vostok::threading::interlocked_and(&query->m_flags, 0xFFFFFFDF);
  vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
    (vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)((char *)this + (_DWORD)&loc_201D7 + 1),
    query);
}
