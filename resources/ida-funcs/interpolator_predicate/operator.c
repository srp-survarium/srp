BOOL __userpurge interpolator_predicate::operator()@<eax>(
        interpolator_predicate *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::animation::base_interpolator *const interpolator)
{
  (*(void (__thiscall **)(_DWORD, const vostok::animation::base_interpolator *const *, const vostok::animation::base_interpolator *const))(*(_DWORD *)*a2 + 20))(
    *a2,
    &interpolator,
    interpolator);
  return interpolator == 0;
}
