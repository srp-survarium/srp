void __userpurge vostok::sound::sound_scene::process_fade(
        vostok::sound::sound_scene *this@<ecx>,
        int a2@<esi>,
        unsigned int time_delta)
{
  int v3; // eax
  double v4; // st7
  float v5; // xmm0_4
  int v6; // eax
  float *v7; // edi
  double v8; // st7
  vostok::sound::sound_world *v9; // ecx
  int v10; // eax

  v3 = *(_DWORD *)(a2 + 756);
  if ( v3 == 1 )
  {
    v4 = (double)time_delta / (double)*(unsigned int *)(a2 + 740) + *(float *)(a2 + 732);
    *(float *)(a2 + 732) = v4;
    if ( v4 >= 1.0 )
    {
      v5 = s_bm_current_air_resistance;
      *(_DWORD *)(a2 + 756) = 0;
      *(float *)(a2 + 732) = v5;
    }
    v6 = *(_DWORD *)(a2 + 728);
    if ( v6 )
      (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)v6 + 48))(
        v6,
        *(float *)(a2 + 736) * *(float *)(a2 + 732),
        0);
  }
  else if ( v3 == 2 )
  {
    v7 = (float *)(a2 + 732);
    v8 = *(float *)(a2 + 732) - (double)time_delta / (double)*(unsigned int *)(a2 + 744);
    *(float *)(a2 + 732) = v8;
    if ( v8 < 0.0
      || (time_delta = 0,
          vostok::math::is_similar<float>((const float *)(a2 + 732), (const float *)&time_delta, 0.0000099999997)) )
    {
      v9 = *(vostok::sound::sound_world **)(a2 + 284);
      *(_DWORD *)(a2 + 756) = 0;
      *v7 = 0.0;
      vostok::sound::sound_world::remove_scene_from_active(v9, (vostok::sound::sound_scene *)a2);
      *(_BYTE *)(a2 + 753) = 0;
    }
    v10 = *(_DWORD *)(a2 + 728);
    if ( v10 )
      (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)v10 + 48))(v10, *(float *)(a2 + 736) * *v7, 0);
  }
}
