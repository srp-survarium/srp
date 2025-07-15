void __usercall vostok::physics::collision_shape_cook::collision_shape_cook(
        vostok::physics::collision_shape_cook *this@<ecx>,
        int a2@<eax>)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v3; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v4; // [esp+0h] [ebp-4h]

  vostok::resources::translate_query_cook::translate_query_cook(
    this,
    (vostok::resources::cook_base *)a2,
    reuse_true,
    0xFFFFFFFD,
    0,
    v4);
  *(_DWORD *)a2 = &vostok::physics::collision_shape_cook::`vftable';
  *(_BYTE *)(a2 + 32) = 1;
  vostok::resources::resources_manager::register_cook((vostok::resources::cook_base *)a2, v3);
}
