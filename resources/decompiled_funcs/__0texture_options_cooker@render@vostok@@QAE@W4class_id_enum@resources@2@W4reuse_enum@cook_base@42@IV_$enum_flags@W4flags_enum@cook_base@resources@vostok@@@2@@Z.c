void __userpurge vostok::render::texture_options_cooker::texture_options_cooker(
        vostok::render::texture_options_cooker *this@<ecx>,
        vostok::resources::translate_query_cook *a2@<esi>,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> resource_class,
        vostok::resources::cook_base::reuse_enum reuse_type,
        unsigned int translate_query_thread,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  vostok::resources::translate_query_cook::translate_query_cook(
    a2,
    texture_options_binary_class,
    reuse_true,
    0xFFFFFFFC,
    resource_class);
  a2->__vftable = (vostok::resources::translate_query_cook_vtbl *)&vostok::render::texture_options_cooker::`vftable';
}
