void __usercall vostok::render::stage_lights::clear_surfaces(
        vostok::render::stage_lights *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>)
{
  bool v4; // al
  vostok::render::renderer_context *m_context; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  vostok::render::backend *v7; // ecx
  vostok::render::render_target *v8; // eax
  vostok::render::render_target *m_object; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // eax
  float z; // edi
  vostok::render::render_target *v12; // eax
  _DWORD *v13; // eax
  int v14; // ecx
  bool v15; // zf
  int v16; // ebx
  vostok::math::color *v17; // ecx
  vostok::math::color *v18; // eax
  vostok::render::backend *v19; // ecx
  const vostok::render::render_target *v20; // [esp+0h] [ebp-20h]
  long double v21; // [esp+Ch] [ebp-14h]
  float v22; // [esp+Ch] [ebp-14h]
  long double v23; // [esp+14h] [ebp-Ch] BYREF
  vostok::render::render_target *rt; // [esp+1Ch] [ebp-4h] BYREF

  v4 = this->is_enabled(this);
  m_context = this->m_context;
  if ( v4 )
  {
    v6 = vostok::render::renderer_context::get_rt(
           m_context,
           rt_particle_lighting,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v6->m_object,
      0,
      0,
      0);
    v8 = rt;
    if ( *(float *)&rt != 0.0 )
    {
      --rt->m_reference_count;
      if ( !v8->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    vostok::render::backend::clear_render_targets(
      v7,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      0,
      0.0,
      0.0,
      1.0);
  }
  else
  {
    v21 = COERCE_DOUBLE(__PAIR64__(a2, a3));
    m_object = vostok::render::renderer_context::get_rt(
                 m_context,
                 rt_accumulator_specular,
                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v23
               + 1)->m_object;
    v10 = vostok::render::renderer_context::get_rt(
            this->m_context,
            rt_accumulator_diffuse,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    v20 = m_object;
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v10->m_object,
      v20,
      0,
      0);
    v12 = rt;
    if ( *(float *)&rt != 0.0 )
    {
      --rt->m_reference_count;
      if ( !v12->m_reference_count )
      {
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v13 = (_DWORD *)HIDWORD(v23);
    if ( HIDWORD(v23) )
    {
      --*(_DWORD *)HIDWORD(v23);
      if ( !*v13 )
      {
        vostok::render::resource_manager::release(
          (vostok::render::render_target *)HIDWORD(v23),
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v14 = *(_DWORD *)(LODWORD(z) + 7440);
    v15 = *(_DWORD *)(LODWORD(z) + 7384) == v14;
    *(_DWORD *)(LODWORD(z) + 7384) = v14;
    *(_BYTE *)(LODWORD(z) + 117) |= !v15;
    __libm_sse2_pow(v21, v23);
    *(float *)&rt = 0.125;
    v16 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
    v18 = (vostok::math::color *)vostok::math::color::color(
                                   v17,
                                   (int *)&v23 + 1,
                                   *(float *)&rt,
                                   (vostok::math *)rt,
                                   *(float *)&rt,
                                   *(float *)&rt,
                                   v22);
    vostok::render::backend::clear_render_targets(
      v19,
      (_DWORD *)LODWORD(z),
      *v18,
      (vostok::math::color)v16,
      (vostok::math::color)v16,
      (vostok::math::color)v16);
  }
}
