void __userpurge vostok::render::environment_probe::environment_probe(
        vostok::render::environment_probe *this@<ecx>,
        unsigned int a2@<esi>,
        vostok::collision::space_partitioning_tree *tree,
        const vostok::render::environment_probe_properties *properties,
        unsigned int id)
{
  vostok::render::environment_probe *v5; // ecx

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = a2 + 24;
  *(_DWORD *)(a2 + 16) = a2 + 24;
  *(_BYTE *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 20) = a2 + 284;
  vostok::math::create_identity_aabb((vostok::math::aabb *)(a2 + 552));
  *(_DWORD *)(a2 + 576) = id;
  *(_DWORD *)(a2 + 584) = tree;
  *(_DWORD *)(a2 + 580) = 1;
  *(_DWORD *)(a2 + 588) = 0;
  *(_DWORD *)(a2 + 592) = 0;
  *(_DWORD *)(a2 + 596) = 0;
  *(_DWORD *)(a2 + 600) = 0;
  *(_DWORD *)(a2 + 604) = 0;
  *(_DWORD *)(a2 + 608) = -1;
  *(_BYTE *)(a2 + 616) = 0;
  id = a2;
  *(float *)(a2 + 612) = vostok::math::random32::random_f((vostok::math::random32 *)&id, 1.0) * 0.1;
  vostok::render::environment_probe::set_properties(v5, (vostok::collision::geometry_instance *)a2, (int)properties);
}
