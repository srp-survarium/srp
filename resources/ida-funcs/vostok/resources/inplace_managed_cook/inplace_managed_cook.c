void __userpurge vostok::resources::inplace_managed_cook::inplace_managed_cook(
        vostok::resources::inplace_managed_cook *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> resource_class,
        vostok::resources::cook_base::reuse_enum reuse_type,
        unsigned int creation_thread_id,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  *a2 = &vostok::resources::cook_base::`vftable';
  a2[1] = 0;
  a2[2] = 8;
  a2[3] = 0;
  a2[4] = -4;
  a2[5] = -1;
  a2[6] = resource_class.m_flags | 0x31;
  a2[7] = 0;
  *a2 = &vostok::resources::inplace_managed_cook::`vftable';
}
