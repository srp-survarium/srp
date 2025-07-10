void __thiscall Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ColorTransform>::ExecuteHW(
        Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *v2; // edi
  Scaleform::Render::TextureManager *v3; // eax
  void (__thiscall *ExecuteHWGetImages)(Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *, Scaleform::Render::DrawableImage **, Scaleform::Render::Size<float> *); // edx
  Scaleform::Render::TextureManager *v5; // ebx
  unsigned int i; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  Scaleform::Render::DrawableImage *pObject; // ecx
  Scaleform::Render::DrawableImage *v12; // esi
  int v13; // eax
  const Scaleform::Render::Size<unsigned long> *v14; // eax
  Scaleform::Render::TextureManager_vtbl *v15; // esi
  int v16; // eax
  bool v17; // zf
  bool (__thiscall *GetRequireSourceRead)(Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *); // eax
  bool v19; // bl
  double v20; // st7
  Scaleform::Render::RenderTarget *v21; // esi
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  Scaleform::Render::DICommandContext *v26; // ebx
  Scaleform::Render::HAL *pHAL; // ecx
  unsigned int v28; // ebx
  unsigned int v29; // edi
  unsigned int v30; // edx
  int v31; // ebx
  double v32; // st6
  double v33; // st7
  unsigned int v34; // eax
  unsigned int v35; // eax
  int v36; // edx
  int v37; // edx
  int v38; // ecx
  int v39; // edx
  Scaleform::Render::HAL *v40; // ecx
  double v41; // st7
  int Width; // eax
  double v43; // st7
  int Height; // ecx
  double v45; // st7
  int x2; // eax
  int *v47; // edi
  Scaleform::Render::Texture *(__thiscall *GetTexture)(Scaleform::Render::RenderTarget *); // eax
  int v49; // ebx
  int v50; // eax
  Scaleform::Render::Point<long> *v51; // [esp+6810h] [ebp-170h]
  unsigned int v53; // [esp+6824h] [ebp-15Ch]
  unsigned int v54; // [esp+6824h] [ebp-15Ch]
  float v55; // [esp+6824h] [ebp-15Ch]
  float v56; // [esp+6824h] [ebp-15Ch]
  float v57; // [esp+6824h] [ebp-15Ch]
  int v58; // [esp+6824h] [ebp-15Ch]
  float v59; // [esp+6828h] [ebp-158h] BYREF
  float v60; // [esp+682Ch] [ebp-154h]
  float v61; // [esp+6830h] [ebp-150h]
  __int16 v62; // [esp+6836h] [ebp-14Ah]
  float v63; // [esp+6838h] [ebp-148h]
  float v64; // [esp+683Ch] [ebp-144h]
  __int64 v65; // [esp+6840h] [ebp-140h] BYREF
  float v66; // [esp+6848h] [ebp-138h]
  float v67; // [esp+684Ch] [ebp-134h]
  int v68; // [esp+6854h] [ebp-12Ch]
  float v69; // [esp+6858h] [ebp-128h]
  float v70; // [esp+685Ch] [ebp-124h]
  float v71; // [esp+6860h] [ebp-120h]
  float v72; // [esp+6864h] [ebp-11Ch]
  int v73; // [esp+6868h] [ebp-118h]
  int v74; // [esp+686Ch] [ebp-114h]
  Scaleform::Render::Rect<long> srcRect; // [esp+6870h] [ebp-110h] BYREF
  float v76; // [esp+6880h] [ebp-100h] BYREF
  float v77; // [esp+6884h] [ebp-FCh]
  float v78; // [esp+6888h] [ebp-F8h]
  float v79; // [esp+688Ch] [ebp-F4h]
  float v80; // [esp+6890h] [ebp-F0h]
  float v81; // [esp+6894h] [ebp-ECh]
  float v82; // [esp+6898h] [ebp-E8h]
  float v83; // [esp+689Ch] [ebp-E4h]
  int v84; // [esp+68A8h] [ebp-D8h] BYREF
  int v85; // [esp+68ACh] [ebp-D4h]
  float v86; // [esp+68B0h] [ebp-D0h] BYREF
  float v87; // [esp+68B4h] [ebp-CCh]
  float v88; // [esp+68B8h] [ebp-C8h]
  float v89; // [esp+68BCh] [ebp-C4h]
  float v90; // [esp+68C0h] [ebp-C0h]
  float v91; // [esp+68C4h] [ebp-BCh]
  float v92; // [esp+68C8h] [ebp-B8h]
  float v93; // [esp+68CCh] [ebp-B4h]
  float v94; // [esp+68D0h] [ebp-B0h] BYREF
  float v95; // [esp+68D4h] [ebp-ACh]
  float v96; // [esp+68D8h] [ebp-A8h]
  float v97; // [esp+68DCh] [ebp-A4h]
  float v98; // [esp+68E0h] [ebp-A0h]
  float v99; // [esp+68E4h] [ebp-9Ch]
  float v100; // [esp+68E8h] [ebp-98h]
  float v101; // [esp+68ECh] [ebp-94h]
  float v102; // [esp+68F0h] [ebp-90h]
  float v103; // [esp+68F4h] [ebp-8Ch]
  float v104; // [esp+68F8h] [ebp-88h]
  float v105; // [esp+68FCh] [ebp-84h]
  float v106; // [esp+6900h] [ebp-80h]
  float v107; // [esp+6904h] [ebp-7Ch]
  float v108; // [esp+6908h] [ebp-78h]
  float v109; // [esp+690Ch] [ebp-74h]
  float v110; // [esp+6910h] [ebp-70h]
  float v111; // [esp+6914h] [ebp-6Ch]
  float v112; // [esp+6918h] [ebp-68h]
  float v113; // [esp+691Ch] [ebp-64h]
  float v114; // [esp+6920h] [ebp-60h]
  float v115; // [esp+6924h] [ebp-5Ch]
  float v116; // [esp+6928h] [ebp-58h]
  float v117; // [esp+692Ch] [ebp-54h]
  float v118; // [esp+693Ch] [ebp-44h] BYREF
  int v119; // [esp+6940h] [ebp-40h]
  float v120; // [esp+6944h] [ebp-3Ch]
  _DWORD v121[3]; // [esp+6948h] [ebp-38h] BYREF
  float v122; // [esp+6954h] [ebp-2Ch] BYREF
  float v123; // [esp+6958h] [ebp-28h]
  float v124; // [esp+695Ch] [ebp-24h]
  float v125; // [esp+6960h] [ebp-20h]
  float v126; // [esp+6964h] [ebp-1Ch]
  float v127; // [esp+6968h] [ebp-18h]
  _DWORD v128[3]; // [esp+696Ch] [ebp-14h]
  int v129; // [esp+6978h] [ebp-8h] BYREF

  v2 = this;
  v3 = context->pHAL->GetTextureManager(context->pHAL);
  ExecuteHWGetImages = v2->ExecuteHWGetImages;
  v5 = v3;
  memset(v121, 0, sizeof(v121));
  ExecuteHWGetImages(v2, (Scaleform::Render::DrawableImage **)v121, (Scaleform::Render::Size<float> *)&v122);
  for ( i = 0; i < 3; ++i )
  {
    v7 = v121[i];
    if ( v7 )
      v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 104))(v7);
    else
      v8 = 0;
    v9 = v121[i];
    v128[i] = v8;
    if ( v9 )
      v10 = (*(int (__thiscall **)(int, Scaleform::Render::TextureManager *))(*(_DWORD *)v9 + 84))(v9, v5);
    else
      v10 = 0;
    *(_DWORD *)((char *)&v118 + i * 4) = v10;
  }
  pObject = v2->pImage.pObject;
  v12 = v2->pSource.pObject;
  memset(&srcRect, 0, sizeof(srcRect));
  v13 = (int)pObject->GetSize(pObject, (Scaleform::Render::Size<unsigned long> *)&v84);
  v14 = (const Scaleform::Render::Size<unsigned long> *)((int (__thiscall *)(Scaleform::Render::DrawableImage *, float *, int))v12->GetSize)(
                                                          v12,
                                                          &v59,
                                                          v13);
  Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
    v2,
    v14,
    (const Scaleform::Render::Size<unsigned long> *)&v2->SourceRect,
    &srcRect,
    (Scaleform::Render::Rect<long> *)&v129,
    v51);
  v15 = v5->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  v16 = ((int (__thiscall *)(Scaleform::Render::TextureManager *, int))v5->GetDrawableImageFormat)(v5, 1152);
  v17 = ((unsigned __int8 (__thiscall *)(Scaleform::Render::TextureManager *, int))v15->IsNonPow2Supported)(v5, v16) == 0;
  GetRequireSourceRead = v2->GetRequireSourceRead;
  v19 = v17;
  LOBYTE(v62) = v17;
  v20 = 0.0;
  v21 = 0;
  HIBYTE(v68) = GetRequireSourceRead(v2);
  if ( HIBYTE(v68) )
  {
    v84 = srcRect.x2 - srcRect.x1;
    v85 = srcRect.y2 - srcRect.y1;
    if ( v19 )
    {
      v23 = ((((unsigned int)(srcRect.x2 - srcRect.x1 - 1) >> 1) | (srcRect.x2 - srcRect.x1 - 1)) >> 2)
          | ((unsigned int)(srcRect.x2 - srcRect.x1 - 1) >> 1)
          | (srcRect.x2 - srcRect.x1 - 1);
      v24 = (((v23 >> 4) | v23) >> 8) | (v23 >> 4) | v23;
      v84 = (v24 | HIWORD(v24)) + 1;
      v22 = srcRect.y2 - srcRect.y1;
      v25 = ((((((((unsigned int)(v22 - 1) >> 1) | (v22 - 1)) >> 2) | ((unsigned int)(v22 - 1) >> 1) | (v22 - 1)) >> 4)
            | ((((unsigned int)(v22 - 1) >> 1) | (v22 - 1)) >> 2)
            | ((unsigned int)(v22 - 1) >> 1)
            | (v22 - 1)) >> 8)
          | ((((((unsigned int)(v22 - 1) >> 1) | (v22 - 1)) >> 2) | ((unsigned int)(v22 - 1) >> 1) | (v22 - 1)) >> 4)
          | ((((unsigned int)(v22 - 1) >> 1) | (v22 - 1)) >> 2)
          | ((unsigned int)(v22 - 1) >> 1)
          | (v22 - 1);
      v85 = (v25 | HIWORD(v25)) + 1;
    }
    v26 = context;
    v21 = context->pHAL->CreateTempRenderTarget(context->pHAL, &v84, 0);
    v59 = (float)(unsigned int)v84;
    pHAL = context->pHAL;
    v60 = (float)(unsigned int)v85;
    *(float *)&v65 = 0.0;
    *((float *)&v65 + 1) = 0.0;
    v66 = v59;
    v67 = v60;
    pHAL->PushRenderTarget(pHAL, (const Scaleform::Render::Rect<float> *)&v65, v21, 2u);
    v20 = 0.0;
  }
  else
  {
    v26 = context;
  }
  v94 = 1.0;
  v99 = 1.0;
  v102 = 1.0;
  v107 = 1.0;
  v110 = 1.0;
  v115 = 1.0;
  v95 = v20;
  v96 = v20;
  v97 = v20;
  v98 = v20;
  v100 = v20;
  v101 = v20;
  v103 = v20;
  v104 = v20;
  v105 = v20;
  v106 = v20;
  v108 = v20;
  v109 = v20;
  v111 = v20;
  v112 = v20;
  v113 = v20;
  v114 = v20;
  v116 = v20;
  v117 = v20;
  if ( LODWORD(v118) )
  {
    v28 = *(_DWORD *)(LODWORD(v118) + 28);
    v61 = *(float *)(LODWORD(v118) + 24);
    v69 = (float)LODWORD(v61);
    v70 = (float)v28;
    v73 = srcRect.x2 - srcRect.x1;
    v71 = (float)(srcRect.x2 - srcRect.x1);
    v74 = srcRect.y2 - srcRect.y1;
    v72 = (float)(srcRect.y2 - srcRect.y1);
    v63 = v71 / v69;
    v64 = v72 / v70;
    v94 = v63;
    v61 = v63 * 0.0;
    v95 = v61;
    v96 = v61;
    v97 = v61;
    v61 = v64 * 0.0;
    v98 = v61;
    v100 = v61;
    v101 = v61;
    v99 = v64;
    v29 = *(_DWORD *)(LODWORD(v118) + 24);
    v61 = *(float *)(LODWORD(v118) + 28);
    *(float *)&v65 = (float)v29;
    *((float *)&v65 + 1) = (float)LODWORD(v61);
    v2 = this;
    v26 = context;
    v59 = v122 / *(float *)&v65;
    v60 = v123 / *((float *)&v65 + 1);
    v97 = v97 + v59;
    v101 = v101 + v60;
  }
  if ( v119 )
  {
    v30 = *(_DWORD *)(v119 + 28);
    v69 = (float)*(unsigned int *)(v119 + 24);
    v70 = (float)v30;
    v73 = srcRect.x2 - srcRect.x1;
    v71 = (float)(srcRect.x2 - srcRect.x1);
    v74 = srcRect.y2 - srcRect.y1;
    v72 = (float)(srcRect.y2 - srcRect.y1);
    v63 = v71 / v69;
    v64 = v72 / v70;
    v102 = v63;
    v61 = v63 * 0.0;
    v103 = v61;
    v104 = v61;
    v105 = v61;
    v61 = v64 * 0.0;
    v106 = v61;
    v108 = v61;
    v109 = v61;
    v107 = v64;
    v53 = *(_DWORD *)(v119 + 28);
    *(float *)&v65 = (float)*(unsigned int *)(v119 + 24);
    *((float *)&v65 + 1) = (float)v53;
    v26 = context;
    v59 = v124 / *(float *)&v65;
    v60 = v125 / *((float *)&v65 + 1);
    v105 = v105 + v59;
    v109 = v61 + v60;
  }
  if ( LODWORD(v120) )
  {
    v31 = *(_DWORD *)(LODWORD(v120) + 28);
    v69 = (float)*(unsigned int *)(LODWORD(v120) + 24);
    v32 = (double)*(int *)(LODWORD(v120) + 28);
    if ( v31 < 0 )
      v32 = v32 + 4294967300.0;
    v70 = v32;
    v73 = srcRect.x2 - srcRect.x1;
    v74 = srcRect.y2 - srcRect.y1;
    v71 = (float)(srcRect.x2 - srcRect.x1);
    v72 = (float)(srcRect.y2 - srcRect.y1);
    v63 = v71 / v69;
    v64 = v72 / v70;
    v110 = v63;
    v61 = v63 * 0.0;
    v111 = v61;
    v112 = v61;
    v113 = v61;
    v61 = 0.0 * v64;
    v114 = v61;
    v116 = v61;
    v117 = v61;
    v115 = v64;
    v54 = *(_DWORD *)(LODWORD(v120) + 28);
    *(float *)&v65 = (float)*(unsigned int *)(LODWORD(v120) + 24);
    *((float *)&v65 + 1) = (float)v54;
    v26 = context;
    v59 = v126 / *(float *)&v65;
    v60 = v127 / *((float *)&v65 + 1);
    v113 = v113 + v59;
    v117 = v61 + v60;
  }
  v2->ExecuteHWCopyAction(
    v2,
    v26,
    (Scaleform::Render::Texture **)&v118,
    (const Scaleform::Render::Matrix2x4<float> *)&v94);
  if ( HIBYTE(v68) )
  {
    v26->pHAL->PopRenderTarget(v26->pHAL, 2u);
    v76 = 1.0;
    v77 = 0.0;
    v78 = 0.0;
    v79 = 0.0;
    v80 = 0.0;
    v82 = 0.0;
    v83 = 0.0;
    v87 = 0.0;
    v88 = 0.0;
    v89 = 0.0;
    v90 = 0.0;
    v92 = 0.0;
    v93 = 0.0;
    v81 = 1.0;
    v86 = 1.0;
    v91 = 1.0;
    *(float *)&v65 = (float)(srcRect.x2 - srcRect.x1);
    *((float *)&v65 + 1) = (float)(srcRect.y2 - srcRect.y1);
    v59 = *(float *)&v65;
    v60 = *((float *)&v65 + 1);
    if ( (_BYTE)v62 )
    {
      v33 = *((float *)&v65 + 1);
      v65 = (__int64)*(float *)&v65;
      v34 = ((((((((unsigned int)(v65 - 1) >> 1) | ((_DWORD)v65 - 1)) >> 2)
              | ((unsigned int)(v65 - 1) >> 1)
              | ((_DWORD)v65 - 1)) >> 4)
            | ((((unsigned int)(v65 - 1) >> 1) | ((_DWORD)v65 - 1)) >> 2)
            | ((unsigned int)(v65 - 1) >> 1)
            | ((_DWORD)v65 - 1)) >> 8)
          | ((((((unsigned int)(v65 - 1) >> 1) | ((_DWORD)v65 - 1)) >> 2)
            | ((unsigned int)(v65 - 1) >> 1)
            | ((_DWORD)v65 - 1)) >> 4)
          | ((((unsigned int)(v65 - 1) >> 1) | ((_DWORD)v65 - 1)) >> 2)
          | ((unsigned int)(v65 - 1) >> 1)
          | (v65 - 1);
      v59 = (float)((v34 | HIWORD(v34)) + 1);
      v65 = (__int64)v33;
      v35 = (((((((((unsigned int)(__int64)v33 - 1) >> 1) | ((unsigned int)(__int64)v33 - 1)) >> 2)
              | (((unsigned int)(__int64)v33 - 1) >> 1)
              | ((unsigned int)(__int64)v33 - 1)) >> 4)
            | (((((unsigned int)(__int64)v33 - 1) >> 1) | ((unsigned int)(__int64)v33 - 1)) >> 2)
            | (((unsigned int)(__int64)v33 - 1) >> 1)
            | ((unsigned int)(__int64)v33 - 1)) >> 8)
          | (((((((unsigned int)(__int64)v33 - 1) >> 1) | ((unsigned int)(__int64)v33 - 1)) >> 2)
            | (((unsigned int)(__int64)v33 - 1) >> 1)
            | ((unsigned int)(__int64)v33 - 1)) >> 4)
          | (((((unsigned int)(__int64)v33 - 1) >> 1) | ((unsigned int)(__int64)v33 - 1)) >> 2)
          | (((unsigned int)(__int64)v33 - 1) >> 1)
          | ((__int64)v33 - 1);
      v60 = (float)((v35 | HIWORD(v35)) + 1);
    }
    v36 = *(_DWORD *)(v128[0] + 40) - *(_DWORD *)(v128[0] + 32);
    *(float *)&v65 = (float)(unsigned int)(*(_DWORD *)(v128[0] + 36) - *(_DWORD *)(v128[0] + 28));
    *((float *)&v65 + 1) = (float)(unsigned int)v36;
    v63 = v59 / *(float *)&v65;
    v64 = v60 / *((float *)&v65 + 1);
    v76 = v63;
    v55 = v63 * 0.0;
    v77 = v55;
    v78 = v55;
    v79 = v55;
    v56 = 0.0 * v64;
    v80 = v56;
    v82 = v56;
    v83 = v56;
    v81 = v64;
    v37 = *(_DWORD *)(v128[0] + 40) - *(_DWORD *)(v128[0] + 32);
    v63 = (float)(unsigned int)(*(_DWORD *)(v128[0] + 36) - *(_DWORD *)(v128[0] + 28));
    v38 = *(_DWORD *)(v128[0] + 36);
    v64 = (float)(unsigned int)v37;
    v39 = *(_DWORD *)(v128[0] + 40) - *(_DWORD *)(v128[0] + 32);
    v59 = (float)(unsigned int)(v38 - *(_DWORD *)(v128[0] + 28));
    v60 = (float)(unsigned int)v39;
    v40 = v26->pHAL;
    *(float *)&v65 = v59 * 0.5;
    *((float *)&v65 + 1) = 0.5 * v60;
    v59 = v122 - *(float *)&v65;
    v60 = v123 - *((float *)&v65 + 1);
    *(float *)&v65 = v59 / v63;
    *((float *)&v65 + 1) = v60 / v64;
    v79 = v79 + *(float *)&v65;
    v83 = v56 + *((float *)&v65 + 1);
    v41 = ((double (__thiscall *)(Scaleform::Render::HAL *))v40->GetViewportScaling)(v40);
    Width = v21->BufferSize.Width;
    v57 = v41 * 2.0;
    v76 = v76 * 2.0;
    v77 = v77 * 2.0;
    v78 = v78 * 2.0;
    v79 = 2.0 * v79;
    v80 = v80 * v57;
    v81 = v81 * v57;
    v82 = v82 * v57;
    v83 = v57 * v83;
    v43 = (double)(int)v21->BufferSize.Width;
    if ( Width < 0 )
      v43 = v43 + 4294967300.0;
    Height = v21->BufferSize.Height;
    *(float *)&v65 = v43;
    v45 = (double)(int)v21->BufferSize.Height;
    if ( Height < 0 )
      v45 = v45 + 4294967300.0;
    x2 = v21->ViewRect.x2;
    *((float *)&v65 + 1) = v45;
    v58 = v21->ViewRect.y2 - v21->ViewRect.y1;
    v59 = (float)(unsigned int)(x2 - v21->ViewRect.x1);
    v60 = (float)(unsigned int)v58;
    v47 = (int *)v26->pHAL;
    GetTexture = v21->GetTexture;
    v63 = v59 / *(float *)&v65;
    v64 = v60 / *((float *)&v65 + 1);
    v86 = v63 * v86;
    v87 = v87 * v63;
    v88 = v88 * v63;
    v89 = v63 * v89;
    v90 = v90 * v64;
    v91 = v91 * v64;
    v92 = v92 * v64;
    v93 = v64 * v93;
    v49 = *v47;
    v50 = ((int (__thiscall *)(Scaleform::Render::RenderTarget *, float *, float *))GetTexture)(v21, &v76, &v86);
    (*(void (__thiscall **)(int *, int))(v49 + 208))(v47, v50);
    v21->SetInUse(v21, RTUse_Unused);
  }
  if ( v21 )
    v21->Release(v21);
}
