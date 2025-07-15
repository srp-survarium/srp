void __usercall vostok::resources::base_of_intrusive_base::pin_reference_count_for_safe_destroying(
        vostok::resources::base_of_intrusive_base *this@<ecx>,
        volatile signed __int32 *a2@<eax>)
{
  _InterlockedExchangeAdd(a2, 1u);
  vostok::threading::interlocked_or(a2 + 1, 8u);
}
