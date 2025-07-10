int __cdecl pcre_exec(int a1, int *a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v9; // ecx
  int v10; // [esp+4h] [ebp-200h]
  BOOL v11; // [esp+8h] [ebp-1FCh]
  BOOL v12; // [esp+Ch] [ebp-1F8h]
  BOOL v13; // [esp+10h] [ebp-1F4h]
  BOOL v14; // [esp+18h] [ebp-1ECh]
  BOOL v15; // [esp+1Ch] [ebp-1E8h]
  BOOL v16; // [esp+20h] [ebp-1E4h]
  BOOL v17; // [esp+24h] [ebp-1E0h]
  BOOL v18; // [esp+28h] [ebp-1DCh]
  BOOL v19; // [esp+2Ch] [ebp-1D8h]
  BOOL v20; // [esp+30h] [ebp-1D4h]
  BOOL v21; // [esp+34h] [ebp-1D0h]
  BOOL v22; // [esp+38h] [ebp-1CCh]
  BOOL v23; // [esp+3Ch] [ebp-1C8h]
  BOOL v24; // [esp+40h] [ebp-1C4h]
  BOOL v25; // [esp+44h] [ebp-1C0h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *v26)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *); // [esp+48h] [ebp-1BCh]
  int v27; // [esp+4Ch] [ebp-1B8h]
  unsigned __int8 *v28; // [esp+50h] [ebp-1B4h]
  int v30; // [esp+58h] [ebp-1ACh]
  int v31; // [esp+5Ch] [ebp-1A8h]
  _DWORD *i; // [esp+60h] [ebp-1A4h]
  int v33; // [esp+68h] [ebp-19Ch]
  unsigned __int8 *v34; // [esp+6Ch] [ebp-198h]
  unsigned __int8 *v35; // [esp+74h] [ebp-190h]
  unsigned int v36; // [esp+78h] [ebp-18Ch]
  _BYTE *v37; // [esp+7Ch] [ebp-188h]
  _DWORD *v38; // [esp+80h] [ebp-184h]
  unsigned int v39; // [esp+84h] [ebp-180h]
  int v40; // [esp+88h] [ebp-17Ch]
  int v41; // [esp+8Ch] [ebp-178h] BYREF
  int valid; // [esp+90h] [ebp-174h]
  BOOL v43; // [esp+94h] [ebp-170h]
  int v44; // [esp+98h] [ebp-16Ch]
  BOOL v45; // [esp+9Ch] [ebp-168h]
  int v46; // [esp+A0h] [ebp-164h]
  void *lhs; // [esp+A4h] [ebp-160h]
  unsigned int v48; // [esp+A8h] [ebp-15Ch]
  int v49; // [esp+ACh] [ebp-158h]
  BOOL v50; // [esp+B0h] [ebp-154h]
  int v51; // [esp+B4h] [ebp-150h]
  BOOL v52; // [esp+B8h] [ebp-14Ch]
  char *v53; // [esp+BCh] [ebp-148h]
  _BYTE *v54; // [esp+C0h] [ebp-144h]
  _BYTE v55[40]; // [esp+C4h] [ebp-140h] BYREF
  int v56; // [esp+ECh] [ebp-118h]
  _BYTE *v57; // [esp+F0h] [ebp-114h]
  int v58; // [esp+F4h] [ebp-110h]
  int v59; // [esp+F8h] [ebp-10Ch]
  int v60; // [esp+FCh] [ebp-108h]
  int v61; // [esp+100h] [ebp-104h]
  char v62; // [esp+104h] [ebp-100h] BYREF
  unsigned int v63; // [esp+1BCh] [ebp-48h]
  int v64; // [esp+1C0h] [ebp-44h]
  _BYTE v65[44]; // [esp+1C4h] [ebp-40h] BYREF
  int v66; // [esp+1F4h] [ebp-10h]
  int v67; // [esp+1F8h] [ebp-Ch]
  BOOL v68; // [esp+1FCh] [ebp-8h]
  int v69; // [esp+200h] [ebp-4h]

  v49 = -1;
  v58 = -1;
  v66 = -1;
  v44 = 0;
  v52 = 0;
  v50 = 0;
  v56 = (int)&v62;
  v57 = 0;
  lhs = (void *)(a5 + a3);
  v64 = 0;
  v48 = a5 + a3 - 1;
  v61 = a1;
  v51 = a1;
  if ( (a6 & 0xE20F5A6F) != 0 )
    return -3;
  if ( !v51 || !a3 || !a7 && a8 > 0 )
    return -2;
  if ( a8 < 0 )
    return -15;
  if ( a5 < 0 || a5 > a4 )
    return -24;
  *(_DWORD *)(v56 + 68) = (*(_DWORD *)(v51 + 8) & 0x800) != 0;
  v46 = *(_DWORD *)(v56 + 68);
  if ( (a6 & 0x8000000) != 0 )
    v30 = 2;
  else
    v30 = (a6 & 0x8000) != 0;
  *(_DWORD *)(v56 + 132) = v30;
  if ( v46 && (a6 & 0x2000) == 0 )
  {
    valid = _pcre_valid_utf8(a3, a4, &v41);
    if ( valid )
    {
      if ( a8 >= 2 )
      {
        *(_DWORD *)a7 = v41;
        *(_DWORD *)(a7 + 4) = valid;
      }
      if ( valid > 5 || *(int *)(v56 + 132) <= 1 )
        return -10;
      else
        return -25;
    }
    if ( a5 > 0 && a5 < a4 && (*(_BYTE *)(a5 + a3) & 0xC0) == 0x80 )
      return -11;
  }
  *(_DWORD *)(v56 + 40) = v51 + *(unsigned __int16 *)(v51 + 24);
  *(_DWORD *)(v56 + 32) = *(unsigned __int16 *)(v51 + 28);
  *(_DWORD *)(v56 + 36) = *(unsigned __int16 *)(v51 + 26);
  v54 = 0;
  *(_DWORD *)(v56 + 4) = &stru_984D24.m_working_macro_list.m_buffer[33].m_store[300];
  *(_DWORD *)(v56 + 8) = &stru_984D24.m_working_macro_list.m_buffer[33].m_store[300];
  *(_DWORD *)(v56 + 164) = 0;
  v53 = *(char **)(v61 + 32);
  if ( a2 )
  {
    v40 = *a2;
    if ( (*a2 & 1) != 0 )
      v54 = (_BYTE *)a2[1];
    if ( (v40 & 2) != 0 )
      *(_DWORD *)(v56 + 4) = a2[2];
    if ( (v40 & 0x10) != 0 )
      *(_DWORD *)(v56 + 8) = a2[5];
    if ( (v40 & 4) != 0 )
      *(_DWORD *)(v56 + 164) = a2[3];
    if ( (v40 & 8) != 0 )
      v53 = (char *)a2[4];
  }
  if ( !v53 )
    v53 = (char *)&_pcre_default_tables;
  if ( *(_DWORD *)v51 != 1346589253 )
  {
    v51 = _pcre_try_flipped(v51, v55, v54, v65);
    if ( !v51 )
      return -4;
    if ( v54 )
      v54 = v65;
  }
  v43 = (((unsigned __int8)a6 | (unsigned __int8)*(_DWORD *)(v51 + 8)) & 0x10) != 0;
  v68 = (*(_WORD *)(v51 + 12) & 8) != 0;
  v45 = (*(_DWORD *)(v51 + 8) & 0x40000) != 0;
  *(_DWORD *)(v56 + 108) = *(unsigned __int16 *)(v51 + 26) * *(unsigned __int16 *)(v51 + 28)
                         + v61
                         + *(unsigned __int16 *)(v51 + 24);
  *(_DWORD *)(v56 + 112) = a3;
  *(_DWORD *)(v56 + 144) = a5;
  *(_DWORD *)(v56 + 116) = a4 + *(_DWORD *)(v56 + 112);
  v63 = *(_DWORD *)(v56 + 116);
  *(_DWORD *)(v56 + 80) = (*(_DWORD *)(v51 + 8) & 0x20) != 0;
  *(_DWORD *)(v56 + 76) = (*(_DWORD *)(v51 + 8) & 0x20000000) != 0;
  *(_DWORD *)(v56 + 72) = (*(_DWORD *)(v51 + 8) & 0x2000000) != 0;
  *(_DWORD *)(v56 + 104) = 0;
  *(_DWORD *)(v56 + 60) = (a6 & 0x80) != 0;
  *(_DWORD *)(v56 + 64) = (a6 & 0x100) != 0;
  *(_DWORD *)(v56 + 84) = (a6 & 0x400) != 0;
  *(_DWORD *)(v56 + 88) = (a6 & 0x10000000) != 0;
  *(_DWORD *)(v56 + 92) = 0;
  *(_DWORD *)(v56 + 172) = 0;
  *(_DWORD *)(v56 + 168) = 0;
  *(_DWORD *)(v56 + 160) = 0;
  *(_DWORD *)(v56 + 100) = (*(_WORD *)(v51 + 12) & 0x40) != 0;
  *(_DWORD *)(v56 + 48) = v53;
  *(_DWORD *)(v56 + 52) = v53 + 832;
  v28 = (unsigned __int8 *)(a6 & 0x1800000);
  if ( (a6 & 0x1800000) != 0 )
  {
    if ( v28 == (unsigned __int8 *)&unk_800000 )
    {
      *(_DWORD *)(v56 + 96) = 1;
    }
    else
    {
      if ( v28 != &vostok::memory::s_CRT_arena[5574200] )
        return -23;
      *(_DWORD *)(v56 + 96) = 0;
    }
  }
  else
  {
    *(_DWORD *)(v56 + 96) = (*(_DWORD *)(v51 + 8) & 0x1800000) == 0
                         || ((unsigned int)&unk_800000 & *(_DWORD *)(v51 + 8)) != 0;
  }
  if ( (a6 & 0x700000) != 0 )
    v27 = a6;
  else
    v27 = *(_DWORD *)(v51 + 8);
  v26 = (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))(v27 & 0x700000);
  if ( (v27 & 0x700000u) > 0x300000 )
  {
    if ( v26 == Scaleform::GFx::AS2::CreateShadow )
    {
      v67 = -1;
    }
    else
    {
      if ( v26 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_4FFFFF + 1) )
        return -23;
      v67 = -2;
    }
  }
  else if ( v26 == (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_2FFFFF + 1) )
  {
    v67 = 3338;
  }
  else if ( v26 )
  {
    if ( v26 == (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_FFFFF + 1) )
    {
      v67 = 13;
    }
    else
    {
      if ( v26 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_1FFFFE + 2) )
        return -23;
      v67 = 10;
    }
  }
  else
  {
    v67 = -2;
  }
  if ( v67 == -2 )
  {
    *(_DWORD *)(v56 + 24) = 2;
  }
  else if ( v67 >= 0 )
  {
    *(_DWORD *)(v56 + 24) = 0;
    if ( v67 <= 255 )
    {
      *(_DWORD *)(v56 + 28) = 1;
      *(_BYTE *)(v56 + 44) = v67;
    }
    else
    {
      *(_DWORD *)(v56 + 28) = 2;
      *(_BYTE *)(v56 + 44) = BYTE1(v67);
      *(_BYTE *)(v56 + 45) = v67;
    }
  }
  else
  {
    *(_DWORD *)(v56 + 24) = 1;
  }
  if ( *(_DWORD *)(v56 + 132) && (*(_WORD *)(v51 + 12) & 1) != 0 )
    return -13;
  v59 = a8 - a8 % 3;
  v60 = 2 * v59 / 3;
  if ( *(_WORD *)(v51 + 18) && *(unsigned __int16 *)(v51 + 18) >= v59 / 3 )
  {
    v59 = 3 * *(unsigned __int16 *)(v51 + 18) + 3;
    *(_DWORD *)(v56 + 12) = pcre_malloc(4 * v59);
    if ( !*(_DWORD *)(v56 + 12) )
      return -6;
    v44 = 1;
  }
  else
  {
    *(_DWORD *)(v56 + 12) = a7;
  }
  *(_DWORD *)(v56 + 16) = v59;
  *(_DWORD *)(v56 + 20) = 2 * v59 / 3;
  *(_DWORD *)(v56 + 56) = 0;
  *(_DWORD *)(v56 + 140) = -1;
  if ( *(_DWORD *)(v56 + 12) )
  {
    v38 = (_DWORD *)(*(_DWORD *)(v56 + 12) + 4 * v59);
    v39 = (unsigned int)&v38[-*(unsigned __int16 *)(v51 + 16)];
    if ( v39 < *(_DWORD *)(v56 + 12) + 8 )
      v39 = *(_DWORD *)(v56 + 12) + 8;
    while ( (unsigned int)--v38 >= v39 )
      *v38 = -1;
    *(_DWORD *)(*(_DWORD *)(v56 + 12) + 4) = -1;
    **(_DWORD **)(v56 + 12) = -1;
  }
  if ( !v43 )
  {
    if ( (*(_WORD *)(v51 + 12) & 2) != 0 )
    {
      v49 = (unsigned __int8)*(_WORD *)(v51 + 20);
      v52 = (*(_WORD *)(v51 + 20) & 0x100) != 0;
      if ( v52 )
        v49 = *(unsigned __int8 *)(*(_DWORD *)(v56 + 48) + v49);
    }
    else if ( !v68 && v54 && (*((_DWORD *)v54 + 1) & 1) != 0 )
    {
      v57 = v54 + 8;
    }
  }
  if ( (*(_WORD *)(v51 + 12) & 4) != 0 )
  {
    v58 = (unsigned __int8)*(_WORD *)(v51 + 22);
    v50 = (*(_WORD *)(v51 + 22) & 0x100) != 0;
    v66 = (unsigned __int8)v53[v58 + 256];
  }
  while ( 1 )
  {
    v36 = v63;
    if ( v45 )
    {
      v35 = (unsigned __int8 *)lhs;
      if ( v46 )
      {
        while ( (unsigned int)v35 < *(_DWORD *)(v56 + 116) )
        {
          if ( *(_DWORD *)(v56 + 24) )
          {
            v25 = (unsigned int)v35 < *(_DWORD *)(v56 + 116)
               && _pcre_is_newline(v35, *(_DWORD *)(v56 + 24), *(_DWORD *)(v56 + 116), v56 + 28, v46);
            v24 = v25;
          }
          else
          {
            v23 = (unsigned int)v35 <= *(_DWORD *)(v56 + 116) - *(_DWORD *)(v56 + 28)
               && *v35 == *(unsigned __int8 *)(v56 + 44)
               && (*(_DWORD *)(v56 + 28) == 1 || v35[1] == *(unsigned __int8 *)(v56 + 45));
            v24 = v23;
          }
          if ( v24 )
            break;
          ++v35;
          while ( (unsigned int)v35 < v63 && (*v35 & 0xC0) == 0x80 )
            ++v35;
        }
      }
      else
      {
        while ( (unsigned int)v35 < *(_DWORD *)(v56 + 116) )
        {
          if ( *(_DWORD *)(v56 + 24) )
          {
            v22 = (unsigned int)v35 < *(_DWORD *)(v56 + 116)
               && _pcre_is_newline(v35, *(_DWORD *)(v56 + 24), *(_DWORD *)(v56 + 116), v56 + 28, v46);
            v21 = v22;
          }
          else
          {
            v20 = (unsigned int)v35 <= *(_DWORD *)(v56 + 116) - *(_DWORD *)(v56 + 28)
               && *v35 == *(unsigned __int8 *)(v56 + 44)
               && (*(_DWORD *)(v56 + 28) == 1 || v35[1] == *(unsigned __int8 *)(v56 + 45));
            v21 = v20;
          }
          if ( v21 )
            break;
          ++v35;
        }
      }
      v63 = (unsigned int)v35;
    }
    if ( ((*(_DWORD *)(v51 + 8) | a6) & 0x4000000) == 0 )
    {
      if ( v49 < 0 )
      {
        if ( v68 )
        {
          if ( (unsigned int)lhs > a5 + *(_DWORD *)(v56 + 112) )
          {
            if ( v46 )
            {
              while ( (unsigned int)lhs < v63 )
              {
                if ( *(_DWORD *)(v56 + 24) )
                {
                  v19 = (unsigned int)lhs > *(_DWORD *)(v56 + 112)
                     && _pcre_was_newline(lhs, *(_DWORD *)(v56 + 24), *(_DWORD *)(v56 + 112), v56 + 28, v46);
                  v18 = v19;
                }
                else
                {
                  v17 = (unsigned int)lhs >= *(_DWORD *)(v56 + 28) + *(_DWORD *)(v56 + 112)
                     && *((char *)lhs - *(_DWORD *)(v56 + 28)) == *(_BYTE *)(v56 + 44)
                     && (*(_DWORD *)(v56 + 28) == 1 || ((char *)lhs - *(_DWORD *)(v56 + 28))[1] == *(_BYTE *)(v56 + 45));
                  v18 = v17;
                }
                if ( v18 )
                  break;
                for ( lhs = (char *)lhs + 1;
                      (unsigned int)lhs < v63 && (*(_BYTE *)lhs & 0xC0) == 0x80;
                      lhs = (char *)lhs + 1 )
                {
                  ;
                }
              }
            }
            else
            {
              while ( (unsigned int)lhs < v63 )
              {
                if ( *(_DWORD *)(v56 + 24) )
                {
                  v16 = (unsigned int)lhs > *(_DWORD *)(v56 + 112)
                     && _pcre_was_newline(lhs, *(_DWORD *)(v56 + 24), *(_DWORD *)(v56 + 112), v56 + 28, v46);
                  v15 = v16;
                }
                else
                {
                  v14 = (unsigned int)lhs >= *(_DWORD *)(v56 + 28) + *(_DWORD *)(v56 + 112)
                     && *((char *)lhs - *(_DWORD *)(v56 + 28)) == *(_BYTE *)(v56 + 44)
                     && (*(_DWORD *)(v56 + 28) == 1 || ((char *)lhs - *(_DWORD *)(v56 + 28))[1] == *(_BYTE *)(v56 + 45));
                  v15 = v14;
                }
                if ( v15 )
                  break;
                lhs = (char *)lhs + 1;
              }
            }
            if ( *((char *)lhs - 1) == 13
              && (*(_DWORD *)(v56 + 24) == 1 || *(_DWORD *)(v56 + 24) == 2)
              && (unsigned int)lhs < v63
              && *(_BYTE *)lhs == 10 )
            {
              lhs = (char *)lhs + 1;
            }
          }
        }
        else if ( v57 )
        {
          while ( (unsigned int)lhs < v63
               && ((1 << (*(_BYTE *)lhs & 7)) & (unsigned __int8)v57[*(unsigned __int8 *)lhs >> 3]) == 0 )
          {
            lhs = (char *)lhs + 1;
            if ( v46 )
            {
              while ( (unsigned int)lhs < v63 && (*(_BYTE *)lhs & 0xC0) == 0x80 )
                lhs = (char *)lhs + 1;
            }
          }
        }
      }
      else if ( v52 )
      {
        while ( (unsigned int)lhs < v63 && *(unsigned __int8 *)(*(_DWORD *)(v56 + 48) + *(unsigned __int8 *)lhs) != v49 )
          lhs = (char *)lhs + 1;
      }
      else
      {
        while ( (unsigned int)lhs < v63 && *(unsigned __int8 *)lhs != v49 )
          lhs = (char *)lhs + 1;
      }
    }
    v63 = v36;
    if ( ((*(_DWORD *)(v51 + 8) | a6) & 0x4000000) == 0 && !*(_DWORD *)(v56 + 132) )
    {
      if ( v54 && (*((_DWORD *)v54 + 1) & 2) != 0 && v63 - (unsigned int)lhs < *((_DWORD *)v54 + 10) )
      {
        v69 = 0;
        goto LABEL_286;
      }
      if ( v58 >= 0 && (int)(v63 - (_DWORD)lhs) < 1000 )
      {
        v34 = (unsigned __int8 *)lhs + (v49 >= 0);
        if ( (unsigned int)v34 > v48 )
        {
          if ( v50 )
          {
            while ( (unsigned int)v34 < v63 )
            {
              v33 = *v34++;
              if ( v33 == v58 || v33 == v66 )
              {
                --v34;
                break;
              }
            }
          }
          else
          {
            while ( (unsigned int)v34 < v63 )
            {
              v9 = *v34++;
              if ( v9 == v58 )
              {
                --v34;
                break;
              }
            }
          }
          if ( (unsigned int)v34 >= v63 )
          {
            v69 = 0;
            goto LABEL_286;
          }
          v48 = (unsigned int)v34;
        }
      }
    }
    *(_DWORD *)(v56 + 120) = lhs;
    *(_DWORD *)(v56 + 128) = lhs;
    *(_DWORD *)v56 = 0;
    *(_DWORD *)(v56 + 148) = 0;
    *(_DWORD *)(v56 + 136) = 0;
    v69 = sub_5147C0(lhs, *(_DWORD *)(v56 + 108), (int)lhs, 2, v56, 0, 0);
    if ( *(_DWORD *)(v56 + 92) && !v64 )
      v64 = *(_DWORD *)(v56 + 128);
    if ( v69 <= -995 )
      break;
    if ( v69 > -992 )
    {
      if ( v69 )
        goto LABEL_286;
    }
    else if ( v69 != -992 )
    {
      if ( v69 != -994 )
      {
        v37 = lhs;
        *(_DWORD *)(v56 + 104) = 1;
        goto LABEL_259;
      }
      if ( *(void **)(v56 + 120) != lhs )
      {
        v37 = *(_BYTE **)(v56 + 120);
        goto LABEL_259;
      }
    }
LABEL_253:
    *(_DWORD *)(v56 + 104) = 0;
    v37 = (char *)lhs + 1;
    if ( v46 )
    {
      while ( (unsigned int)v37 < v63 && (*v37 & 0xC0) == 0x80 )
        ++v37;
    }
LABEL_259:
    v69 = 0;
    if ( v45 )
    {
      if ( *(_DWORD *)(v56 + 24) )
      {
        v13 = (unsigned int)lhs < *(_DWORD *)(v56 + 116)
           && _pcre_is_newline(lhs, *(_DWORD *)(v56 + 24), *(_DWORD *)(v56 + 116), v56 + 28, v46);
        v12 = v13;
      }
      else
      {
        v11 = (unsigned int)lhs <= *(_DWORD *)(v56 + 116) - *(_DWORD *)(v56 + 28)
           && *(unsigned __int8 *)lhs == *(unsigned __int8 *)(v56 + 44)
           && (*(_DWORD *)(v56 + 28) == 1 || *((unsigned __int8 *)lhs + 1) == *(unsigned __int8 *)(v56 + 45));
        v12 = v11;
      }
      if ( v12 )
        goto LABEL_286;
    }
    lhs = v37;
    if ( v43 || (unsigned int)lhs > v63 )
      goto LABEL_286;
    if ( *((char *)lhs - 1) == 13
      && (unsigned int)lhs < v63
      && *(_BYTE *)lhs == 10
      && (*(_WORD *)(v51 + 12) & 0x20) == 0
      && (*(_DWORD *)(v56 + 24) == 1 || *(_DWORD *)(v56 + 24) == 2 || *(_DWORD *)(v56 + 28) == 2) )
    {
      lhs = (char *)lhs + 1;
    }
    *(_DWORD *)(v56 + 168) = 0;
  }
  if ( v69 == -995 )
    goto LABEL_253;
  if ( v69 == -998 )
    v69 = 0;
