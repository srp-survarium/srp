void __userpurge vostok::render::visibility_statistics_group::visibility_statistics_group(
        vostok::render::visibility_statistics_group *this@<ecx>,
        int a2@<eax>,
        const vostok::math::color *group_name,
        const vostok::math::color *group_color)
{
  vostok::render::statistics_group::statistics_group(
    this,
    (vostok::render::statistics_group *)a2,
    "visibility statistics",
    group_name);
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 152),
    (vostok::render::statistics_group *)a2,
    "portals culling time",
    6u);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 496),
    (vostok::render::statistics_group *)a2,
    "frustums count");
  *(_DWORD *)(a2 + 496) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 744),
    (vostok::render::statistics_group *)a2,
    "culling time",
    6u);
  vostok::render::statistics_float::statistics_float(
    (vostok::render::statistics_float *)(a2 + 1088),
    (vostok::render::statistics_group *)a2,
    "models updating time",
    6u);
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1432),
    (vostok::render::statistics_group *)a2,
    "occ culled surfaces");
  *(_DWORD *)(a2 + 1432) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1680),
    (vostok::render::statistics_group *)a2,
    "occ culled lights");
  *(_DWORD *)(a2 + 1680) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1928),
    (vostok::render::statistics_group *)a2,
    "occ culled amb lights");
  *(_DWORD *)(a2 + 1928) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2176),
    (vostok::render::statistics_group *)a2,
    "occ culled grass ptchs");
  *(_DWORD *)(a2 + 2176) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2424),
    (vostok::render::statistics_group *)a2,
    "occ culled particle");
  *(_DWORD *)(a2 + 2424) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2672),
    (vostok::render::statistics_group *)a2,
    "occ culled decals");
  *(_DWORD *)(a2 + 2672) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2920),
    (vostok::render::statistics_group *)a2,
    "occ culled env. probes");
  *(_DWORD *)(a2 + 2920) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3168),
    (vostok::render::statistics_group *)a2,
    "occ culled portals");
  *(_DWORD *)(a2 + 3168) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3416),
    (vostok::render::statistics_group *)a2,
    "occ culled amb volumes");
  *(_DWORD *)(a2 + 3416) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3664),
    (vostok::render::statistics_group *)a2,
    "visible triangles");
  *(_DWORD *)(a2 + 3664) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3912),
    (vostok::render::statistics_group *)a2,
    "total rendered points");
  *(_DWORD *)(a2 + 3912) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4160),
    (vostok::render::statistics_group *)a2,
    "particle systems");
  *(_DWORD *)(a2 + 4160) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4408),
    (vostok::render::statistics_group *)a2,
    "particles");
  *(_DWORD *)(a2 + 4408) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4656),
    (vostok::render::statistics_group *)a2,
    "environment probes");
  *(_DWORD *)(a2 + 4656) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4904),
    (vostok::render::statistics_group *)a2,
    "ambient volumes");
  *(_DWORD *)(a2 + 4904) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5152),
    (vostok::render::statistics_group *)a2,
    "ambient lights");
  *(_DWORD *)(a2 + 5152) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5400),
    (vostok::render::statistics_group *)a2,
    "lights");
  *(_DWORD *)(a2 + 5400) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5648),
    (vostok::render::statistics_group *)a2,
    "surfaces");
  *(_DWORD *)(a2 + 5648) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 5896),
    (vostok::render::statistics_group *)a2,
    "total rendered triangles");
  *(_DWORD *)(a2 + 5896) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 6144),
    (vostok::render::statistics_group *)a2,
    "dips instancing");
  *(_DWORD *)(a2 + 6144) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 6392),
    (vostok::render::statistics_group *)a2,
    "dips");
  *(_DWORD *)(a2 + 6392) = &vostok::render::statistics_int::`vftable';
}
