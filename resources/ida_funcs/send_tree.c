void __usercall send_tree(internal_state *s@<eax>, ct_data_s *tree@<edx>, int max_code@<ecx>)
{
  int v3; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // edx
  int dummy_high; // edi
  int dummy; // ecx
  unsigned __int16 v10; // si
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  __int16 v14; // si
  int v15; // ecx
  int v16; // ecx
  unsigned __int16 v17; // si
  int v18; // edi
  int v19; // ecx
  int v20; // ebx
  int v21; // ecx
  int v22; // ecx
  unsigned __int16 v23; // si
  int v24; // edi
  int v25; // ecx
  int v26; // ebx
  int v27; // ecx
  int v28; // esi
  int v29; // edi
  int v30; // ecx
  int v31; // ebx
  int v32; // ecx
  int v33; // ecx
  unsigned __int16 v34; // si
  int v35; // edi
  int v36; // ecx
  int v37; // ebx
  int v38; // ecx
  int v39; // esi
  int v40; // edi
  int v41; // ecx
  int v42; // ebx
  unsigned __int16 v43; // si
  int v44; // edi
  int v45; // ecx
  int v46; // ebx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  int v50; // ecx
  int v51; // ebx
  int count; // [esp+10h] [ebp-18h]
  int nextlen; // [esp+14h] [ebp-14h]
  $2467CA9704E0472D4CCF1296A763D23A *p_dl; // [esp+18h] [ebp-10h]
  int len; // [esp+1Ch] [ebp-Ch]
  int lena; // [esp+1Ch] [ebp-Ch]
  int lenb; // [esp+1Ch] [ebp-Ch]
  int lenc; // [esp+1Ch] [ebp-Ch]
  int lend; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int curlen; // [esp+24h] [ebp-4h]

  v3 = 0;
  len = -1;
  nextlen = tree->dl.dad;
  v5 = 7;
  v6 = 4;
  if ( !tree->dl.dad )
  {
    v5 = 138;
    v6 = 3;
  }
  if ( max_code >= 0 )
  {
    p_dl = &tree[1].dl;
    for ( i = max_code + 1; i; --i )
    {
      v7 = nextlen;
      ++v3;
      curlen = nextlen;
      nextlen = p_dl->dad;
      count = v3;
      if ( v3 < v5 && v7 == p_dl->dad )
        goto LABEL_44;
      if ( v3 < v6 )
      {
        do
        {
          dummy_high = HIWORD(s[v7 + 671].dummy);
          dummy = s[1455].dummy;
          if ( dummy <= 16 - dummy_high )
          {
            LOWORD(s[1454].dummy) |= LOWORD(s[v7 + 671].dummy) << dummy;
            v15 = dummy_high + dummy;
          }
          else
          {
            v10 = s[v7 + 671].dummy;
            v11 = v10 << dummy;
            v12 = s[2].dummy;
            LOWORD(s[1454].dummy) |= v11;
            *(_BYTE *)(v12 + s[5].dummy++) = s[1454].dummy;
            *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
            v13 = s[1455].dummy;
            ++s[5].dummy;
            v14 = v10 >> (16 - v13);
            v15 = v13 + dummy_high - 16;
            v7 = curlen;
            LOWORD(s[1454].dummy) = v14;
            v3 = count;
          }
          --v3;
          s[1455].dummy = v15;
          count = v3;
        }
        while ( v3 );
        goto LABEL_39;
      }
      if ( v7 )
      {
        if ( v7 != len )
        {
          v16 = s[1455].dummy;
          lena = HIWORD(s[v7 + 671].dummy);
          if ( v16 <= 16 - lena )
          {
            LOWORD(s[1454].dummy) |= LOWORD(s[v7 + 671].dummy) << v16;
            v21 = lena + v16;
          }
          else
          {
            v17 = s[v7 + 671].dummy;
            v18 = v17 << v16;
            v19 = s[2].dummy;
            LOWORD(s[1454].dummy) |= v18;
            *(_BYTE *)(v19 + s[5].dummy++) = s[1454].dummy;
            *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
            v20 = s[1455].dummy;
            ++s[5].dummy;
            v21 = v20 + lena - 16;
            LOWORD(s[1454].dummy) = v17 >> (16 - v20);
            v3 = count;
          }
          --v3;
          s[1455].dummy = v21;
          count = v3;
        }
        v22 = s[1455].dummy;
        lenb = HIWORD(s[687].dummy);
        if ( v22 <= 16 - lenb )
        {
          LOWORD(s[1454].dummy) |= LOWORD(s[687].dummy) << v22;
          v27 = lenb + v22;
        }
        else
        {
          v23 = s[687].dummy;
          v24 = v23 << v22;
          v25 = s[2].dummy;
          LOWORD(s[1454].dummy) |= v24;
          *(_BYTE *)(v25 + s[5].dummy++) = s[1454].dummy;
          *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
          v26 = s[1455].dummy;
          ++s[5].dummy;
          v27 = v26 + lenb - 16;
          LOWORD(s[1454].dummy) = v23 >> (16 - v26);
          v3 = count;
        }
        v28 = v3 - 3;
        s[1455].dummy = v27;
        if ( v27 > 14 )
        {
          v29 = v28 << v27;
          v30 = s[2].dummy;
          LOWORD(s[1454].dummy) |= v29;
          *(_BYTE *)(v30 + s[5].dummy++) = s[1454].dummy;
          *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
          v31 = s[1455].dummy;
          ++s[5].dummy;
          s[1455].dummy = v31 - 14;
          LOWORD(s[1454].dummy) = (unsigned __int16)v28 >> (16 - v31);
          goto LABEL_39;
        }
        LOWORD(s[1454].dummy) |= v28 << v27;
        v32 = v27 + 2;
      }
      else
      {
        v33 = s[1455].dummy;
        if ( v3 > 10 )
        {
          lend = HIWORD(s[689].dummy);
          if ( v33 <= 16 - lend )
          {
            LOWORD(s[1454].dummy) |= LOWORD(s[689].dummy) << v33;
            v47 = lend + v33;
          }
          else
          {
            v43 = s[689].dummy;
            v44 = v43 << v33;
            v45 = s[2].dummy;
            LOWORD(s[1454].dummy) |= v44;
            *(_BYTE *)(v45 + s[5].dummy++) = s[1454].dummy;
            *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
            v46 = s[1455].dummy;
            ++s[5].dummy;
            v47 = v46 + lend - 16;
            LOWORD(s[1454].dummy) = v43 >> (16 - v46);
            v3 = count;
          }
          v48 = v3 - 11;
          s[1455].dummy = v47;
          if ( v47 > 9 )
          {
            v49 = v48 << v47;
            v50 = s[2].dummy;
            LOWORD(s[1454].dummy) |= v49;
            *(_BYTE *)(v50 + s[5].dummy++) = s[1454].dummy;
            *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
            v51 = s[1455].dummy;
            ++s[5].dummy;
            s[1455].dummy = v51 - 9;
            LOWORD(s[1454].dummy) = (unsigned __int16)v48 >> (16 - v51);
            goto LABEL_39;
          }
          LOWORD(s[1454].dummy) |= v48 << v47;
          v32 = v47 + 7;
        }
        else
        {
          lenc = HIWORD(s[688].dummy);
          if ( v33 <= 16 - lenc )
          {
            LOWORD(s[1454].dummy) |= LOWORD(s[688].dummy) << v33;
            v38 = lenc + v33;
          }
          else
          {
            v34 = s[688].dummy;
            v35 = v34 << v33;
            v36 = s[2].dummy;
            LOWORD(s[1454].dummy) |= v35;
            *(_BYTE *)(v36 + s[5].dummy++) = s[1454].dummy;
            *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
            v37 = s[1455].dummy;
            ++s[5].dummy;
            v38 = v37 + lenc - 16;
            LOWORD(s[1454].dummy) = v34 >> (16 - v37);
            v3 = count;
          }
          v39 = v3 - 3;
          s[1455].dummy = v38;
          if ( v38 > 13 )
          {
            v40 = v39 << v38;
            v41 = s[2].dummy;
            LOWORD(s[1454].dummy) |= v40;
            *(_BYTE *)(v41 + s[5].dummy++) = s[1454].dummy;
            *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
            v42 = s[1455].dummy;
            ++s[5].dummy;
            s[1455].dummy = v42 - 13;
            LOWORD(s[1454].dummy) = (unsigned __int16)v39 >> (16 - v42);
            goto LABEL_39;
          }
          LOWORD(s[1454].dummy) |= v39 << v38;
          v32 = v38 + 3;
        }
      }
      s[1455].dummy = v32;
LABEL_39:
      v3 = 0;
      len = v7;
      if ( nextlen )
      {
        if ( v7 == nextlen )
        {
          v5 = 6;
          v6 = 3;
        }
        else
        {
          v5 = 7;
          v6 = 4;
        }
      }
      else
      {
        v5 = 138;
        v6 = 3;
      }
LABEL_44:
      p_dl += 2;
    }
  }
}
