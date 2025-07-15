void __usercall vostok::render::debug_statistics_group::debug_statistics_group(
        vostok::render::debug_statistics_group *this@<ecx>,
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
  vostok::buffer_string::operator+=(v3, "debug statistics");
  v5 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  *(_DWORD *)(a2 + 144) = vostok::quasi_singleton<vostok::render::statistics>::pinst->first_group;
  v5->first_group = (vostok::render::statistics_group *)a2;
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 148),
    (vostok::render::statistics_group *)a2,
    "avaliable video memory(Mb)");
  *(_DWORD *)(a2 + 148) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 336),
    (vostok::render::statistics_group *)a2,
    "texture video memory(Mb)");
  *(_DWORD *)(a2 + 336) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 524),
    (vostok::render::statistics_group *)a2,
    "other rt video memory(Mb)");
  *(_DWORD *)(a2 + 524) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 712),
    (vostok::render::statistics_group *)a2,
    "G-Buffer video memory(Mb)");
  *(_DWORD *)(a2 + 712) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 900),
    (vostok::render::statistics_group *)a2,
    "dips in lpv");
  *(_DWORD *)(a2 + 900) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1088),
    (vostok::render::statistics_group *)a2,
    "vertex shader changes");
  *(_DWORD *)(a2 + 1088) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1276),
    (vostok::render::statistics_group *)a2,
    "pixel shader changes");
  *(_DWORD *)(a2 + 1276) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1464),
    (vostok::render::statistics_group *)a2,
    "vs textures changes");
  *(_DWORD *)(a2 + 1464) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1652),
    (vostok::render::statistics_group *)a2,
    "vs constants changes");
  *(_DWORD *)(a2 + 1652) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 1840),
    (vostok::render::statistics_group *)a2,
    "vs samplers changes");
  *(_DWORD *)(a2 + 1840) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2028),
    (vostok::render::statistics_group *)a2,
    "ps textures changes");
  *(_DWORD *)(a2 + 2028) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2216),
    (vostok::render::statistics_group *)a2,
    "ps constants changes");
  *(_DWORD *)(a2 + 2216) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2404),
    (vostok::render::statistics_group *)a2,
    "ps samplers changes");
  *(_DWORD *)(a2 + 2404) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 2592),
    (vostok::render::statistics_group *)a2,
    "input layout changes");
  *(_DWORD *)(a2 + 2592) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    (vostok::render::statistics_value<double> *)(a2 + 2784),
    (vostok::render::statistics_group *)a2,
    "GPU compressor time");
  *(_DWORD *)(a2 + 2784) = &vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    (vostok::render::statistics_value<double> *)(a2 + 3000),
    (vostok::render::statistics_group *)a2,
    "GPU compressor RT create time");
  *(_DWORD *)(a2 + 3000) = &vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<double>::statistics_value<double>(
    (vostok::render::statistics_value<double> *)(a2 + 3216),
    (vostok::render::statistics_group *)a2,
    "CPU compressor time");
  *(_DWORD *)(a2 + 3216) = &vostok::render::statistics_float::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3432),
    (vostok::render::statistics_group *)a2,
    "GPU num compressed textures");
  *(_DWORD *)(a2 + 3432) = &vostok::render::statistics_int::`vftable';
  vostok::render::statistics_value<int>::statistics_value<int>(
    (vostok::render::statistics_value<int> *)(a2 + 3620),
    (vostok::render::statistics_group *)a2,
    "CPU num compressed textures");
  *(_DWORD *)(a2 + 3620) = &vostok::render::statistics_int::`vftable';
}
