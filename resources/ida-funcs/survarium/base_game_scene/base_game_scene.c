void __thiscall survarium::base_game_scene::base_game_scene(
        survarium::base_game_scene *this,
        survarium::base_game_scene *g,
        survarium::game *text_manager,
        survarium::flash_text_manager *a4)
{
  long double v4; // rdi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::console_commands::cc_float3 *v8; // ecx
  survarium::camera_director *v9; // eax
  const char *v10; // [esp+0h] [ebp-54h]
  const char *v11; // [esp+4h] [ebp-50h]
  unsigned int v12; // [esp+8h] [ebp-4Ch]
  vostok::math::float4x4 v13; // [esp+10h] [ebp-44h] BYREF

  g->m_render_scene.m_object = 0;
  g->m_render_scene_view.m_object = 0;
  g->__vftable = (survarium::base_game_scene_vtbl *)&survarium::base_game_scene::`vftable';
  qmemcpy(
    &g->m_inverted_view_matrix,
    vostok::math::float4x4::identity((vostok::math::float4x4 *)this, &v13),
    sizeof(g->m_inverted_view_matrix));
  LODWORD(v4) = 0;
  g->m_mouse_x = 0;
  g->m_mouse_y = 0;
  g->m_sound_scene.m_object = 0;
  g->m_text_manager = a4;
  g->m_game = text_manager;
  g->m_is_ui_shown = 0;
  survarium::scheduler::scheduler(0, &g->m_scheduler.m_inactive_objects._M_impl._M_start);
  HIDWORD(v4) = survarium::g_allocator;
  g->m_is_active = 0;
  g->m_drawable_objects.m_first = 0;
  g->m_drawable_objects.m_last = 0;
  v5 = type_info::raw_name(&survarium::camera_director `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, SHIDWORD(v4), 0x8Cu, v5, v10, v11, v12);
  if ( v7 )
    survarium::camera_director::camera_director(g, v8, v4, (survarium::camera_director *)v7);
  else
    v9 = 0;
  g->m_camera_director = v9;
}
