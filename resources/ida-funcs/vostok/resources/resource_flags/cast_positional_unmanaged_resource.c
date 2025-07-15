vostok::resources::positional_unmanaged_resource *__usercall vostok::resources::resource_flags::cast_positional_unmanaged_resource@<eax>(
        vostok::resources::resource_flags *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 8) & 8) != 8 ? 0 : (vostok::resources::positional_unmanaged_resource *)a2;
}
