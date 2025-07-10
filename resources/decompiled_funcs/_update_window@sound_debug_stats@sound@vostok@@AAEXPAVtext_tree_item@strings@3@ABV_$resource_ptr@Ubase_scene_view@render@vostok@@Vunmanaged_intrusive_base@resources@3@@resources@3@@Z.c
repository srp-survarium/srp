void __thiscall vostok::sound::sound_debug_stats::update_window(
        vostok::sound::sound_debug_stats *this,
        vostok::strings::text_tree_item *item,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  int v3; // eax
  vostok::ui::text_tree_draw_helper_params v4; // [esp-24h] [ebp-110h] BYREF
  vostok::memory::pthreads3_allocator *v5; // [esp-4h] [ebp-F0h]
  vostok::sound::sound_debug_stats *thisa; // [esp+4h] [ebp-E8h]
  vostok::math::float2 *p_start_pos; // [esp+74h] [ebp-78h]
  int v8; // [esp+7Ch] [ebp-70h]
  int v9; // [esp+80h] [ebp-6Ch]
  int v10; // [esp+84h] [ebp-68h]
  int v11; // [esp+88h] [ebp-64h]
  char v12; // [esp+8Eh] [ebp-5Eh]
  char v13; // [esp+8Fh] [ebp-5Dh]
  vostok::ui::text_tree_draw_helper_params params; // [esp+90h] [ebp-5Ch] BYREF
  vostok::ui::text_tree_draw_helper h; // [esp+B0h] [ebp-3Ch] BYREF

  thisa = this;
  v13 = 0;
  v12 = 0;
  this->m_main_window->remove_all_children(this->m_main_window);
  p_start_pos = &params.start_pos;
  v11 = -16711906;
  params.color1 = -16711906;
  v10 = -16711856;
  params.color2 = -16711856;
  params.is_multipaged = 0;
  params.fnt = fnt_arial;
  params.row_height = FLOAT_15_0;
  params.space_between_pages = FLOAT_10_0;
  v8 = 1133903872;
  v9 = *(_DWORD *)&FLOAT_0_0;
  params.start_pos.x = 300.0;
  params.start_pos.y = *(float *)&FLOAT_0_0;
  v5 = &vostok::memory::g_mt_allocator;
  vostok::ui::text_tree_draw_helper_params::text_tree_draw_helper_params(&v4, &params);
  vostok::ui::text_tree_draw_helper::text_tree_draw_helper(&h, thisa->m_ui_world, thisa->m_main_window, v4, v5);
  vostok::ui::text_tree_draw_helper::output(&h, item, 4u, 58);
  v3 = ((int (__thiscall *)(vostok::ui::world *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *))thisa->m_ui_world->get_renderer)(
         thisa->m_ui_world,
         scene_view);
  ((void (__thiscall *)(vostok::ui::window *, int))thisa->m_main_window->draw)(thisa->m_main_window, v3);
}
