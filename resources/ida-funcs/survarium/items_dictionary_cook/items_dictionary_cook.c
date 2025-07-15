void __thiscall survarium::items_dictionary_cook::items_dictionary_cook(survarium::items_dictionary_cook *this)
{
  vostok::memory::doug_lea_allocator *v1; // edi
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-Ch]

  v1 = survarium::g_allocator;
  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x43,
    &s_items_dictionary_cook,
    reuse_true,
    0xFFFFFFFB,
    0,
    v3);
  s_items_dictionary_cook.__vftable = (survarium::items_dictionary_cook_vtbl *)&survarium::items_dictionary_cook::`vftable';
  s_items_dictionary_cook.m_allocator = v1;
  vostok::resources::resources_manager::register_cook(&s_items_dictionary_cook, v2);
}
