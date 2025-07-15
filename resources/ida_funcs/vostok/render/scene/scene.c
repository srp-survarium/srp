void __userpurge vostok::render::scene::scene(
        vostok::render::scene *this@<ecx>,
        int a2@<edi>,
        const vostok::render::scene_configuration *renderer_configuration)
{
  vostok::render::batched_geometry<vostok::render::lpv_vertex> *v3; // ecx
  vostok::render::batched_geometry<vostok::render::shadow_vertex> *v4; // ecx
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  vostok::render::speedtree_forest *v7; // eax
  vostok::render::speedtree_forest *v8; // ecx
  int v9; // eax
  void *v10; // eax
  vostok::render::grass_world *v11; // ecx
  int v12; // eax
  const vostok::math::float4x4 *v13; // xmm0_4
  bool v14; // cl
  unsigned int v15; // [esp+8h] [ebp-10h]
  unsigned int v16; // [esp+8h] [ebp-10h]
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  unsigned int v18; // [esp+Ch] [ebp-Ch]
  char v19; // [esp+17h] [ebp-1h]

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &vostok::render::base_scene::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = -1;
  *(_DWORD *)a2 = &vostok::render::scene::`vftable';
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 324) = 0;
  *(_BYTE *)(a2 + 329) = (_BYTE)renderer_configuration;
  *(_DWORD *)(a2 + 332) = 0;
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::batched_geometry<vostok::render::lpv_vertex>(
    v3,
    a2 + 336,
    (const D3D11_INPUT_ELEMENT_DESC *)3,
    v15,
    v17);
  *(_DWORD *)(a2 + 336) = &vostok::render::lpv_batched_geometry::`vftable';
  vostok::render::batched_geometry<vostok::render::shadow_vertex>::batched_geometry<vostok::render::shadow_vertex>(
    v4,
    a2 + 540,
    (const D3D11_INPUT_ELEMENT_DESC *)3,
    v16,
    v18);
  *(_DWORD *)(a2 + 540) = &vostok::render::shadow_batched_geometry::`vftable';
  *(_DWORD *)(a2 + 744) = &vostok::render::scene::particle_engine::`vftable';
  *(_DWORD *)(a2 + 752) = a2;
  *(_DWORD *)(a2 + 756) = 0;
  *(_DWORD *)(a2 + 760) = 0;
  *(_DWORD *)(a2 + 764) = 0;
  *(_DWORD *)(a2 + 768) = 0;
  *(_DWORD *)(a2 + 772) = 0;
  *(_DWORD *)(a2 + 776) = 0;
  *(_DWORD *)(a2 + 780) = 0;
  *(_DWORD *)(a2 + 784) = 0;
  *(_DWORD *)(a2 + 788) = 0;
  *(_DWORD *)(a2 + 792) = 0;
  *(_DWORD *)(a2 + 796) = 0;
  *(_DWORD *)(a2 + 800) = 0;
  *(_DWORD *)(a2 + 804) = 0;
  *(_DWORD *)(a2 + 808) = 0;
  *(_DWORD *)(a2 + 812) = 0;
  *(_DWORD *)(a2 + 816) = 0;
  *(_DWORD *)(a2 + 820) = 0;
  *(_DWORD *)(a2 + 824) = 0;
  *(_DWORD *)(a2 + 828) = 0;
  *(_DWORD *)(a2 + 832) = 0;
  *(_DWORD *)(a2 + 836) = 0;
  *(_DWORD *)(a2 + 840) = 0;
  *(_DWORD *)(a2 + 844) = 0;
  *(_DWORD *)(a2 + 848) = 0;
  *(_DWORD *)(a2 + 852) = 0;
  *(_DWORD *)(a2 + 856) = 0;
  *(_DWORD *)(a2 + 860) = 0;
  *(_DWORD *)(a2 + 864) = 0;
  *(_DWORD *)(a2 + 868) = 0;
  *(_DWORD *)(a2 + 872) = 0;
  *(_DWORD *)(a2 + 876) = 0;
  *(_DWORD *)(a2 + 884) = 0;
  *(_DWORD *)(a2 + 888) = 0;
  *(_DWORD *)(a2 + 892) = 0;
  *(_DWORD *)(a2 + 896) = 0;
  *(_DWORD *)(a2 + 900) = 0;
  *(_DWORD *)(a2 + 904) = vostok::collision::new_space_partitioning_tree(
                            (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                            1.0,
                            0x400u);
  *(_DWORD *)(a2 + 908) = vostok::collision::new_space_partitioning_tree(
                            (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                            1.0,
                            0x400u);
  *(_DWORD *)(a2 + 912) = vostok::collision::new_space_partitioning_tree(
                            (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                            1.0,
                            0x400u);
  *(_DWORD *)(a2 + 916) = 0;
  *(_DWORD *)(a2 + 920) = 0;
  *(_DWORD *)(a2 + 924) = 0;
  *(_BYTE *)(a2 + 929) = v19;
  *(_DWORD *)(a2 + 932) = 0;
  *(_DWORD *)(a2 + 936) = 0;
  *(_DWORD *)(a2 + 940) = 0;
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x14u);
  v6 = v5;
  if ( v5 )
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    v5[4] = 0;
    v5[4] = vostok::collision::new_space_partitioning_tree(
              (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
              1.0,
              (unsigned int)&loc_19000);
  }
  else
  {
    v6 = 0;
  }
  *(_DWORD *)(a2 + 944) = v6;
  *(_DWORD *)(a2 + 948) = 0;
  if ( (*(_BYTE *)renderer_configuration & 8) != 0
    && (v7 = (vostok::render::speedtree_forest *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                   0x1CF4u)) != 0 )
  {
    vostok::render::speedtree_forest::speedtree_forest(v8, v7);
  }
  else
  {
    v9 = 0;
  }
  *(_DWORD *)(a2 + 952) = v9;
  if ( (*(_BYTE *)renderer_configuration & 0x10) != 0
    && (v10 = vostok::memory::doug_lea_allocator::malloc_impl(
                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                0x168u)) != 0 )
  {
    vostok::render::grass_world::grass_world(v11, (int)v10);
  }
  else
  {
    v12 = 0;
  }
  v13 = clear_value;
  *(_DWORD *)(a2 + 956) = v12;
  *(_DWORD *)(a2 + 960) = 0;
  *(_DWORD *)(a2 + 964) = v13;
  *(_BYTE *)(a2 + 969) = (*(_BYTE *)renderer_configuration & 0x20) != 0;
  v14 = (*(_BYTE *)renderer_configuration & 0x40) != 0;
  *(_DWORD *)(a2 + 972) = 0;
  *(_BYTE *)(a2 + 970) = v14;
}
