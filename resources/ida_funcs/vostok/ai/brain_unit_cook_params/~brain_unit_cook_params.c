void __thiscall vostok::ai::brain_unit_cook_params::~brain_unit_cook_params(
        vostok::memory::detail::call_destructor_predicate *this)
{
  int v1; // eax

  v1 = *(_DWORD *)&this[4];
  if ( v1 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v1 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)&this[4] + 208),
        *(vostok::resources::unmanaged_resource **)&this[4]);
  }
}
