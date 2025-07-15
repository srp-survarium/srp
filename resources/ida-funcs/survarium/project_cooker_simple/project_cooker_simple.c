void __thiscall survarium::project_cooker_simple::project_cooker_simple(
        survarium::project_cooker_simple *this,
        bool editor_present)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v3; // [esp+0h] [ebp-8h]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x41,
    &s_simple_project_cook,
    reuse_true,
    0xFFFFFFFD,
    0,
    v3);
  s_simple_project_cook.__vftable = (survarium::project_cooker_simple_vtbl *)&survarium::project_cooker_simple::`vftable';
  s_simple_project_cook.m_editor_present = editor_present;
  vostok::resources::resources_manager::register_cook(&s_simple_project_cook, v2);
}
