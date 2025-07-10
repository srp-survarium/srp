void __thiscall vostok::render::grass_world::populate(
        vostok::render::grass_world *this,
        vostok::render::grass_world *patch_size_ground)
{
  float v2; // edi
  vostok::render::grass_patch *M_finish; // ecx
  vostok::render::grass_instance *v4; // eax
  __int64 v5; // xmm1_8
  int v6; // ebx
  int v7; // ecx
  unsigned int v8; // esi
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // edi
  int v12; // edx
  signed int v13; // ecx
  int v14; // edi
  int v15; // esi
  vostok::render::grass_patch *M_start; // eax
  signed int v17; // esi
  vostok::render::grass_patch *v18; // edi
  vostok::render::grass_patch *v19; // edi
  vostok::render::grass_patch *v20; // eax
  char *v21; // esi
  unsigned int v22; // eax
  int *v23; // ecx
  unsigned int v24; // ecx
  int *v25; // eax
  unsigned int v26; // ecx
  vostok::render::grass_render_model *m_object; // edx
  bool v28; // al
  unsigned __int8 *v29; // edi
  unsigned __int8 *v30; // eax
  unsigned int v31; // esi
  int v32; // eax
  _DWORD *v33; // eax
  void **v34; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  int v36; // edx
  char *v37; // esi
  unsigned int v38; // eax
  char v39; // dl
  int *v40; // ecx
  unsigned int v41; // ecx
  int *v42; // eax
  int v43; // ecx
  vostok::render::grass_render_model *v44; // eax
  unsigned int v45; // ecx
  unsigned __int8 *v46; // ebx
  unsigned int v47; // eax
  char v48; // dl
  int *v49; // ecx
  unsigned int v50; // ecx
  int *v51; // eax
  int v52; // ecx
  unsigned __int8 *v53; // eax
  unsigned int v54; // esi
  int v55; // eax
  _DWORD *v56; // eax
  vostok::render::grass_render_model *v57; // ecx
  void **v58; // eax
  int v59; // edx
  vostok::render::grass_patch **v60; // esi
  vostok::render::grass_patch **i; // ebx
  vostok::render::grass_patch *v62; // edi
  vostok::render::grass_patch *v63; // ecx
  float v64; // [esp+0h] [ebp-58h]
  vostok::render::grass_patch *new_patcha; // [esp+10h] [ebp-48h]
  vostok::render::grass_patch *new_patch; // [esp+10h] [ebp-48h]
  vostok::render::grass_instance *instance; // [esp+14h] [ebp-44h]
  vostok::render::grass_instance **it_instance; // [esp+1Ch] [ebp-3Ch]
  vostok::render::grass_template **it; // [esp+20h] [ebp-38h]
  _DWORD v70[2]; // [esp+24h] [ebp-34h] BYREF
  vostok::render::grass_template *templ; // [esp+2Ch] [ebp-2Ch]
  int v72; // [esp+30h] [ebp-28h] BYREF
  int v73; // [esp+34h] [ebp-24h] BYREF
  vostok::render::grass_instance **end_instance; // [esp+38h] [ebp-20h]
  vostok::render::grass_template **end; // [esp+3Ch] [ebp-1Ch]
  vostok::math::float3 origin; // [esp+40h] [ebp-18h]
  vostok::math::float3 origin_aligned; // [esp+4Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  v2 = *(float *)&patch_size_ground;
  vostok::render::grass_world::remove_patches(this, patch_size_ground);
  M_finish = (vostok::render::grass_patch *)patch_size_ground->m_templates._M_impl._M_finish;
  it = (vostok::render::grass_template **)patch_size_ground->m_templates._M_impl._M_start;
  end = (vostok::render::grass_template **)M_finish;
  if ( it != (vostok::render::grass_template **)M_finish )
  {
    while ( 1 )
    {
      M_finish = (vostok::render::grass_patch *)(*it)->m_instances._M_impl._M_start;
      templ = *it;
      it_instance = (vostok::render::grass_instance **)M_finish;
      end_instance = (vostok::render::grass_instance **)templ->m_instances._M_impl._M_finish;
      if ( M_finish != (vostok::render::grass_patch *)end_instance )
        break;
LABEL_75:
      if ( ++it == end )
      {
        v2 = *(float *)&patch_size_ground;
        goto LABEL_77;
      }
    }
    origin_aligned.y = 0.0;
    while ( 1 )
    {
      v4 = *it_instance;
      v5 = *(_QWORD *)&(*it_instance)->m_transform.lines[3].x;
      origin.z = (*it_instance)->m_transform.c.z;
      instance = v4;
      *(_QWORD *)&origin.x = v5;
      *(float *)&v70[1] = origin.z * 0.0625;
      v6 = ~(~(COERCE_INT(origin.z * 0.0625) - 1) & 0x80000000) & COERCE_UNSIGNED_INT(origin.z * 0.0625);
      v7 = 158 - (unsigned __int8)(v6 >> 23);
      v8 = (v6 | 0xFF800000) << 8 >> v7;
      new_patcha = (vostok::render::grass_patch *)(v7 - 96);
      v9 = -((v6 & (((1 << (v7 - 96)) - 1) >> 8)) != 0);
      v10 = 158
          - (unsigned __int8)((int)(~(~(COERCE_INT(*(float *)&v5 * 0.0625) - 1) & 0x80000000)
                                  & COERCE_UNSIGNED_INT(*(float *)&v5 * 0.0625)) >> 23);
      v11 = (~(~(COERCE_INT(*(float *)&v5 * 0.0625) - 1) & 0x80000000) & COERCE_UNSIGNED_INT(*(float *)&v5 * 0.0625)
           | 0xFF800000) << 8 >> v10;
      v10 -= 96;
      v12 = 1 << v10;
      v70[0] = v10;
      v13 = ~(~(COERCE_INT(*(float *)&v5 * 0.0625) - 1) & 0x80000000) & COERCE_UNSIGNED_INT(*(float *)&v5 * 0.0625);
      v6 >>= 31;
      v14 = (v13 >> 31) ^ ((v70[0] + 64) >> 31) & (v11 - ((v13 >> 31) & ((v13 & ((v12 - 1) >> 8)) == 0)));
      v15 = ((int)&new_patcha->m_movement_data[0][16] >> 31) & (v8 - (v6 & (v9 + 1)));
      M_start = (vostok::render::grass_patch *)patch_size_ground->m_patches._M_impl._M_start;
      M_finish = (vostok::render::grass_patch *)patch_size_ground->m_patches._M_impl._M_finish;
      v17 = v6 ^ v15;
      origin_aligned.x = (float)((float)v14 * 16.0) + 8.0;
      origin_aligned.z = (float)((float)v17 * 16.0) + 8.0;
      if ( M_start == M_finish )
      {
LABEL_10:
        v19 = (vostok::render::grass_patch *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               0x40B0u);
        if ( v19 )
        {
          vostok::render::grass_patch::grass_patch(
            v19,
            &origin_aligned,
            (unsigned int)&savedregs,
            v17,
            patch_size_ground->m_patches_tree,
            templ,
            v64);
          M_finish = v20;
          new_patch = v20;
        }
        else
        {
          new_patch = 0;
          M_finish = 0;
        }
        v21 = (char *)patch_size_ground->m_patches._M_impl._M_finish;
        if ( v21 == (char *)patch_size_ground->m_patches._M_impl._M_end_of_storage._M_data )
        {
          v22 = (v21 - (char *)patch_size_ground->m_patches._M_impl._M_start) >> 2;
          v72 = 1;
          v70[0] = v22;
          if ( v22 == 0x3FFFFFFF )
            goto LABEL_80;
          v23 = v70;
          if ( v22 <= 1 )
            v23 = &v72;
          v24 = v22 + *v23;
          v70[0] = v24;
          if ( v24 > 0x3FFFFFFF || v24 < v22 )
          {
            v24 = 0x3FFFFFFF;
            v70[0] = 0x3FFFFFFF;
          }
          v73 = v24;
          v72 = 1;
          v25 = &v72;
          if ( v24 )
            v25 = &v73;
          v26 = 4 * *v25;
          m_object = vostok::render::g_allocator.m_object;
          v28 = BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) && v26;
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v28;
          if ( v26 )
            v29 = (unsigned __int8 *)vostok_mspace_malloc(
                                       (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                       v26);
          else
            v29 = 0;
          v30 = (unsigned __int8 *)patch_size_ground->m_patches._M_impl._M_start;
          v31 = v21 - (char *)v30;
          if ( v31 )
          {
            memmove(v29, v30, v31);
            v33 = (_DWORD *)(v31 + v32);
          }
          else
          {
            v33 = v29;
          }
          *v33 = new_patch;
          v73 = (int)(v33 + 1);
          v34 = patch_size_ground->m_patches._M_impl._M_start;
          if ( v34 )
          {
            m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v34);
          }
          v36 = v73;
          patch_size_ground->m_patches._M_impl._M_end_of_storage._M_data = (void **)&v29[4 * v70[0]];
          M_finish = new_patch;
          patch_size_ground->m_patches._M_impl._M_start = (void **)v29;
          patch_size_ground->m_patches._M_impl._M_finish = (void **)v36;
        }
        else
        {
          *(_DWORD *)v21 = M_finish;
          ++patch_size_ground->m_patches._M_impl._M_finish;
        }
        v37 = (char *)M_finish->m_instances._M_impl._M_finish;
        if ( v37 == (char *)M_finish->m_instances._M_impl._M_end_of_storage._M_data )
        {
          v38 = (v37 - (char *)M_finish->m_instances._M_impl._M_start) >> 2;
          v39 = 1;
          v72 = 1;
          v73 = v38;
          if ( v38 == 0x3FFFFFFF )
            goto LABEL_80;
          v40 = &v73;
          if ( v38 <= 1 )
            v40 = &v72;
          v41 = v38 + *v40;
          v70[0] = v41;
          if ( v41 > 0x3FFFFFFF || v41 < v38 )
          {
            v41 = 0x3FFFFFFF;
            v70[0] = 0x3FFFFFFF;
          }
          v72 = v41;
          v73 = 1;
          v42 = &v73;
          if ( v41 )
            v42 = &v72;
          v43 = *v42;
          v44 = vostok::render::g_allocator.m_object;
          v45 = 4 * v43;
          if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v45 )
            v39 = 0;
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v39;
          v18 = new_patch;
          if ( !v45 )
          {
            v46 = 0;
LABEL_68:
            v53 = (unsigned __int8 *)v18->m_instances._M_impl._M_start;
            v54 = v37 - (char *)v53;
            if ( v54 )
            {
              memmove(v46, v53, v54);
              v56 = (_DWORD *)(v54 + v55);
            }
            else
            {
              v56 = v46;
            }
            *v56 = instance;
            v57 = vostok::render::g_allocator.m_object;
            v73 = (int)(v56 + 1);
            v58 = v18->m_instances._M_impl._M_start;
            if ( v58 )
            {
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free((void *)HIDWORD(v57->m_reconstruction_info_actuality_tick), v58);
            }
            v59 = v73;
            M_finish = (vostok::render::grass_patch *)&v46[4 * v70[0]];
            v18->m_instances._M_impl._M_end_of_storage._M_data = (void **)M_finish;
            v18->m_instances._M_impl._M_finish = (void **)v59;
            v18->m_instances._M_impl._M_start = (void **)v46;
            goto LABEL_74;
          }
LABEL_67:
          v46 = (unsigned __int8 *)vostok_mspace_malloc((void *)HIDWORD(v44->m_reconstruction_info_actuality_tick), v45);
          goto LABEL_68;
        }
        *(_DWORD *)v37 = instance;
        ++M_finish->m_instances._M_impl._M_finish;
      }
      else
      {
        while ( 1 )
        {
          v18 = (vostok::render::grass_patch *)LODWORD(M_start->m_movement_data[0][0]);
          if ( *(float *)&v5 >= *(float *)(LODWORD(M_start->m_movement_data[0][0]) + 16404)
            && origin.z >= v18->m_aabb.min.z
            && v18->m_aabb.max.x >= *(float *)&v5
            && v18->m_aabb.max.z >= origin.z )
          {
            break;
          }
          M_start = (vostok::render::grass_patch *)((char *)M_start + 4);
          if ( M_start == M_finish )
            goto LABEL_10;
        }
        v37 = (char *)v18->m_instances._M_impl._M_finish;
        if ( v37 == (char *)v18->m_instances._M_impl._M_end_of_storage._M_data )
        {
          v47 = (v37 - (char *)v18->m_instances._M_impl._M_start) >> 2;
          v48 = 1;
          v72 = 1;
          v73 = v47;
          if ( v47 == 0x3FFFFFFF )
LABEL_80:
            stlp_std::__stl_throw_length_error("vector");
          v49 = &v73;
          if ( v47 <= 1 )
            v49 = &v72;
          v50 = v47 + *v49;
          v70[0] = v50;
          if ( v50 > 0x3FFFFFFF || v50 < v47 )
          {
            v50 = 0x3FFFFFFF;
            v70[0] = 0x3FFFFFFF;
          }
          v72 = v50;
          v73 = 1;
          v51 = &v73;
          if ( v50 )
            v51 = &v72;
          v52 = *v51;
          v44 = vostok::render::g_allocator.m_object;
          v45 = 4 * v52;
          if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v45 )
            v48 = 0;
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v48;
          if ( !v45 )
          {
            v46 = 0;
            goto LABEL_68;
          }
          goto LABEL_67;
        }
        *(_DWORD *)v37 = instance;
        ++v18->m_instances._M_impl._M_finish;
      }
LABEL_74:
      if ( ++it_instance == end_instance )
        goto LABEL_75;
    }
  }
LABEL_77:
  v60 = *(vostok::render::grass_patch ***)(LODWORD(v2) + 288);
  for ( i = *(vostok::render::grass_patch ***)(LODWORD(v2) + 292); v60 != i; ++v60 )
  {
    v62 = *v60;
    vostok::render::grass_patch::init_collision(M_finish, *v60);
    vostok::render::grass_patch::merge_instances(v63, v62);
  }
}
