void __thiscall vostok::render::stage_atmosphere::execute(vostok::render::stage_atmosphere *this)
{
  vostok::render::renderer_context *m_context; // eax
  vostok::render::lights_db *m_object; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  vostok::render::light *v5; // ecx
  vostok::render::light *v6; // ebx
  _DWORD *v7; // eax
  void *v8; // edi
  vostok::render::grass_render_model *v9; // esi
  _QWORD *p_x; // esi
  float z; // eax
  bool v12; // zf
  unsigned int v13; // xmm0_4
  unsigned int v14; // xmm1_4
  const vostok::math::float4x4 *v15; // xmm0_4
  const char *v16; // esi
  vostok::render::shader_constant_host *v17; // eax
  int v18; // ecx
  unsigned __int16 v19; // cx
  vostok::collision::space_partitioning_tree *v20; // xmm1_4
  vostok::render::light_data *v21; // xmm2_4
  vostok::render::light_data *v22; // xmm3_4
  vostok::render::shader_constant_host *m_c_atmosphere_parameters; // eax
  vostok::render::enum_render_target_index v24; // ecx
  vostok::render::renderer_context *v25; // edx
  vostok::render::stage_atmosphere *v26; // ecx
  vostok::render::render_target *v27; // eax
  vostok::render::render_target *v28; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  int v31; // esi
  const vostok::math::float3 *intensity_low; // xmm0_4
  const char *v33; // esi
  vostok::render::shader_constant_host *m_to_sun_direction_parameter; // eax
  int v35; // ecx
  unsigned __int16 m_buffer_index; // cx
  float x; // xmm0_4
  vostok::render::shader_constant_host *v38; // eax
  int v39; // ecx
  unsigned __int16 v40; // cx
  vostok::render::renderer_context *v41; // eax
  const vostok::math::float4x4 *v42; // eax
  vostok::render::renderer_context *v43; // ecx
  vostok::render::lights_db *v44; // edi
  const char *v45; // esi
  const char *v46; // esi
  vostok::render::shader_constant_host *m_sky_clouds_parameters0; // eax
  int v48; // ecx
  vostok::collision::space_partitioning_tree *m_lights_tree; // xmm0_4
  unsigned __int16 v50; // cx
  vostok::render::shader_constant_buffer *v51; // edx
  unsigned __int16 m_class_id; // cx
  unsigned __int16 m_slot_index; // ax
  vostok::render::shader_constant_host *m_sky_clouds_parameters1; // eax
  int v55; // ecx
  vostok::render::light_data *M_start; // xmm1_4
  unsigned __int16 v57; // cx
  vostok::render::shader_constant_buffer *v58; // edx
  unsigned __int16 v59; // cx
  unsigned __int16 v60; // ax
  long double v61; // st7
  vostok::render::shader_constant_host *m_sky_clouds_parameters2; // eax
  int v63; // ecx
  unsigned __int16 v64; // cx
  vostok::render::shader_constant_buffer *v65; // edx
  unsigned __int16 v66; // cx
  unsigned __int16 v67; // ax
  float *v68; // eax
  float v69; // xmm0_4
  float v70; // eax
  float v71; // xmm3_4
  __int64 v72; // xmm0_8
  vostok::math::float3 *p_L_up; // ecx
  float v74; // xmm2_4
  float v75; // xmm1_4
  vostok::render::renderer_context *v76; // eax
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm2_4
  long double v80; // st7
  float y; // xmm2_4
  long double v82; // st7
  float v83; // xmm3_4
  float v84; // xmm0_4
  float v85; // xmm1_4
  float v86; // xmm2_4
  float v87; // ecx
  vostok::math::float4x4 *v88; // ecx
  const vostok::math::float3 *angles_xyz; // eax
  vostok::math::float4x4 *v90; // eax
  const vostok::math::float4x4 *v91; // eax
  vostok::render::lights_db *v92; // esi
  const char *v93; // edi
  vostok::render::shader_constant_host *m_sun_moon_parameters; // eax
  vostok::render::light_data *M_finish; // xmm0_4
  vostok::render::backend *v96; // esi
  int v97; // ecx
  unsigned __int16 v98; // cx
  const vostok::math::float3 *v99; // edx
  const vostok::math::float4x4 *v100; // eax
  vostok::render::renderer_context *v101; // esi
  const char *v102; // eax
  vostok::render::backend *v103; // ecx
  vostok::render::constants_handler<1> *v104; // esi
  vostok::render::shader_constant_host *v105; // eax
  int v106; // ecx
  unsigned __int16 v107; // cx
  const vostok::math::float4x4 *v108; // edx
  const vostok::math::float3 *v109; // eax
  const vostok::math::float3 *v110; // ecx
  vostok::collision::space_partitioning_tree *v111; // xmm1_4
  vostok::render::shader_constant_host *m_c_inscatter_parameters; // eax
  vostok::render::enum_render_target_index m_diff_range_start; // ecx
  vostok::render::stage_atmosphere *v114; // ecx
  vostok::render::constants_handler<1> *v115; // esi
  vostok::render::shader_constant_host *v116; // eax
  int v117; // ecx
  unsigned __int16 v118; // cx
  const vostok::math::float4x4 *v119; // edx
  const vostok::math::float3 *v120; // eax
  const vostok::math::float3 *v121; // ecx
  vostok::render::light *v122; // xmm1_4
  vostok::render::shader_constant_host *v123; // eax
  vostok::render::enum_render_target_index v124; // ecx
  vostok::render::stage_atmosphere *v125; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v126; // [esp-8h] [ebp-1ACh] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v127; // [esp-4h] [ebp-1A8h] BYREF
  int epsilon; // [esp+0h] [ebp-1A4h]
  char src_ptr[8]; // [esp+14h] [ebp-190h] BYREF
  unsigned __int64 v130; // [esp+1Ch] [ebp-188h]
  const vostok::math::float3 *eye_rays; // [esp+24h] [ebp-180h] BYREF
  vostok::math::float3 L_dir; // [esp+28h] [ebp-17Ch]
  bool recalc_rayleigh_scattering; // [esp+37h] [ebp-16Dh]
  vostok::render::lights_db *v134; // [esp+38h] [ebp-16Ch]
  vostok::math::float3 to_sun_direction; // [esp+3Ch] [ebp-168h]
  vostok::math::float3 L_up; // [esp+48h] [ebp-15Ch] BYREF
  vostok::math::float3 L_right; // [esp+54h] [ebp-150h] BYREF
  void *mem; // [esp+60h] [ebp-144h] BYREF
  vostok::math::float4x4 world_transform; // [esp+64h] [ebp-140h] BYREF
  vostok::math::float4x4 v140; // [esp+A4h] [ebp-100h] BYREF
  vostok::math::float4x4 result; // [esp+E4h] [ebp-C0h] BYREF
  char v142[64]; // [esp+124h] [ebp-80h] BYREF
  vostok::math::float4x4 v143; // [esp+164h] [ebp-40h] BYREF

  if ( !this->m_atmospheric_scattering_effect.m_object )
    return;
  if ( !this->is_enabled(this) )
  {
    this->execute_disabled(this);
    return;
  }
  m_context = this->m_context;
  m_object = (vostok::render::lights_db *)m_context->m_scene_view.m_object;
  v4 = (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_context->m_scene->m_lights.m_object;
  v134 = m_object;
  to_sun_direction.x = 0.0;
  *(_QWORD *)&to_sun_direction.elements[1] = (unsigned int)clear_value;
  v6 = vostok::render::lights_db::get_sun(
         m_object,
         v4,
         (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&mem)->m_object;
  v7 = mem;
  if ( mem )
  {
    --*(_DWORD *)mem;
    if ( !*v7 )
    {
      v8 = mem;
      v9 = vostok::render::g_allocator.m_object;
      if ( mem )
      {
        vostok::render::light::~light(v5, (int)mem);
        BYTE2(v9->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v9->m_reconstruction_info_actuality_tick), v8);
      }
    }
  }
  if ( this->m_type == atmosphere_on_sky )
  {
    recalc_rayleigh_scattering = HIDWORD(this->m_context->m_scene_view.m_object[5].m_current_satisfaction_update_tick) != this->m_context->m_targets->m_id;
    if ( !v6 )
      goto LABEL_14;
    p_x = (_QWORD *)&v6->direction.x;
    if ( !vostok::math::float3_pod::is_similar(&v6->direction, &v6->previous_direction, 0.001) )
    {
      z = v6->direction.z;
      *(_QWORD *)&v6->previous_direction.x = *p_x;
      v6->previous_direction.z = z;
      recalc_rayleigh_scattering = 1;
    }
    v12 = LOBYTE(v134[47].m_lights._M_impl._M_end_of_storage._M_data) == 0;
    *(float *)&v13 = -*(float *)p_x;
    *(float *)&v14 = -v6->direction.y;
    L_up.z = -v6->direction.z;
    *(_QWORD *)&L_up.x = __PAIR64__(v14, v13);
    *(_QWORD *)&to_sun_direction.x = __PAIR64__(v14, v13);
    to_sun_direction.z = L_up.z;
    if ( v12 )
    {
LABEL_14:
      if ( !recalc_rayleigh_scattering )
      {
LABEL_25:
        v27 = this->m_context->m_targets->m_family[47].target.m_object;
        v28 = 0;
        if ( v27 )
        {
          v28 = this->m_context->m_targets->m_family[47].target.m_object;
          ++v27->m_reference_count;
          m_rt = v27->m_rt;
        }
        else
        {
          m_rt = 0;
        }
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
             + 535) != m_rt )
        {
          *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
          *((_BYTE *)m_conflicted_key_name + 163) = 1;
        }
        if ( *((_DWORD *)m_conflicted_key_name + 536) )
        {
          *((_DWORD *)m_conflicted_key_name + 536) = 0;
          *((_BYTE *)m_conflicted_key_name + 164) = 1;
        }
        if ( *((_DWORD *)m_conflicted_key_name + 537) )
        {
          *((_DWORD *)m_conflicted_key_name + 537) = 0;
          *((_BYTE *)m_conflicted_key_name + 165) = 1;
        }
        if ( *((_DWORD *)m_conflicted_key_name + 538) )
        {
          *((_DWORD *)m_conflicted_key_name + 538) = 0;
          *((_BYTE *)m_conflicted_key_name + 166) = 1;
        }
        if ( v28 )
        {
          if ( !--v28->m_reference_count )
          {
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)v28,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              (const char *)v28);
            m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          }
        }
        v31 = *((_DWORD *)m_conflicted_key_name + 547);
        v12 = *((_DWORD *)m_conflicted_key_name + 539) == v31;
        *((_DWORD *)m_conflicted_key_name + 539) = v31;
        *((_BYTE *)m_conflicted_key_name + 167) |= !v12;
        if ( v6 )
          intensity_low = (const vostok::math::float3 *)LODWORD(v6->intensity);
        else
          intensity_low = (const vostok::math::float3 *)clear_value;
        v12 = LOBYTE(v134[40].m_sun.m_object) == 0;
        eye_rays = intensity_low;
        if ( v12 )
          eye_rays = 0;
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)1,
          &this->m_atmospheric_scattering_effect.m_object->__vftable);
        v33 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        m_to_sun_direction_parameter = this->m_to_sun_direction_parameter;
        v35 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
        *(_QWORD *)src_ptr = *(_QWORD *)&to_sun_direction.x;
        v130 = __PAIR64__((unsigned int)eye_rays, LODWORD(to_sun_direction.z));
        if ( m_to_sun_direction_parameter->m_update_markers[1] == v35 )
        {
          m_buffer_index = m_to_sun_direction_parameter->m_shader_slots[1].m_buffer_index;
          if ( m_buffer_index != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              m_to_sun_direction_parameter->m_shader_slots[1].m_slot_index,
              (unsigned __int8)m_to_sun_direction_parameter->m_shader_slots[1].m_class_id,
              *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                       + 371)
                                                                     + 16)
                                                         + 4 * m_buffer_index),
              src_ptr);
        }
        x = to_sun_direction.x;
        ++*((_DWORD *)v33 + 23);
        v38 = this->m_to_sun_direction_parameter;
        v39 = *((_DWORD *)v33 + 572);
        *(_QWORD *)src_ptr = __PAIR64__(LODWORD(to_sun_direction.y), LODWORD(x));
        v130 = __PAIR64__((unsigned int)eye_rays, LODWORD(to_sun_direction.z));
        if ( v38->m_update_markers[0] == v39 )
        {
          v40 = v38->m_shader_slots[0].m_buffer_index;
          if ( v40 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              v38->m_shader_slots[0].m_slot_index,
              (unsigned __int8)v38->m_shader_slots[0].m_class_id,
              *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v33 + 51) + 16) + 4 * v40),
              src_ptr);
        }
        ++*((_DWORD *)v33 + 23);
        v41 = this->m_context;
        qmemcpy((void *)&world_transform, &v41->m_p, sizeof(world_transform));
        world_transform.k.z = 1.0000001;
        world_transform.c.z = -1.0000001;
        vostok::render::renderer_context::push_set_p(0, (int)v41, (vostok::render::renderer_context *)&world_transform);
        v42 = vostok::math::float4x4::identity(&world_transform);
        vostok::render::renderer_context::set_w(this->m_context, v42);
        vostok::render::sky_dome_geometry::draw(&this->m_sky_dome_geometry);
        v44 = v134;
        if ( v134[39].m_lights._M_impl._M_end_of_storage._M_data
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          vostok::render::res_effect::apply(
            (vostok::render::res_effect *)(3 - (v134[42].m_lights._M_impl._M_end_of_storage._M_data != 0)),
            &this->m_atmospheric_scattering_effect.m_object->__vftable);
          epsilon = (int)v44[39].m_lights._M_impl._M_end_of_storage._M_data;
          v45 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_BYTE *)v45 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                    (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                          + 1488),
                                    (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                  + 1488,
                                    (vostok::render::res_texture *)&stru_9620D4.destroyer,
                                    (vostok::render::res_texture *)epsilon);
          v46 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          m_sky_clouds_parameters0 = this->m_sky_clouds_parameters0;
          v48 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 573);
          m_lights_tree = v44[40].m_lights_tree;
          *(_DWORD *)src_ptr = v44[41].m_lights._M_impl._M_start;
          *(_DWORD *)&src_ptr[4] = v44[41].m_lights._M_impl._M_finish;
          LODWORD(v130) = v44[41].m_lights._M_impl._M_end_of_storage._M_data;
          HIDWORD(v130) = m_lights_tree;
          if ( m_sky_clouds_parameters0->m_update_markers[1] == v48 )
          {
            v50 = m_sky_clouds_parameters0->m_shader_slots[1].m_buffer_index;
            if ( v50 != 0xFFFF )
            {
              v51 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                             + 371)
                                                                           + 16)
                                                               + 4 * v50);
              m_class_id = m_sky_clouds_parameters0->m_shader_slots[1].m_class_id;
              m_slot_index = m_sky_clouds_parameters0->m_shader_slots[1].m_slot_index;
              eye_rays = (const vostok::math::float3 *)(unsigned __int8)m_class_id;
              vostok::render::shader_constant_buffer::set_memory(
                m_slot_index,
                (unsigned __int8)m_class_id,
                v51,
                src_ptr);
            }
          }
          ++*((_DWORD *)v46 + 23);
          m_sky_clouds_parameters1 = this->m_sky_clouds_parameters1;
          v55 = *((_DWORD *)v46 + 573);
          M_start = v44[42].m_lights._M_impl._M_start;
          *(_DWORD *)src_ptr = v44[41].m_lights_tree;
          *(_DWORD *)&src_ptr[4] = M_start;
          v130 = 0;
          if ( m_sky_clouds_parameters1->m_update_markers[1] == v55 )
          {
            v57 = m_sky_clouds_parameters1->m_shader_slots[1].m_buffer_index;
            if ( v57 != 0xFFFF )
            {
              v58 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v46 + 371) + 16) + 4 * v57);
              v59 = m_sky_clouds_parameters1->m_shader_slots[1].m_class_id;
              v60 = m_sky_clouds_parameters1->m_shader_slots[1].m_slot_index;
              eye_rays = (const vostok::math::float3 *)(unsigned __int8)v59;
              vostok::render::shader_constant_buffer::set_memory(v60, (unsigned __int8)v59, v58, src_ptr);
            }
          }
          ++*((_DWORD *)v46 + 23);
          *(float *)&eye_rays = *(float *)&v44[42].m_lights._M_impl._M_finish * 0.0055555557 * 3.1415927;
          L_dir.x = sinf(*(float *)&eye_rays);
          v61 = cosf(*(float *)&eye_rays);
          m_sky_clouds_parameters2 = this->m_sky_clouds_parameters2;
          *(float *)src_ptr = v61;
          v63 = *((_DWORD *)v46 + 572);
          *(float *)&src_ptr[4] = L_dir.x;
          v130 = 0;
          if ( m_sky_clouds_parameters2->m_update_markers[0] == v63 )
          {
            v64 = m_sky_clouds_parameters2->m_shader_slots[0].m_buffer_index;
            if ( v64 != 0xFFFF )
            {
              v65 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v46 + 51) + 16) + 4 * v64);
              v66 = m_sky_clouds_parameters2->m_shader_slots[0].m_class_id;
              v67 = m_sky_clouds_parameters2->m_shader_slots[0].m_slot_index;
              LODWORD(L_dir.x) = (unsigned __int8)v66;
              vostok::render::shader_constant_buffer::set_memory(v67, (unsigned __int8)v66, v65, src_ptr);
            }
          }
          ++*((_DWORD *)v46 + 23);
          vostok::render::sphere_geometry::draw(&this->m_clouds_geometry);
        }
        if ( v44[39].m_sun.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
          && v6 )
        {
          eye_rays = 0;
          v68 = (float *)vostok::render::vertex_buffer::lock(
                           (vostok::render::vertex_buffer *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                           + 40),
                           4u,
                           0x18u,
                           (unsigned int *)&eye_rays);
          v69 = *(float *)&clear_value;
          *(_QWORD *)v68 = 0xBF800000BF800000uLL;
          *((float *)&v130 + 1) = v69;
          v68[5] = v69;
          LODWORD(v130) = 0;
          *((_QWORD *)v68 + 1) = v130;
          v68[4] = 0.0;
          v68 += 6;
          *(_DWORD *)src_ptr = -1082130432;
          *(float *)&src_ptr[4] = v69;
          *(_QWORD *)v68 = *(_QWORD *)src_ptr;
          *((float *)&v130 + 1) = v69;
          LODWORD(v130) = 0;
          *((_QWORD *)v68 + 1) = v130;
          v68[4] = 0.0;
          v68[5] = 0.0;
          v68 += 6;
          *(_QWORD *)src_ptr = LODWORD(v69) | 0xBF80000000000000uLL;
          *(_QWORD *)v68 = *(_QWORD *)src_ptr;
          v68[4] = v69;
          v68[5] = v69;
          *((float *)&v130 + 1) = v69;
          LODWORD(v130) = 0;
          *((_QWORD *)v68 + 1) = v130;
          v68 += 6;
          L_dir.x = v69;
          *(float *)src_ptr = v69;
          *(float *)&src_ptr[4] = v69;
          *((float *)&v130 + 1) = v69;
          *(_QWORD *)v68 = *(_QWORD *)src_ptr;
          L_dir.y = 0.0;
          LODWORD(v130) = 0;
          *((_QWORD *)v68 + 1) = v130;
          v68[4] = v69;
          v68[5] = 0.0;
          vostok::render::vertex_buffer::unlock((vostok::render::vertex_buffer *)LODWORD(v69));
          vostok::render::res_geometry::apply(this->m_screen_vertex_geometry.m_object);
          vostok::render::res_effect::apply(
            (vostok::render::res_effect *)4,
            &this->m_atmospheric_scattering_effect.m_object->__vftable);
          v70 = v6->direction.z;
          *(_QWORD *)&L_dir.x = *(_QWORD *)&v6->direction.x;
          v71 = (float)((float)(v6->right.y * v6->right.y) + (float)(v6->right.z * v6->right.z))
              + (float)(v6->right.x * v6->right.x);
          L_dir.z = v70;
          if ( v71 <= 0.0000099999997 )
          {
            v74 = *(float *)&clear_value;
            v75 = 0.0;
            if ( COERCE_FLOAT(
                   COERCE_UNSIGNED_INT((float)((float)(L_dir.x * 0.0) + L_dir.y) + (float)(L_dir.z * 0.0))
                 & _mask__AbsFloat_) > 0.99000001 )
            {
              v75 = *(float *)&clear_value;
              v74 = 0.0;
            }
            *(float *)&v130 = (float)(L_dir.y * 0.0) - (float)(v74 * L_dir.x);
            *(float *)src_ptr = (float)(v74 * L_dir.z) - (float)(v75 * L_dir.y);
            *(float *)&src_ptr[4] = (float)(v75 * L_dir.x) - (float)(L_dir.z * 0.0);
            L_right.z = *(float *)&v130;
            *(_QWORD *)&L_right.x = *(_QWORD *)src_ptr;
            vostok::math::float3_pod::normalize(&L_right);
            *(float *)src_ptr = (float)(L_right.z * L_dir.y) - (float)(L_right.y * L_dir.z);
            *(float *)&v130 = (float)(L_right.y * L_dir.x) - (float)(L_dir.y * L_right.x);
            *(float *)&src_ptr[4] = (float)(L_dir.z * L_right.x) - (float)(L_right.z * L_dir.x);
            *(_QWORD *)&L_up.x = *(_QWORD *)src_ptr;
            L_up.z = *(float *)&v130;
            p_L_up = &L_up;
          }
          else
          {
            v72 = *(_QWORD *)&v6->right.x;
            L_right.z = v6->right.z;
            *(_QWORD *)&L_right.x = v72;
            vostok::math::float3_pod::normalize(&L_right);
            *(float *)src_ptr = (float)(L_right.z * L_dir.y) - (float)(L_right.y * L_dir.z);
            *(float *)&v130 = (float)(L_right.y * L_dir.x) - (float)(L_dir.y * L_right.x);
            *(float *)&src_ptr[4] = (float)(L_dir.z * L_right.x) - (float)(L_right.z * L_dir.x);
            *(_QWORD *)&L_up.x = *(_QWORD *)src_ptr;
            L_up.z = *(float *)&v130;
            vostok::math::float3_pod::normalize(&L_up);
            *(float *)src_ptr = (float)(L_up.y * L_dir.z) - (float)(L_up.z * L_dir.y);
            *(float *)&v130 = (float)(L_dir.y * L_up.x) - (float)(L_up.y * L_dir.x);
            *(float *)&src_ptr[4] = (float)(L_up.z * L_dir.x) - (float)(L_dir.z * L_up.x);
            *(_QWORD *)&L_right.x = *(_QWORD *)src_ptr;
            L_right.z = *(float *)&v130;
            p_L_up = &L_right;
          }
          vostok::math::float3_pod::normalize(p_L_up);
          v76 = this->m_context;
          v77 = v76->m_view_pos.x - v6->position.x;
          v78 = v76->m_view_pos.y - v6->position.y;
          v79 = v76->m_view_pos.z - v6->position.z;
          v80 = sqrtf((float)((float)(v77 * v77) + (float)(v78 * v78)) + (float)(v79 * v79));
          y = v6->direction.y;
          v82 = v80 * 0.0000000026010034 * 6948400.0 * *(float *)&v134[40].m_lights._M_impl._M_end_of_storage._M_data;
          v83 = v6->direction.z;
          *(_QWORD *)&world_transform.i.x = *(_QWORD *)&L_right.x;
          L_dir.x = v82;
          *(_QWORD *)&world_transform.lines[1].x = *(_QWORD *)&L_up.x;
          *(_QWORD *)&world_transform.lines[2].x = *(_QWORD *)&v6->direction.x;
          *(_QWORD *)&world_transform.lines[3].x = *(_QWORD *)&v6->position.x;
          v84 = (float)(v6->direction.x * 0.0) + v6->position.x;
          v85 = v6->position.y + (float)(y * 0.0);
          v86 = v6->position.z;
          *(_QWORD *)&world_transform.lines[1].elements[2] = LODWORD(L_up.z);
          *(_QWORD *)&world_transform.lines[2].elements[2] = LODWORD(v83);
          *(_QWORD *)&world_transform.lines[0].elements[2] = LODWORD(L_right.z);
          v87 = v6->position.z;
          *(float *)src_ptr = v84;
          *(float *)&src_ptr[4] = v85;
          *(float *)&v130 = v86 + (float)(v83 * 0.0);
          *(_QWORD *)&world_transform.lines[3].elements[2] = __PAIR64__((unsigned int)clear_value, LODWORD(v87));
          L_up.x = L_dir.x;
          L_up.y = L_dir.x;
          L_up.z = L_dir.x;
          epsilon = (int)vostok::math::create_translation(&result, (const vostok::math::float3 *)src_ptr);
          angles_xyz = vostok::math::float4x4::get_angles_xyz(v88, (vostok::math::float3 *)v88);
          v127.m_object = (vostok::render::render_target *)vostok::math::create_rotation(&v143, angles_xyz);
          v90 = vostok::math::create_scale(&L_up, (int)v142);
          v91 = vostok::math::operator*(&v140, v90, (const vostok::math::float4x4 *)v127.m_object);
          vostok::math::operator*(&world_transform, v91, (const vostok::math::float4x4 *)epsilon);
          vostok::render::renderer_context::set_w(this->m_context, &world_transform);
          v92 = v134;
          epsilon = (int)v134[39].m_sun.m_object;
          v93 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_BYTE *)v93 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                    (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                          + 1488),
                                    (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                  + 1488,
                                    (vostok::render::res_texture *)&stru_9621B0,
                                    (vostok::render::res_texture *)epsilon);
          m_sun_moon_parameters = this->m_sun_moon_parameters;
          *(_DWORD *)src_ptr = v92[39].m_lights_tree;
          *(_DWORD *)&src_ptr[4] = v92[40].m_lights._M_impl._M_start;
          M_finish = v92[40].m_lights._M_impl._M_finish;
          v96 = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          v97 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 573);
          v130 = (unsigned int)M_finish;
          if ( m_sun_moon_parameters->m_update_markers[1] == v97 )
          {
            v98 = m_sun_moon_parameters->m_shader_slots[1].m_buffer_index;
            if ( v98 != 0xFFFF )
              vostok::render::shader_constant_buffer::set_memory(
                m_sun_moon_parameters->m_shader_slots[1].m_slot_index,
                (unsigned __int8)m_sun_moon_parameters->m_shader_slots[1].m_class_id,
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                         + 371)
                                                                       + 16)
                                                           + 4 * v98),
                src_ptr);
          }
          v99 = eye_rays;
          ++v96->num_setted_shader_constants;
          vostok::render::backend::render_indexed(v96, 6u, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 0, (unsigned int)v99);
          v100 = vostok::math::float4x4::identity(&v140);
          vostok::render::renderer_context::set_w(this->m_context, v100);
        }
        v101 = this->m_context;
        epsilon = (int)&v101->m_p_stack.m_end[-1];
        vostok::render::renderer_context::set_p(v43, (const vostok::math::float4x4 *)v101);
        v102 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        --v101->m_p_stack.m_end;
        vostok::render::backend::reset_render_targets(v103, (int)v102);
        goto LABEL_75;
      }
    }
    else
    {
      LOBYTE(v134[47].m_lights._M_impl._M_end_of_storage._M_data) = 0;
    }
    LOBYTE(this->m_context->m_scene_view.m_object[3].m_fat_it.m_link_target) = 0;
    vostok::render::res_effect::apply(0, &this->m_atmospheric_scattering_effect.m_object->__vftable);
    if ( v6 )
      v15 = (const vostok::math::float4x4 *)LODWORD(v6->intensity);
    else
      v15 = clear_value;
    v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v17 = this->m_to_sun_direction_parameter;
    v18 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
    *(_QWORD *)src_ptr = *(_QWORD *)&to_sun_direction.x;
    v130 = __PAIR64__((unsigned int)v15, LODWORD(to_sun_direction.z));
    if ( v17->m_update_markers[1] == v18 )
    {
      v19 = v17->m_shader_slots[1].m_buffer_index;
      if ( v19 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          v17->m_shader_slots[1].m_slot_index,
          (unsigned __int8)v17->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                   + 371)
                                                                 + 16)
                                                     + 4 * v19),
          src_ptr);
    }
    ++*((_DWORD *)v16 + 23);
    v20 = v134[46].m_lights_tree;
    v21 = v134[47].m_lights._M_impl._M_start;
    v22 = v134[47].m_lights._M_impl._M_finish;
    m_c_atmosphere_parameters = this->m_c_atmosphere_parameters;
    v24 = *((_DWORD *)v16 + 573);
    *(_DWORD *)src_ptr = v134[46].m_sun.m_object;
    *(_DWORD *)&src_ptr[4] = v20;
    v130 = __PAIR64__((unsigned int)v22, (unsigned int)v21);
    if ( m_c_atmosphere_parameters->m_update_markers[1] == v24 )
    {
      v24 = m_c_atmosphere_parameters->m_shader_slots[1].m_buffer_index;
      if ( (unsigned __int16)v24 != 0xFFFF )
        vostok::render::shader_constant_buffer::set_memory(
          m_c_atmosphere_parameters->m_shader_slots[1].m_slot_index,
          (unsigned __int8)m_c_atmosphere_parameters->m_shader_slots[1].m_class_id,
          *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v16 + 371) + 16)
                                                     + 4 * (unsigned __int16)v24),
          src_ptr);
    }
    ++*((_DWORD *)v16 + 23);
    v25 = this->m_context;
    epsilon = 0;
    v127.m_object = (vostok::render::render_target *)v24;
    vostok::render::renderer_context::get_rt((vostok::render::renderer_context *)0x41, &v127, v25, v24);
    vostok::render::renderer_context::get_rt(
      (vostok::render::renderer_context *)0x42,
      &v126,
      this->m_context,
      (vostok::render::enum_render_target_index)v126.m_object);
    vostok::render::stage_atmosphere::fill_surfaces(v26, this, v126, v127, epsilon);
    HIDWORD(this->m_context->m_scene_view.m_object[5].m_current_satisfaction_update_tick) = this->m_context->m_targets->m_id;
    goto LABEL_25;
  }
