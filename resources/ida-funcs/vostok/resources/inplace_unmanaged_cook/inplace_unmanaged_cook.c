void __userpurge vostok::resources::inplace_unmanaged_cook::inplace_unmanaged_cook(
        vostok::resources::inplace_unmanaged_cook *this@<ecx>,
        vostok::resources::cook_base *a2@<eax>,
        vostok::resources::class_id_enum resource_class,
        vostok::resources::cook_base::reuse_enum reuse_type,
        unsigned int creation_thread_id,
        unsigned int allocate_thread_id,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  vostok::resources::cook_base::cook_base(
    a2,
    (vostok::resources::class_id_enum)this,
    0xFFFFFFFC,
    reuse_true,
    (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)(resource_class | 0x10),
    0xFFFFFFFC);
  a2->__vftable = (vostok::resources::cook_base_vtbl *)&vostok::resources::inplace_unmanaged_cook::`vftable';
}
