void __userpurge vostok::render::particles_statistics_group::particles_statistics_group(
        vostok::render::particles_statistics_group *this@<ecx>,
        int a2@<eax>,
        const vostok::math::color *group_name,
        const vostok::math::color *group_color)
{
  const char *v5; // [esp+0h] [ebp-8h]
  const char *v6; // [esp+0h] [ebp-8h]
  const char *v7; // [esp+0h] [ebp-8h]
  const char *v8; // [esp+0h] [ebp-8h]

  vostok::render::statistics_group::statistics_group(
    this,
    (vostok::render::statistics_group *)a2,
    "particles statistics",
    group_name);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 152,
    (vostok::render::statistics_group *)"execute time",
    v5);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 992,
    (vostok::render::statistics_group *)"sprites execute time",
    v6);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 1832,
    (vostok::render::statistics_group *)"beams and trails execute time",
    v7);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 2672,
    (vostok::render::statistics_group *)"meshes execute time",
    v8);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3512),
    (vostok::render::statistics_group *)a2,
    "total instances");
  *(_DWORD *)(a2 + 3512) = &vostok::render::statistics_int::`vftable';
}
