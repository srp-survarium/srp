void __thiscall vostok::render::statistics::~statistics(vostok::render::statistics *this)
{
  vostok::render::visibility_statistics_group *v1; // ecx
  vostok::render::lights_statistics_group *v2; // ecx
  vostok::render::lpv_statistics_group *v3; // ecx
  vostok::render::ssao_statistics_group *v4; // ecx
  vostok::render::cascaded_sun_shadow_statistics_group *v5; // ecx
  vostok::render::particles_statistics_group *v6; // ecx
  vostok::render::ssao_statistics_group *v7; // ecx
  vostok::render::ssao_statistics_group *v8; // ecx

  vostok::render::debug_statistics_group::~debug_statistics_group(
    (vostok::render::debug_statistics_group *)this,
    &s_statistics_buffer[38288]);
  *(_DWORD *)&s_statistics_buffer[38040] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[37792] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[37448] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[37104] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[36760] = &vostok::render::statistics_base::`vftable';
  vostok::render::visibility_statistics_group::~visibility_statistics_group(v1, &s_statistics_buffer[29968]);
  vostok::render::lights_statistics_group::~lights_statistics_group(v2, &s_statistics_buffer[27296]);
  *(_DWORD *)&s_statistics_buffer[27048] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[26800] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[26456] = &vostok::render::statistics_base::`vftable';
  vostok::render::lpv_statistics_group::~lpv_statistics_group(v3, &s_statistics_buffer[19872]);
  *(_DWORD *)&s_statistics_buffer[19624] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[19376] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[19032] = &vostok::render::statistics_base::`vftable';
  vostok::render::distortion_pass_statistics_group::~distortion_pass_statistics_group(v4, &s_statistics_buffer[17048]);
  *(_DWORD *)&s_statistics_buffer[16800] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[16552] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[16304] = &vostok::render::statistics_base::`vftable';
  vostok::render::cascaded_sun_shadow_statistics_group::~cascaded_sun_shadow_statistics_group(
    v5,
    &s_statistics_buffer[10408]);
  *(_DWORD *)&s_statistics_buffer[10064] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[9720] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[9568] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[9072] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[8728] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[8576] = &vostok::render::statistics_base::`vftable';
  vostok::render::particles_statistics_group::~particles_statistics_group(v6, &s_statistics_buffer[4664]);
  vostok::render::distortion_pass_statistics_group::~distortion_pass_statistics_group(v7, &s_statistics_buffer[2832]);
  vostok::render::distortion_pass_statistics_group::~distortion_pass_statistics_group(v8, &s_statistics_buffer[1000]);
  vostok::quasi_singleton<vostok::render::statistics>::pinst = 0;
  *(_DWORD *)&s_statistics_buffer[656] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[312] = &vostok::render::statistics_base::`vftable';
  *(_DWORD *)&s_statistics_buffer[160] = &vostok::render::statistics_base::`vftable';
}
