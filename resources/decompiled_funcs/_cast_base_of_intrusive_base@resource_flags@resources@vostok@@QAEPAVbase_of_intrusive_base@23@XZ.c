vostok::resources::base_of_intrusive_base *__usercall vostok::resources::resource_flags::cast_base_of_intrusive_base@<eax>(
        vostok::resources::resource_flags *this@<ecx>,
        int a2@<eax>)
{
  if ( (*(_DWORD *)(a2 + 8) & 1) != 0 && a2 )
    return (vostok::resources::base_of_intrusive_base *)(a2 + 220);
  if ( (*(_DWORD *)(a2 + 8) & 4) != 0 && a2 )
    return (vostok::resources::base_of_intrusive_base *)(a2 + 208);
  return 0;
}
