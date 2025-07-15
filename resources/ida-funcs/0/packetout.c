int __usercall packetout@<eax>(ogg_stream_state *os@<eax>, ogg_packet *op@<esi>, int adv)
{
  int lacing_returned; // ebx
  int *v5; // ebp
  bool v6; // cf
  int v7; // edi
  int v8; // edx
  int v9; // edx
  int eos; // [esp+4h] [ebp-8h]
  int bos; // [esp+8h] [ebp-4h]

  lacing_returned = os->lacing_returned;
  if ( os->lacing_packet <= lacing_returned )
    return 0;
  v5 = &os->lacing_vals[lacing_returned];
  if ( (*v5 & 0x400) != 0 )
  {
    v6 = __CFADD__(LODWORD(os->packetno)++, 1);
    os->lacing_returned = lacing_returned + 1;
    HIDWORD(os->packetno) += v6;
    return -1;
  }
  else
  {
    if ( op || adv )
    {
      v7 = (unsigned __int8)*v5;
      v8 = *v5 & 0x200;
      eos = v8;
      bos = *v5 & 0x100;
      if ( v7 == 255 )
      {
        do
        {
          v9 = v5[1];
          ++v5;
          ++lacing_returned;
          if ( (v9 & 0x200) != 0 )
            eos = 512;
          v7 += (unsigned __int8)v9;
        }
        while ( (unsigned __int8)v9 == 255 );
        v8 = eos;
      }
      if ( op )
      {
        op->e_o_s = v8;
        op->b_o_s = bos;
        op->packet = &os->body_data[os->body_returned];
        op->packetno = os->packetno;
        op->granulepos = os->granule_vals[lacing_returned];
        op->bytes = v7;
      }
      if ( adv )
      {
        os->body_returned += v7;
        v6 = __CFADD__(LODWORD(os->packetno)++, 1);
        os->lacing_returned = lacing_returned + 1;
        HIDWORD(os->packetno) += v6;
      }
    }
    return 1;
  }
}
