// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::render::stage_shadow_direct::execute_cascade(
        vostok::render::stage_shadow_direct *this,
        vostok::render::stage_shadow_direct *cascade_id,
        unsigned int cascade_index,
        unsigned int shadow_map_size,
        unsigned int shadow_map_sizea)
{
  vostok::render::renderer_context *m_context; // ecx
  unsigned int v6; // edx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_object; // eax
  vostok::render::light *v8; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // eax
  vostok::render::light *v10; // esi
  vostok::render::light *v11; // eax
  vostok::render::shader_constant_host *m_c_light_position; // esi
  vostok::render::renderer_context *v13; // esi
  float v14; // xmm0_4
  void **M_start; // eax
  bool v16; // zf
  double v17; // st7
  long double v18; // st7
  float v19; // xmm0_4
  __int64 v20; // xmm1_8
  float z; // eax
  float v22; // edi
  unsigned int v23; // edx
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // esi
  float v27; // eax
  float v28; // ecx
  __int64 v29; // xmm0_8
  float v30; // xmm2_4
  float v31; // xmm1_4
  vostok::math::float3 *p_direction; // ecx
  float v33; // xmm0_4
  float v34; // edx
  vostok::math::float3 *p_position; // ebx
  float v36; // edi
  float *v37; // esi
  float v38; // ecx
  long double v39; // st7
  float v40; // xmm1_4
  float v41; // xmm2_4
  unsigned int v42; // xmm0_4
  unsigned int v43; // xmm1_4
  float v44; // xmm3_4
  vostok::render::ray *m_end; // eax
  unsigned __int64 v46; // xmm0_8
  vostok::render::sun_cascade *m_begin; // edx
  float v48; // xmm3_4
  float y; // xmm4_4
  float x; // xmm5_4
  unsigned int i; // eax
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  float v55; // ecx
  int *v56; // eax
  vostok::render::shadow_cascade_volume::polygon *light_cuboid_polys; // ecx
  float v58; // xmm2_4
  unsigned int v59; // xmm1_4
  unsigned int v60; // xmm0_4
  float v61; // xmm2_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  unsigned int v64; // ebx
  char v65; // dl
  char *v66; // eax
  vostok::render::renderer_context *v67; // eax
  vostok::math::float4x4 *v68; // edi
  vostok::render::renderer_context *v69; // ecx
  vostok::render::renderer_context *v70; // eax
  vostok::math::float4x4 *v71; // edi
  vostok::render::renderer_context *v72; // ebx
  vostok::render::renderer_context *v73; // esi
  char *v74; // ebx
  vostok::render::renderer_context *v75; // esi
  vostok::render::sun_cascade *v76; // eax
  vostok::render::renderer_context *v77; // eax
  vostok::math::float4x4 *v78; // edi
  vostok::render::renderer_context *v79; // ecx
  vostok::render::renderer_context *v80; // eax
  vostok::math::float4x4 *v81; // edi
  vostok::render::renderer_context *v82; // esi
  vostok::render::renderer_context *v83; // ecx
  vostok::render::renderer_context *v84; // esi
  vostok::render::renderer_context *v85; // ecx
  vostok::render::renderer_context *v86; // esi
  float v87; // ecx
  vostok::math::float3 *v88; // ebp
  vostok::render::grass_render_model *v89; // ecx
  float _X; // [esp+0h] [ebp-4ECh]
  float v91; // [esp+8h] [ebp-4E4h]
  bool v92; // [esp+8h] [ebp-4E4h]
  float v93; // [esp+8h] [ebp-4E4h]
  float v94; // [esp+8h] [ebp-4E4h]
  unsigned int v95; // [esp+8h] [ebp-4E4h]
  float v96; // [esp+Ch] [ebp-4E0h]
  float v97; // [esp+10h] [ebp-4DCh]
  float v98; // [esp+14h] [ebp-4D8h]
  vostok::render::ray *end; // [esp+18h] [ebp-4D4h] BYREF
  bool need_refresh; // [esp+1Fh] [ebp-4CDh]
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+20h] [ebp-4CCh] BYREF
  vostok::math::float3 real_vp; // [esp+24h] [ebp-4C8h] BYREF
  int v103; // [esp+30h] [ebp-4BCh]
  vostok::math::float3 view_pos; // [esp+34h] [ebp-4B8h] BYREF
  vostok::math::float3 eye_ray; // [esp+40h] [ebp-4ACh] BYREF
  int v106; // [esp+4Ch] [ebp-4A0h]
  vostok::render::ray *v107; // [esp+50h] [ebp-49Ch] BYREF
  vostok::math::float3 view_dir; // [esp+54h] [ebp-498h] BYREF
  vostok::render::stage_shadow_direct *v109; // [esp+60h] [ebp-48Ch]
  float current_cascade_offset; // [esp+64h] [ebp-488h]
  vostok::math::float3 gran0; // [esp+68h] [ebp-484h] BYREF
  int v112; // [esp+74h] [ebp-478h]
  unsigned int v113; // [esp+78h] [ebp-474h]
  float size; // [esp+7Ch] [ebp-470h]
  vostok::math::float4_pod offset_to_viewer; // [esp+80h] [ebp-46Ch] OVERLAPPED
  vostok::math::float3 light_shift_xz; // [esp+90h] [ebp-45Ch] BYREF
  float current_cascade_align_mult; // [esp+9Ch] [ebp-450h]
  vostok::render::vector<vostok::render::render_surface_instance *> m_caster_model; // [esp+A0h] [ebp-44Ch] BYREF
  unsigned int pass_index; // [esp+ACh] [ebp-440h]
  vostok::math::float4x4 orig_view_projection; // [esp+B0h] [ebp-43Ch] BYREF
  vostok::math::float4x4 light_full_transform_invert; // [esp+F0h] [ebp-3FCh] BYREF
  __int128 v122; // [esp+138h] [ebp-3B4h]
  vostok::math::float4x4 shadow_trans; // [esp+148h] [ebp-3A4h] BYREF
  vostok::math::float4x4 light_view_transform; // [esp+188h] [ebp-364h] BYREF
  vostok::render::shadow_cascade_volume cascade_volume; // [esp+1C8h] [ebp-324h] BYREF
  vostok::fixed_vector<vostok::math::plane,16> cull_planes; // [esp+3A0h] [ebp-14Ch] BYREF

  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
  + 299) = 1;
  m_context = cascade_id->m_context;
  memset(&m_caster_model, 0, sizeof(m_caster_model));
  v6 = LODWORD(m_context->m_scene_view.m_object[4].m_current_satisfaction_update_tick) % refresh_rate[shadow_map_size];
  m_object = (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_context->m_scene->m_lights.m_object;
  v8 = m_object[3].m_object;
  v107 = (vostok::render::ray *)&refresh_rate[shadow_map_size];
  need_refresh = v6 == 0;
  v9 = m_object + 3;
  pass_index = v6;
  if ( !v8
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    || v8->m_enabled )
  {
    object.m_object = 0;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
      (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v8,
      &object,
      v9);
    v10 = object.m_object;
    if ( !object.m_object )
      goto LABEL_8;
    v16 = object.m_object->m_reference_count-- == 1;
    if ( v16 )
    {
      v109 = (vostok::render::stage_shadow_direct *)vostok::render::g_allocator.m_object;
      vostok::render::light::~light((vostok::render::light *)vostok::render::g_allocator.m_object, (int)v10);
      v11 = v10;
      m_c_light_position = v109->m_c_light_position;
      BYTE2(v109->m_effect_shadow_direct.m_object) = 0;
      vostok_mspace_free((void *)m_c_light_position, v11);
    }
    v13 = cascade_id->m_context;
    v14 = v13->m_sun_cascades.m_begin[cascade_index].size;
    v113 = 276 * cascade_index;
    size = v14;
    if ( v14 < 0.0000001 )
    {
LABEL_8:
      M_start = m_caster_model._M_impl._M_start;
      v16 = m_caster_model._M_impl._M_start == 0;
LABEL_61:
      if ( !v16 )
      {
        v89 = vostok::render::g_allocator.m_object;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v89->m_reconstruction_info_actuality_tick), M_start);
      }
      return;
    }
    v17 = (double)shadow_map_sizea;
    *(float *)&v109 = v17;
    _X = 2048.0 / v17;
    v18 = powf(_X, 2.0);
    v19 = cascade_offsets[shadow_map_size];
    v16 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 299) == 0;
    current_cascade_offset = v19;
    current_cascade_align_mult = 1.0 / v18 * cascade_align_mults[shadow_map_size];
    if ( !v16 )
    {
      if ( shadow_map_size )
        v19 = 0.0;
      else
        v19 = -0.25;
      current_cascade_offset = v19;
      current_cascade_align_mult = *(float *)&clear_value;
    }
    v16 = !cascade_id->m_invalid_shadow;
    v20 = *(_QWORD *)&v13->m_view_dir.x;
    z = v13->m_view_dir.z;
    *(_QWORD *)&view_pos.x = *(_QWORD *)&v13->m_view_pos.x;
    v22 = v13->m_view_pos.z;
    *(_QWORD *)&view_dir.x = v20;
    view_dir.z = z;
    view_pos.z = v22;
    if ( v16
      && !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 299) )
    {
      *(float *)&end = fabs(
                         (float)((float)(cascade_id->m_previous_direction.y * view_dir.y)
                               + (float)(cascade_id->m_previous_direction.z * view_dir.z))
                       + (float)(view_dir.x * cascade_id->m_previous_direction.x));
      if ( *(float *)&end >= 0.75 )
      {
        v23 = 3 * shadow_map_size + 351;
        v24 = view_pos.y - *((float *)&cascade_id->m_context + v23);
        v25 = view_pos.z - *((float *)&cascade_id->m_renderer + v23);
        v26 = (float *)(&cascade_id->__vftable + v23);
        if ( sqrtf(
               (float)((float)(v24 * v24) + (float)(v25 * v25))
             + (float)((float)(view_pos.x - *v26) * (float)(view_pos.x - *v26))) <= cascade_pos_mults[shadow_map_size] )
        {
          v27 = v26[2];
          v28 = cascade_id->m_previous_direction.z;
          *(_QWORD *)&view_pos.x = *(_QWORD *)v26;
          v29 = *(_QWORD *)&cascade_id->m_previous_direction.x;
          view_pos.z = v27;
          *(_QWORD *)&view_dir.x = v29;
          view_dir.z = v28;
        }
        else
        {
          *(_QWORD *)v26 = *(_QWORD *)&view_pos.x;
          v26[2] = v22;
        }
        v19 = current_cascade_offset;
      }
      else
      {
        *(_QWORD *)&cascade_id->m_previous_direction.x = v20;
        cascade_id->m_previous_direction.z = z;
      }
    }
    v30 = object.m_object->direction.z;
    offset_to_viewer.x = view_dir.x * v19;
    offset_to_viewer.y = view_dir.y * v19;
    v31 = view_dir.z * v19;
    p_direction = &object.m_object->direction;
    v33 = object.m_object->direction.x * 300.0;
    offset_to_viewer.z = v31;
    eye_ray.y = view_pos.y - (float)(object.m_object->direction.y * 300.0);
    eye_ray.z = view_pos.z - (float)(v30 * 300.0);
    v34 = eye_ray.z;
    p_position = &object.m_object->position;
    eye_ray.x = view_pos.x - v33;
    *(_QWORD *)&object.m_object->position.x = *(_QWORD *)&eye_ray.x;
    LODWORD(real_vp.x) = clear_value;
    object.m_object = (vostok::render::light *)p_direction;
    p_position->z = v34;
    *(_QWORD *)&real_vp.elements[1] = 0;
    vostok::math::create_camera_direction(p_position, p_direction, &real_vp);
    vostok::math::create_orthographic_projection(
      (vostok::math *)LODWORD(size),
      (struct vostok::math::float4x4 *)LODWORD(size),
      v91,
      v96,
      v97,
      v98);
    cull_planes.m_begin = (vostok::math::plane *)cull_planes.m_buffer;
    cull_planes.m_end = (vostok::math::plane *)cull_planes.m_buffer;
    memset(&light_shift_xz, 0, sizeof(light_shift_xz));
    cascade_volume.view_frustum_rays.m_begin = (vostok::render::ray *)cascade_volume.view_frustum_rays.m_buffer;
    cascade_volume.view_frustum_rays.m_end = (vostok::render::ray *)cascade_volume.view_frustum_rays.m_buffer;
    if ( shadow_map_size )
    {
      m_begin = cascade_id->m_context->m_sun_cascades.m_begin;
      end = m_begin[v113 / 0x114].rays.m_end;
      v36 = COERCE_FLOAT(&end);
      vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
        m_begin[v113 / 0x114].rays.m_begin,
        (const vostok::render::ray *const *)&end,
        &cascade_volume.view_frustum_rays);
    }
    else
    {
      v36 = 0.0;
      do
      {
        v37 = (float *)cascade_id->m_context;
        v38 = *(float *)((char *)v37 + LODWORD(v36) + 16780);
        *(_QWORD *)&eye_ray.x = *(_QWORD *)((char *)v37 + LODWORD(v36) + 16772);
        eye_ray.z = v38;
        v39 = sqrtf((float)((float)(eye_ray.x * eye_ray.x) + (float)(v38 * v38)) + (float)(eye_ray.y * eye_ray.y));
        v40 = v37[3941];
        v41 = v37[3942];
        *(float *)&end = 1.0 / v39;
        *(float *)&v42 = (float)((float)(v37[3945] * (float)(*(float *)&end * eye_ray.z))
                               + (float)(v40 * (float)(*(float *)&end * eye_ray.y)))
                       + (float)((float)(*(float *)&end * eye_ray.x) * v37[3937]);
        *(float *)&v43 = (float)((float)(v37[3946] * (float)(*(float *)&end * eye_ray.z))
                               + (float)(v41 * (float)(*(float *)&end * eye_ray.y)))
                       + (float)(v37[3938] * (float)(*(float *)&end * eye_ray.x));
        v44 = v37[3093];
        gran0.z = (float)((float)(v37[3947] * (float)(*(float *)&end * eye_ray.z))
                        + (float)(v37[3943] * (float)(*(float *)&end * eye_ray.y)))
                + (float)(v37[3939] * (float)(*(float *)&end * eye_ray.x));
        *(_QWORD *)&gran0.x = __PAIR64__(v43, v42);
        real_vp.z = (float)(gran0.z * v44) + view_pos.z;
        m_end = cascade_volume.view_frustum_rays.m_end;
        real_vp.x = (float)(*(float *)&v42 * v44) + view_pos.x;
        v46 = __PAIR64__(v43, v42);
        real_vp.y = (float)(*(float *)&v43 * v44) + view_pos.y;
        *(float *)&v122 = gran0.z;
        *(vostok::math::float3 *)((char *)&v122 + 4) = real_vp;
        if ( cascade_volume.view_frustum_rays.m_end )
        {
          *(_QWORD *)&cascade_volume.view_frustum_rays.m_end->direction.x = v46;
          *(_OWORD *)&m_end->direction.elements[2] = v122;
        }
        ++cascade_volume.view_frustum_rays.m_end;
        LODWORD(v36) += 12;
      }
      while ( SLODWORD(v36) < 48 );
    }
    cascade_volume.view_ray.origin = view_pos;
    cascade_volume.view_ray.direction = view_dir;
    cascade_volume.light_ray.origin = *p_position;
    *(_QWORD *)&cascade_volume.light_ray.direction.x = *(_QWORD *)&object.m_object->m_reference_count;
    cascade_volume.light_ray.direction.z = object.m_object->m_xform.i.y;
    vostok::math::mul4x3(&orig_view_projection, &light_view_transform, &shadow_trans);
    invert_impl(
      &orig_view_projection,
      (float)((float)((float)((float)(orig_view_projection.k.z * orig_view_projection.j.y)
                            - (float)(orig_view_projection.j.z * orig_view_projection.k.y))
                    * orig_view_projection.i.x)
            - (float)((float)((float)(orig_view_projection.k.z * orig_view_projection.j.x)
                            - (float)(orig_view_projection.j.z * orig_view_projection.k.x))
                    * orig_view_projection.i.y))
    + (float)((float)((float)(orig_view_projection.j.x * orig_view_projection.k.y)
                    - (float)(orig_view_projection.j.y * orig_view_projection.k.x))
            * orig_view_projection.i.z));
    v48 = light_full_transform_invert.c.z;
    y = light_full_transform_invert.c.y;
    x = light_full_transform_invert.c.x;
    for ( i = 0; (int)i < 96; i += 12 )
    {
      v52 = corners[i / 0xC].x;
      v53 = *(float *)&dword_A57480[i / 4];
      v54 = *(float *)&dword_A5747C[i / 4];
      real_vp.x = (float)((float)((float)(light_full_transform_invert.i.x * v52)
                                + (float)(light_full_transform_invert.k.x * v53))
                        + (float)(light_full_transform_invert.j.x * v54))
                + x;
      real_vp.y = (float)((float)((float)(v52 * light_full_transform_invert.i.y)
                                + (float)(light_full_transform_invert.k.y * v53))
                        + (float)(light_full_transform_invert.j.y * v54))
                + y;
      real_vp.z = (float)((float)((float)(v52 * light_full_transform_invert.i.z)
                                + (float)(light_full_transform_invert.k.z * v53))
                        + (float)(light_full_transform_invert.j.z * v54))
                + v48;
      v55 = real_vp.z;
      *(_QWORD *)&cascade_volume.light_cuboid_points[i / 0xC].x = *(_QWORD *)&real_vp.x;
      *(float *)((char *)&cascade_volume.light_cuboid_points[0].z + i) = v55;
    }
    v56 = facetable[0];
    light_cuboid_polys = cascade_volume.light_cuboid_polys;
    do
    {
      light_cuboid_polys->points[0] = *v56;
      light_cuboid_polys->points[1] = v56[1];
      light_cuboid_polys->points[2] = v56[2];
      light_cuboid_polys->points[3] = v56[3];
      v56 += 4;
      ++light_cuboid_polys;
    }
    while ( (int)v56 < (int)facetable[4] );
    vostok::render::shadow_cascade_volume::compute_caster_model_fixed(
      (vostok::render::shadow_cascade_volume *)&cull_planes,
      v36,
      (float *)&cascade_volume,
      &cull_planes,
      &light_shift_xz,
      size,
      v92);
    vostok::math::mul4x3(&orig_view_projection, &light_view_transform, &shadow_trans);
    vostok::render::stage_shadow_direct::compute_aligment(
      &light_shift_xz,
      &real_vp,
      (int)&eye_ray,
      v109,
      current_cascade_align_mult,
      v93);
    v58 = eye_ray.x + p_position->x;
    *(float *)&v59 = (float)(p_position->z + eye_ray.z) + offset_to_viewer.z;
    *(_QWORD *)&gran0.x = (unsigned int)clear_value;
    gran0.z = 0.0;
    *(float *)&v60 = (float)(p_position->y + eye_ray.y) + offset_to_viewer.y;
    real_vp.x = offset_to_viewer.x + v58;
    *(_QWORD *)&real_vp.elements[1] = __PAIR64__(v59, v60);
    vostok::math::create_camera_direction(&real_vp, (const vostok::math::float3 *)object.m_object, &gran0);
    vostok::math::mul4x3(&light_full_transform_invert, &orig_view_projection, &shadow_trans);
    vostok::render::stage_shadow_direct::compute_aligment(&light_shift_xz, &gran0, (int)&real_vp, v109, 1.0, v94);
    v61 = light_shift_xz.x + p_position->x;
    v62 = p_position->z;
    *(_QWORD *)&view_dir.x = (unsigned int)clear_value;
    view_dir.z = 0.0;
    v63 = (float)((float)(p_position->y + light_shift_xz.y) + eye_ray.y) + offset_to_viewer.y;
    gran0.x = (float)(offset_to_viewer.x + (float)(eye_ray.x + v61)) + real_vp.x;
    gran0.y = real_vp.y + v63;
    gran0.z = real_vp.z + (float)((float)((float)(v62 + light_shift_xz.z) + eye_ray.z) + offset_to_viewer.z);
    qmemcpy(
      (void *)&light_view_transform,
      vostok::math::create_camera_direction(&gran0, (const vostok::math::float3 *)object.m_object, &view_dir),
      sizeof(light_view_transform));
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 299)
      || cascade_id->m_invalid_shadow )
    {
      v64 = shadow_map_size;
    }
    else
    {
      v64 = shadow_map_size;
      *(float *)&end = light_view_transform.c.x - cascade_id->m_previous_adjastment[shadow_map_size].x;
      end = (vostok::render::ray *)((unsigned int)end & 0x7FFFFFFF);
      if ( *(float *)&end < 0.0099999998
        || (*(float *)&end = light_view_transform.c.y - cascade_id->m_previous_adjastment[shadow_map_size].y,
            end = (vostok::render::ray *)((unsigned int)end & 0x7FFFFFFF),
            *(float *)&end < 0.0099999998) )
      {
        v65 = 0;
LABEL_40:
        if ( need_refresh )
        {
          v66 = (char *)cascade_id + 64 * v64;
          qmemcpy(v66 + 1452, &light_view_transform, 0x40u);
          qmemcpy(v66 + 1708, &shadow_trans, 0x40u);
        }
        if ( v65 )
        {
          v67 = cascade_id->m_context;
          qmemcpy((void *)&orig_view_projection, &v67->m_vp, sizeof(orig_view_projection));
          v68 = v67->m_v_stack.m_end;
          if ( v68 )
            qmemcpy((void *)v68, &v67->m_v, sizeof(vostok::math::float4x4));
          ++v67->m_v_stack.m_end;
          vostok::render::renderer_context::set_v(
            (vostok::render::renderer_context *)&light_view_transform,
            (const vostok::math::float4x4 *)v67);
          v70 = cascade_id->m_context;
          v71 = v70->m_p_stack.m_end;
          if ( v71 )
          {
            qmemcpy((void *)v71, &v70->m_p, sizeof(vostok::math::float4x4));
            v69 = 0;
          }
          ++v70->m_p_stack.m_end;
          vostok::render::renderer_context::set_p(v69, (const vostok::math::float4x4 *)v70);
          if ( need_refresh )
            vostok::render::stage_shadow_direct::prepare_models(
              &view_pos,
              cascade_id,
              &m_caster_model,
              &orig_view_projection,
              v64,
              v95);
          vostok::render::stage_shadow_direct::render_models(
            shadow_map_sizea,
            LODWORD(v107->direction.x),
            cascade_id,
            &m_caster_model,
            v64,
            (vostok::render::grass_world *)&view_pos,
            (const vostok::math::float3 *)pass_index,
            v95);
          v72 = cascade_id->m_context;
          qmemcpy((void *)&shadow_trans, &v72->m_vp, sizeof(shadow_trans));
          vostok::render::renderer_context::set_v(0, (const vostok::math::float4x4 *)v72);
          --v72->m_v_stack.m_end;
          v73 = cascade_id->m_context;
          vostok::render::renderer_context::set_p(
            (vostok::render::renderer_context *)&v73->m_p_stack.m_end[-1],
            (const vostok::math::float4x4 *)v73);
          --v73->m_p_stack.m_end;
          offset_to_viewer.z = -cascade_id->m_context->m_sun_cascades.m_begin[v113 / 0x114].bias;
          *(_QWORD *)&eye_ray.x = 0;
          v106 = 0;
          gran0.x = 0.0;
          v112 = 0;
          real_vp.z = 0.0;
          v103 = 0;
          *(_QWORD *)&real_vp.x = LODWORD(FLOAT_0_5);
          *(_QWORD *)&orig_view_projection.i.x = LODWORD(FLOAT_0_5);
          *(_QWORD *)&orig_view_projection.lines[0].elements[2] = 0;
          LODWORD(offset_to_viewer.w) = clear_value;
          LODWORD(eye_ray.z) = clear_value;
          *(_QWORD *)&gran0.elements[1] = 3204448256LL;
          *(_QWORD *)&orig_view_projection.lines[1].x = *(_QWORD *)&gran0.x;
          memset(&orig_view_projection.lines[1].elements[2], 0, 16);
          *(_QWORD *)&orig_view_projection.lines[2].elements[2] = (unsigned int)clear_value;
          offset_to_viewer.x = FLOAT_0_5;
          offset_to_viewer.y = FLOAT_0_5;
          orig_view_projection.c = offset_to_viewer;
          if ( need_refresh )
          {
            v74 = (char *)cascade_id + 64 * shadow_map_size;
            qmemcpy(v74 + 2476, v74 + 2220, 0x40u);
            vostok::math::mul4x3(&light_full_transform_invert, &shadow_trans, &orig_view_projection);
            qmemcpy(v74 + 2220, &light_full_transform_invert, 0x40u);
            v75 = cascade_id->m_context;
            if ( cascade_index < v75->m_sun_cascades.m_end - v75->m_sun_cascades.m_begin - 1 )
            {
              v76 = v75->m_sun_cascades.m_begin;
              v107 = cascade_volume.view_frustum_rays.m_end;
              vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
                cascade_volume.view_frustum_rays.m_begin,
                (const vostok::render::ray *const *)&v107,
                &v76[v113 / 0x114 + 1].rays);
            }
            qmemcpy(v74 + 1964, &cascade_id->m_context->m_v_inverted, 0x40u);
          }
          v64 = shadow_map_size;
        }
        if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
              + 299) )
        {
          v77 = cascade_id->m_context;
          real_vp = view_pos;
          v78 = v77->m_v_stack.m_end;
          if ( v78 )
            qmemcpy((void *)v78, &v77->m_v, sizeof(vostok::math::float4x4));
          ++v77->m_v_stack.m_end;
          v107 = (vostok::render::ray *)((char *)cascade_id + 64 * v64);
          vostok::render::renderer_context::set_v(
            (vostok::render::renderer_context *)&v107[60].origin,
            (const vostok::math::float4x4 *)v77);
          v80 = cascade_id->m_context;
          v81 = v80->m_p_stack.m_end;
          if ( v81 )
          {
            qmemcpy((void *)v81, &v80->m_p, sizeof(vostok::math::float4x4));
            v79 = 0;
          }
          ++v80->m_p_stack.m_end;
          vostok::render::renderer_context::set_p(v79, (const vostok::math::float4x4 *)v80);
          v82 = cascade_id->m_context;
          vostok::render::renderer_context::set_v(v83, (const vostok::math::float4x4 *)v82);
          --v82->m_v_stack.m_end;
          v84 = cascade_id->m_context;
          vostok::render::renderer_context::set_p(v85, (const vostok::math::float4x4 *)v84);
          --v84->m_p_stack.m_end;
        }
        v86 = cascade_id->m_context;
        vostok::math::mul4x3(&shadow_trans, &v86->m_v_inverted, &cascade_id->m_view_to_shadow[v64]);
        vostok::render::renderer_context::set_view2shadow(v86, &shadow_trans, v64);
        v87 = light_view_transform.c.z;
        v88 = &cascade_id->m_previous_adjastment[cascade_index];
        M_start = m_caster_model._M_impl._M_start;
        *(_QWORD *)&v88->x = *(_QWORD *)&light_view_transform.lines[3].x;
        v88->z = v87;
        v16 = M_start == 0;
        goto LABEL_61;
      }
    }
    v65 = 1;
    goto LABEL_40;
  }
}
