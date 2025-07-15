void __thiscall vostok::physics::animated_model_instance_cook::animated_model_instance_cook(
        vostok::physics::animated_model_instance_cook *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v2; // [esp+0h] [ebp-4h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x5F,
    &animated_model_cook_0,
    reuse_false,
    0xFFFFFFFD,
    0,
    v2);
  animated_model_cook_0.__vftable = (vostok::physics::animated_model_instance_cook_vtbl *)&vostok::physics::animated_model_instance_cook::`vftable';
  animated_model_cook_0.m_allocator = vostok::physics::g_allocator;
  vostok::resources::resources_manager::register_cook(&animated_model_cook_0, v1);
}