LABEL_75:
  if ( this->m_type == atmosphere_on_geometry )
  {
    eye_rays = this->m_context->m_eye_rays;
    if ( LOBYTE(v134[50].m_lights._M_impl._M_start) )
    {
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)6,
        &this->m_atmospheric_scattering_effect.m_object->__vftable);
      v104 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v105 = this->m_to_sun_direction_parameter;
      v106 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
      *(_QWORD *)src_ptr = *(_QWORD *)&to_sun_direction.x;
      v130 = __PAIR64__((unsigned int)clear_value, LODWORD(to_sun_direction.z));
      if ( v105->m_update_markers[1] == v106 )
      {
        v107 = v105->m_shader_slots[1].m_buffer_index;
        if ( v107 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v105->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v105->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v107),
            src_ptr);
      }
      ++v104[7].m_current.m_object;
      vostok::math::try_invert4x4(&this->m_context->m_vp, &world_transform);
      v109 = (const vostok::math::float3 *)vostok::math::transpose(&v140, v108);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_c_inverted_view_projection_matrix,
        v104 + 123,
        v109);
      v110 = eye_rays;
      ++v104[7].m_current.m_object;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_c_eye_ray_corner,
        v104 + 123,
        v110);
      ++v104[7].m_current.m_object;
      v111 = v134[49].m_lights_tree;
      m_c_inscatter_parameters = this->m_c_inscatter_parameters;
      m_diff_range_start = v104[191].m_diff_range_start;
      *(_DWORD *)src_ptr = v134[49].m_sun.m_object;
      *(_DWORD *)&src_ptr[4] = v111;
      v130 = 0;
      if ( m_c_inscatter_parameters->m_update_markers[1] == m_diff_range_start )
      {
        m_diff_range_start = m_c_inscatter_parameters->m_shader_slots[1].m_buffer_index;
        if ( (unsigned __int16)m_diff_range_start != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            m_c_inscatter_parameters->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_c_inscatter_parameters->m_shader_slots[1].m_class_id,
            v104[123].m_current.m_object->m_const_buffers._M_impl._M_start[(unsigned __int16)m_diff_range_start].m_object,
            src_ptr);
      }
      ++v104[7].m_current.m_object;
      epsilon = 1;
      v127.m_object = 0;
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)0x2F,
        &v126,
        this->m_context,
        m_diff_range_start);
      vostok::render::stage_atmosphere::fill_surfaces(v114, this, v126, v127, epsilon);
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)7,
        &this->m_atmospheric_scattering_effect.m_object->__vftable);
      v115 = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v116 = this->m_to_sun_direction_parameter;
      v117 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
      *(_QWORD *)src_ptr = *(_QWORD *)&to_sun_direction.x;
      v130 = __PAIR64__((unsigned int)clear_value, LODWORD(to_sun_direction.z));
      if ( v116->m_update_markers[1] == v117 )
      {
        v118 = v116->m_shader_slots[1].m_buffer_index;
        if ( v118 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v116->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v116->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v118),
            src_ptr);
      }
      ++v115[7].m_current.m_object;
      vostok::math::try_invert4x4(&this->m_context->m_vp, &world_transform);
      v120 = (const vostok::math::float3 *)vostok::math::transpose(&v140, v119);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_c_inverted_view_projection_matrix,
        v115 + 123,
        v120);
      v121 = eye_rays;
      ++v115[7].m_current.m_object;
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_c_eye_ray_corner,
        v115 + 123,
        v121);
      ++v115[7].m_current.m_object;
      v122 = v134[49].m_sun.m_object;
      v123 = this->m_c_inscatter_parameters;
      v124 = v115[191].m_diff_range_start;
      *(_DWORD *)&src_ptr[4] = v134[49].m_lights_tree;
      *(_DWORD *)src_ptr = v122;
      v130 = 0;
      if ( v123->m_update_markers[1] == v124 )
      {
        v124 = v123->m_shader_slots[1].m_buffer_index;
        if ( (unsigned __int16)v124 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v123->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v123->m_shader_slots[1].m_class_id,
            v115[123].m_current.m_object->m_const_buffers._M_impl._M_start[(unsigned __int16)v124].m_object,
            src_ptr);
      }
      ++v115[7].m_current.m_object;
      epsilon = 1;
      v127.m_object = 0;
      vostok::render::renderer_context::get_rt((vostok::render::renderer_context *)0x2F, &v126, this->m_context, v124);
      vostok::render::stage_atmosphere::fill_surfaces(v125, this, v126, v127, epsilon);
    }
  }
  vostok::render::backend::reset_render_targets(
    (vostok::render::backend *)v5,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
}
