void __usercall vostok::render::model_factory::create_render_model(unsigned __int16 type@<ax>)
{
  int v1; // eax
  vostok::render::render_model *v2; // ecx
  int *v3; // esi
  int *v4; // eax
  vostok::render::skeleton_render_model *v5; // ecx
  vostok::render::render_model *v6; // ecx
  int *v7; // esi

  v1 = type - 1;
  if ( v1 )
  {
    if ( v1 == 39 )
    {
      v4 = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             0x150u);
      if ( v4 )
        vostok::render::skeleton_render_model::skeleton_render_model(v5, v4);
    }
    else
    {
      v3 = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             0x148u);
      if ( v3 )
      {
        vostok::render::render_model::render_model(v2, (int)v3);
        *v3 = (int)&vostok::render::grass_render_model::`vftable';
        v3[78] = 0;
        v3[79] = 0;
        v3[80] = 0;
      }
    }
  }
  else
  {
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x138u);
    if ( v7 )
    {
      vostok::render::render_model::render_model(v6, (int)v7);
      *v7 = (int)&vostok::render::static_render_model::`vftable';
    }
  }
}
