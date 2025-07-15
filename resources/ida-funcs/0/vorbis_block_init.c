int __cdecl vorbis_block_init(vorbis_dsp_state *v, vorbis_block *vb)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned __int8 *dst; // [esp+14h] [ebp+Ch]

  v3 = 0;
  memset((int)vb, 0, sizeof(vorbis_block));
  vb->vd = v;
  vb->localalloc = 0;
  vb->localstore = 0;
  if ( v->analysisp )
  {
    v4 = ogg_calloc_impl(1u, 0x48u);
    vb->internal = v4;
    *((float *)v4 + 1) = FLOAT_N9999_0;
    for ( dst = 0; ; v3 = dst )
    {
      if ( v3 == (unsigned __int8 *)7 )
        *((_DWORD *)v4 + 10) = &vb->opb;
      else
        *(_DWORD *)&v4[4 * (_DWORD)v3 + 12] = ogg_calloc_impl(1u, 0x14u);
      oggpack_writeinit(*(oggpack_buffer **)&v4[4 * (_DWORD)v3 + 12]);
      if ( (int)++dst >= 15 )
        break;
    }
  }
  return 0;
}
