int __cdecl vorbis_synthesis(vorbis_block *vb, ogg_packet *op)
{
  vorbis_dsp_state *vd; // eax
  vorbis_info *vi; // ecx
  oggpack_buffer *v5; // edi
  int bytes; // edx
  unsigned __int8 *packet; // ecx
  oggpack_buffer *v8; // esi
  int *p_endbit; // edi
  unsigned int v11; // eax
  _DWORD *v12; // edi
  int v13; // eax
  unsigned int v14; // eax
  oggpack_buffer *b; // [esp+Ch] [ebp-Ch]
  int **ba; // [esp+Ch] [ebp-Ch]
  _DWORD *codec_setup; // [esp+10h] [ebp-8h]
  int v18; // [esp+10h] [ebp-8h]
  _DWORD *backend_state; // [esp+14h] [ebp-4h]
  vorbis_info *v20; // [esp+20h] [ebp+8h]

  if ( vb )
    vd = vb->vd;
  else
    vd = 0;
  if ( vd )
    backend_state = vd->backend_state;
  else
    backend_state = 0;
  if ( vd )
  {
    vi = vd->vi;
    v20 = vi;
  }
  else
  {
    v20 = 0;
    vi = 0;
  }
  if ( vi )
    codec_setup = vi->codec_setup;
  else
    codec_setup = 0;
  v5 = vb != 0 ? &vb->opb : 0;
  b = v5;
  if ( !vd || !backend_state || !vi || !codec_setup || !v5 )
    return -136;
  _vorbis_block_ripcord(vb);
  bytes = op->bytes;
  packet = op->packet;
  v8 = vb != 0 ? &vb->opb : 0;
  v5->endbyte = 0;
  p_endbit = &v5->endbit;
  *p_endbit++ = 0;
  *p_endbit++ = 0;
  *p_endbit = 0;
  p_endbit[1] = 0;
  v8->ptr = packet;
  v8->buffer = packet;
  v8->storage = bytes;
  if ( oggpack_read(b, 1u) )
    return -135;
  v11 = oggpack_read(b, backend_state[11]);
  if ( v11 == -1 )
    return -136;
  v12 = codec_setup;
  vb->mode = v11;
  ba = (int **)&codec_setup[v11 + 8];
  if ( !*ba )
    return -136;
  v13 = **ba;
  vb->W = v13;
  if ( v13 )
  {
    vb->lW = oggpack_read(v8, 1u);
    v14 = oggpack_read(v8, 1u);
    vb->nW = v14;
    if ( v14 == -1 )
      return -136;
  }
  else
  {
    vb->lW = 0;
    vb->nW = 0;
  }
  vb->granulepos = op->granulepos;
  vb->sequence = op->packetno;
  vb->eofflag = op->e_o_s;
  vb->pcmend = codec_setup[vb->W];
  v18 = 0;
  for ( vb->pcm = (float **)_vorbis_block_alloc(vb, 4 * v20->channels); v18 < v20->channels; ++v18 )
    vb->pcm[v18] = (float *)_vorbis_block_alloc(vb, 4 * vb->pcmend);
  return _mapping_P[v12[(*ba)[3] + 72]]->inverse(vb, (void *)v12[(*ba)[3] + 136]);
}
