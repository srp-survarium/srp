void __userpurge vostok::render::frame_statistics_group::frame_statistics_group(
        vostok::render::frame_statistics_group *this@<ecx>,
        int a2@<eax>,
        const vostok::math::color *group_name,
        const vostok::math::color *group_color)
{
  vostok::render::statistics_group::statistics_group(
    this,
    (vostok::render::statistics_group *)a2,
    "general statistics",
    group_name);
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 152),
    (vostok::render::statistics_group *)a2,
    "render only",
    2u);
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 496),
    (vostok::render::statistics_group *)a2,
    "fully frame",
    2u);
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 840),
    (vostok::render::statistics_group *)a2,
    "cpu idle",
    2u);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1184),
    (vostok::render::statistics_group *)a2,
    "FPS");
  *(_DWORD *)(a2 + 1184) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1432),
    (vostok::render::statistics_group *)a2,
    "passed shader constants");
  *(_DWORD *)(a2 + 1432) = &vostok::render::statistics_int::`vftable';
}
