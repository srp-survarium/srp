void __fastcall vostok::sound::sound_world::add_scene_to_active(vostok::sound::sound_world *this, int a2)
{
  float v2; // eax
  float v3; // xmm0_4

  this->m_panning_lut.m_table[14] = 0.0;
  ++*(_DWORD *)(a2 + 18652);
  if ( *(_DWORD *)(a2 + 18660) )
    *(_DWORD *)(*(_DWORD *)(a2 + 18664) + 264) = this;
  else
    *(_DWORD *)(a2 + 18660) = this;
  *(_DWORD *)(a2 + 18664) = this;
  v2 = this->m_panning_lut.m_table[130];
  v3 = (float)*(unsigned __int8 *)(a2 + 18672) * 0.0099999998;
  this->m_panning_lut.m_table[132] = v3;
  if ( v2 != 0.0 )
    (*(void (__stdcall **)(float, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v2) + 48))(
      COERCE_FLOAT(LODWORD(v2)),
      this->m_panning_lut.m_table[131] * v3,
      0);
}
