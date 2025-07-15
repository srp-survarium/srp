void __thiscall vostok::render::render_output_window_cook::translate_query(
        vostok::render::render_output_window_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::render::render_output_window *v2; // ebx
  vostok::resources::unmanaged_resource *m_object; // eax
  HWND DesktopWindow; // eax
  unsigned int width; // esi
  unsigned int height; // edi
  DWORD WindowLongA; // ebx
  HMENU Menu; // eax
  int top; // edi
  int left; // eax
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  vostok::buffer_vector<vostok::render::render_output_window *> *v16; // ecx
  vostok::render::render_output_window *v17; // eax
  survarium::pure_game_effect_emitter_base *v18; // ecx
  vostok::resources::query_result_for_cook *v19; // ecx
  vostok::resources::query_result_for_cook *v20; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21; // [esp-Ch] [ebp-54h] BYREF
  const vostok::resources::memory_type *v22; // [esp-8h] [ebp-50h]
  unsigned int p_out_value; // [esp-4h] [ebp-4Ch]
  const char *v24; // [esp+0h] [ebp-48h]
  const char *v25; // [esp+4h] [ebp-44h]
  unsigned int v26; // [esp+8h] [ebp-40h]
  vostok::render::render_output_window *v27; // [esp+10h] [ebp-38h] BYREF
  tagRECT Rect; // [esp+14h] [ebp-34h] BYREF
  tagRECT v29; // [esp+24h] [ebp-24h] BYREF
  vostok::render::output_window_configuration out_value; // [esp+34h] [ebp-14h] BYREF

  v2 = 0;
  p_out_value = (unsigned int)&out_value;
  m_object = parent[66].m_object;
  memset(&out_value, 0, 17);
  out_value.windowed = 1;
  vostok::variant<32>::try_get<vostok::render::output_window_configuration>(
    (vostok::variant<32> *)this,
    (int)m_object,
    &out_value);
  if ( !this->m_is_editor )
  {
    if ( out_value.windowed )
    {
      DesktopWindow = GetDesktopWindow();
      GetWindowRect(DesktopWindow, &Rect);
      width = out_value.width;
      height = out_value.height;
      v29.left = (Rect.right - Rect.left) / 2 - (out_value.width >> 1);
      v29.top = (Rect.bottom - Rect.top) / 2 - (out_value.height >> 1);
      v29.right = out_value.width + v29.left;
      v29.bottom = out_value.height + v29.top;
      WindowLongA = GetWindowLongA((HWND)out_value.hwnd, -16);
      Menu = GetMenu((HWND)out_value.hwnd);
      AdjustWindowRect(&v29, WindowLongA, Menu != 0);
      if ( width == Rect.right - Rect.left && height == Rect.bottom - Rect.top )
      {
        top = v29.top;
        left = v29.left;
      }
      else
      {
        top = (Rect.bottom + v29.top - v29.bottom - Rect.top) / 2;
        left = (Rect.right + v29.left - v29.right - Rect.left) / 2;
      }
      SetWindowPos((HWND)out_value.hwnd, 0, left, top, v29.right - v29.left, v29.bottom - v29.top, 0);
      v2 = 0;
    }
    else
    {
      SetWindowPos((HWND)out_value.hwnd, 0, 0, 0, out_value.width, out_value.height, 0);
    }
  }
  v12 = vostok::render::g_allocator;
  v13 = type_info::raw_name(&vostok::render::render_output_window `RTTI Type Descriptor');
  v15 = vostok::memory::doug_lea_allocator::malloc_impl(v14, (int)v12, 0x2ED0u, v13, v24, v25, v26);
  if ( v15 )
  {
    vostok::render::render_output_window::render_output_window(
      (vostok::render::render_output_window *)&out_value,
      (vostok::render::render_output_window *)v15,
      (survarium::flash_renderer *)&out_value);
    v2 = v17;
  }
  v27 = v2;
  vostok::buffer_vector<vostok::render::render_output_window *>::push_back(
    v16,
    (int)&vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows,
    &v27);
  p_out_value = 11984;
  v22 = &vostok::resources::nocache_memory;
  v21.m_object = v18;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v21,
    (survarium::pure_game_effect_emitter_base *)v2);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v19,
    parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v21.m_object,
    v22,
    p_out_value);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v20,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
