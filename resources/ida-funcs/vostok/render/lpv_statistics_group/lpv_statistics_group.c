void __userpurge vostok::render::lpv_statistics_group::lpv_statistics_group(
        vostok::render::lpv_statistics_group *this@<ecx>,
        int a2@<eax>,
        const vostok::math::color *group_name,
        const vostok::math::color *group_color)
{
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+0h] [ebp-Ch]
  const char *v9; // [esp+0h] [ebp-Ch]
  const char *v10; // [esp+0h] [ebp-Ch]

  vostok::render::statistics_group::statistics_group(
    this,
    (vostok::render::statistics_group *)a2,
    "light propagation volumes statistics",
    group_name);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 152,
    (vostok::render::statistics_group *)"LPV lookup time",
    v5);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 992,
    (vostok::render::statistics_group *)"propagation time",
    v6);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 1832,
    (vostok::render::statistics_group *)"GV injection time",
    v7);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 2672,
    (vostok::render::statistics_group *)"VPL injection time",
    v8);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 3512,
    (vostok::render::statistics_group *)"RSM downsample time",
    v9);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 4352,
    (vostok::render::statistics_group *)"RSM rendering time",
    v10);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5192),
    (vostok::render::statistics_group *)a2,
    "dips");
  *(_DWORD *)(a2 + 5192) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5440),
    (vostok::render::statistics_group *)a2,
    "dips in cascade #1");
  *(_DWORD *)(a2 + 5440) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5688),
    (vostok::render::statistics_group *)a2,
    "dips in cascade #2");
  *(_DWORD *)(a2 + 5688) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5936),
    (vostok::render::statistics_group *)a2,
    "dips in cascade #3");
  *(_DWORD *)(a2 + 5936) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 6184),
    (vostok::render::statistics_group *)a2,
    "clipped dips");
  *(_DWORD *)(a2 + 6184) = &vostok::render::statistics_int::`vftable';
}
