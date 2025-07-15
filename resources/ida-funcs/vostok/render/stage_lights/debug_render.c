void __thiscall vostok::render::stage_lights::debug_render(vostok::render::stage_lights *this)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::render::system_renderer *v3; // ecx
  vostok::render::render_target *v4; // eax
  int **v5; // eax
  int *v6; // ebx
  const vostok::math::color *v7; // edx
  int v8; // ecx
  char *v9; // eax
  _BYTE *v10; // ecx
  unsigned int j; // eax
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  int *v15; // edi
  vostok::render::render_target *rt; // [esp+Ch] [ebp-E4h] BYREF
  int *i; // [esp+10h] [ebp-E0h]
  float v18; // [esp+14h] [ebp-DCh]
  float v19; // [esp+18h] [ebp-D8h]
  float v20; // [esp+1Ch] [ebp-D4h]
  float v21[17]; // [esp+20h] [ebp-D0h] BYREF
  float v22; // [esp+64h] [ebp-8Ch]
  float v23; // [esp+68h] [ebp-88h]
  int v24; // [esp+6Ch] [ebp-84h]
  _BYTE v25[12]; // [esp+70h] [ebp-80h] BYREF
  char v26; // [esp+7Ch] [ebp-74h] BYREF
  char vars0; // [esp+F0h] [ebp+0h] BYREF

  if ( s_debug_render )
  {
    v2 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_present,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v2->m_object,
      0,
      0,
      0);
    v4 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v4->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v5 = *(int ***)((char *)&dword_8B9660 + (unsigned int)this->m_context->m_scene);
    v6 = *v5;
    for ( i = v5[1]; v6 != i; v6 += 2 )
    {
      if ( !vostok::render::light::is_occluded((vostok::render::light *)v3, *v6) && (v7[215].m_value & 0xF) != 4 )
      {
        rt = (vostok::render::render_target *)-16776961;
        vostok::render::system_renderer::draw_aabb(
          v3,
          vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
          v7 + 218,
          (int *)&rt);
        v3 = (vostok::render::system_renderer *)(*(_DWORD *)(*v6 + 860) & 0xF);
        if ( (_BYTE)v3 == 6 )
        {
          qmemcpy(v21, (const void *)(*v6 + 388), 0x40u);
          v8 = 7;
          v9 = &v26;
          do
          {
            *(_DWORD *)v9 = -1;
            v9 += 16;
            --v8;
          }
          while ( v8 >= 0 );
          v24 = -14614784;
          v10 = v25;
          for ( j = 0; j < 24; j += 3 )
          {
            v12 = vostok::geometry_utils::cube_solid::vertices[j];
            v13 = *(float *)&dword_7E9500[j];
            v14 = *(float *)&dword_7E94FC[j];
            v18 = (float)((float)((float)(v21[8] * v13) + (float)(v21[0] * v12)) + (float)(v21[4] * v14)) + v21[12];
            v19 = (float)((float)((float)(v21[9] * v13) + (float)(v21[1] * v12)) + (float)(v21[5] * v14)) + v21[13];
            v20 = (float)((float)((float)(v21[10] * v13) + (float)(v21[2] * v12)) + (float)(v21[6] * v14)) + v21[14];
            v21[16] = v18;
            v22 = v19;
            v23 = v20;
            *(float *)v10 = v18;
            *((float *)v10 + 1) = v22;
            *((float *)v10 + 2) = v23;
            v15 = (int *)(v10 + 12);
            v10 += 16;
            *v15 = v24;
          }
          vostok::render::system_renderer::draw_triangles(
            (const vostok::render::vertex_colored *const)&vars0,
            (vostok::render::system_renderer *)v10,
            (unsigned int)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
            (unsigned int)v25,
            (unsigned __int8 *)vostok::geometry_utils::cube_solid::faces,
            (char *)vostok::geometry_utils::rectangle_solid::vertices,
            0);
        }
      }
    }
  }
}
