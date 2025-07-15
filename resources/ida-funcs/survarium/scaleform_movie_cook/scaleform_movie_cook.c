void __thiscall survarium::scaleform_movie_cook::scaleform_movie_cook(
        survarium::scaleform_movie_cook *this,
        survarium::flash_factory *factory)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x203,
    &s_scaleform_movie_cook,
    reuse_false,
    0xFFFFFFFD,
    0,
    v3);
  s_scaleform_movie_cook.__vftable = (survarium::scaleform_movie_cook_vtbl *)&survarium::scaleform_movie_cook::`vftable';
  s_scaleform_movie_cook.m_factory = factory;
  vostok::resources::resources_manager::register_cook(&s_scaleform_movie_cook, v2);
}
