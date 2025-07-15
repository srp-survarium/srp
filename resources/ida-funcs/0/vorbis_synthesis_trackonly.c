int __cdecl vorbis_synthesis_trackonly(vorbis_block *vb, ogg_packet *op)
{
  vorbis_dsp_state *vd; // eax
  int bytes; // edx
  unsigned __int8 *packet; // ecx
  oggpack_buffer *p_opb; // edi
  unsigned int v9; // eax
  int *p_blockflag; // eax
  int v11; // eax
  unsigned int v12; // eax
  codec_setup_info *ci; // [esp+10h] [ebp-4h]
  private_state *b; // [esp+18h] [ebp+4h]

  vd = vb->vd;
  b = (private_state *)vd->backend_state;
  ci = (codec_setup_info *)vd->vi->codec_setup;
  _vorbis_block_ripcord(vb);
  bytes = op->bytes;
  packet = op->packet;
  vb->opb.endbyte = 0;
  vb->opb.endbit = 0;
  p_opb = &vb->opb;
  p_opb->ptr = packet;
  p_opb->buffer = packet;
  p_opb->storage = bytes;
  if ( oggpack_read(p_opb, 1u) )
    return -135;
  v9 = oggpack_read(p_opb, b->modebits);
  if ( v9 == -1 )
    return -136;
  vb->mode = v9;
  p_blockflag = &ci->mode_param[v9]->blockflag;
  if ( !p_blockflag )
    return -136;
  v11 = *p_blockflag;
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
