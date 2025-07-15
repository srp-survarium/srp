void __thiscall vostok::collision::animated_object_cook::animated_object_cook(
        vostok::collision::animated_object_cook *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x7A,
    &stru_47EC9E4,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  stru_47EC9E4.__vftable = (vostok::resources::cook_base_vtbl *)&vostok::collision::animated_object_cook::`vftable';
  dword_47ECA04 = (int)allocator;
  vostok::resources::resources_manager::register_cook(&stru_47EC9E4, v2);
}
