unsigned __int8 *__cdecl floor0_look(vorbis_dsp_state *vd, _DWORD *i)
{
  unsigned __int8 *v2; // esi

  v2 = ogg_calloc_impl(1u, 0x20u);
  *((_DWORD *)v2 + 1) = *i;
  *(_DWORD *)v2 = i[2];
  *((_DWORD *)v2 + 5) = i;
  *((_DWORD *)v2 + 2) = ogg_calloc_impl(2u, 4u);
  return v2;
}
