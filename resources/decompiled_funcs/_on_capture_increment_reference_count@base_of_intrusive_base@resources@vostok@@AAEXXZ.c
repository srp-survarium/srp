void __usercall vostok::resources::base_of_intrusive_base::on_capture_increment_reference_count(
        vostok::resources::base_of_intrusive_base *this@<ecx>,
        volatile signed __int32 *a2@<eax>)
{
  _InterlockedExchangeAdd(a2, 1u);
  vostok::threading::interlocked_or(a2 + 1, 1u);
}
