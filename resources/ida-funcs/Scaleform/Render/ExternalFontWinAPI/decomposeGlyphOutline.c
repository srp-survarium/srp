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
  int *v44; // eax
  int v45; // esi
  int v46; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v47; // edx
  int v48; // edi
  int v49; // esi
  bool v50; // cc
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v51; // eax
  const unsigned __int8 *v52; // edi
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
  _WORD *v73; // [esp+10h] [ebp-A8h]
  int v74; // [esp+14h] [ebp-A4h]
  float v75; // [esp+14h] [ebp-A4h]
  float v76; // [esp+14h] [ebp-A4h]
  float v77; // [esp+14h] [ebp-A4h]
  float v78; // [esp+14h] [ebp-A4h]
  float v79; // [esp+14h] [ebp-A4h]
  int v80; // [esp+14h] [ebp-A4h]
  int v81; // [esp+1Ch] [ebp-9Ch]
  int v82; // [esp+1Ch] [ebp-9Ch]
  int *v83; // [esp+1Ch] [ebp-9Ch]
  int v84; // [esp+1Ch] [ebp-9Ch]
  float v85; // [esp+20h] [ebp-98h]
  float v86; // [esp+20h] [ebp-98h]
  float v87; // [esp+20h] [ebp-98h]
  const unsigned __int8 *v88; // [esp+24h] [ebp-94h]
  int v89; // [esp+28h] [ebp-90h]
  int v90; // [esp+2Ch] [ebp-8Ch]
  const unsigned __int8 *v91; // [esp+30h] [ebp-88h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v92; // [esp+34h] [ebp-84h] BYREF
  float Multiplier; // [esp+38h] [ebp-80h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v94; // [esp+3Ch] [ebp-7Ch] BYREF
  float v95; // [esp+40h] [ebp-78h]
  int v96; // [esp+44h] [ebp-74h]
  int v97; // [esp+48h] [ebp-70h]
  const unsigned __int8 *v98; // [esp+4Ch] [ebp-6Ch]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v99; // [esp+50h] [ebp-68h] BYREF
  float v100; // [esp+54h] [ebp-64h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v101; // [esp+58h] [ebp-60h] BYREF
  float v102; // [esp+5Ch] [ebp-5Ch]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v103; // [esp+60h] [ebp-58h] BYREF
  float v104; // [esp+64h] [ebp-54h]
  const unsigned __int8 *v105; // [esp+68h] [ebp-50h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v106; // [esp+6Ch] [ebp-4Ch] BYREF
  float v107; // [esp+70h] [ebp-48h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v108; // [esp+74h] [ebp-44h] BYREF
  float v109; // [esp+78h] [ebp-40h]
  int v110; // [esp+7Ch] [ebp-3Ch]
  int v111; // [esp+84h] [ebp-34h]
  int v112; // [esp+88h] [ebp-30h]
  int v113; // [esp+90h] [ebp-28h]

  v5 = shape->Data.Data.Size == 0;
  v91 = data;
  v105 = &data[size];
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
      v6 = *((_DWORD *)v91 + 3);
      v98 = &v91[*(_DWORD *)v91];
      v88 = v91 + 16;
      if ( hintedSize )
      {
        v7 = *((_DWORD *)v91 + 2);
        pContainer = shape->pContainer;
        Multiplier = shape->Multiplier;
        v81 = v7;
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
        v65 = 20.0 * (double)SHIWORD(v81) + (double)(unsigned __int16)v81 * 20.0 * 0.0000152587890625;
        v18 = (int)(v65 * Multiplier);
        v111 = v18;
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
        v82 = *((_DWORD *)v91 + 2);
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
        v67 = (double)((SHIWORD(v82) << 8) + BYTE1(v82)) * 4.0 / 240.0;
        v18 = (int)(v67 * v95);
        v111 = v18;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
          &v94,
          v18);
        v68 = (double)((SHIWORD(v6) << 8) + BYTE1(v6)) * -4.0 / 240.0;
        v19 = (int)(v68 * v95);
        v20 = &v94;
      }
      v113 = v19;
      v112 = v19;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        v20,
        v19);
      for ( ; v88 < v98; v88 += 8 * *((unsigned __int16 *)v88 + 1) + 4 )
      {
        if ( *(_WORD *)v88 == 1 )
        {
          v74 = 0;
          if ( *((_WORD *)v88 + 1) )
          {
            v83 = (int *)(v88 + 4);
            do
            {
              v31 = shape->pContainer;
              if ( hintedSize )
              {
                v32 = v83[1];
                v102 = shape->Multiplier;
                v33 = *v83;
                v101.Data = v31;
                v69 = (double)(unsigned __int16)v33 * 20.0 * 0.0000152587890625 + (double)SHIWORD(v33) * 20.0;
                v34 = (int)(v69 * v102) - v18;
                v70 = 0.0000152587890625 * (20.0 * (double)(unsigned __int16)v32) + (double)SHIWORD(v32) * 20.0;
                v35 = (int)(v102 * v70);
                v36 = -(v113 + v35);
                if ( v113 + v35 )
                {
                  v62 = -(v113 + v35);
                  if ( v34 )
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                      &v101,
                      v34,
                      v62);
                    v18 += v34;
                  }
                  else
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                      &v101,
                      v62);
                  }
                  v113 += v36;
                }
                else
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v101,
                    v34);
                  v18 += v34;
                  v113 += v36;
                }
              }
              else
              {
                v37 = v83[1];
                v100 = shape->Multiplier;
                v38 = *v83;
                v99.Data = v31;
                v71 = (double)(BYTE1(v38) + (SHIWORD(v38) << 8)) * -4.0 / 240.0;
                v39 = -v18 - (int)(v71 * v100);
                v72 = (double)(BYTE1(v37) + (SHIWORD(v37) << 8)) * 4.0 / 240.0;
                v40 = (int)(v100 * v72);
                v41 = -v113 - v40;
                if ( -v113 == v40 )
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v99,
                    v39);
                }
                else
                {
                  v63 = -v113 - v40;
                  if ( v39 )
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                      &v99,
                      v39,
                      v63);
                  else
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                      &v99,
                      v63);
                }
                v18 += v39;
                v113 += v41;
              }
              v83 += 2;
              ++v74;
            }
            while ( v74 < *((unsigned __int16 *)v88 + 1) );
          }
        }
        if ( *(_WORD *)v88 == 2 )
        {
          v42 = *((unsigned __int16 *)v88 + 1);
          v43 = 0;
          v84 = 0;
          if ( v42 - 1 > 0 )
          {
            v44 = (int *)(v88 + 12);
            v73 = v88 + 12;
            do
            {
              v45 = v44[1];
              v89 = *(v44 - 2);
              v90 = *(v44 - 1);
              v46 = *v44;
              v96 = *v44;
              v97 = v45;
              if ( v43 < v42 - 2 )
              {
                v46 = (v46 + v89) / 2;
                v45 = (v45 + v90) / 2;
                v96 = v46;
                v97 = v45;
              }
              v47 = shape->pContainer;
              if ( hintedSize )
              {
                v107 = shape->Multiplier;
                v106.Data = v47;
                v75 = (double)(unsigned __int16)v46 * 20.0 * 0.0000152587890625 + (double)SHIWORD(v46) * 20.0;
                v48 = (int)(v75 * v107) - v18;
                v76 = (double)SHIWORD(v45) * 20.0 + (double)(unsigned __int16)v45 * 20.0 * 0.0000152587890625;
                v49 = -(v113 + (int)(v76 * v107));
                v77 = (double)SHIWORD(v90) * 20.0 + (double)(unsigned __int16)v90 * 20.0 * 0.0000152587890625;
                v60 = -(v113 + (int)(v77 * v107));
                v78 = 0.0000152587890625 * (20.0 * (double)(unsigned __int16)v89) + (double)SHIWORD(v89) * 20.0;
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                  &v106,
                  (int)(v107 * v78) - v18,
                  v60,
                  v48,
                  v49);
                v18 += v48;
                v113 += v49;
              }
              else
              {
                v109 = shape->Multiplier;
                v108.Data = v47;
                v79 = (double)((SHIWORD(v96) << 8) + BYTE1(v46)) * -4.0 / 240.0;
                v80 = -v18 - (int)(v79 * v109);
                v85 = (double)((SHIWORD(v97) << 8) + BYTE1(v97)) * 4.0 / 240.0;
                v110 = -v113 - (int)(v85 * v109);
                v86 = 4.0 * (double)((SHIWORD(v90) << 8) + BYTE1(v90)) / 240.0;
                v61 = -v113 - (int)(v86 * v109);
                v87 = -4.0 * (double)((SHIWORD(v89) << 8) + BYTE1(v89)) / 240.0;
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                  &v108,
                  -v18 - (int)(v109 * v87),
                  v61,
                  v80,
                  v110);
                v18 += v80;
                v113 += v110;
              }
              v42 = *((unsigned __int16 *)v88 + 1);
              v43 = v84 + 1;
              v44 = (int *)(v73 + 4);
              v50 = ++v84 < v42 - 1;
              v73 += 4;
            }
            while ( v50 );
          }
        }
      }
      v51 = shape->pContainer;
      v104 = shape->Multiplier;
      v52 = &v91[*(_DWORD *)v91];
      v103.Data = v51;
      v91 = v52;
      if ( v18 != v111 || v113 != v112 )
      {
        if ( v112 == v113 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
            &v103,
            v111 - v18);
        }
        else
        {
          v64 = v112 - v113;
          if ( v111 == v18 )
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
              &v103,
              v64);
          else
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
              &v103,
              v111 - v18,
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
    while ( v52 < v105 );
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
