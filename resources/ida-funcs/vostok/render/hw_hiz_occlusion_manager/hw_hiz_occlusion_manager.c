void __thiscall vostok::render::hw_hiz_occlusion_manager::hw_hiz_occlusion_manager(
        vostok::render::hw_hiz_occlusion_manager *this,
        unsigned int use_scene_depth_buffer,
        unsigned int rasterize_width,
        const D3D11_SUBRESOURCE_DATA *rasterize_height)
{
  const D3D11_SUBRESOURCE_DATA *v5; // eax
  unsigned int v6; // ecx
  int v7; // edx
  unsigned int v8; // ecx
  char *v9; // edx
  long double v10; // st7
  vostok::render::res_declaration *declaration; // eax
  vostok::render::resource_manager *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // edi
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  unsigned int v16; // edi
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_object; // eax
  vostok::render::res_texture *v18; // esi
  bool v19; // zf
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *texture2d; // eax
  vostok::render::resource_manager *v22; // ecx
  vostok::render::res_texture *v23; // eax
  vostok::render::effect_manager *v24; // ecx
  vostok::render::res_texture *v25; // ecx
  vostok::render::resource_manager *v26; // ecx
  stlp_std::priv::_Rb_tree_node_base *v27; // eax
  vostok::shared_string *v28; // ecx
  vostok::render::backend *v29; // ecx
  vostok::render::shader_constant_host *v30; // eax
  vostok::shared_string *v31; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v32; // esi
  vostok::render::backend *v33; // ecx
  vostok::render::shader_constant_host *v34; // eax
  vostok::shared_string *v35; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v36; // esi
  vostok::render::backend *v37; // ecx
  vostok::render::shader_constant_host *v38; // eax
  vostok::shared_string *v39; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v40; // esi
  vostok::render::backend *v41; // ecx
  vostok::render::shader_constant_host *v42; // eax
  vostok::shared_string *v43; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v44; // esi
  vostok::render::backend *v45; // ecx
  vostok::render::shader_constant_host *v46; // eax
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v47; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v48; // [esp-Ch] [ebp-118h] BYREF
  const D3D11_INPUT_ELEMENT_DESC *v49; // [esp-8h] [ebp-114h]
  unsigned int v50; // [esp-4h] [ebp-110h]
  vostok::strings::shared::profile *v51; // [esp+0h] [ebp-10Ch]
  unsigned int w; // [esp+10h] [ebp-FCh] BYREF
  _BYTE *v53; // [esp+14h] [ebp-F8h]
  _BYTE *v54; // [esp+18h] [ebp-F4h]
  _BYTE v55[128]; // [esp+1Ch] [ebp-F0h] BYREF
  _BYTE v56[8]; // [esp+9Ch] [ebp-70h] BYREF
  unsigned int count[14]; // [esp+A4h] [ebp-68h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v58; // [esp+DCh] [ebp-30h] BYREF
  char *name; // [esp+E8h] [ebp-24h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+ECh] [ebp-20h] BYREF
  unsigned int h; // [esp+F0h] [ebp-1Ch] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v62; // [esp+F4h] [ebp-18h] BYREF
  unsigned int v63; // [esp+100h] [ebp-Ch]
  vostok::buffer_string *v64; // [esp+104h] [ebp-8h]
  unsigned int sample_count; // [esp+114h] [ebp+8h]
  unsigned int sample_counta; // [esp+114h] [ebp+8h]

  *(_BYTE *)use_scene_depth_buffer = 1;
  *(_DWORD *)(use_scene_depth_buffer + 4) = 0;
  memset((void *)(use_scene_depth_buffer + 8), 0, 0x40u);
  memset((void *)(use_scene_depth_buffer + 72), 0, 0x40u);
  memset((void *)(use_scene_depth_buffer + 136), 0, 0x40u);
  v5 = rasterize_height;
  v6 = rasterize_width;
  *(_DWORD *)(use_scene_depth_buffer + 200) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 204) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 208) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 212) = 0;
  v7 = -(v6 < (unsigned int)v5);
  *(_DWORD *)(use_scene_depth_buffer + 216) = v6;
  v8 = v6 - (_DWORD)v5;
  v9 = (char *)v5 + (v8 & v7);
  name = v9;
  sample_count = 0;
  *(_DWORD *)(use_scene_depth_buffer + 220) = v5;
  v10 = (double)(int)name;
  if ( (int)v9 < 0 )
    v10 = v10 + 4294967300.0;
  *(_DWORD *)(use_scene_depth_buffer + 224) = (unsigned __int64)(__FYL2X__(v10, 0.6931471805599453094)
                                                               / __FYL2X__(2.0, 0.6931471805599453094))
                                            + 1;
  v50 = use_scene_depth_buffer + 232;
  *(_BYTE *)(use_scene_depth_buffer + 228) = 1;
  vostok::render::sphere_occluder_geometry::sphere_occluder_geometry(
    (vostok::render::sphere_occluder_geometry *)v8,
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v50);
  *(_DWORD *)(use_scene_depth_buffer + 256) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 260) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 264) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 268) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 272) = 0;
  count[9] = 16;
  count[11] = 16;
  v50 = 2;
  *(_DWORD *)(use_scene_depth_buffer + 276) = 0;
  v49 = (const D3D11_INPUT_ELEMENT_DESC *)count;
  v48.m_object = (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  *(_DWORD *)(use_scene_depth_buffer + 280) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 284) = 0;
  *(_DWORD *)(use_scene_depth_buffer + 288) = 0;
  count[0] = (unsigned int)"POSITION";
  count[1] = 0;
  count[2] = 2;
  memset(&count[3], 0, 16);
  count[7] = (unsigned int)"TEXCOORD";
  count[8] = 0;
  count[10] = 0;
  count[12] = 0;
  count[13] = 0;
  declaration = vostok::render::resource_manager::create_declaration(
                  (vostok::render::resource_manager *)2,
                  (const D3D11_INPUT_ELEMENT_DESC *)v48.m_object,
                  v49,
                  v50);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(use_scene_depth_buffer + 280),
    declaration);
  v64 = 0;
  if ( *(_DWORD *)(use_scene_depth_buffer + 224) )
  {
    v63 = use_scene_depth_buffer + 8;
    do
    {
      w = (unsigned int)v55;
      v53 = v55;
      v54 = v56;
      v13 = rasterize_width >> (char)v64;
      v14 = (unsigned int)rasterize_height >> (char)v64;
      v55[0] = 0;
      vostok::fs_new::path_string_impl::assignf(
        &w,
        v64,
        (vostok::buffer_string *)"%s_work_%d",
        "$user$hiz_occlusion_depth_mips",
        v64);
      render_target = vostok::render::resource_manager::create_render_target(
                        0,
                        (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                        (_BYTE *)w,
                        v13,
                        v14,
                        (char *)0x36,
                        DXGI_FORMAT_R32G32B32A32_TYPELESS,
                        0,
                        0,
                        0,
                        (unsigned int)v51);
      v16 = v63;
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v63,
        (vostok::render::render_target *)render_target);
      if ( *(_DWORD *)v16
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        sample_count |= 1u;
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &object,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)v16 + 28));
        v16 = v63;
        p_object = &object;
        v18 = (vostok::render::res_texture *)h;
      }
      else
      {
        sample_count |= 2u;
        v18 = 0;
        h = 0;
        p_object = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&h;
      }
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        p_object,
        (vostok::render::res_texture *)(v16 + 64));
      if ( (sample_count & 2) != 0 )
      {
        sample_count &= ~2u;
        if ( v18 )
        {
          v19 = v18->m_reference_count-- == 1;
          if ( v19 )
            vostok::render::resource_manager::release(
              v12,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v18);
        }
      }
      if ( (sample_count & 1) != 0 )
      {
        m_object = object.m_object;
        sample_count &= ~1u;
        if ( object.m_object )
        {
          v19 = object.m_object->m_reference_count-- == 1;
          if ( v19 )
            vostok::render::resource_manager::release(
              v12,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              m_object);
        }
      }
      v64 = (vostok::buffer_string *)((char *)v64 + 1);
      v63 += 4;
    }
    while ( (unsigned int)v64 < *(_DWORD *)(use_scene_depth_buffer + 224) );
  }
  texture2d = vostok::render::resource_manager::create_texture2d(
                v12,
                (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                "$user$hiz_occlusion_depth_mips",
                rasterize_width,
                rasterize_height,
                0,
                DXGI_FORMAT_R16_FLOAT,
                D3D11_USAGE_DEFAULT,
                *(_DWORD *)(use_scene_depth_buffer + 224),
                1u);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    texture2d,
    (vostok::render::res_texture *)(use_scene_depth_buffer + 204));
  v23 = vostok::render::resource_manager::create_texture2d(
          v22,
          (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          "$user$hiz_occlusion_depth_mips_lockable",
          rasterize_width,
          rasterize_height,
          0,
          DXGI_FORMAT_R16_FLOAT,
          D3D11_USAGE_STAGING,
          1u,
          0);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v23,
    (vostok::render::res_texture *)(use_scene_depth_buffer + 212));
  sample_counta = 0;
  if ( *(_DWORD *)(use_scene_depth_buffer + 224) )
  {
    v64 = (vostok::buffer_string *)(use_scene_depth_buffer + 136);
    do
    {
      h = rasterize_width >> sample_counta;
      v55[0] = 0;
      object.m_object = (vostok::render::res_texture *)((unsigned int)rasterize_height >> sample_counta);
      w = (unsigned int)v55;
      v53 = v55;
      v54 = v56;
      vostok::fs_new::path_string_impl::assignf(
        &w,
        (vostok::buffer_string *)sample_counta,
        (vostok::buffer_string *)"%s_%d",
        "$user$hiz_occlusion_depth_mips",
        sample_counta);
      v50 = sample_counta;
      v49 = 0;
      v63 = w;
      v48.m_object = v25;
      name = (char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        &v48,
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(use_scene_depth_buffer + 204));
      v27 = vostok::render::resource_manager::create_render_target(
              v26,
              (const char **)name,
              (_BYTE *)v63,
              h,
              (unsigned int)object.m_object,
              (char *)0x36,
              DXGI_FORMAT_R32G32B32A32_TYPELESS,
              v48.m_object,
              (unsigned int)v49,
              (vostok::render::res_texture *)v50,
              (unsigned int)v51);
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v64,
        (vostok::render::render_target *)v27);
      ++sample_counta;
      v64 = (vostok::buffer_string *)((char *)v64 + 4);
    }
    while ( sample_counta < *(_DWORD *)(use_scene_depth_buffer + 224) );
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_hiz_occlusion>(
    v24,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(use_scene_depth_buffer + 4));
  vostok::shared_string::shared_string(
    v28,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&rasterize_width,
    "source_mip_level");
  v30 = vostok::render::backend::register_constant_host(
          v29,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&rasterize_width,
          (vostok::strings::shared::profile *)1);
  v19 = rasterize_width == 0;
  *(_DWORD *)(use_scene_depth_buffer + 236) = v30;
  if ( !v19 )
  {
    v31 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)rasterize_width, 0xFFFFFFFF);
    if ( !v31 )
    {
      v32 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)rasterize_width;
      rasterize_height = (const D3D11_SUBRESOURCE_DATA *)rasterize_width;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v32,
        &v62,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v51);
      while ( v62.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v62.m_value != v32 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v62,
          &v58);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v62.m_index,
        v62.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)rasterize_height, v51);
      v31 = (vostok::shared_string *)v50;
    }
  }
  vostok::shared_string::shared_string(
    v31,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&rasterize_width,
    "draw_color");
  v34 = vostok::render::backend::register_constant_host(
          v33,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&rasterize_width,
          0);
  v19 = rasterize_width == 0;
  *(_DWORD *)(use_scene_depth_buffer + 240) = v34;
  if ( !v19 )
  {
    v35 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)rasterize_width, 0xFFFFFFFF);
    if ( !v35 )
    {
      v36 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)rasterize_width;
      rasterize_height = (const D3D11_SUBRESOURCE_DATA *)rasterize_width;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v36,
        &v62,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v51);
      while ( v62.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v62.m_value != v36 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v62,
          &v58);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v62.m_index,
        v62.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)rasterize_height, v51);
      v35 = (vostok::shared_string *)v50;
    }
  }
  vostok::shared_string::shared_string(
    v35,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&rasterize_width,
    "render_target_size");
  v38 = vostok::render::backend::register_constant_host(
          v37,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&rasterize_width,
          0);
  v19 = rasterize_width == 0;
  *(_DWORD *)(use_scene_depth_buffer + 244) = v38;
  if ( !v19 )
  {
    v39 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)rasterize_width, 0xFFFFFFFF);
    if ( !v39 )
    {
      v40 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)rasterize_width;
      rasterize_height = (const D3D11_SUBRESOURCE_DATA *)rasterize_width;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v40,
        &v62,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v51);
      while ( v62.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v62.m_value != v40 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v62,
          &v58);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v62.m_index,
        v62.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)rasterize_height, v51);
      v39 = (vostok::shared_string *)v50;
    }
  }
  vostok::shared_string::shared_string(
    v39,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&rasterize_width,
    "rasterize_size");
  v42 = vostok::render::backend::register_constant_host(
          v41,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&rasterize_width,
          0);
  v19 = rasterize_width == 0;
  *(_DWORD *)(use_scene_depth_buffer + 248) = v42;
  if ( !v19 )
  {
    v43 = (vostok::shared_string *)_InterlockedExchangeAdd((volatile signed __int32 *)rasterize_width, 0xFFFFFFFF);
    if ( !v43 )
    {
      v44 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)rasterize_width;
      rasterize_height = (const D3D11_SUBRESOURCE_DATA *)rasterize_width;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v44,
        &v62,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v51);
      while ( v62.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v62.m_value != v44 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v62,
          &v58);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v62.m_index,
        v62.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)rasterize_height, v51);
      v43 = (vostok::shared_string *)v50;
    }
  }
  vostok::shared_string::shared_string(
    v43,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&rasterize_width,
    "prev_texture_size");
  v46 = vostok::render::backend::register_constant_host(
          v45,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&rasterize_width,
          0);
  v19 = rasterize_width == 0;
  *(_DWORD *)(use_scene_depth_buffer + 252) = v46;
  if ( !v19 && !_InterlockedExchangeAdd((volatile signed __int32 *)rasterize_width, 0xFFFFFFFF) )
  {
    v47 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)rasterize_width;
    rasterize_height = (const D3D11_SUBRESOURCE_DATA *)rasterize_width;
    vostok::threading::mutex::lock(0, &s_manager_buffer);
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
      v47,
      &v62,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
      v51);
    while ( v62.m_value
         && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v62.m_value != v47 )
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
        &v62,
        &v58);
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
      v62.m_index,
      v62.m_value);
    LeaveCriticalSection(&s_manager_buffer);
    vostok::strings::shared::profile::destroy((vostok::threading::mutex *)rasterize_height, v51);
  }
}
