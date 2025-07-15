int __cdecl vorbis_synthesis_trackonly(vorbis_block *vb, ogg_packet *op)
{
  vorbis_dsp_state *vd; // eax
  int bytes; // edx
  unsigned __int8 *packet; // ecx
  oggpack_buffer *p_opb; // esi
  unsigned int v9; // eax
  int *v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  _DWORD *codec_setup; // [esp+Ch] [ebp-4h]
  _DWORD *backend_state; // [esp+18h] [ebp+8h]

  vd = vb->vd;
  backend_state = vd->backend_state;
  codec_setup = vd->vi->codec_setup;
  _vorbis_block_ripcord(vb);
  bytes = op->bytes;
  packet = op->packet;
  vb->opb.endbyte = 0;
  vb->opb.endbit = 0;
  vb->opb.buffer = 0;
  vb->opb.ptr = 0;
  vb->opb.storage = 0;
  p_opb = &vb->opb;
  vb->opb.ptr = packet;
  vb->opb.buffer = packet;
  vb->opb.storage = bytes;
  if ( oggpack_read(&vb->opb, 1u) )
    return -135;
  v9 = oggpack_read(p_opb, backend_state[11]);
  if ( v9 == -1 )
    return -136;
  vb->mode = v9;
  v10 = (int *)codec_setup[v9 + 8];
  if ( !v10 )
    return -136;
  v11 = *v10;
  vb->W = v11;
  if ( v11 )
  {
    vb->lW = oggpack_read(p_opb, 1u);
    v12 = oggpack_read(p_opb, 1u);
    vb->nW = v12;
    if ( v12 == -1 )
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
  vb->pcmend = 0;
  vb->pcm = 0;
  return 0;
}
