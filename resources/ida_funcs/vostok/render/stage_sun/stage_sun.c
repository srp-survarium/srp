void __userpurge vostok::render::stage_sun::stage_sun(
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *in_context@<eax>,
        vostok::render::stage_sun *this,
        vostok::render::cloud_interp_textures *in_cloud_interp_textures,
        vostok::render::cloud_simulation *in_simulation)
{
  vostok::strings::shared::profile *v5; // eax
  vostok::render::backend *v6; // ecx
  vostok::strings::shared::manager *v7; // esi
  vostok::strings::shared::profile *v8; // eax
  vostok::render::backend *v9; // ecx
  vostok::strings::shared::manager *v10; // esi
  vostok::strings::shared::profile *v11; // eax
  vostok::render::backend *v12; // ecx
  vostok::strings::shared::manager *v13; // esi
  vostok::strings::shared::profile *v14; // eax
  vostok::render::backend *v15; // ecx
  vostok::strings::shared::manager *v16; // esi
  vostok::strings::shared::profile *v17; // eax
  vostok::render::backend *v18; // ecx
  vostok::strings::shared::manager *v19; // esi
  vostok::strings::shared::profile *v20; // eax
  vostok::render::backend *v21; // ecx
  vostok::strings::shared::manager *v22; // esi
  vostok::strings::shared::profile *v23; // eax
  vostok::render::backend *v24; // ecx
  vostok::strings::shared::manager *v25; // esi
  vostok::strings::shared::profile *v26; // eax
  vostok::render::backend *v27; // ecx
  vostok::strings::shared::manager *v28; // esi
  vostok::strings::shared::profile *v29; // eax
  vostok::render::backend *v30; // ecx
  vostok::strings::shared::manager *v31; // esi
  vostok::strings::shared::profile *v32; // eax
  vostok::render::backend *v33; // ecx
  vostok::strings::shared::manager *v34; // esi
  vostok::strings::shared::profile *v35; // eax
  vostok::render::backend *v36; // ecx
  vostok::strings::shared::manager *v37; // esi
  vostok::strings::shared::profile *v38; // eax
  vostok::render::backend *v39; // ecx
  vostok::strings::shared::manager *v40; // esi
  vostok::strings::shared::profile *v41; // eax
  vostok::render::backend *v42; // ecx
  vostok::strings::shared::manager *v43; // esi
  vostok::strings::shared::profile *v44; // eax
  vostok::render::backend *v45; // ecx
  vostok::strings::shared::manager *v46; // esi
  vostok::strings::shared::profile *v47; // eax
  vostok::render::backend *v48; // ecx
  vostok::strings::shared::manager *v49; // esi
  vostok::strings::shared::profile *v50; // eax
  vostok::render::backend *v51; // ecx
  vostok::strings::shared::manager *v52; // esi
  vostok::strings::shared::profile *v53; // eax
  vostok::render::backend *v54; // ecx
  vostok::strings::shared::manager *v55; // esi
  vostok::strings::shared::profile *v56; // eax
  vostok::render::backend *v57; // ecx
  vostok::strings::shared::profile *m_object; // ecx
  int v59; // edi
  vostok::render::stage_sun::{ctor}::__l2::half2 *v60; // esi
  int v61; // ebx
  long double v62; // st7
  unsigned __int16 *v63; // eax
  unsigned __int16 *v64; // eax
  vostok::render::stage_sun::{ctor}::__l2::half2 *v65; // ebx
  vostok::render::res_texture *v66; // eax
  vostok::render::res_texture *v67; // ecx
  vostok::render::res_texture *v68; // esi
  void *m_reconstruction_info_actuality_tick_high; // esi
  float x; // [esp+0h] [ebp-34h]
  float xa; // [esp+0h] [ebp-34h]
  float xb; // [esp+0h] [ebp-34h]
  unsigned int v74; // [esp+4h] [ebp-30h]
  vostok::math::half v75; // [esp+12h] [ebp-22h] BYREF
  vostok::shared_string name; // [esp+14h] [ebp-20h] BYREF
  int v77; // [esp+18h] [ebp-1Ch]
  int v78; // [esp+1Ch] [ebp-18h]
  float angle; // [esp+20h] [ebp-14h]
  vostok::render::stage_sun::{ctor}::__l2::half2 *temp_data; // [esp+24h] [ebp-10h]
  D3D11_SUBRESOURCE_DATA data; // [esp+28h] [ebp-Ch] BYREF

  this->m_context = in_context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_sun_vtbl *)&vostok::render::stage_sun::`vftable';
  this->m_sun_effect.m_object = 0;
  this->m_shadow_jitter.m_object = 0;
  vostok::render::box_geometry::box_geometry((vostok::render::box_geometry *)in_renderer);
  this->m_cloud_interp_textures = in_cloud_interp_textures;
  this->m_simulation = in_simulation;
  v5 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v7 = 0;
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    v7 = (vostok::strings::shared::manager *)v5;
    name.m_pointer.m_object = v5;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  this->m_c_light_color = vostok::render::backend::register_constant_host(
                            v6,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v7 && !_InterlockedExchangeAdd((volatile signed __int32 *)v7, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v7, (vostok::strings::shared::profile *)s_manager.m_variable);
  v8 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v10 = 0;
  name.m_pointer.m_object = 0;
  if ( v8 )
  {
    v10 = (vostok::strings::shared::manager *)v8;
    name.m_pointer.m_object = v8;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  this->m_c_light_direction = vostok::render::backend::register_constant_host(
                                v9,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                &name,
                                rc_float);
  if ( v10 && !_InterlockedExchangeAdd((volatile signed __int32 *)v10, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v10, (vostok::strings::shared::profile *)s_manager.m_variable);
  v11 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v13 = 0;
  name.m_pointer.m_object = 0;
  if ( v11 )
  {
    v13 = (vostok::strings::shared::manager *)v11;
    name.m_pointer.m_object = v11;
    _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  this->m_c_light_intensity = vostok::render::backend::register_constant_host(
                                v12,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                &name,
                                rc_float);
  if ( v13 && !_InterlockedExchangeAdd((volatile signed __int32 *)v13, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v13, (vostok::strings::shared::profile *)s_manager.m_variable);
  v14 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v16 = 0;
  name.m_pointer.m_object = 0;
  if ( v14 )
  {
    v16 = (vostok::strings::shared::manager *)v14;
    name.m_pointer.m_object = v14;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  this->m_c_shadow_transparency = vostok::render::backend::register_constant_host(
                                    v15,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    &name,
                                    rc_float);
  if ( v16 && !_InterlockedExchangeAdd((volatile signed __int32 *)v16, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v16, (vostok::strings::shared::profile *)s_manager.m_variable);
  v17 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v19 = 0;
  name.m_pointer.m_object = 0;
  if ( v17 )
  {
    v19 = (vostok::strings::shared::manager *)v17;
    name.m_pointer.m_object = v17;
    _InterlockedExchangeAdd(&v17->m_reference_count, 1u);
  }
  this->m_c_diffuse_influence_factor = vostok::render::backend::register_constant_host(
                                         v18,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_float);
  if ( v19 && !_InterlockedExchangeAdd((volatile signed __int32 *)v19, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v19, (vostok::strings::shared::profile *)s_manager.m_variable);
  v20 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v22 = 0;
  name.m_pointer.m_object = 0;
  if ( v20 )
  {
    v22 = (vostok::strings::shared::manager *)v20;
    name.m_pointer.m_object = v20;
    _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  this->m_c_specular_influence_factor = vostok::render::backend::register_constant_host(
                                          v21,
                                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                          &name,
                                          rc_float);
  if ( v22 && !_InterlockedExchangeAdd((volatile signed __int32 *)v22, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v22, (vostok::strings::shared::profile *)s_manager.m_variable);
  v23 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v25 = 0;
  name.m_pointer.m_object = 0;
  if ( v23 )
  {
    v25 = (vostok::strings::shared::manager *)v23;
    name.m_pointer.m_object = v23;
    _InterlockedExchangeAdd(&v23->m_reference_count, 1u);
  }
  this->m_c_inverted_view_projection_matrix = vostok::render::backend::register_constant_host(
                                                v24,
                                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                &name,
                                                rc_float);
  if ( v25 && !_InterlockedExchangeAdd((volatile signed __int32 *)v25, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v25, (vostok::strings::shared::profile *)s_manager.m_variable);
  v26 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v28 = 0;
  name.m_pointer.m_object = 0;
  if ( v26 )
  {
    v28 = (vostok::strings::shared::manager *)v26;
    name.m_pointer.m_object = v26;
    _InterlockedExchangeAdd(&v26->m_reference_count, 1u);
  }
  this->m_c_sun_fixed_matrix = vostok::render::backend::register_constant_host(
                                 v27,
                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                 &name,
                                 rc_float);
  if ( v28 && !_InterlockedExchangeAdd((volatile signed __int32 *)v28, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v28, (vostok::strings::shared::profile *)s_manager.m_variable);
  v29 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v31 = 0;
  name.m_pointer.m_object = 0;
  if ( v29 )
  {
    v31 = (vostok::strings::shared::manager *)v29;
    name.m_pointer.m_object = v29;
    _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
  }
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                               v30,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               &name,
                               rc_float);
  if ( v31 && !_InterlockedExchangeAdd((volatile signed __int32 *)v31, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v31, (vostok::strings::shared::profile *)s_manager.m_variable);
  v32 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v34 = 0;
  name.m_pointer.m_object = 0;
  if ( v32 )
  {
    v34 = (vostok::strings::shared::manager *)v32;
    name.m_pointer.m_object = v32;
    _InterlockedExchangeAdd(&v32->m_reference_count, 1u);
  }
  this->m_shadow[0] = vostok::render::backend::register_constant_host(
                        v33,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v34 && !_InterlockedExchangeAdd((volatile signed __int32 *)v34, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v34, (vostok::strings::shared::profile *)s_manager.m_variable);
  v35 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v37 = 0;
  name.m_pointer.m_object = 0;
  if ( v35 )
  {
    v37 = (vostok::strings::shared::manager *)v35;
    name.m_pointer.m_object = v35;
    _InterlockedExchangeAdd(&v35->m_reference_count, 1u);
  }
  this->m_shadow[1] = vostok::render::backend::register_constant_host(
                        v36,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v37 && !_InterlockedExchangeAdd((volatile signed __int32 *)v37, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v37, (vostok::strings::shared::profile *)s_manager.m_variable);
  v38 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v40 = 0;
  name.m_pointer.m_object = 0;
  if ( v38 )
  {
    v40 = (vostok::strings::shared::manager *)v38;
    name.m_pointer.m_object = v38;
    _InterlockedExchangeAdd(&v38->m_reference_count, 1u);
  }
  this->m_shadow[2] = vostok::render::backend::register_constant_host(
                        v39,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v40 && !_InterlockedExchangeAdd((volatile signed __int32 *)v40, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v40, (vostok::strings::shared::profile *)s_manager.m_variable);
  v41 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v43 = 0;
  name.m_pointer.m_object = 0;
  if ( v41 )
  {
    v43 = (vostok::strings::shared::manager *)v41;
    name.m_pointer.m_object = v41;
    _InterlockedExchangeAdd(&v41->m_reference_count, 1u);
  }
  this->m_shadow[3] = vostok::render::backend::register_constant_host(
                        v42,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v43 && !_InterlockedExchangeAdd((volatile signed __int32 *)v43, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v43, (vostok::strings::shared::profile *)s_manager.m_variable);
  v44 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v46 = 0;
  name.m_pointer.m_object = 0;
  if ( v44 )
  {
    v46 = (vostok::strings::shared::manager *)v44;
    name.m_pointer.m_object = v44;
    _InterlockedExchangeAdd(&v44->m_reference_count, 1u);
  }
  this->m_c_clouds_offset = vostok::render::backend::register_constant_host(
                              v45,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v46 && !_InterlockedExchangeAdd((volatile signed __int32 *)v46, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v46, (vostok::strings::shared::profile *)s_manager.m_variable);
  v47 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v49 = 0;
  name.m_pointer.m_object = 0;
  if ( v47 )
  {
    v49 = (vostok::strings::shared::manager *)v47;
    name.m_pointer.m_object = v47;
    _InterlockedExchangeAdd(&v47->m_reference_count, 1u);
  }
  this->m_c_world_to_cloud = vostok::render::backend::register_constant_host(
                               v48,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               &name,
                               rc_float);
  if ( v49 && !_InterlockedExchangeAdd((volatile signed __int32 *)v49, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v49, (vostok::strings::shared::profile *)s_manager.m_variable);
  v50 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v52 = 0;
  name.m_pointer.m_object = 0;
  if ( v50 )
  {
    v52 = (vostok::strings::shared::manager *)v50;
    name.m_pointer.m_object = v50;
    _InterlockedExchangeAdd(&v50->m_reference_count, 1u);
  }
  this->m_c_cloud_interp_alpha = vostok::render::backend::register_constant_host(
                                   v51,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( v52 && !_InterlockedExchangeAdd((volatile signed __int32 *)v52, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v52, (vostok::strings::shared::profile *)s_manager.m_variable);
  v53 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v55 = 0;
  name.m_pointer.m_object = 0;
  if ( v53 )
  {
    v55 = (vostok::strings::shared::manager *)v53;
    name.m_pointer.m_object = v53;
    _InterlockedExchangeAdd(&v53->m_reference_count, 1u);
  }
  this->m_c_environment_skylight_upper_color = vostok::render::backend::register_constant_host(
                                                 v54,
                                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                 &name,
                                                 rc_float);
  if ( v55 && !_InterlockedExchangeAdd((volatile signed __int32 *)v55, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v55, (vostok::strings::shared::profile *)s_manager.m_variable);
  v56 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v56);
  this->m_c_environment_skylight_lower_color = vostok::render::backend::register_constant_host(
                                                 v57,
                                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                 &name,
                                                 rc_float);
  if ( name.m_pointer.m_object )
  {
    m_object = name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)m_object,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 248);
  temp_data = (vostok::render::stage_sun::{ctor}::__l2::half2 *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                  0x4000u);
  v59 = (int)&loc_186A0;
  v60 = temp_data;
  v78 = 16;
  do
  {
    v77 = 16;
    do
    {
      v61 = 16;
      do
      {
        v59 = 134775813 * v59 + 1;
        v62 = (double)((unsigned __int64)(unsigned int)v59 >> 12) * 0.00000095367432 * 6.2831855;
        angle = v62;
        x = cos(v62);
        vostok::math::half::half(&v75, x);
        xa = angle;
        v60->x.data = *v63;
        xb = sinf(xa);
        vostok::math::half::half((vostok::math::half *)&name, xb);
        v60->y.data = *v64;
        ++v60;
        --v61;
      }
      while ( v61 );
      --v77;
    }
    while ( v77 );
    --v78;
  }
  while ( v78 );
  v65 = temp_data;
  data.pSysMem = temp_data;
  data.SysMemPitch = 64;
  data.SysMemSlicePitch = 1024;
  v66 = vostok::render::resource_manager::create_texture3d(
          &data,
          DXGI_FORMAT_R16G16_FLOAT,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          "$user$jitter_lookup",
          0x10u,
          0x10u,
          0x10u,
          D3D11_USAGE_IMMUTABLE,
          v74);
  v67 = 0;
  if ( v66 )
  {
    ++v66->m_reference_count;
    v67 = v66;
  }
  v68 = this->m_shadow_jitter.m_object;
  this->m_shadow_jitter.m_object = v67;
  if ( v68 )
  {
    if ( v68->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl(v67, v68);
  }
  if ( v65 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v65);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_sun>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sun_effect);
}
