void __usercall vostok::render::grass_statistics_group::grass_statistics_group(
        vostok::render::grass_statistics_group *this@<ecx>,
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
  vostok::buffer_string::operator+=(v3, "grass statistics");
  v5 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  *(_DWORD *)(a2 + 144) = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v5->first_group = (vostok::render::statistics_group *)a2;
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 148),
    (vostok::render::statistics_group *)a2,
    "total patches");
  *(_DWORD *)(a2 + 148) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 336),
    (vostok::render::statistics_group *)a2,
    "rendered patches");
  *(_DWORD *)(a2 + 336) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 524),
    (vostok::render::statistics_group *)a2,
    "visible patches");
  *(_DWORD *)(a2 + 524) = &vostok::render::statistics_int::`vftable';
}
