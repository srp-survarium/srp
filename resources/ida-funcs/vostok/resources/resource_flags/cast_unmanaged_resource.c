vostok::resources::unmanaged_resource *__usercall vostok::resources::resource_flags::cast_unmanaged_resource@<eax>(
        vostok::resources::resource_flags *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 8) & 4) != 4 ? 0 : (vostok::resources::unmanaged_resource *)a2;
}
