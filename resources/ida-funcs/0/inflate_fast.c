void __cdecl inflate_fast(z_stream_s *strm, unsigned int start)
{
  internal_state *v2; // eax
  unsigned int dummy; // ebx
  unsigned __int8 *v4; // ebp
  unsigned __int8 *v5; // esi
  unsigned int v6; // edi
  int v7; // edx
  int v8; // eax
  code v9; // eax
  unsigned __int8 op; // dl
  unsigned int v11; // edx
  int v12; // eax
  int v13; // edx
  unsigned __int8 *v14; // ebp
  int v15; // eax
  code v16; // edx
  unsigned __int8 v17; // al
  unsigned int v18; // eax
  int v19; // edx
  int v20; // edx
  int v21; // edx
  unsigned int v22; // edx
  char v23; // cl
  int v24; // eax
  unsigned int v25; // ebp
  unsigned __int8 *v26; // ecx
  unsigned __int8 *v27; // ecx
  unsigned __int8 v28; // al
  unsigned int v29; // edx
  unsigned int v30; // ebp
  unsigned __int8 v31; // dl
  unsigned int v32; // ebp
  unsigned __int8 v33; // al
  unsigned __int8 v34; // al
  unsigned int v35; // ebp
  unsigned __int8 v36; // al
  unsigned __int8 *v37; // ecx
  unsigned __int8 *v38; // esi
  unsigned __int8 v39; // dl
  unsigned __int8 v40; // al
  unsigned __int8 v41; // dl
  unsigned __int8 *v42; // ecx
  unsigned __int8 *v43; // edx
  unsigned __int8 *v44; // eax
  unsigned __int8 v45; // cl
  unsigned __int8 *v46; // eax
  char v47; // dl
  _BYTE *v48; // esi
  unsigned __int8 v49; // cl
  unsigned int v50; // ecx
  unsigned __int8 v51; // dl
  unsigned __int8 *v52; // eax
  unsigned __int8 *v53; // ebp
  unsigned int v54; // edi
  unsigned __int8 *in; // [esp+10h] [ebp-3Ch]
  unsigned __int8 *last; // [esp+14h] [ebp-38h]
  inflate_state *state; // [esp+18h] [ebp-34h]
  unsigned int dist; // [esp+1Ch] [ebp-30h]
  unsigned int dista; // [esp+1Ch] [ebp-30h]
  unsigned __int16 dist_2; // [esp+1Eh] [ebp-2Eh]
  const code *lcode; // [esp+20h] [ebp-2Ch]
  const code *dcode; // [esp+24h] [ebp-28h]
  unsigned int wsize; // [esp+28h] [ebp-24h]
  unsigned __int8 *end; // [esp+2Ch] [ebp-20h]
  unsigned int dmask; // [esp+30h] [ebp-1Ch]
  unsigned __int8 *beg; // [esp+38h] [ebp-14h]
  unsigned int whave; // [esp+3Ch] [ebp-10h]
  unsigned __int8 *window; // [esp+40h] [ebp-Ch]
  unsigned int write; // [esp+44h] [ebp-8h]
  unsigned int lmask; // [esp+48h] [ebp-4h]
  unsigned int len; // [esp+54h] [ebp+8h]

  v2 = strm->state;
  dummy = v2[14].dummy;
  v4 = strm->next_in - 1;
  last = &v4[strm->avail_in - 5];
  v5 = strm->next_out - 1;
  beg = &v5[strm->avail_out - start];
  end = &v5[strm->avail_out - 257];
  wsize = v2[10].dummy;
  whave = v2[11].dummy;
  write = v2[12].dummy;
  window = (unsigned __int8 *)v2[13].dummy;
  lcode = (const code *)v2[19].dummy;
  dcode = (const code *)v2[20].dummy;
  state = (inflate_state *)v2;
  v6 = v2[15].dummy;
  v7 = (1 << v2[21].dummy) - 1;
  in = v4;
  lmask = v7;
  dmask = (1 << v2[22].dummy) - 1;
  while ( 1 )
  {
    if ( v6 < 0xF )
    {
      v8 = v4[1];
      v4 += 2;
      in = v4;
      dummy += (*v4 << (v6 + 8)) + (v8 << v6);
      v6 += 16;
    }
    v9 = lcode[dummy & v7];
    op = v9.op;
    dummy >>= v9.bits;
    v6 -= v9.bits;
    if ( !v9.op )
    {
LABEL_8:
      *++v5 = v9.val;
      goto LABEL_47;
    }
    while ( (op & 0x10) == 0 )
    {
      if ( (op & 0x40) != 0 )
      {
        if ( (op & 0x20) != 0 )
        {
          state->mode = TYPE;
          goto LABEL_61;
        }
        strm->msg = "invalid literal/length code";
LABEL_60:
        state->mode = BAD;
        goto LABEL_61;
      }
      v9 = lcode[HIWORD(*(unsigned int *)&v9) + (dummy & ((1 << op) - 1))];
      op = v9.op;
      dummy >>= v9.bits;
      v6 -= v9.bits;
      if ( !v9.op )
        goto LABEL_8;
    }
    v11 = op & 0xF;
    len = HIWORD(*(unsigned int *)&v9);
    if ( v11 )
    {
      if ( v6 < v11 )
      {
        v12 = *++v4;
        in = v4;
        dummy += v12 << v6;
        v6 += 8;
      }
      len += dummy & ((1 << v11) - 1);
      dummy >>= v11;
      v6 -= v11;
    }
    if ( v6 < 0xF )
    {
      v13 = v4[1];
      v14 = v4 + 1;
      v15 = v14[1];
      v4 = v14 + 1;
      in = v4;
      dummy += (v15 << (v6 + 8)) + (v13 << v6);
      v6 += 16;
    }
    v16 = dcode[dummy & dmask];
    v17 = v16.op;
    dummy >>= v16.bits;
    v6 -= v16.bits;
    dist_2 = v16.val;
    if ( (v16.op & 0x10) == 0 )
    {
      while ( (v17 & 0x40) == 0 )
      {
        v16 = dcode[dist_2 + (dummy & ((1 << v17) - 1))];
        v17 = v16.op;
        dummy >>= v16.bits;
        v6 -= v16.bits;
        dist_2 = v16.val;
        if ( (v16.op & 0x10) != 0 )
          goto LABEL_18;
      }
      strm->msg = "invalid distance code";
      goto LABEL_60;
    }
LABEL_18:
    v18 = v17 & 0xF;
    dist = HIWORD(*(unsigned int *)&v16);
    if ( v6 < v18 )
    {
      v19 = *++v4;
      v20 = v19 << v6;
      v6 += 8;
      in = v4;
      dummy += v20;
      if ( v6 < v18 )
      {
        v21 = *++v4;
        in = v4;
        dummy += v21 << v6;
        v6 += 8;
      }
    }
    v6 -= v18;
    v22 = (dummy & ((1 << v18) - 1)) + dist;
    v23 = v18;
    v24 = v5 - beg;
    dummy >>= v23;
    dista = v22;
    if ( v22 > v5 - beg )
    {
      v25 = v22 - v24;
      if ( v22 - v24 > whave )
      {
        v4 = in;
        strm->msg = "invalid distance too far back";
        state->mode = BAD;
LABEL_61:
        v43 = last;
        break;
      }
      v26 = window - 1;
      if ( write )
      {
        if ( write < v25 )
        {
          v29 = wsize + write - v25;
          v30 = v25 - write;
          v27 = &v26[v29];
          if ( v30 < len )
          {
            len -= v30;
            do
            {
              v31 = *++v27;
              ++v5;
              --v30;
              *v5 = v31;
            }
            while ( v30 );
            v27 = window - 1;
            if ( write < len )
            {
              len -= write;
              v32 = write;
              do
              {
                v33 = *++v27;
                ++v5;
                --v32;
                *v5 = v33;
              }
              while ( v32 );
              v27 = &v5[-dista];
            }
          }
          goto LABEL_40;
        }
        v27 = &v26[write - v25];
        if ( v25 < len )
        {
          len -= v25;
          do
          {
            v34 = *++v27;
            ++v5;
            --v25;
            *v5 = v34;
          }
          while ( v25 );
          goto LABEL_39;
        }
      }
      else
      {
        v27 = &v26[wsize - v25];
        if ( v25 < len )
        {
          len -= v25;
          do
          {
            v28 = *++v27;
            ++v5;
            --v25;
            *v5 = v28;
          }
          while ( v25 );
LABEL_39:
          v27 = &v5[-v22];
        }
      }
LABEL_40:
      if ( len > 2 )
      {
        v35 = (len - 3) / 3 + 1;
        do
        {
          v36 = v27[1];
          len -= 3;
          v37 = v27 + 1;
          v38 = v5 + 1;
          *v38 = v36;
          v39 = *++v37;
          *++v38 = v39;
          v40 = v37[1];
          v27 = v37 + 1;
          v5 = v38 + 1;
          --v35;
          *v5 = v40;
        }
        while ( v35 );
      }
      if ( len )
      {
        v41 = v27[1];
        v42 = v27 + 1;
        *++v5 = v41;
        if ( len > 1 )
          *++v5 = v42[1];
      }
      v4 = in;
      goto LABEL_47;
    }
    v44 = &v5[-v22];
    do
    {
      v45 = v44[1];
      v46 = v44 + 1;
      v5[1] = v45;
      v47 = *++v46;
      v48 = v5 + 2;
      *v48 = v47;
      v49 = v46[1];
      v44 = v46 + 1;
      v5 = v48 + 1;
      *v5 = v49;
      v50 = len - 3;
      len = v50;
    }
    while ( v50 > 2 );
    if ( v50 )
    {
      v51 = v44[1];
      v52 = v44 + 1;
      *++v5 = v51;
      if ( v50 > 1 )
        *++v5 = v52[1];
    }
LABEL_47:
    v43 = last;
    if ( v4 >= last || v5 >= end )
      break;
    v7 = lmask;
  }
  v53 = &v4[-(v6 >> 3)];
  v54 = v6 - 8 * (v6 >> 3);
  strm->next_in = v53 + 1;
  strm->next_out = v5 + 1;
  strm->avail_out = end - v5 + 257;
  strm->avail_in = v43 - v53 + 5;
  state->bits = v54;
  state->hold = ((1 << v54) - 1) & dummy;
}
