void __userpurge vostok::resources::translate_query_cook::translate_query_cook(
        vostok::resources::translate_query_cook *this@<ecx>,
        vostok::resources::cook_base *a2@<eax>,
        vostok::resources::cook_base::reuse_enum resource_class,
        DWORD reuse_type,
        unsigned int translate_query_thread,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  vostok::resources::cook_base::cook_base(
    a2,
    (vostok::resources::class_id_enum)this,
    0xFFFFFFFF,
    resource_class,
    (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)(translate_query_thread | 8),
    reuse_type);
  a2->__vftable = (vostok::resources::cook_base_vtbl *)&vostok::resources::translate_query_cook::`vftable';
}
