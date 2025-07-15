int __cdecl vorbis_synthesis(vorbis_block *vb, ogg_packet *op)
{
  vorbis_dsp_state *vd; // eax
  vorbis_info *v4; // ecx
  oggpack_buffer *p_opb; // ebp
  unsigned int v7; // eax
  int *p_blockflag; // eax
  int v9; // eax
  unsigned int v10; // eax
  int W; // ecx
  int v12; // edi
  int mapping; // eax
  int mode; // [esp+Ch] [ebp-8h]
  int modea; // [esp+Ch] [ebp-8h]
  vorbis_info *vi; // [esp+10h] [ebp-4h]
  codec_setup_info *ci; // [esp+18h] [ebp+4h]

  if ( !vb )
  {
    vd = 0;
    goto LABEL_6;
  }
  vd = vb->vd;
  if ( !vd )
  {
LABEL_6:
    mode = 0;
    vi = 0;
    v4 = 0;
    goto LABEL_7;
  }
  mode = (int)vd->backend_state;
  v4 = vd->vi;
  vi = v4;
  if ( v4 )
  {
    ci = (codec_setup_info *)v4->codec_setup;
    goto LABEL_8;
  }
LABEL_7:
  ci = 0;
LABEL_8:
  if ( vb )
    p_opb = &vb->opb;
  else
    p_opb = 0;
  if ( !vd || !mode || !v4 || !ci || !p_opb )
    return -136;
  _vorbis_block_ripcord(vb);
  oggpack_readinit(p_opb, op->packet, op->bytes);
  if ( oggpack_read(p_opb, 1u) )
    return -135;
  v7 = oggpack_read(p_opb, *(_DWORD *)(mode + 44));
  modea = v7;
  if ( v7 == -1 )
    return -136;
  vb->mode = v7;
  p_blockflag = &ci->mode_param[v7]->blockflag;
  if ( !p_blockflag )
    return -136;
  v9 = *p_blockflag;
  vb->W = v9;
  if ( v9 )
  {
    vb->lW = oggpack_read(p_opb, 1u);
    v10 = oggpack_read(p_opb, 1u);
    vb->nW = v10;
    if ( v10 == -1 )
      return -136;
  }
  else
  {
    vb->lW = 0;
    vb->nW = 0;
  }
  vb->granulepos = op->granulepos;
  LODWORD(vb->sequence) = op->packetno;
  W = vb->W;
  HIDWORD(vb->sequence) = HIDWORD(op->packetno);
  vb->eofflag = op->e_o_s;
  vb->pcmend = ci->blocksizes[W];
  v12 = 0;
  for ( vb->pcm = (float **)_vorbis_block_alloc(vb, 4 * vi->channels); v12 < vi->channels; ++v12 )
    vb->pcm[v12] = (float *)_vorbis_block_alloc(vb, 4 * vb->pcmend);
  mapping = ci->mode_param[modea]->mapping;
  return _mapping_P[ci->map_type[mapping]]->inverse(vb, ci->map_param[mapping]);
}
