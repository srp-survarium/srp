void __usercall vostok::render::model_factory::create_render_surface(unsigned __int16 type@<ax>)
{
  int *v1; // eax
  vostok::render::render_surface *v2; // ecx
  int *v3; // esi
  int *v4; // eax
  vostok::render::render_surface *v5; // ecx
  int *v6; // esi
  int *v7; // eax
  vostok::render::skeleton_mesh_gpu_skinning_4weights *v8; // ecx
  int *v9; // eax
  vostok::render::skeleton_mesh_gpu_skinning_3weights *v10; // ecx
  int *v11; // eax
  vostok::render::skeleton_mesh_gpu_skinning_2weights *v12; // ecx
  int *v13; // eax
  vostok::render::skeleton_mesh_gpu_skinning_1weight *v14; // ecx
  int *v15; // eax
  vostok::render::render_surface *v16; // ecx
  int *v17; // esi
  int *v18; // eax
  vostok::render::render_surface *v19; // ecx
  int *v20; // esi
  int *v21; // eax
  vostok::render::grass_render_surface *v22; // ecx

  switch ( byte_781C18[type] )
  {
    case 0:
      v1 = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             0x9Cu);
      v3 = v1;
      if ( v1 )
      {
        vostok::render::render_surface::render_surface(v2, (int)v1);
        *v3 = (int)&vostok::render::static_render_surface::`vftable';
        v3[1] = 1;
      }
      break;
    case 1:
      v4 = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             0x9Cu);
      v6 = v4;
      if ( v4 )
      {
        vostok::render::render_surface::render_surface(v5, (int)v4);
        *v6 = (int)&vostok::render::static_render_surface::`vftable';
        v6[1] = 2;
      }
      break;
    case 2:
      v13 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0xA0u);
      if ( v13 )
        vostok::render::skeleton_mesh_gpu_skinning_1weight::skeleton_mesh_gpu_skinning_1weight(
          v14,
          (unsigned int **)v13);
      break;
    case 3:
      v11 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0xA0u);
      if ( v11 )
        vostok::render::skeleton_mesh_gpu_skinning_2weights::skeleton_mesh_gpu_skinning_2weights(
          v12,
          (D3D11_TEXTURE3D_DESC **)v11);
      break;
    case 4:
      v9 = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             0xA0u);
      if ( v9 )
        vostok::render::skeleton_mesh_gpu_skinning_3weights::skeleton_mesh_gpu_skinning_3weights(
          v10,
          (DXGI_FORMAT **)v9);
      break;
    case 5:
      v7 = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             0xA0u);
      if ( v7 )
        vostok::render::skeleton_mesh_gpu_skinning_4weights::skeleton_mesh_gpu_skinning_4weights(
          v8,
          (unsigned int **)v7);
      break;
    case 6:
      v15 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0xA0u);
      v17 = v15;
      if ( v15 )
      {
        vostok::render::render_surface::render_surface(v16, (int)v15);
        *v17 = (int)&vostok::render::user_render_surface_editable::`vftable';
      }
      break;
    case 7:
      v18 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0x9Cu);
      v20 = v18;
      if ( v18 )
      {
        vostok::render::render_surface::render_surface(v19, (int)v18);
        *v20 = (int)&vostok::render::user_render_surface_wire::`vftable';
      }
      break;
    case 8:
      v21 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0xACu);
      if ( v21 )
        vostok::render::grass_render_surface::grass_render_surface(v22, v21);
      break;
  }
}
