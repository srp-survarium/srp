void __usercall vostok::render::render_model_cook::render_model_cook(
        vostok::render::render_model_cook *this@<ecx>,
        vostok::resources::cook_base *a2@<eax>)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v3; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v4; // [esp+0h] [ebp-4h]

  vostok::resources::translate_query_cook::translate_query_cook(this, a2, reuse_true, 0xFFFFFFFD, 0, v4);
  a2->__vftable = (vostok::resources::cook_base_vtbl *)&vostok::render::render_model_cook::`vftable';
  vostok::resources::resources_manager::register_cook(a2, v3);
}
