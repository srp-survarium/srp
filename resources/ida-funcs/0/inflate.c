int __cdecl inflate(z_stream_s *strm, int flush)
{
  z_stream_s *v2; // edx
  internal_state *state; // edi
  unsigned __int8 *next_out; // eax
  unsigned int dummy; // ebx
  __m128i *next_in; // ebp
  int v7; // ecx
  unsigned int avail_in; // eax
  unsigned int v9; // esi
  int result; // eax
  int v11; // edx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  int v15; // edx
  int *v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // ecx
  unsigned int v24; // ecx
  int v25; // edx
  unsigned int v26; // edx
  unsigned int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // edx
  int v30; // ecx
  unsigned int v31; // edx
  int v32; // ecx
  unsigned int v33; // ecx
  unsigned int v34; // edx
  int v35; // ecx
  unsigned int v36; // edx
  int v37; // ecx
  int v38; // edx
  int v39; // eax
  unsigned int v40; // eax
  int v41; // edx
  unsigned int v42; // ecx
  unsigned int v43; // eax
  int v44; // ecx
  int v45; // edx
  int v46; // ecx
  unsigned int v47; // ebx
  unsigned int v48; // esi
  int v49; // ecx
  int v50; // edx
  int v51; // ecx
  unsigned int v52; // ecx
  int v53; // edx
  int v54; // ecx
  unsigned int v55; // ebx
  char v56; // dl
  unsigned int v57; // edx
  int v58; // ecx
  bool v59; // cc
  int v60; // edx
  code v61; // ecx
  int v62; // edx
  int v63; // edx
  int v64; // ecx
  code bits; // ecx
  int v66; // edx
  int v67; // ecx
  int v68; // ecx
  int v69; // edx
  unsigned int v70; // ebx
  int v71; // edx
  int v72; // edx
  unsigned int v73; // ebx
  int v74; // edx
  __int16 v75; // cx
  unsigned int v76; // edx
  int v77; // ecx
  unsigned __int8 *v78; // ecx
  unsigned int v79; // edx
  unsigned int avail_out; // edx
  code v81; // edx
  int v82; // edx
  int v83; // edx
  unsigned int v84; // ecx
  int v85; // edx
  int v86; // ecx
  code v87; // edx
  int v88; // edx
  int v89; // edx
  unsigned int v90; // ecx
  int v91; // edx
  int v92; // ecx
  unsigned int v93; // ecx
  unsigned int v94; // ecx
  unsigned int v95; // edx
  code v96; // edx
  unsigned int v97; // edx
  unsigned __int8 *v98; // edx
  unsigned __int8 *v99; // ecx
  bool v100; // zf
  unsigned __int8 *v101; // ecx
  int v102; // edx
  unsigned int v103; // ecx
  unsigned int v104; // eax
  int v105; // ecx
  int v106; // edx
  unsigned int v107; // ebp
  unsigned int v108; // ebx
  unsigned int v109; // eax
  unsigned int v110; // [esp-18h] [ebp-48h]
  const unsigned __int8 *v111; // [esp-14h] [ebp-44h]
  unsigned int have; // [esp+4h] [ebp-2Ch]
  unsigned int this; // [esp+8h] [ebp-28h]
  unsigned int thisa; // [esp+8h] [ebp-28h]
  unsigned int thisb; // [esp+8h] [ebp-28h]
  unsigned int thisc; // [esp+8h] [ebp-28h]
  code thisd; // [esp+8h] [ebp-28h]
  code thise; // [esp+8h] [ebp-28h]
  code thisf; // [esp+8h] [ebp-28h]
  code thisg; // [esp+8h] [ebp-28h]
  code thish; // [esp+8h] [ebp-28h]
  code thisi; // [esp+8h] [ebp-28h]
  code thisj; // [esp+8h] [ebp-28h]
  unsigned int left; // [esp+Ch] [ebp-24h]
  unsigned __int8 hbuf[4]; // [esp+10h] [ebp-20h] BYREF
  unsigned int len; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *put; // [esp+18h] [ebp-18h]
  unsigned int out; // [esp+1Ch] [ebp-14h]
  code last; // [esp+20h] [ebp-10h]
  int ret; // [esp+24h] [ebp-Ch]
  unsigned int v131; // [esp+28h] [ebp-8h]
  unsigned int in; // [esp+2Ch] [ebp-4h]

  v2 = strm;
  if ( !strm )
    return -2;
  state = strm->state;
  if ( !state || !strm->next_out || !strm->next_in && strm->avail_in )
    return -2;
  if ( state->dummy == 11 )
    state->dummy = 12;
  next_out = strm->next_out;
  dummy = state[14].dummy;
  next_in = (__m128i *)strm->next_in;
  left = strm->avail_out;
  out = left;
  v7 = state->dummy;
  put = next_out;
  avail_in = strm->avail_in;
  v9 = state[15].dummy;
  have = avail_in;
  in = avail_in;
  ret = 0;
  while ( 2 )
  {
    switch ( v7 )
    {
      case 0:
        if ( !state[2].dummy )
        {
          state->dummy = 12;
          goto LABEL_297;
        }
        for ( ; v9 < 0x10; have = avail_in )
        {
          if ( !avail_in )
            goto inf_leave;
          v11 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v11;
        }
        if ( (state[2].dummy & 2) != 0 && dummy == 35615 )
        {
          state[6].dummy = crc32(0, 0, 0);
          hbuf[0] = 31;
          hbuf[1] = -117;
          state[6].dummy = crc32(state[6].dummy, hbuf, 2u);
          avail_in = have;
          dummy = 0;
          v9 = 0;
          state->dummy = 1;
          goto LABEL_297;
        }
        v12 = state[8].dummy;
        state[4].dummy = 0;
        if ( v12 )
          *(_DWORD *)(v12 + 48) = -1;
        if ( (state[2].dummy & 1) == 0 || ((dummy >> 8) + ((unsigned __int8)dummy << 8)) % 0x1F )
        {
          avail_in = have;
          strm->msg = "incorrect header check";
          goto LABEL_296;
        }
        if ( (dummy & 0xF) != 8 )
        {
          strm->msg = "unknown compression method";
          avail_in = have;
          goto LABEL_296;
        }
        dummy >>= 4;
        v13 = (dummy & 0xF) + 8;
        v9 -= 4;
        if ( v13 > state[9].dummy )
        {
          avail_in = have;
          strm->msg = "invalid window size";
          goto LABEL_296;
        }
        state[5].dummy = 1 << v13;
        v14 = adler32(0, 0, 0);
        state[6].dummy = v14;
        strm->adler = v14;
        avail_in = have;
        state->dummy = ~BYTE1(dummy) & 2 | 9;
        dummy = 0;
        v9 = 0;
        goto LABEL_297;
      case 1:
        if ( v9 >= 0x10 )
          goto LABEL_34;
        do
        {
          if ( !avail_in )
            goto inf_leave;
          v15 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v15;
          have = avail_in;
        }
        while ( v9 < 0x10 );
LABEL_34:
        state[4].dummy = dummy;
        if ( (_BYTE)dummy != 8 )
        {
          strm->msg = "unknown compression method";
          goto LABEL_296;
        }
        if ( (dummy & 0xE000) != 0 )
        {
          strm->msg = "unknown header flags set";
          goto LABEL_296;
        }
        v16 = (int *)state[8].dummy;
        if ( v16 )
          *v16 = (dummy >> 8) & 1;
        if ( (state[4].dummy & 0x200) != 0 )
        {
          hbuf[0] = 8;
          hbuf[1] = BYTE1(dummy);
          state[6].dummy = crc32(state[6].dummy, hbuf, 2u);
          avail_in = have;
        }
        dummy = 0;
        v9 = 0;
        state->dummy = 2;
        do
        {
LABEL_44:
          if ( !avail_in )
            goto inf_leave;
          v17 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v17;
          have = avail_in;
        }
        while ( v9 < 0x20 );
LABEL_46:
        v18 = state[8].dummy;
        if ( v18 )
          *(_DWORD *)(v18 + 4) = dummy;
        if ( (state[4].dummy & 0x200) != 0 )
        {
          *(_DWORD *)hbuf = dummy;
          state[6].dummy = crc32(state[6].dummy, hbuf, 4u);
          avail_in = have;
        }
        dummy = 0;
        v9 = 0;
        state->dummy = 3;
        do
        {
LABEL_52:
          if ( !avail_in )
            goto inf_leave;
          v19 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v19;
          have = avail_in;
        }
        while ( v9 < 0x10 );
LABEL_54:
        v20 = state[8].dummy;
        if ( v20 )
        {
          *(_DWORD *)(v20 + 8) = (unsigned __int8)dummy;
          *(_DWORD *)(state[8].dummy + 12) = dummy >> 8;
        }
        if ( (state[4].dummy & 0x200) != 0 )
        {
          *(_WORD *)hbuf = dummy;
          state[6].dummy = crc32(state[6].dummy, hbuf, 2u);
          avail_in = have;
        }
        dummy = 0;
        v9 = 0;
        state->dummy = 4;
$LN737:
        if ( (state[4].dummy & 0x400) != 0 )
        {
          if ( v9 < 0x10 )
          {
            while ( avail_in )
            {
              v21 = next_in->m128i_u8[0] << v9;
              --avail_in;
              v9 += 8;
              next_in = (__m128i *)((char *)next_in + 1);
              dummy += v21;
              have = avail_in;
              if ( v9 >= 0x10 )
                goto LABEL_63;
            }
            goto inf_leave;
          }
LABEL_63:
          v22 = state[8].dummy;
          state[16].dummy = dummy;
          if ( v22 )
            *(_DWORD *)(v22 + 20) = dummy;
          if ( (state[4].dummy & 0x200) != 0 )
          {
            *(_WORD *)hbuf = dummy;
            state[6].dummy = crc32(state[6].dummy, hbuf, 2u);
            avail_in = have;
          }
          dummy = 0;
          v9 = 0;
        }
        else
        {
          v23 = state[8].dummy;
          if ( v23 )
            *(_DWORD *)(v23 + 16) = 0;
        }
        state->dummy = 5;
$LN738_0:
        if ( (state[4].dummy & 0x400) != 0 )
        {
          v24 = state[16].dummy;
          this = v24;
          if ( v24 > avail_in )
          {
            v24 = avail_in;
            this = avail_in;
          }
          if ( v24 )
          {
            v25 = state[8].dummy;
            if ( v25 )
            {
              v131 = *(_DWORD *)(v25 + 16);
              if ( v131 )
              {
                v26 = *(_DWORD *)(state[8].dummy + 24);
                len = *(_DWORD *)(state[8].dummy + 20) - state[16].dummy;
                if ( v24 + len > v26 )
                  v24 = v26 - len;
                memcpy(len + v131, next_in, v24);
                v24 = this;
                avail_in = have;
              }
            }
            if ( (state[4].dummy & 0x200) != 0 )
            {
              v27 = crc32(state[6].dummy, (const unsigned __int8 *)next_in, this);
              v24 = this;
              state[6].dummy = v27;
              avail_in = have;
            }
            avail_in -= v24;
            next_in = (__m128i *)((char *)next_in + v24);
            state[16].dummy -= v24;
            have = avail_in;
          }
          if ( state[16].dummy )
            goto inf_leave;
        }
        state[16].dummy = 0;
        state->dummy = 6;
$LN739:
        if ( (state[4].dummy & 0x800) != 0 )
        {
          if ( !avail_in )
            goto inf_leave;
          v28 = 0;
          do
          {
            v29 = next_in->m128i_u8[v28];
            thisa = v28 + 1;
            v30 = state[8].dummy;
            len = v29;
            if ( v30 )
            {
              v131 = *(_DWORD *)(v30 + 28);
              if ( v131 )
              {
                v31 = state[16].dummy;
                if ( v31 < *(_DWORD *)(v30 + 32) )
                {
                  *(_BYTE *)(v131 + v31) = len;
                  ++state[16].dummy;
                  avail_in = have;
                }
              }
            }
            if ( !len )
              break;
            v28 = thisa;
          }
          while ( thisa < avail_in );
          if ( (state[4].dummy & 0x200) != 0 )
          {
            state[6].dummy = crc32(state[6].dummy, (const unsigned __int8 *)next_in, thisa);
            avail_in = have;
          }
          avail_in -= thisa;
          next_in = (__m128i *)((char *)next_in + thisa);
          have = avail_in;
          if ( len )
            goto inf_leave;
        }
        else
        {
          v32 = state[8].dummy;
          if ( v32 )
            *(_DWORD *)(v32 + 28) = 0;
        }
        state[16].dummy = 0;
        state->dummy = 7;
$LN741_0:
        if ( (state[4].dummy & 0x1000) != 0 )
        {
          if ( !avail_in )
            goto inf_leave;
          v33 = 0;
          do
          {
            v34 = next_in->m128i_u8[v33];
            thisb = v33 + 1;
            v35 = state[8].dummy;
            len = v34;
            if ( v35 )
            {
              v131 = *(_DWORD *)(v35 + 36);
              if ( v131 )
              {
                v36 = state[16].dummy;
                if ( v36 < *(_DWORD *)(v35 + 40) )
                {
                  *(_BYTE *)(v131 + v36) = len;
                  ++state[16].dummy;
                  avail_in = have;
                }
              }
            }
            if ( !len )
              break;
            v33 = thisb;
          }
          while ( thisb < avail_in );
          if ( (state[4].dummy & 0x200) != 0 )
          {
            state[6].dummy = crc32(state[6].dummy, (const unsigned __int8 *)next_in, thisb);
            avail_in = have;
          }
          avail_in -= thisb;
          next_in = (__m128i *)((char *)next_in + thisb);
          have = avail_in;
          if ( len )
            goto inf_leave;
        }
        else
        {
          v37 = state[8].dummy;
          if ( v37 )
            *(_DWORD *)(v37 + 36) = 0;
        }
        state->dummy = 8;
$LN743_0:
        if ( (state[4].dummy & 0x200) != 0 )
        {
          if ( v9 < 0x10 )
          {
            while ( avail_in )
            {
              v38 = next_in->m128i_u8[0] << v9;
              --avail_in;
              v9 += 8;
              next_in = (__m128i *)((char *)next_in + 1);
              dummy += v38;
              have = avail_in;
              if ( v9 >= 0x10 )
                goto LABEL_121;
            }
            goto inf_leave;
          }
LABEL_121:
          if ( dummy != LOWORD(state[6].dummy) )
          {
            strm->msg = "header crc mismatch";
            goto LABEL_296;
          }
          dummy = 0;
          v9 = 0;
        }
        v39 = state[8].dummy;
        if ( v39 )
        {
          *(_DWORD *)(v39 + 44) = (state[4].dummy >> 9) & 1;
          *(_DWORD *)(state[8].dummy + 48) = 1;
        }
        v40 = crc32(0, 0, 0);
        state[6].dummy = v40;
        strm->adler = v40;
        avail_in = have;
        state->dummy = 11;
        goto LABEL_297;
      case 2:
        if ( v9 < 0x20 )
          goto LABEL_44;
        goto LABEL_46;
      case 3:
        if ( v9 < 0x10 )
          goto LABEL_52;
        goto LABEL_54;
      case 4:
        goto $LN737;
      case 5:
        goto $LN738_0;
      case 6:
        goto $LN739;
      case 7:
        goto $LN741_0;
      case 8:
        goto $LN743_0;
      case 9:
        if ( v9 >= 0x20 )
          goto LABEL_130;
        do
        {
          if ( !avail_in )
            goto inf_leave;
          v41 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v41;
          have = avail_in;
        }
        while ( v9 < 0x20 );
LABEL_130:
        v2 = strm;
        v42 = HIBYTE(dummy) + ((dummy >> 8) & 0xFF00) + (((dummy << 16) + (dummy & 0xFF00)) << 8);
        state[6].dummy = v42;
        strm->adler = v42;
        dummy = 0;
        v9 = 0;
        state->dummy = 10;
$LN317_0:
        if ( !state[3].dummy )
        {
          v2->next_out = put;
          v2->next_in = (unsigned __int8 *)next_in;
          v2->avail_in = avail_in;
          v2->avail_out = left;
          state[15].dummy = v9;
          state[14].dummy = dummy;
          return 2;
        }
        v43 = adler32(0, 0, 0);
        state[6].dummy = v43;
        strm->adler = v43;
        avail_in = have;
        state->dummy = 11;
$LN312_1:
        if ( flush == 5 )
          goto inf_leave;
$LN311_1:
        if ( state[1].dummy )
        {
          v44 = v9 & 7;
          dummy >>= v44;
          v9 -= v44;
          state->dummy = 24;
        }
        else
        {
          if ( v9 < 3 )
          {
            while ( avail_in )
            {
              v45 = next_in->m128i_u8[0] << v9;
              --avail_in;
              v9 += 8;
              next_in = (__m128i *)((char *)next_in + 1);
              dummy += v45;
              have = avail_in;
              if ( v9 >= 3 )
                goto LABEL_139;
            }
            goto inf_leave;
          }
LABEL_139:
          v46 = dummy & 1;
          v47 = dummy >> 1;
          state[1].dummy = v46;
          v48 = v9 - 1;
          switch ( v47 & 3 )
          {
            case 0u:
              dummy = v47 >> 2;
              state->dummy = 13;
              v9 = v48 - 2;
              break;
            case 1u:
              dummy = v47 >> 2;
              state[19].dummy = (int)"`\a";
              state[21].dummy = 9;
              state[20].dummy = (int)&unk_730680;
              state[22].dummy = 5;
              state->dummy = 18;
              v9 = v48 - 2;
              break;
            case 2u:
              dummy = v47 >> 2;
              state->dummy = 15;
              v9 = v48 - 2;
              break;
            case 3u:
              strm->msg = "invalid block type";
              state->dummy = 27;
              goto LABEL_144;
            default:
LABEL_144:
              dummy = v47 >> 2;
              v9 = v48 - 2;
              break;
          }
        }
        goto LABEL_297;
      case 10:
        goto $LN317_0;
      case 11:
        goto $LN312_1;
      case 12:
        goto $LN311_1;
      case 13:
        v49 = v9 & 7;
        v9 -= v49;
        dummy >>= v49;
        if ( v9 >= 0x20 )
          goto LABEL_148;
        do
        {
          if ( !avail_in )
            goto inf_leave;
          v50 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v50;
          have = avail_in;
        }
        while ( v9 < 0x20 );
LABEL_148:
        v51 = (unsigned __int16)dummy;
        if ( (unsigned __int16)dummy != ~dummy >> 16 )
        {
          strm->msg = "invalid stored block lengths";
          goto LABEL_296;
        }
        dummy = 0;
        state[16].dummy = v51;
        v9 = 0;
        state->dummy = 14;
$LN744_1:
        v52 = state[16].dummy;
        thisc = v52;
        if ( !v52 )
          goto LABEL_228;
        if ( v52 > avail_in )
        {
          v52 = avail_in;
          thisc = avail_in;
        }
        if ( v52 > left )
        {
          v52 = left;
          thisc = left;
        }
        if ( !v52 )
          goto inf_leave;
        memcpy((int)put, next_in, thisc);
        have -= thisc;
        left -= thisc;
        put += thisc;
        next_in = (__m128i *)((char *)next_in + thisc);
        state[16].dummy -= thisc;
        avail_in = have;
        goto LABEL_297;
      case 14:
        goto $LN744_1;
      case 15:
        if ( v9 >= 0xE )
          goto LABEL_161;
        do
        {
          if ( !avail_in )
            goto inf_leave;
          v53 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v53;
          have = avail_in;
        }
        while ( v9 < 0xE );
LABEL_161:
        v54 = dummy & 0x1F;
        v55 = dummy >> 5;
        v56 = v55;
        state[24].dummy = v54 + 257;
        v55 >>= 5;
        v57 = (v56 & 0x1F) + 1;
        v58 = (v55 & 0xF) + 4;
        dummy = v55 >> 4;
        v9 -= 14;
        v59 = state[24].dummy <= 0x11Eu;
        state[25].dummy = v57;
        state[23].dummy = v58;
        if ( !v59 || v57 > 0x1E )
        {
          strm->msg = "too many length or distance symbols";
          goto LABEL_296;
        }
        state[26].dummy = 0;
        state->dummy = 16;
$LN519_1:
        if ( state[26].dummy < (unsigned int)state[23].dummy )
        {
          while ( v9 >= 3 )
          {
LABEL_168:
            *((_WORD *)&state[28].dummy + order[state[26].dummy++]) = dummy & 7;
            dummy >>= 3;
            v9 -= 3;
            if ( state[26].dummy >= (unsigned int)state[23].dummy )
              goto LABEL_169;
          }
          while ( avail_in )
          {
            v60 = next_in->m128i_u8[0] << v9;
            --avail_in;
            v9 += 8;
            next_in = (__m128i *)((char *)next_in + 1);
            dummy += v60;
            have = avail_in;
            if ( v9 >= 3 )
              goto LABEL_168;
          }
          goto inf_leave;
        }
LABEL_169:
        while ( state[26].dummy < 0x13u )
          *((_WORD *)&state[28].dummy + order[state[26].dummy++]) = 0;
        state[27].dummy = (int)&state[332];
        state[19].dummy = (int)&state[332];
        state[21].dummy = 7;
        ret = inflate_table(
                CODES,
                (unsigned __int16 *)&state[28],
                0x13u,
                (code **)&state[27],
                (unsigned int *)&state[21],
                (unsigned __int16 *)&state[188]);
        avail_in = have;
        if ( ret )
        {
          strm->msg = "invalid code lengths set";
          goto LABEL_296;
        }
        state[26].dummy = 0;
        state->dummy = 17;
$LN745:
        if ( state[26].dummy < (unsigned int)(state[24].dummy + state[25].dummy) )
        {
          while ( 1 )
          {
            v61 = *(code *)(state[19].dummy + 4 * (dummy & ((1 << state[21].dummy) - 1)));
            thisd = v61;
            if ( v61.bits > v9 )
              break;
LABEL_179:
            if ( HIWORD(*(unsigned int *)&v61) >= 0x10u )
            {
              bits = (code)v61.bits;
              last = bits;
              if ( thisd.val == 16 )
              {
                if ( v9 < *(_DWORD *)&bits + 2 )
                {
                  while ( avail_in )
                  {
                    v66 = next_in->m128i_u8[0] << v9;
                    bits = last;
                    --avail_in;
                    v9 += 8;
                    dummy += v66;
                    next_in = (__m128i *)((char *)next_in + 1);
                    have = avail_in;
                    if ( v9 >= *(_DWORD *)&last + 2 )
                      goto LABEL_188;
                  }
                  goto inf_leave;
                }
LABEL_188:
                dummy >>= bits.op;
                v9 -= *(_DWORD *)&bits;
                v67 = state[26].dummy;
                if ( !v67 )
                {
                  strm->msg = "invalid bit length repeat";
                  goto LABEL_296;
                }
                len = *((unsigned __int16 *)&state[27].dummy + v67 + 1);
                v68 = (dummy & 3) + 3;
                dummy >>= 2;
                thise = (code)v68;
                v9 -= 2;
              }
              else
              {
                if ( thisd.val == 17 )
                {
                  if ( v9 < *(_DWORD *)&bits + 3 )
                  {
                    while ( avail_in )
                    {
                      v69 = next_in->m128i_u8[0] << v9;
                      bits = last;
                      --avail_in;
                      v9 += 8;
                      dummy += v69;
                      next_in = (__m128i *)((char *)next_in + 1);
                      have = avail_in;
                      if ( v9 >= *(_DWORD *)&last + 3 )
                        goto LABEL_194;
                    }
                    goto inf_leave;
                  }
LABEL_194:
                  v70 = dummy >> bits.op;
                  thise = (code)((v70 & 7) + 3);
                  dummy = v70 >> 3;
                  v71 = -3;
                }
                else
                {
                  if ( v9 < *(_DWORD *)&bits + 7 )
                  {
                    while ( avail_in )
                    {
                      v72 = next_in->m128i_u8[0] << v9;
                      bits = last;
                      --avail_in;
                      v9 += 8;
                      dummy += v72;
                      next_in = (__m128i *)((char *)next_in + 1);
                      have = avail_in;
                      if ( v9 >= *(_DWORD *)&last + 7 )
                        goto LABEL_198;
                    }
                    goto inf_leave;
                  }
LABEL_198:
                  v73 = dummy >> bits.op;
                  thise = (code)((v73 & 0x7F) + 11);
                  dummy = v73 >> 7;
                  v71 = -7;
                }
                v74 = v71 - *(_DWORD *)&bits;
                v68 = (int)thise;
                v9 += v74;
                len = 0;
              }
              if ( v68 + state[26].dummy > (unsigned int)(state[24].dummy + state[25].dummy) )
              {
                strm->msg = "invalid bit length repeat";
                goto LABEL_296;
              }
              if ( thise )
              {
                v75 = len;
                do
                {
                  --*(_DWORD *)&thise;
                  *((_WORD *)&state[28].dummy + state[26].dummy++) = v75;
                }
                while ( thise );
              }
            }
            else
            {
              if ( v9 < v61.bits )
              {
                while ( avail_in )
                {
                  v63 = next_in->m128i_u8[0] << v9;
                  v61.bits = thisd.bits;
                  --avail_in;
                  v9 += 8;
                  dummy += v63;
                  next_in = (__m128i *)((char *)next_in + 1);
                  have = avail_in;
                  if ( v9 >= thisd.bits )
                    goto LABEL_183;
                }
                goto inf_leave;
              }
LABEL_183:
              v64 = v61.bits;
              dummy >>= v64;
              v9 -= v64;
              *((_WORD *)&state[28].dummy + state[26].dummy++) = thisd.val;
            }
            if ( state[26].dummy >= (unsigned int)(state[24].dummy + state[25].dummy) )
              goto LABEL_205;
          }
          while ( avail_in )
          {
            v62 = next_in->m128i_u8[0] << v9;
            --avail_in;
            v9 += 8;
            dummy += v62;
            next_in = (__m128i *)((char *)next_in + 1);
            have = avail_in;
            v61 = *(code *)(state[19].dummy + 4 * (dummy & ((1 << state[21].dummy) - 1)));
            thisd = v61;
            if ( v61.bits <= v9 )
              goto LABEL_179;
          }
          goto inf_leave;
        }
LABEL_205:
        if ( state->dummy == 27 )
          goto LABEL_297;
        state[27].dummy = (int)&state[332];
        state[19].dummy = (int)&state[332];
        v76 = state[24].dummy;
        state[21].dummy = 9;
        ret = inflate_table(
                LENS,
                (unsigned __int16 *)&state[28],
                v76,
                (code **)&state[27],
                (unsigned int *)&state[21],
                (unsigned __int16 *)&state[188]);
        if ( ret )
        {
          avail_in = have;
          strm->msg = "invalid literal/lengths set";
          goto LABEL_296;
        }
        state[20].dummy = state[27].dummy;
        v77 = state[24].dummy;
        state[22].dummy = 6;
        ret = inflate_table(
                DISTS,
                (unsigned __int16 *)&state[28] + v77,
                state[25].dummy,
                (code **)&state[27],
                (unsigned int *)&state[22],
                (unsigned __int16 *)&state[188]);
        if ( ret )
        {
          strm->msg = "invalid distances set";
          avail_in = have;
          goto LABEL_296;
        }
        avail_in = have;
        state->dummy = 18;
$LN746:
        if ( avail_in >= 6 && left >= 0x102 )
        {
          v78 = put;
          strm->avail_out = left;
          v79 = out;
          strm->next_out = v78;
          strm->next_in = (unsigned __int8 *)next_in;
          strm->avail_in = have;
          state[14].dummy = dummy;
          state[15].dummy = v9;
          inflate_fast(strm, v79);
          avail_out = strm->avail_out;
          next_in = (__m128i *)strm->next_in;
          avail_in = strm->avail_in;
          dummy = state[14].dummy;
          v9 = state[15].dummy;
          put = strm->next_out;
          left = avail_out;
          have = avail_in;
          goto LABEL_297;
        }
        v81 = *(code *)(state[19].dummy + 4 * (dummy & ((1 << state[21].dummy) - 1)));
        thisf = v81;
        if ( v81.bits > v9 )
        {
          while ( avail_in )
          {
            v82 = next_in->m128i_u8[0] << v9;
            --avail_in;
            v9 += 8;
            dummy += v82;
            next_in = (__m128i *)((char *)next_in + 1);
            have = avail_in;
            v81 = *(code *)(state[19].dummy + 4 * (dummy & ((1 << state[21].dummy) - 1)));
            thisf = v81;
            if ( v81.bits <= v9 )
              goto LABEL_219;
          }
          goto inf_leave;
        }
LABEL_219:
        if ( v81.op && (v81.op & 0xF0) == 0 )
        {
          v131 = *(unsigned int *)&v81 >> 8;
          len = v81.bits;
          last = v81;
          thisg = *(code *)(state[19].dummy
                          + 4
                          * (HIWORD(*(unsigned int *)&thisf) + ((dummy & ((1 << (v81.bits + v81.op)) - 1)) >> v81.bits)));
          if ( v81.bits + (unsigned int)thisg.bits > v9 )
          {
            while ( avail_in )
            {
              v83 = next_in->m128i_u8[0] << v9;
              --avail_in;
              v9 += 8;
              dummy += v83;
              len = last.bits;
              next_in = (__m128i *)((char *)next_in + 1);
              have = avail_in;
              thisg = *(code *)(state[19].dummy
                              + 4 * (last.val + ((dummy & ((1 << (last.bits + last.op)) - 1)) >> last.bits)));
              if ( last.bits + (unsigned int)thisg.bits <= v9 )
                goto LABEL_224;
            }
            goto inf_leave;
          }
LABEL_224:
          v81 = thisg;
          dummy >>= last.bits;
          v9 -= last.bits;
        }
        dummy >>= v81.bits;
        v9 -= v81.bits;
        len = v81.bits;
        state[16].dummy = HIWORD(*(unsigned int *)&v81);
        if ( !v81.op )
        {
          state->dummy = 23;
          goto LABEL_297;
        }
        if ( (v81.op & 0x20) != 0 )
        {
LABEL_228:
          state->dummy = 11;
          goto LABEL_297;
        }
        if ( (v81.op & 0x40) != 0 )
        {
          strm->msg = "invalid literal/length code";
          goto LABEL_296;
        }
        state[18].dummy = v81.op & 0xF;
        state->dummy = 19;
$LN697:
        v84 = state[18].dummy;
        if ( v84 )
        {
          if ( v9 < v84 )
          {
            while ( avail_in )
            {
              v85 = next_in->m128i_u8[0] << v9;
              --avail_in;
              v9 += 8;
              next_in = (__m128i *)((char *)next_in + 1);
              dummy += v85;
              have = avail_in;
              if ( v9 >= state[18].dummy )
                goto LABEL_236;
            }
            goto inf_leave;
          }
LABEL_236:
          v86 = state[18].dummy;
          state[16].dummy += dummy & ((1 << v86) - 1);
          dummy >>= v86;
          v9 -= v86;
        }
        state->dummy = 20;
$LN698:
        v87 = *(code *)(state[20].dummy + 4 * (dummy & ((1 << state[22].dummy) - 1)));
        thish = v87;
        if ( v87.bits > v9 )
        {
          while ( avail_in )
          {
            v88 = next_in->m128i_u8[0] << v9;
            --avail_in;
            v9 += 8;
            dummy += v88;
            next_in = (__m128i *)((char *)next_in + 1);
            have = avail_in;
            v87 = *(code *)(state[20].dummy + 4 * (dummy & ((1 << state[22].dummy) - 1)));
            thish = v87;
            if ( v87.bits <= v9 )
              goto LABEL_241;
          }
          goto inf_leave;
        }
LABEL_241:
        if ( (v87.op & 0xF0) == 0 )
        {
          v131 = *(unsigned int *)&v87 >> 8;
          len = v87.bits;
          last = v87;
          thisi = *(code *)(state[20].dummy
                          + 4
                          * (HIWORD(*(unsigned int *)&thish) + ((dummy & ((1 << (v87.bits + v87.op)) - 1)) >> v87.bits)));
          if ( v87.bits + (unsigned int)thisi.bits > v9 )
          {
            while ( avail_in )
            {
              v89 = next_in->m128i_u8[0] << v9;
              --avail_in;
              v9 += 8;
              dummy += v89;
              len = last.bits;
              next_in = (__m128i *)((char *)next_in + 1);
              have = avail_in;
              thisi = *(code *)(state[20].dummy
                              + 4 * (last.val + ((dummy & ((1 << (last.bits + last.op)) - 1)) >> last.bits)));
              if ( last.bits + (unsigned int)thisi.bits <= v9 )
                goto LABEL_245;
            }
            goto inf_leave;
          }
LABEL_245:
          v87 = thisi;
          dummy >>= last.bits;
          v9 -= last.bits;
        }
        dummy >>= v87.bits;
        v9 -= v87.bits;
        len = v87.bits;
        if ( (v87.op & 0x40) != 0 )
        {
          strm->msg = "invalid distance code";
          goto LABEL_296;
        }
        state[17].dummy = HIWORD(*(unsigned int *)&v87);
        state[18].dummy = v87.op & 0xF;
        state->dummy = 21;
$LN699:
        v90 = state[18].dummy;
        if ( v90 )
        {
          if ( v9 < v90 )
          {
            while ( avail_in )
            {
              v91 = next_in->m128i_u8[0] << v9;
              --avail_in;
              v9 += 8;
              next_in = (__m128i *)((char *)next_in + 1);
              dummy += v91;
              have = avail_in;
              if ( v9 >= state[18].dummy )
                goto LABEL_253;
            }
            goto inf_leave;
          }
LABEL_253:
          v92 = state[18].dummy;
          state[17].dummy += dummy & ((1 << v92) - 1);
          dummy >>= v92;
          v9 -= v92;
        }
        if ( state[17].dummy > out + state[11].dummy - left )
        {
          strm->msg = "invalid distance too far back";
          goto LABEL_296;
        }
        state->dummy = 22;
$LN700:
        if ( !left )
          goto inf_leave;
        v93 = state[17].dummy;
        if ( v93 <= out - left )
        {
          v98 = &put[-v93];
          v94 = state[16].dummy;
          last = (code)v98;
          v131 = v94;
          goto LABEL_265;
        }
        v94 = v93 - (out - left);
        v95 = state[12].dummy;
        thisj = (code)v94;
        if ( v94 <= v95 )
        {
          v96 = (code)(state[12].dummy + state[13].dummy - v94);
        }
        else
        {
          v94 -= v95;
          thisj = (code)v94;
          v96 = (code)(state[10].dummy + state[13].dummy - v94);
        }
        last = v96;
        v97 = state[16].dummy;
        v131 = v97;
        if ( v94 > v97 )
        {
          v94 = v97;
LABEL_265:
          thisj = (code)v94;
        }
        if ( v94 > left )
        {
          v94 = left;
          thisj = (code)left;
        }
        left -= v94;
        state[16].dummy = v131 - v94;
        do
        {
          v99 = put;
          *put = *(_BYTE *)(*(_DWORD *)&last)++;
          v100 = (*(_DWORD *)&thisj)-- == 1;
          put = v99 + 1;
        }
        while ( !v100 );
        if ( !state[16].dummy )
          state->dummy = 18;
        goto LABEL_297;
      case 16:
        goto $LN519_1;
      case 17:
        goto $LN745;
      case 18:
        goto $LN746;
      case 19:
        goto $LN697;
      case 20:
        goto $LN698;
      case 21:
        goto $LN699;
      case 22:
        goto $LN700;
      case 23:
        if ( !left )
          goto inf_leave;
        v101 = put;
        *put = state[16].dummy;
        --left;
        put = v101 + 1;
        state->dummy = 18;
        goto LABEL_297;
      case 24:
        if ( !state[2].dummy )
          goto LABEL_288;
        if ( v9 >= 0x20 )
          goto LABEL_278;
        do
        {
          if ( !avail_in )
            goto inf_leave;
          v102 = next_in->m128i_u8[0] << v9;
          --avail_in;
          v9 += 8;
          next_in = (__m128i *)((char *)next_in + 1);
          dummy += v102;
          have = avail_in;
        }
        while ( v9 < 0x20 );
LABEL_278:
        v103 = out - left;
        strm->total_out += out - left;
        state[7].dummy += v103;
        out = v103;
        if ( v103 )
        {
          v111 = &put[-v103];
          v110 = state[6].dummy;
          if ( state[4].dummy )
            v104 = crc32(v110, v111, v103);
          else
            v104 = adler32(v110, v111, v103);
          state[6].dummy = v104;
          strm->adler = v104;
          avail_in = have;
        }
        v100 = state[4].dummy == 0;
        out = left;
        v105 = dummy;
        if ( v100 )
          v105 = HIBYTE(dummy) + ((dummy >> 8) & 0xFF00) + (((dummy << 16) + (dummy & 0xFF00)) << 8);
        if ( v105 != state[6].dummy )
        {
          strm->msg = "incorrect data check";
LABEL_296:
          state->dummy = 27;
LABEL_297:
          v7 = state->dummy;
          if ( state->dummy > 0x1Cu )
            return -2;
          v2 = strm;
          continue;
        }
        dummy = 0;
        v9 = 0;
LABEL_288:
        state->dummy = 25;
$LN748_0:
        if ( !state[2].dummy || !state[4].dummy )
          goto LABEL_301;
        if ( v9 < 0x20 )
        {
          while ( avail_in )
          {
            v106 = next_in->m128i_u8[0] << v9;
            --avail_in;
            v9 += 8;
            next_in = (__m128i *)((char *)next_in + 1);
            dummy += v106;
            have = avail_in;
            if ( v9 >= 0x20 )
              goto LABEL_294;
          }
          goto inf_leave;
        }
LABEL_294:
        if ( dummy != state[7].dummy )
        {
          strm->msg = "incorrect length check";
          goto LABEL_296;
        }
        dummy = 0;
        v9 = 0;
LABEL_301:
        state->dummy = 26;
$LN750_0:
        ret = 1;
inf_leave:
        strm->next_out = put;
        strm->avail_out = left;
        strm->next_in = (unsigned __int8 *)next_in;
        strm->avail_in = avail_in;
        v100 = state[10].dummy == 0;
        state[14].dummy = dummy;
        state[15].dummy = v9;
        if ( v100 && (state->dummy >= 24 || out == strm->avail_out) || !updatewindow(strm, out) )
        {
          v107 = in - strm->avail_in;
          v108 = out - strm->avail_out;
          strm->total_in += v107;
          strm->total_out += v108;
          state[7].dummy += v108;
          if ( state[2].dummy && v108 )
          {
            if ( state[4].dummy )
              v109 = crc32(state[6].dummy, &strm->next_out[-v108], v108);
            else
              v109 = adler32(state[6].dummy, &strm->next_out[-v108], v108);
            state[6].dummy = v109;
            strm->adler = v109;
          }
          strm->data_type = state[15].dummy + (state->dummy != 11 ? 0 : 0x80) + (state[1].dummy != 0 ? 0x40 : 0);
          if ( (v107 || v108) && flush != 4 )
          {
            return ret;
          }
          else
          {
            result = ret;
            if ( !ret )
              return -5;
          }
        }
        else
        {
          state->dummy = 28;
          return -4;
        }
        return result;
      case 25:
        goto $LN748_0;
      case 26:
        goto $LN750_0;
      case 27:
        ret = -3;
        goto inf_leave;
      case 28:
        return -4;
      default:
        return -2;
    }
  }
}
