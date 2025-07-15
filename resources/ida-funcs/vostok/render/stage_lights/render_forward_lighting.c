void __thiscall vostok::render::stage_lights::render_forward_lighting(
        vostok::render::stage_lights *this,
        vostok::render::backend *foreground,
        char a3)
{
  long double v3; // rdi
  unsigned int m_size; // eax
  int v5; // ebx
  float *v6; // ecx
  char *v7; // ebx
  int v8; // eax
  vostok::render::render_surface *v9; // ecx
  vostok::render::render_surface_instance *v10; // ecx
  vostok::render::res_geometry *v11; // ecx
  vostok::render::renderer *v12; // ecx
  float *v13; // eax
  float v14; // ebx
  bool v15; // zf
  vostok::math::float4x4 *v16; // eax
  vostok::math::aabb *v17; // ecx
  vostok::render::renderer *v18; // ecx
  int v19; // eax
  vostok::render::render_surface_instance *v20; // ecx
  vostok::render::light *v21; // ecx
  vostok::render::renderer *v22; // ecx
  vostok::render::renderer *v23; // ecx
  vostok::math::float3 v24; // [esp-Ch] [ebp-19Ch]
  vostok::math::float3 v25; // [esp-8h] [ebp-198h]
  float *v26; // [esp+Ch] [ebp-184h]
  int v27; // [esp+Ch] [ebp-184h]
  int add_shadow_vertices; // [esp+10h] [ebp-180h]
  float v29; // [esp+10h] [ebp-180h]
  vostok::render::render_surface_vtbl *v30; // [esp+14h] [ebp-17Ch]
  vostok::render::render_surface *v31; // [esp+18h] [ebp-178h]
  float v32; // [esp+1Ch] [ebp-174h]
  char *v33; // [esp+20h] [ebp-170h]
  float *v34; // [esp+24h] [ebp-16Ch]
  int *v35; // [esp+28h] [ebp-168h]
  vostok::render::render_surface *v36; // [esp+2Ch] [ebp-164h]
  vostok::math::float4x4 *v37; // [esp+30h] [ebp-160h]
  vostok::math::aabb v38; // [esp+34h] [ebp-15Ch] BYREF
  vostok::math::aabb v39; // [esp+4Ch] [ebp-144h] BYREF
  vostok::math::float3 v40; // [esp+64h] [ebp-12Ch] BYREF
  vostok::math::sphere v41; // [esp+70h] [ebp-120h] BYREF
  vostok::math::sphere v42; // [esp+80h] [ebp-110h] BYREF
  vostok::math::float4x4 v43; // [esp+90h] [ebp-100h] BYREF
  _BYTE v44[64]; // [esp+D0h] [ebp-C0h] BYREF
  vostok::math::float4x4 v45; // [esp+110h] [ebp-80h] BYREF
  char v46[64]; // [esp+150h] [ebp-40h] BYREF

  HIDWORD(v3) = foreground;
  v35 = *(int **)((char *)&dword_8B9660 + *(_DWORD *)(foreground->vertex_small.m_size + 16264));
  m_size = foreground->vertex_small.m_size;
  v5 = *(_DWORD *)(m_size + 16264);
  v6 = *(float **)(v5 + 9135448);
  v7 = &aAvbtcollisionw[v5 + 4];
  v8 = *(_DWORD *)(m_size + 16268) + 9368;
  v34 = v6;
  v9 = *(vostok::render::render_surface **)v8;
  v33 = v7;
  v31 = *(vostok::render::render_surface **)v8;
  v36 = *(vostok::render::render_surface **)(v8 + 4);
  if ( *(vostok::render::render_surface **)v8 != v36 )
  {
    while ( 1 )
    {
      LODWORD(v3) = v9->__vftable;
      v30 = v9->__vftable;
      add_shadow_vertices = (int)v9->add_shadow_vertices;
      if ( vostok::render::render_surface::get_material_effects(v9, add_shadow_vertices)->m_effects[17].m_object
        && a3 == vostok::render::render_surface_instance::is_foreground(v10, SLODWORD(v3)) )
      {
        vostok::render::renderer_context::set_w(
          *(const vostok::math::float4x4 **)(LODWORD(v3) + 36),
          *(vostok::render::renderer_context **)(HIDWORD(v3) + 4));
        vostok::render::res_geometry::apply(v11, *(_DWORD *)(add_shadow_vertices + 4));
        if ( *(_BYTE *)(HIDWORD(v3) + 2584) )
        {
          v13 = *(float **)v7;
          v29 = 0.0;
          v32 = float_max_17;
          v26 = *(float **)v7;
          if ( *(float **)v7 != v34 )
          {
            while ( 1 )
            {
              v14 = *v13;
              (*(void (__thiscall **)(void (__thiscall *)(vostok::render::render_surface *), vostok::math::aabb *))(*(_DWORD *)v30[1].~vostok::render::render_surface + 72))(
                v30[1].~vostok::render::render_surface,
                &v39);
              vostok::math::aabb::modify((vostok::math::aabb *)v30[1].add_shadow_vertices, &v39);
              vostok::math::create_identity_aabb(&v38);
              v15 = *(_DWORD *)(LODWORD(v14) + 548) == 0;
              qmemcpy(v44, (const void *)(LODWORD(v14) + 348), sizeof(v44));
              if ( v15 )
              {
                v40.x = *(float *)(LODWORD(v14) + 524);
                v40.y = v40.x;
                v40.z = v40.x;
                v37 = vostok::math::create_translation((const vostok::math::float3 *)(LODWORD(v14) + 508), &v45);
                v16 = vostok::math::create_scale(&v40, (vostok::math::float4x4 *)v46);
                vostok::math::mul4x3(v37, v16, &v43);
                v17 = (vostok::math::aabb *)&v43;
              }
              else
              {
                v17 = (vostok::math::aabb *)v44;
              }
              vostok::math::aabb::modify(v17, &v38);
              if ( v38.max.x >= v39.min.x
                && v38.max.y >= v39.min.y
                && v38.max.z >= v39.min.z
                && v39.max.x >= v38.min.x
                && v39.max.y >= v38.min.y
                && v39.max.z >= v38.min.z
                && v32 > *(float *)(LODWORD(v14) + 524) )
              {
                v32 = *(float *)(LODWORD(v14) + 524);
                v29 = v14;
              }
              if ( ++v26 == v34 )
                break;
              v13 = v26;
            }
            if ( v29 != 0.0 )
            {
              if ( a3 )
                vostok::render::renderer::foreground_begin(v12, foreground->vertex_small.m_position);
              vostok::render::stage_lights::render_model_probe_lighting(
                (vostok::render::stage_lights *)v12,
                foreground,
                (vostok::render::environment_probe *)v30,
                v29);
              if ( a3 )
                vostok::render::renderer::foreground_end(v12, foreground->vertex_small.m_position);
            }
            HIDWORD(v3) = foreground;
            v7 = v33;
          }
        }
        if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(HIDWORD(v3) + 4) + 16268) + 336) )
        {
          if ( a3 )
            vostok::render::renderer::foreground_begin(v12, *(_DWORD *)(HIDWORD(v3) + 8));
          LODWORD(v25.y) = v30;
          v25.x = *((float *)&v3 + 1);
          vostok::render::stage_lights::render_model_sun_lighting((vostok::render::stage_lights *)v12, v25);
          if ( a3 )
            vostok::render::renderer::foreground_end(v18, *(_DWORD *)(HIDWORD(v3) + 8));
        }
        v19 = *v35;
        v27 = *v35;
        if ( *v35 != v35[1] )
        {
          while ( 1 )
          {
            LODWORD(v3) = *(_DWORD *)v19;
            vostok::math::aabb::sphere((vostok::math::aabb *)(*(_DWORD *)v19 + 872), &v41);
            vostok::render::render_surface_instance::get_bound_sphere(v20, (vostok::math::sphere *)v30, &v42);
            if ( (float)(v42.vector.w + v41.vector.w) > fsqrt(
                                                          (float)((float)((float)(v41.vector.z - v42.vector.z)
                                                                        * (float)(v41.vector.z - v42.vector.z))
                                                                + (float)((float)(v41.vector.y - v42.vector.y)
                                                                        * (float)(v41.vector.y - v42.vector.y)))
                                                        + (float)((float)(v41.vector.x - v42.vector.x)
                                                                * (float)(v41.vector.x - v42.vector.x)))
              && !vostok::render::light::is_occluded(v21, SLODWORD(v3))
              && *(_BYTE *)(LODWORD(v3) + 681) )
            {
              if ( a3 )
                vostok::render::renderer::foreground_begin(v22, *(_DWORD *)(HIDWORD(v3) + 8));
              *(_QWORD *)&v24.elements[1] = __PAIR64__(LODWORD(v3), (unsigned int)v30);
              v24.x = *((float *)&v3 + 1);
              vostok::render::stage_lights::render_model_lighting((vostok::render::stage_lights *)v22, v3, v24);
              if ( a3 )
                vostok::render::renderer::foreground_end(v23, *(_DWORD *)(HIDWORD(v3) + 8));
            }
            v27 += 8;
            if ( v27 == v35[1] )
              break;
            v19 = v27;
          }
        }
      }
      v31 = (vostok::render::render_surface *)((char *)v31 + 4);
      if ( v31 == v36 )
        break;
      v9 = v31;
    }
  }
}
