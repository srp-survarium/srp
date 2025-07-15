void __thiscall vostok::ai::working_memory::delete_memory_object(
        vostok::ai::working_memory *this,
        vostok::ai::percept_memory_object *object_to_be_deleted)
{
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    &this->m_percept_objects.elems[object_to_be_deleted->type],
    object_to_be_deleted);
  vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>,vostok::ai::percept_memory_object,vostok::memory::detail::call_destructor_predicate>(
    &this->m_allocator,
    &object_to_be_deleted);
}