LABEL_286:
  if ( v69 == 1 || v69 == -999 )
  {
    if ( v44 )
    {
      if ( v60 >= 4 )
        memcpy((unsigned __int8 *)(a7 + 8), (unsigned __int8 *)(*(_DWORD *)(v56 + 12) + 8), 4 * v60 - 8);
      if ( *(_DWORD *)(v56 + 136) > v60 )
        *(_DWORD *)(v56 + 56) = 1;
      pcre_free(*(void **)(v56 + 12));
    }
    if ( *(_DWORD *)(v56 + 56) && *(_DWORD *)(v56 + 136) >= v60 )
      v10 = 0;
    else
      v10 = *(_DWORD *)(v56 + 136) / 2;
    v69 = v10;
    if ( *(_DWORD *)(v56 + 136) / 2 <= *(unsigned __int16 *)(v51 + 16) && a7 )
    {
      v31 = 2 * *(unsigned __int16 *)(v51 + 16) + 2;
      if ( v31 > a8 )
        v31 = v59;
      for ( i = (_DWORD *)(a7 + 4 * *(_DWORD *)(v56 + 136)); (unsigned int)i < a7 + 4 * v31; ++i )
        *i = -1;
    }
    if ( a8 >= 2 )
    {
      *(_DWORD *)a7 = *(_DWORD *)(v56 + 120) - *(_DWORD *)(v56 + 112);
      *(_DWORD *)(a7 + 4) = *(_DWORD *)(v56 + 124) - *(_DWORD *)(v56 + 112);
    }
    else
    {
      v69 = 0;
    }
    if ( a2 && (*a2 & 0x20) != 0 )
      *(_DWORD *)a2[6] = *(_DWORD *)(v56 + 168);
    return v69;
  }
  else
  {
    if ( v44 )
      pcre_free(*(void **)(v56 + 12));
    if ( !v69 || v69 == -12 )
    {
      if ( v64 )
      {
        *(_DWORD *)(v56 + 168) = 0;
        if ( a8 > 1 )
        {
          *(_DWORD *)a7 = v64 - a3;
          *(_DWORD *)(a7 + 4) = v63 - a3;
        }
        v69 = -12;
      }
      else
      {
        v69 = -1;
      }
      if ( a2 && (*a2 & 0x20) != 0 )
        *(_DWORD *)a2[6] = *(_DWORD *)(v56 + 172);
      return v69;
    }
    else
    {
      return v69;
    }
  }
}
