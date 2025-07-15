int __usercall packetout@<eax>(ogg_stream_state *os@<eax>, ogg_packet *op@<ecx>, int adv)
{
  int lacing_returned; // esi
  int *v5; // edx
  int v6; // edi
  int v7; // ebx
  int *i; // edi
  int v9; // [esp+4h] [ebp-14h]
  int *v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]

  lacing_returned = os->lacing_returned;
  if ( os->lacing_packet <= lacing_returned )
    return 0;
  v5 = &os->lacing_vals[lacing_returned];
  if ( (*v5 & 0x400) != 0 )
  {
    os->lacing_returned = lacing_returned + 1;
    ++os->packetno;
    return -1;
  }
  else
  {
    if ( op || adv )
    {
      v12 = (unsigned __int8)*v5;
      v9 = *v5 & 0x100;
      v6 = v12;
      v7 = *v5 & 0x200;
      if ( v12 == 255 )
      {
        for ( i = &os->lacing_vals[lacing_returned]; ; i = v10 )
        {
          v10 = i + 1;
          ++lacing_returned;
          v11 = (unsigned __int8)i[1];
          if ( (i[1] & 0x200) != 0 )
            v7 = 512;
          v6 = v11 + v12;
          v12 += v11;
          if ( v11 != 255 )
            break;
        }
      }
      if ( op )
      {
        op->e_o_s = v7;
        op->b_o_s = v9;
        op->packet = &os->body_data[os->body_returned];
        op->packetno = os->packetno;
        op->granulepos = os->granule_vals[lacing_returned];
        op->bytes = v6;
      }
      if ( adv )
      {
        os->body_returned += v6;
        os->lacing_returned = lacing_returned + 1;
        ++os->packetno;
      }
    }
    return 1;
  }
}
