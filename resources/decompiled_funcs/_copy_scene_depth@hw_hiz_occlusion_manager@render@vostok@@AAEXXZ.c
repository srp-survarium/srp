void __usercall vostok::render::hw_hiz_occlusion_manager::copy_scene_depth(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  unsigned int v3; // ecx
  vostok::render::render_target *v4; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v5; // [esp-1Ch] [ebp-30h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v6; // [esp-18h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v7; // [esp-14h] [ebp-28h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v8; // [esp-10h] [ebp-24h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v9; // [esp-Ch] [ebp-20h]
  D3D11_VIEWPORT *v10; // [esp-8h] [ebp-1Ch]
  float v11; // [esp-4h] [ebp-18h]
  float pos_y; // [esp+0h] [ebp-14h]
  float size_x; // [esp+4h] [ebp-10h]
  float size_y; // [esp+8h] [ebp-Ch]
  float v15; // [esp+Ch] [ebp-8h]
  vostok::render::hw_hiz_occlusion_manager *v16; // [esp+10h] [ebp-4h]

  v16 = this;
  v2 = *(_DWORD **)(a2 + 4);
  v3 = (v2[71] - v2[70]) >> 2;
  if ( v3 > 2 )
  {
    v2[69] = 2;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v3, (int)v2);
  }
  v15 = 1.0;
  size_y = 1.0;
  size_x = 0.0;
  pos_y = 0.0;
  v11 = 0.0;
  v10 = 0;
  v9.m_object = 0;
  v8.m_object = 0;
  v7.m_object = 0;
  v6.m_object = 0;
  v4 = *(vostok::render::render_target **)(a2 + 136);
  v5.m_object = 0;
  if ( v4 )
  {
    v5.m_object = v4;
    ++v4->m_reference_count;
  }
  vostok::render::system_renderer::fill_surface(
    (vostok::render::system_renderer *)&v5,
    (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    pos_y,
    size_x,
    size_y,
    v15);
}
