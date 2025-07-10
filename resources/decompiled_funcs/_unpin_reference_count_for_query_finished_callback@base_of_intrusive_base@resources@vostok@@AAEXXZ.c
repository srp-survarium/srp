void __usercall vostok::resources::base_of_intrusive_base::unpin_reference_count_for_query_finished_callback(
        vostok::resources::base_of_intrusive_base *this@<ecx>,
        volatile signed __int32 *a2@<eax>)
{
  _InterlockedExchangeAdd(a2, 0xFFFFFFFF);
  vostok::threading::interlocked_and(a2 + 1, 0xFFFFFFFD);
}
