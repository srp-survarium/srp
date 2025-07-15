void __thiscall vostok::render::culling::portal_sector_system::calculate_portal_rects_in_screen_space(
        vostok::render::culling::portal_sector_system *this,
        vostok::render::culling::portal_sector_system *mat_vp,
        float min_z,
        vostok::buffer_vector<vostok::render::culling::aab_rect> *rects,
        vostok::buffer_vector<float> *distances)
{
  float v5; // eax
  const vostok::render::culling::portal *v6; // edx
  float *p_z; // esi
  vostok::render::culling::aab_rect *m_end; // eax
  float *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  vostok::render::culling::portal *m_begin; // edi
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  unsigned int v19; // edx
  unsigned int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm7_4
  float v32; // xmm4_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm4_4
  float v37; // xmm2_4
  vostok::render::culling::aab_rect *v38; // eax
  float v39; // xmm0_4
  float v40; // xmm5_4
  float v41; // xmm1_4
  float v42; // xmm7_4
  vostok::render::culling::aab_rect *v43; // edx
  const vostok::math::float4x4 *v44; // xmm0_4
  bool v45; // cc
  bool v46; // dl
  float v47; // [esp+14h] [ebp-98h]
  float v48; // [esp+18h] [ebp-94h]
  float v49; // [esp+1Ch] [ebp-90h]
  float v50; // [esp+20h] [ebp-8Ch]
  const vostok::render::culling::portal *it; // [esp+24h] [ebp-88h]
  const vostok::render::culling::portal *portals_end; // [esp+28h] [ebp-84h]
  float cs_f4; // [esp+2Ch] [ebp-80h]
  float cs_f4_4; // [esp+30h] [ebp-7Ch]
  float cs_f4_8; // [esp+34h] [ebp-78h]
  float cs_f4_16; // [esp+3Ch] [ebp-70h]
  float cs_f4_20; // [esp+40h] [ebp-6Ch]
  float cs_f4_24; // [esp+44h] [ebp-68h]
  float cs_f4_28; // [esp+48h] [ebp-64h]
  float cs_f4_32; // [esp+4Ch] [ebp-60h]
  float cs_f4_36; // [esp+50h] [ebp-5Ch]
  float cs_f4_40; // [esp+54h] [ebp-58h]
  float cs_f4_44; // [esp+58h] [ebp-54h]
  float cs_f4_48; // [esp+5Ch] [ebp-50h]
  float portal_rect; // [esp+6Ch] [ebp-40h]
  float hs_f3_4; // [esp+80h] [ebp-2Ch]
  float hs_f3_16; // [esp+8Ch] [ebp-20h]
  float hs_f3_28; // [esp+98h] [ebp-14h]
  float hs_f3_40; // [esp+A4h] [ebp-8h]

  rects->m_end = rects->m_begin;
  distances->m_end = distances->m_begin;
  v5 = *(float *)&mat_vp->m_structure.m_object;
  v6 = *(const vostok::render::culling::portal **)(LODWORD(v5) + 272);
  portals_end = *(const vostok::render::culling::portal **)(LODWORD(v5) + 276);
  it = v6;
  if ( v6 != portals_end )
  {
    p_z = &v6->m_points[0].z;
    do
    {
      if ( !*((_BYTE *)p_z + 40) )
      {
        m_end = rects->m_end;
        if ( m_end )
        {
          m_end->min.x = 0.0;
          m_end->min.y = 0.0;
          m_end->max.x = 0.0;
          m_end->max.y = 0.0;
        }
        rects->m_end = m_end + 1;
        v9 = distances->m_end;
        if ( v9 )
          *v9 = float_max_11;
        goto LABEL_70;
      }
      v10 = *(p_z - 1);
      v11 = *(p_z - 2);
      v12 = *(float *)&this->m_reconstruction_info_actuality_tick;
      v13 = *(float *)&this->m_uid;
      m_begin = mat_vp->m_structure.m_object->m_portals.m_begin;
      v15 = *(float *)&this->m_children_resources.m_size;
      v16 = *((float *)&this->m_reconstruction_info_actuality_tick + 1);
      cs_f4 = (float)((float)((float)(*(float *)&this->__vftable * v11) + (float)(v10 * v12)) + (float)(v13 * *p_z))
            + *(float *)&this->m_children_resources.gapC;
      cs_f4_4 = (float)((float)((float)(*(float *)&this->type * v11) + (float)(v10 * v16)) + (float)(v15 * *p_z))
              + *(float *)&this->m_children_resources.m_first;
      v49 = *(float *)&this->m_children_resources.m_lock;
      v50 = *(float *)&this->m_reconstruction_size;
      cs_f4_8 = (float)((float)((float)(*(float *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                      * v11)
                              + (float)(v10 * v50))
                      + (float)(v49 * *p_z))
              + *(float *)&this->m_children_resources.m_last;
      v48 = *((float *)&this->m_reconstruction_size + 1);
      v47 = *(float *)&this->m_children_resources.m_thread_id;
      v17 = (float)((float)((float)(*((float *)&this->vostok::resources::resource_flags + 3) * v11) + (float)(v10 * v48))
                  + (float)(v47 * *p_z))
          + *(float *)&this->m_parent_resources.m_size;
      v18 = p_z[1];
      v19 = (int)((unsigned __int64)(1808407283LL * ((char *)v6 - (char *)m_begin)) >> 32) >> 5;
      v20 = v19 + (v19 >> 31);
      cs_f4_16 = (float)((float)((float)(v18 * *(float *)&this->__vftable) + (float)(v13 * p_z[3]))
                       + (float)(v12 * p_z[2]))
               + *(float *)&this->m_children_resources.gapC;
      cs_f4_20 = (float)((float)((float)(v18 * *(float *)&this->type) + (float)(v15 * p_z[3])) + (float)(v16 * p_z[2]))
               + *(float *)&this->m_children_resources.m_first;
      cs_f4_24 = (float)((float)((float)(v18
                                       * *(float *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags)
                               + (float)(v49 * p_z[3]))
                       + (float)(v50 * p_z[2]))
               + *(float *)&this->m_children_resources.m_last;
      v21 = p_z[4];
      cs_f4_28 = (float)((float)((float)(v18 * *((float *)&this->vostok::resources::resource_flags + 3))
                               + (float)(v47 * p_z[3]))
                       + (float)(v48 * p_z[2]))
               + *(float *)&this->m_parent_resources.m_size;
      cs_f4_32 = (float)((float)((float)(v21 * *(float *)&this->__vftable) + (float)(v13 * p_z[6]))
                       + (float)(v12 * p_z[5]))
               + *(float *)&this->m_children_resources.gapC;
      cs_f4_36 = (float)((float)((float)(v21 * *(float *)&this->type) + (float)(v15 * p_z[6])) + (float)(v16 * p_z[5]))
               + *(float *)&this->m_children_resources.m_first;
      cs_f4_40 = (float)((float)((float)(v21
                                       * *(float *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags)
                               + (float)(v49 * p_z[6]))
                       + (float)(v50 * p_z[5]))
               + *(float *)&this->m_children_resources.m_last;
      v22 = p_z[7];
      cs_f4_44 = (float)((float)((float)(v21 * *((float *)&this->vostok::resources::resource_flags + 3))
                               + (float)(v47 * p_z[6]))
                       + (float)(v48 * p_z[5]))
               + *(float *)&this->m_parent_resources.m_size;
      v23 = p_z[9];
      v24 = p_z[8];
      cs_f4_48 = (float)((float)((float)(v22 * *(float *)&this->__vftable) + (float)(v13 * v23)) + (float)(v12 * v24))
               + *(float *)&this->m_children_resources.gapC;
      v25 = (float)((float)((float)(v22 * *(float *)&this->type) + (float)(v15 * v23)) + (float)(v16 * v24))
          + *(float *)&this->m_children_resources.m_first;
      v26 = (float)((float)((float)(v22
                                  * *(float *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags)
                          + (float)(v49 * v23))
                  + (float)(v50 * v24))
          + *(float *)&this->m_children_resources.m_last;
      v27 = (float)((float)((float)(v22 * *((float *)&this->vostok::resources::resource_flags + 3)) + (float)(v47 * v23))
                  + (float)(v48 * v24))
          + *(float *)&this->m_parent_resources.m_size;
      v28 = epsilon_3_11;
      if ( v17 < 0.001 )
        v17 = epsilon_3_11;
      v29 = *(float *)&clear_value / v17;
      v30 = cs_f4_28;
      v31 = v29 * cs_f4;
      hs_f3_4 = v29 * cs_f4_4;
      if ( cs_f4_28 < 0.001 )
        v30 = epsilon_3_11;
      v32 = cs_f4_44;
      v33 = *(float *)&clear_value / v30;
      v34 = (float)(*(float *)&clear_value / v30) * cs_f4_16;
      hs_f3_16 = v33 * cs_f4_20;
      if ( cs_f4_44 < 0.001 )
        v32 = epsilon_3_11;
      v35 = *(float *)&clear_value / v32;
      v36 = (float)(*(float *)&clear_value / v32) * cs_f4_32;
      hs_f3_28 = v35 * cs_f4_36;
      if ( v27 >= 0.001 )
        v28 = v27;
      v37 = (float)(*(float *)&clear_value / v28) * cs_f4_48;
      hs_f3_40 = (float)(*(float *)&clear_value / v28) * v25;
      if ( min_z <= cs_f4_8 || min_z <= cs_f4_24 || min_z <= cs_f4_40 || min_z <= v26 )
      {
        portal_rect = v31;
        if ( v34 <= v31 )
          portal_rect = v34;
        v40 = hs_f3_4;
        if ( hs_f3_16 <= hs_f3_4 )
          v41 = hs_f3_16;
        else
          v41 = hs_f3_4;
        if ( v31 > v34 )
          v34 = v31;
        if ( hs_f3_4 <= hs_f3_16 )
          v40 = hs_f3_16;
        v42 = portal_rect;
        if ( v36 <= portal_rect )
          v42 = v36;
        if ( hs_f3_28 <= v41 )
          v41 = hs_f3_28;
        if ( v34 <= v36 )
          v34 = v36;
        if ( v40 <= hs_f3_28 )
          v40 = hs_f3_28;
        if ( v37 <= v42 )
          v42 = (float)(*(float *)&clear_value / v28) * cs_f4_48;
        if ( hs_f3_40 <= v41 )
          v41 = hs_f3_40;
        if ( v34 <= v37 )
          v34 = (float)(*(float *)&clear_value / v28) * cs_f4_48;
        if ( v40 <= hs_f3_40 )
          v40 = hs_f3_40;
        v43 = rects->m_end;
        if ( v43 )
        {
          v43->min.x = v42;
          v43->min.y = v41;
          v43->max.x = v34;
          v43->max.y = v40;
        }
        v44 = clear_value;
        v45 = *(float *)&clear_value <= v42;
        rects->m_end = v43 + 1;
        v46 = !v45 && v34 > -1.0 && *(float *)&v44 > v41 && v40 > -1.0;
        mat_vp->m_structure.m_object->m_portals.m_begin[v20].m_visible = v46;
        if ( v46 )
        {
          if ( v26 > cs_f4_40 )
            v26 = cs_f4_40;
          v39 = cs_f4_8;
          if ( cs_f4_24 <= cs_f4_8 )
            v39 = cs_f4_24;
          if ( v26 <= v39 )
            v39 = v26;
          if ( v39 < 0.0 )
            v39 = 0.0;
        }
        else
        {
          v39 = float_max_11;
        }
        v9 = distances->m_end;
        if ( !v9 )
          goto LABEL_69;
      }
      else
      {
        m_begin[v20].m_visible = 0;
        v38 = rects->m_end;
        if ( v38 )
        {
          v38->min.x = 0.0;
          v38->min.y = 0.0;
          v38->max.x = 0.0;
          v38->max.y = 0.0;
        }
        rects->m_end = v38 + 1;
        v9 = distances->m_end;
        if ( !v9 )
          goto LABEL_69;
        v39 = float_max_11;
      }
      *v9 = v39;
LABEL_69:
      v6 = it;
LABEL_70:
      ++v6;
      p_z += 19;
      distances->m_end = v9 + 1;
      it = v6;
    }
    while ( v6 != portals_end );
  }
}
