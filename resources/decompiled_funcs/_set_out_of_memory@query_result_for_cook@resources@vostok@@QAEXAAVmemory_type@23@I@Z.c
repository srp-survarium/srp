void __userpurge vostok::resources::query_result_for_cook::set_out_of_memory(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<eax>,
        vostok::resources::memory_type *type,
        unsigned int size)
{
  *(_DWORD *)(a2 + 308) = this;
  *(_DWORD *)(a2 + 312) = type;
}
