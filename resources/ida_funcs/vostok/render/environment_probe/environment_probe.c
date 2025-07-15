void __userpurge vostok::render::environment_probe::environment_probe(
        vostok::render::environment_probe *this@<ecx>,
        int a2@<esi>,
        vostok::collision::space_partitioning_tree *tree,
        vostok::render::environment_probe_properties *properties,
        unsigned int id)
{
  const vostok::math::float4x4 *v5; // xmm0_4
  __int64 v6; // [esp+4h] [ebp-Ch]

  *(_DWORD *)a2 = 0;
  *(_BYTE *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 4) = a2 + 16;
  *(_DWORD *)(a2 + 8) = a2 + 16;
  *(_DWORD *)(a2 + 12) = a2 + 276;
  *(_QWORD *)(a2 + 380) = 0xBF800000BF800000uLL;
  v5 = clear_value;
  *(_DWORD *)(a2 + 388) = -1082130432;
  LODWORD(v6) = v5;
  HIDWORD(v6) = v5;
  *(_QWORD *)(a2 + 392) = v6;
  *(_DWORD *)(a2 + 400) = v5;
  *(_DWORD *)(a2 + 404) = 0;
  *(_DWORD *)(a2 + 408) = 0;
  *(_DWORD *)(a2 + 412) = id;
  *(_DWORD *)(a2 + 416) = 1;
  *(_DWORD *)(a2 + 420) = tree;
  *(_DWORD *)(a2 + 424) = 0;
  *(_DWORD *)(a2 + 428) = 0;
  *(_DWORD *)(a2 + 432) = -1;
  *(_BYTE *)(a2 + 436) = 0;
  vostok::render::environment_probe::set_properties(0, (vostok::render::environment_probe *)a2, properties);
}
