void __usercall vostok::render::visibility_statistics_group::visibility_statistics_group(
        vostok::render::visibility_statistics_group *this@<ecx>,
        int a2@<eax>)
{
  vostok::buffer_string *v3; // ecx
  char *v4; // eax
  vostok::render::statistics *v5; // eax

  v3 = (vostok::buffer_string *)(a2 + 4);
  v4 = (char *)(a2 + 16);
  *(_DWORD *)a2 = 0;
  v3->m_begin = v4;
  v3->m_end = v4;
  v3->m_max_end = v4 + 128;
  *v4 = 0;
  vostok::buffer_string::operator+=(v3, "visibility statistics");
  v5 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  *(_DWORD *)(a2 + 144) = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v5->first_group = (vostok::render::statistics_group *)a2;
  vostok::render::statistics_value<double>::statistics_value<double>(
    (vostok::render::statistics_value<double> *)(a2 + 152),
    (vostok::render::statistics_group *)a2,
    "portals culling time");
  *(_DWORD *)(a2 + 152) = &vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 368),
    (vostok::render::statistics_group *)a2,
    "frustums count");
  *(_DWORD *)(a2 + 368) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    (vostok::render::statistics_value<double> *)(a2 + 560),
    (vostok::render::statistics_group *)a2,
    "culling time");
  *(_DWORD *)(a2 + 560) = &vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    (vostok::render::statistics_value<double> *)(a2 + 776),
    (vostok::render::statistics_group *)a2,
    "models updating time");
  *(_DWORD *)(a2 + 776) = &vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 992),
    (vostok::render::statistics_group *)a2,
    "draw calls");
  *(_DWORD *)(a2 + 992) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1180),
    (vostok::render::statistics_group *)a2,
    "visible triangles");
  *(_DWORD *)(a2 + 1180) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1368),
    (vostok::render::statistics_group *)a2,
    "total rendered triangles");
  *(_DWORD *)(a2 + 1368) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1556),
    (vostok::render::statistics_group *)a2,
    "total rendered points");
  *(_DWORD *)(a2 + 1556) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1744),
    (vostok::render::statistics_group *)a2,
    "surfaces");
  *(_DWORD *)(a2 + 1744) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1932),
    (vostok::render::statistics_group *)a2,
    "lights");
  *(_DWORD *)(a2 + 1932) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2120),
    (vostok::render::statistics_group *)a2,
    "particle instances");
  *(_DWORD *)(a2 + 2120) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2308),
    (vostok::render::statistics_group *)a2,
    "total rendered speedtree instances");
  *(_DWORD *)(a2 + 2308) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2496),
    (vostok::render::statistics_group *)a2,
    "environment probes");
  *(_DWORD *)(a2 + 2496) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2684),
    (vostok::render::statistics_group *)a2,
    "ambient volumes");
  *(_DWORD *)(a2 + 2684) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2872),
    (vostok::render::statistics_group *)a2,
    "occlusion culled surfaces");
  *(_DWORD *)(a2 + 2872) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3060),
    (vostok::render::statistics_group *)a2,
    "occlusion culled lights");
  *(_DWORD *)(a2 + 3060) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3248),
    (vostok::render::statistics_group *)a2,
    "occlusion culled grass patches");
  *(_DWORD *)(a2 + 3248) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3436),
    (vostok::render::statistics_group *)a2,
    "occlusion culled particle instances");
  *(_DWORD *)(a2 + 3436) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3624),
    (vostok::render::statistics_group *)a2,
    "occlusion culled decals");
  *(_DWORD *)(a2 + 3624) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3812),
    (vostok::render::statistics_group *)a2,
    "occlusion culled environment probes");
  *(_DWORD *)(a2 + 3812) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4000),
    (vostok::render::statistics_group *)a2,
    "occlusion culled portals");
  *(_DWORD *)(a2 + 4000) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 4188),
    (vostok::render::statistics_group *)a2,
    "occlusion culled ambient volumes");
  *(_DWORD *)(a2 + 4188) = &vostok::render::statistics_int::`vftable';
}
