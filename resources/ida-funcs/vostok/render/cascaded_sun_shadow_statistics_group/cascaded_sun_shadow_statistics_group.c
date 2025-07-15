void __userpurge vostok::render::cascaded_sun_shadow_statistics_group::cascaded_sun_shadow_statistics_group(
        vostok::render::cascaded_sun_shadow_statistics_group *this@<ecx>,
        int a2@<eax>,
        const vostok::math::color *group_name,
        const vostok::math::color *group_color)
{
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+0h] [ebp-Ch]

  vostok::render::statistics_group::statistics_group(
    this,
    (vostok::render::statistics_group *)a2,
    "cascaded sun shadow statistics",
    group_name);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 152,
    (vostok::render::statistics_group *)"execute time cascade # 1",
    v5);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 992,
    (vostok::render::statistics_group *)"execute time cascade # 2",
    v6);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 1832,
    (vostok::render::statistics_group *)"execute time cascade # 3",
    v7);
  vostok::render::statistics_cpu_gpu::statistics_cpu_gpu(
    (vostok::render::statistics_cpu_gpu *)a2,
    a2 + 2672,
    (vostok::render::statistics_group *)"execute time cascade # 4",
    v8);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3512),
    (vostok::render::statistics_group *)a2,
    "instancing dips");
  *(_DWORD *)(a2 + 3512) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3760),
    (vostok::render::statistics_group *)a2,
    "clipped dips");
  *(_DWORD *)(a2 + 3760) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4008),
    (vostok::render::statistics_group *)a2,
    "prev cascade clip dip");
  *(_DWORD *)(a2 + 4008) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4256),
    (vostok::render::statistics_group *)a2,
    "invis clip dip");
  *(_DWORD *)(a2 + 4256) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4504),
    (vostok::render::statistics_group *)a2,
    "dips in cascade # 4");
  *(_DWORD *)(a2 + 4504) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4752),
    (vostok::render::statistics_group *)a2,
    "dips in cascade # 3");
  *(_DWORD *)(a2 + 4752) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5000),
    (vostok::render::statistics_group *)a2,
    "dips in cascade # 2");
  *(_DWORD *)(a2 + 5000) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5248),
    (vostok::render::statistics_group *)a2,
    "dips in cascade # 1");
  *(_DWORD *)(a2 + 5248) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5496),
    (vostok::render::statistics_group *)a2,
    "dips");
  *(_DWORD *)(a2 + 5496) = &vostok::render::statistics_int::`vftable';
}
