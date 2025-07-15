bool __thiscall Scaleform::Render::ExternalFontWinAPI::decomposeGlyphOutline(
        Scaleform::Render::ExternalFontWinAPI *this,
        const unsigned __int8 *data,
        unsigned int size,
        Scaleform::Render::GlyphShape *shape,
        unsigned int hintedSize)
{
  bool v5; // zf
  int v6; // edi
  int v7; // edx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // esi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  unsigned __int8 *v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // ebx
  unsigned __int8 *v14; // edx
  unsigned int v15; // eax
  unsigned int v16; // ebx
  unsigned __int8 *v17; // edx
  int v18; // ebx
  int v19; // eax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v20; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v21; // esi
  unsigned int v22; // eax
  unsigned int v23; // ebx
  unsigned __int8 *v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // ebx
  unsigned __int8 *v27; // ecx
  unsigned int v28; // eax
  unsigned int v29; // ebx
  unsigned __int8 *v30; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v31; // edx
  int v32; // esi
  int v33; // eax
  int v34; // edi
  int v35; // eax
  int v36; // esi
  int v37; // edi
  int v38; // eax
  int v39; // esi
  int v40; // eax
  int v41; // edi
  int v42; // edx
  int v43; // edi
  const unsigned __int8 *v44; // eax
  int v45; // esi
  _FIXED v46; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v47; // edx
  int v48; // edi
  int v49; // esi
  bool v50; // cc
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v51; // eax
  unsigned int v52; // edi
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v53; // ebx
  unsigned int v54; // esi
  bool *v55; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v56; // edi
  unsigned int v57; // esi
  bool *v58; // eax
  bool result; // al
  int v60; // [esp-Ch] [ebp-C4h]
  int v61; // [esp-Ch] [ebp-C4h]
  int v62; // [esp-4h] [ebp-BCh]
  int v63; // [esp-4h] [ebp-BCh]
  int v64; // [esp-4h] [ebp-BCh]
  float v65; // [esp+10h] [ebp-A8h]
  float v66; // [esp+10h] [ebp-A8h]
  float v67; // [esp+10h] [ebp-A8h]
  float v68; // [esp+10h] [ebp-A8h]
  float v69; // [esp+10h] [ebp-A8h]
  float v70; // [esp+10h] [ebp-A8h]
  float v71; // [esp+10h] [ebp-A8h]
  float v72; // [esp+10h] [ebp-A8h]
  const unsigned __int8 *v73; // [esp+10h] [ebp-A8h]
  int i; // [esp+14h] [ebp-A4h]
  float ia; // [esp+14h] [ebp-A4h]
  float ib; // [esp+14h] [ebp-A4h]
  float ic; // [esp+14h] [ebp-A4h]
  float id; // [esp+14h] [ebp-A4h]
  float ie; // [esp+14h] [ebp-A4h]
  int ig; // [esp+14h] [ebp-A4h]
  int u; // [esp+1Ch] [ebp-9Ch]
  int ua; // [esp+1Ch] [ebp-9Ch]
  int *ub; // [esp+1Ch] [ebp-9Ch]
  int uc; // [esp+1Ch] [ebp-9Ch]
  float v85; // [esp+20h] [ebp-98h]
  float v86; // [esp+20h] [ebp-98h]
  float v87; // [esp+20h] [ebp-98h]
  const unsigned __int8 *curPoly; // [esp+24h] [ebp-94h]
  int pntB; // [esp+28h] [ebp-90h]
  int pntB_4; // [esp+2Ch] [ebp-8Ch]
  const unsigned __int8 *curGlyph; // [esp+30h] [ebp-88h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v92; // [esp+34h] [ebp-84h] BYREF
  float Multiplier; // [esp+38h] [ebp-80h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v94; // [esp+3Ch] [ebp-7Ch] BYREF
  float v95; // [esp+40h] [ebp-78h]
  tagPOINTFX pntC; // [esp+44h] [ebp-74h]
  const unsigned __int8 *endPoly; // [esp+4Ch] [ebp-6Ch]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v98; // [esp+50h] [ebp-68h] BYREF
  float v99; // [esp+54h] [ebp-64h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v100; // [esp+58h] [ebp-60h] BYREF
  float v101; // [esp+5Ch] [ebp-5Ch]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v102; // [esp+60h] [ebp-58h] BYREF
  float v103; // [esp+64h] [ebp-54h]
  const unsigned __int8 *endGlyph; // [esp+68h] [ebp-50h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v105; // [esp+6Ch] [ebp-4Ch] BYREF
  float v106; // [esp+70h] [ebp-48h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v107; // [esp+74h] [ebp-44h] BYREF
  float v108; // [esp+78h] [ebp-40h]
  int v109; // [esp+7Ch] [ebp-3Ch]
  Scaleform::Render::ShapePosInfo pos; // [esp+80h] [ebp-38h]

  v5 = shape->Data.Data.Size == 0;
  curGlyph = data;
  endGlyph = &data[size];
  if ( v5 )
  {
    if ( shape->Data.Data.Policy.Capacity )
      goto LABEL_6;
  }
  else if ( (shape->Data.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
    goto LABEL_6;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&shape->Data,
    &shape->Data,
    0);
LABEL_6:
  shape->Data.Data.Size = 0;
  if ( data < &data[size] )
  {
    do
    {
      v6 = *((_DWORD *)curGlyph + 3);
      endPoly = &curGlyph[*(_DWORD *)curGlyph];
      curPoly = curGlyph + 16;
      if ( hintedSize )
      {
        v7 = *((_DWORD *)curGlyph + 2);
        pContainer = shape->pContainer;
        Multiplier = shape->Multiplier;
        u = v7;
        v92.Data = pContainer;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
          &v92,
          1u);
        v9 = pContainer->Data.Size;
        v10 = v9 + 1;
        if ( v9 + 1 >= v9 )
        {
          if ( v10 >= pContainer->Data.Policy.Capacity )
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
              pContainer,
              v10 + (v10 >> 2));
        }
        else if ( v10 < pContainer->Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
            pContainer,
            v10);
        }
        v11 = pContainer->Data.Data;
        pContainer->Data.Size = v10;
        v11[v10 - 1] = 4;
        v12 = pContainer->Data.Size;
        v13 = v12 + 1;
        if ( v12 + 1 >= v12 )
        {
          if ( v13 >= pContainer->Data.Policy.Capacity )
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
              pContainer,
              v13 + (v13 >> 2));
        }
        else if ( v13 < pContainer->Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
            pContainer,
            v13);
        }
        v14 = pContainer->Data.Data;
        pContainer->Data.Size = v13;
        v14[v13 - 1] = 0;
        v15 = pContainer->Data.Size;
        v16 = v15 + 1;
        if ( v15 + 1 >= v15 )
        {
          if ( v16 >= pContainer->Data.Policy.Capacity )
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
              pContainer,
              v16 + (v16 >> 2));
        }
        else if ( v16 < pContainer->Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
            pContainer,
            v16);
        }
        v17 = pContainer->Data.Data;
        pContainer->Data.Size = v16;
        v17[v16 - 1] = 0;
        v65 = 20.0 * (double)SHIWORD(u) + (double)(unsigned __int16)u * 20.0 * 0.0000152587890625;
        v18 = (int)(v65 * Multiplier);
        pos.StartX = v18;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
          &v92,
          v18);
        v66 = 20.0 * (double)SHIWORD(v6) + (double)(unsigned __int16)v6 * 20.0 * 0.0000152587890625;
        v19 = (int)(-v66 * Multiplier);
        v20 = &v92;
      }
      else
      {
        v21 = shape->pContainer;
        ua = *((_DWORD *)curGlyph + 2);
        v95 = shape->Multiplier;
        v94.Data = v21;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
          &v94,
          1u);
        v22 = v21->Data.Size;
        v23 = v22 + 1;
        if ( v22 + 1 >= v22 )
        {
          if ( v23 >= v21->Data.Policy.Capacity )
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v21,
              v21,
              v23 + (v23 >> 2));
        }
        else if ( v23 < v21->Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v21,
            v21,
            v22 + 1);
        }
        v24 = v21->Data.Data;
        v21->Data.Size = v23;
        v24[v23 - 1] = 4;
        v25 = v21->Data.Size;
        v26 = v25 + 1;
        if ( v25 + 1 >= v25 )
        {
          if ( v26 >= v21->Data.Policy.Capacity )
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v21,
              v21,
              v26 + (v26 >> 2));
        }
        else if ( v26 < v21->Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v21,
            v21,
            v25 + 1);
        }
        v27 = v21->Data.Data;
        v21->Data.Size = v26;
        v27[v26 - 1] = 0;
        v28 = v21->Data.Size;
        v29 = v28 + 1;
        if ( v28 + 1 >= v28 )
        {
          if ( v29 >= v21->Data.Policy.Capacity )
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v21,
              v21,
              v29 + (v29 >> 2));
        }
        else if ( v29 < v21->Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v21,
            v21,
            v28 + 1);
        }
        v30 = v21->Data.Data;
        v21->Data.Size = v29;
        v30[v29 - 1] = 0;
        v67 = (double)((SHIWORD(ua) << 8) + BYTE1(ua)) * 4.0 / 240.0;
        v18 = (int)(v67 * v95);
        pos.StartX = v18;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
          &v94,
          v18);
        v68 = (double)((SHIWORD(v6) << 8) + BYTE1(v6)) * -4.0 / 240.0;
        v19 = (int)(v68 * v95);
        v20 = &v94;
      }
      pos.LastY = v19;
      pos.StartY = v19;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        v20,
        v19);
      for ( ; curPoly < endPoly; curPoly += 8 * *((unsigned __int16 *)curPoly + 1) + 4 )
      {
        if ( *(_WORD *)curPoly == 1 )
        {
          i = 0;
          if ( *((_WORD *)curPoly + 1) )
          {
            ub = (int *)(curPoly + 4);
            do
            {
              v31 = shape->pContainer;
              if ( hintedSize )
              {
                v32 = ub[1];
                v101 = shape->Multiplier;
                v33 = *ub;
                v100.Data = v31;
                v69 = (double)(unsigned __int16)v33 * 20.0 * 0.0000152587890625 + (double)SHIWORD(v33) * 20.0;
                v34 = (int)(v69 * v101) - v18;
                v70 = 0.0000152587890625 * (20.0 * (double)(unsigned __int16)v32) + (double)SHIWORD(v32) * 20.0;
                v35 = (int)(v101 * v70);
                v36 = -(pos.LastY + v35);
                if ( pos.LastY + v35 )
                {
                  v62 = -(pos.LastY + v35);
                  if ( v34 )
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                      &v100,
                      v34,
                      v62);
                    v18 += v34;
                  }
                  else
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                      &v100,
                      v62);
                  }
                  pos.LastY += v36;
                }
                else
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v100,
                    v34);
                  v18 += v34;
                  pos.LastY += v36;
                }
              }
              else
              {
                v37 = ub[1];
                v99 = shape->Multiplier;
                v38 = *ub;
                v98.Data = v31;
                v71 = (double)(BYTE1(v38) + (SHIWORD(v38) << 8)) * -4.0 / 240.0;
                v39 = -v18 - (int)(v71 * v99);
                v72 = (double)(BYTE1(v37) + (SHIWORD(v37) << 8)) * 4.0 / 240.0;
                v40 = (int)(v99 * v72);
                v41 = -pos.LastY - v40;
                if ( -pos.LastY == v40 )
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v98,
                    v39);
                }
                else
                {
                  v63 = -pos.LastY - v40;
                  if ( v39 )
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                      &v98,
                      v39,
                      v63);
                  else
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                      &v98,
                      v63);
                }
                v18 += v39;
                pos.LastY += v41;
              }
              ub += 2;
              ++i;
            }
            while ( i < *((unsigned __int16 *)curPoly + 1) );
          }
        }
        if ( *(_WORD *)curPoly == 2 )
        {
          v42 = *((unsigned __int16 *)curPoly + 1);
          v43 = 0;
          uc = 0;
          if ( v42 - 1 > 0 )
          {
            v44 = curPoly + 12;
            v73 = curPoly + 12;
            do
            {
              v45 = *((_DWORD *)v44 + 1);
              pntB = *((_DWORD *)v44 - 2);
              pntB_4 = *((_DWORD *)v44 - 1);
              v46 = *(_FIXED *)v44;
              pntC.x = *(_FIXED *)v44;
              pntC.y = (_FIXED)v45;
              if ( v43 < v42 - 2 )
              {
                v46 = (_FIXED)((*(_DWORD *)&v46 + pntB) / 2);
                v45 = (v45 + pntB_4) / 2;
                pntC.x = v46;
                pntC.y = (_FIXED)v45;
              }
              v47 = shape->pContainer;
              if ( hintedSize )
              {
                v106 = shape->Multiplier;
                v105.Data = v47;
                ia = (double)v46.fract * 20.0 * 0.0000152587890625 + (double)v46.value * 20.0;
                v48 = (int)(ia * v106) - v18;
                ib = (double)SHIWORD(v45) * 20.0 + (double)(unsigned __int16)v45 * 20.0 * 0.0000152587890625;
                v49 = -(pos.LastY + (int)(ib * v106));
                ic = (double)SHIWORD(pntB_4) * 20.0 + (double)(unsigned __int16)pntB_4 * 20.0 * 0.0000152587890625;
                v60 = -(pos.LastY + (int)(ic * v106));
                id = 0.0000152587890625 * (20.0 * (double)(unsigned __int16)pntB) + (double)SHIWORD(pntB) * 20.0;
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                  &v105,
                  (int)(v106 * id) - v18,
                  v60,
                  v48,
                  v49);
                v18 += v48;
                pos.LastY += v49;
              }
              else
              {
                v108 = shape->Multiplier;
                v107.Data = v47;
                ie = (double)((pntC.x.value << 8) + HIBYTE(v46.fract)) * -4.0 / 240.0;
                ig = -v18 - (int)(ie * v108);
                v85 = (double)((pntC.y.value << 8) + HIBYTE(pntC.y.fract)) * 4.0 / 240.0;
                v109 = -pos.LastY - (int)(v85 * v108);
                v86 = 4.0 * (double)((SHIWORD(pntB_4) << 8) + BYTE1(pntB_4)) / 240.0;
                v61 = -pos.LastY - (int)(v86 * v108);
                v87 = -4.0 * (double)((SHIWORD(pntB) << 8) + BYTE1(pntB)) / 240.0;
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                  &v107,
                  -v18 - (int)(v108 * v87),
                  v61,
                  ig,
                  v109);
                v18 += ig;
                pos.LastY += v109;
              }
              v42 = *((unsigned __int16 *)curPoly + 1);
              v43 = uc + 1;
              v44 = v73 + 8;
              v50 = ++uc < v42 - 1;
              v73 += 8;
            }
            while ( v50 );
          }
        }
      }
      v51 = shape->pContainer;
      v103 = shape->Multiplier;
      v52 = (unsigned int)&curGlyph[*(_DWORD *)curGlyph];
      v102.Data = v51;
      curGlyph = (const unsigned __int8 *)v52;
      if ( v18 != pos.StartX || pos.LastY != pos.StartY )
      {
        if ( pos.StartY == pos.LastY )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
            &v102,
            pos.StartX - v18);
        }
        else
        {
          v64 = pos.StartY - pos.LastY;
          if ( pos.StartX == v18 )
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
              &v102,
              v64);
          else
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
              &v102,
              pos.StartX - v18,
              v64);
        }
      }
      v53 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)shape->pContainer;
      v54 = v53->Size + 1;
      if ( v54 >= v53->Size )
      {
        if ( v54 >= v53->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v53,
            v53,
            v54 + (v54 >> 2));
      }
      else if ( v54 < v53->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v53,
          v53,
          v53->Size + 1);
      }
      v55 = v53->Data;
      v53->Size = v54;
      v55[v54 - 1] = 15;
    }
    while ( v52 < (unsigned int)endGlyph );
  }
  if ( shape->IsEmpty(shape) )
    return 0;
  v56 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)shape->pContainer;
  v57 = v56->Size + 1;
  if ( v57 >= v56->Size )
  {
    if ( v57 >= v56->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v56,
        v56,
        v57 + (v57 >> 2));
  }
  else if ( v57 < v56->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v56,
      v56,
      v56->Size + 1);
  }
  v58 = v56->Data;
  v56->Size = v57;
  v58[v57 - 1] = 0;
  if ( hintedSize )
  {
    shape->HintedSize = 20 * hintedSize;
    return 1;
  }
  else
  {
    result = 1;
    shape->HintedSize = 0;
  }
  return result;
}
