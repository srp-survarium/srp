void __userpurge vostok::render::debug_statistics_group::debug_statistics_group(
        vostok::render::debug_statistics_group *this@<ecx>,
        int a2@<eax>,
        const vostok::math::color *group_name,
        const vostok::math::color *group_color)
{
  vostok::render::statistics_group::statistics_group(
    this,
    (vostok::render::statistics_group *)a2,
    "debug statistics",
    group_name);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 152),
    (vostok::render::statistics_group *)a2,
    "total vmem(Mb)");
  *(_DWORD *)(a2 + 152) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 400),
    (vostok::render::statistics_group *)a2,
    "texture vmem(Mb)",
    6u);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 744),
    (vostok::render::statistics_group *)a2,
    "texture pool used");
  *(_DWORD *)(a2 + 744) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 992),
    (vostok::render::statistics_group *)a2,
    "texture pool total");
  *(_DWORD *)(a2 + 992) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1240),
    (vostok::render::statistics_group *)a2,
    "vertices memory");
  *(_DWORD *)(a2 + 1240) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1488),
    (vostok::render::statistics_group *)a2,
    "indices memory");
  *(_DWORD *)(a2 + 1488) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1736),
    (vostok::render::statistics_group *)a2,
    "total rt vmem");
  *(_DWORD *)(a2 + 1736) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1984),
    (vostok::render::statistics_group *)a2,
    "g-buffer vmem");
  *(_DWORD *)(a2 + 1984) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2232),
    (vostok::render::statistics_group *)a2,
    "dips in lpv");
  *(_DWORD *)(a2 + 2232) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2480),
    (vostok::render::statistics_group *)a2,
    "v shd chgs");
  *(_DWORD *)(a2 + 2480) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2728),
    (vostok::render::statistics_group *)a2,
    "p shd chgs");
  *(_DWORD *)(a2 + 2728) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2976),
    (vostok::render::statistics_group *)a2,
    "v tex chgs");
  *(_DWORD *)(a2 + 2976) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3224),
    (vostok::render::statistics_group *)a2,
    "v consts chgs");
  *(_DWORD *)(a2 + 3224) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3472),
    (vostok::render::statistics_group *)a2,
    "v smplrs chgs");
  *(_DWORD *)(a2 + 3472) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3720),
    (vostok::render::statistics_group *)a2,
    "p tex chgs");
  *(_DWORD *)(a2 + 3720) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3968),
    (vostok::render::statistics_group *)a2,
    "p consts chgs");
  *(_DWORD *)(a2 + 3968) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4216),
    (vostok::render::statistics_group *)a2,
    "p smplrs chgs");
  *(_DWORD *)(a2 + 4216) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4464),
    (vostok::render::statistics_group *)a2,
    "il chgs");
  *(_DWORD *)(a2 + 4464) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 4712),
    (vostok::render::statistics_group *)a2,
    "gpu compressor time",
    6u);
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 5056),
    (vostok::render::statistics_group *)a2,
    "gpu compr rt time",
    6u);
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 5400),
    (vostok::render::statistics_group *)a2,
    "cpu compr time",
    6u);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5744),
    (vostok::render::statistics_group *)a2,
    "gpu compr tex");
  *(_DWORD *)(a2 + 5744) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5992),
    (vostok::render::statistics_group *)a2,
    "cpu compr tex");
  *(_DWORD *)(a2 + 5992) = &vostok::render::statistics_int::`vftable';
}
