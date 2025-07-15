void __thiscall Scaleform::GFx::MovieImpl::ProcessFocusKey(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Event::EventType event,
        const Scaleform::GFx::InputEventsQueueEntry::KeyEntry *keyEntry,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  unsigned int Code; // eax
  Scaleform::GFx::ProcessFocusKeyInfo *v5; // edi
  bool v6; // zf
  Scaleform::GFx::FocusGroupDescr *pFocusGroup; // ebx
  signed int Size; // eax
  int CurFocusIdx; // esi
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  Scaleform::GFx::InteractiveObject *v11; // ecx
  Scaleform::GFx::InteractiveObject *v12; // ecx
  __m128 *v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // ebx
  double v17; // st7
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v18; // ecx
  Scaleform::GFx::DisplayObjectBase *v19; // esi
  __m128 *v20; // eax
  unsigned int v21; // edi
  double v22; // st6
  double x1; // st7
  double v24; // st6
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st6
  double v29; // st6
  double v30; // st5
  double v31; // st6
  bool v32; // c0
  double v33; // st7
  int v34; // ebx
  float v35; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *Data; // ecx
  Scaleform::GFx::InteractiveObject *v37; // eax
  Scaleform::GFx::DisplayObjectBase **p_pObject; // ecx
  Scaleform::GFx::DisplayObjectBase *v39; // esi
  __m128 *v40; // eax
  unsigned int v41; // edi
  double v42; // st6
  double y1; // st7
  double v44; // st5
  double v45; // st5
  double v46; // st7
  double v47; // st6
  double v48; // st5
  double v49; // st5
  double v50; // st5
  double v51; // st6
  bool v52; // c0
  double v53; // st7
  int v54; // eax
  int v55; // esi
  Scaleform::RefCountNTSImpl *v56; // ecx
  Scaleform::RefCountNTSImpl *v57; // ecx
  float v58; // [esp+28h] [ebp-1A0h]
  float v59; // [esp+28h] [ebp-1A0h]
  float v60; // [esp+28h] [ebp-1A0h]
  float v61; // [esp+28h] [ebp-1A0h]
  float v62; // [esp+28h] [ebp-1A0h]
  float v63; // [esp+28h] [ebp-1A0h]
  float v64; // [esp+28h] [ebp-1A0h]
  float v65; // [esp+28h] [ebp-1A0h]
  float v66; // [esp+28h] [ebp-1A0h]
  float v67; // [esp+28h] [ebp-1A0h]
  float v68; // [esp+28h] [ebp-1A0h]
  float v69; // [esp+28h] [ebp-1A0h]
  float v70; // [esp+28h] [ebp-1A0h]
  float v71; // [esp+28h] [ebp-1A0h]
  float v72; // [esp+28h] [ebp-1A0h]
  float v73; // [esp+28h] [ebp-1A0h]
  float v74; // [esp+28h] [ebp-1A0h]
  float v75; // [esp+28h] [ebp-1A0h]
  float v76; // [esp+28h] [ebp-1A0h]
  float v77; // [esp+28h] [ebp-1A0h]
  float v78; // [esp+28h] [ebp-1A0h]
  float v79; // [esp+28h] [ebp-1A0h]
  float v80; // [esp+28h] [ebp-1A0h]
  float v81; // [esp+28h] [ebp-1A0h]
  float v82; // [esp+28h] [ebp-1A0h]
  float v83; // [esp+28h] [ebp-1A0h]
  float v84; // [esp+28h] [ebp-1A0h]
  float v85; // [esp+28h] [ebp-1A0h]
  float v86; // [esp+28h] [ebp-1A0h]
  float v87; // [esp+28h] [ebp-1A0h]
  float v88; // [esp+28h] [ebp-1A0h]
  int v89; // [esp+2Ch] [ebp-19Ch]
  float v90; // [esp+2Ch] [ebp-19Ch]
  float v91; // [esp+2Ch] [ebp-19Ch]
  float v92; // [esp+2Ch] [ebp-19Ch]
  float v93; // [esp+2Ch] [ebp-19Ch]
  float v94; // [esp+2Ch] [ebp-19Ch]
  float v95; // [esp+2Ch] [ebp-19Ch]
  float v96; // [esp+2Ch] [ebp-19Ch]
  float v97; // [esp+2Ch] [ebp-19Ch]
  float v98; // [esp+2Ch] [ebp-19Ch]
  float v99; // [esp+2Ch] [ebp-19Ch]
  float v100; // [esp+2Ch] [ebp-19Ch]
  float v101; // [esp+2Ch] [ebp-19Ch]
  float v102; // [esp+2Ch] [ebp-19Ch]
  float v103; // [esp+2Ch] [ebp-19Ch]
  float v104; // [esp+2Ch] [ebp-19Ch]
  float v105; // [esp+2Ch] [ebp-19Ch]
  float v106; // [esp+2Ch] [ebp-19Ch]
  float v107; // [esp+2Ch] [ebp-19Ch]
  float v108; // [esp+2Ch] [ebp-19Ch]
  float v109; // [esp+2Ch] [ebp-19Ch]
  float v110; // [esp+2Ch] [ebp-19Ch]
  float v111; // [esp+2Ch] [ebp-19Ch]
  float v112; // [esp+2Ch] [ebp-19Ch]
  float v113; // [esp+2Ch] [ebp-19Ch]
  float v114; // [esp+2Ch] [ebp-19Ch]
  float v115; // [esp+2Ch] [ebp-19Ch]
  float v116; // [esp+2Ch] [ebp-19Ch]
  float v117; // [esp+2Ch] [ebp-19Ch]
  float v118; // [esp+2Ch] [ebp-19Ch]
  char v119; // [esp+33h] [ebp-195h]
  char v120; // [esp+33h] [ebp-195h]
  int v121; // [esp+34h] [ebp-194h]
  float v122; // [esp+34h] [ebp-194h]
  float v123; // [esp+34h] [ebp-194h]
  int v124; // [esp+34h] [ebp-194h]
  Scaleform::Render::Rect<float> pr; // [esp+38h] [ebp-190h] BYREF
  float v126; // [esp+4Ch] [ebp-17Ch]
  float v127; // [esp+50h] [ebp-178h]
  int v128; // [esp+54h] [ebp-174h]
  Scaleform::Render::Rect<float> rc; // [esp+58h] [ebp-170h] BYREF
  Scaleform::Render::Rect<float> top; // [esp+68h] [ebp-160h] BYREF
  Scaleform::GFx::MovieImpl *v131; // [esp+84h] [ebp-144h]
  float v132; // [esp+88h] [ebp-140h]
  float v133; // [esp+8Ch] [ebp-13Ch]
  float v134; // [esp+90h] [ebp-138h]
  float v135; // [esp+94h] [ebp-134h]
  Scaleform::Render::Rect<float> v136; // [esp+98h] [ebp-130h] BYREF
  Scaleform::GFx::FocusGroupDescr *v137; // [esp+ACh] [ebp-11Ch]
  float v138; // [esp+B0h] [ebp-118h]
  float v139; // [esp+B4h] [ebp-114h]
  Scaleform::Render::Rect<float> v140; // [esp+B8h] [ebp-110h] BYREF
  float v141; // [esp+D0h] [ebp-F8h]
  float v142; // [esp+D4h] [ebp-F4h]
  Scaleform::Render::Rect<float> v143; // [esp+D8h] [ebp-F0h] BYREF
  Scaleform::Render::Rect<float> v144; // [esp+E8h] [ebp-E0h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+F8h] [ebp-D0h] BYREF
  Scaleform::Render::Rect<float> v146; // [esp+108h] [ebp-C0h] BYREF
  Scaleform::Render::Rect<float> v147; // [esp+118h] [ebp-B0h] BYREF
  float v148; // [esp+130h] [ebp-98h]
  float v149; // [esp+134h] [ebp-94h]
  float v150; // [esp+138h] [ebp-90h]
  float v151; // [esp+13Ch] [ebp-8Ch]
  float v152; // [esp+140h] [ebp-88h]
  float v153; // [esp+144h] [ebp-84h]
  Scaleform::Render::Rect<float> v154; // [esp+148h] [ebp-80h] BYREF
  Scaleform::Render::Rect<float> v155; // [esp+158h] [ebp-70h] BYREF
  Scaleform::Render::Matrix2x4<float> v156; // [esp+168h] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+188h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v158; // [esp+1A8h] [ebp-20h] BYREF

  v131 = this;
  if ( event != KeyDown )
    return;
  Code = keyEntry->Code;
  v5 = pfocusInfo;
  if ( Code != 9
    && (!this->FocusGroups[this->FocusGroupIndexes[keyEntry->KeyboardIndex]].FocusRectShown && !pfocusInfo->ManualFocus
     || Code != 37 && Code != 39 && Code != 38 && Code != 40) )
  {
    return;
  }
  Scaleform::GFx::MovieImpl::InitFocusKeyInfo(this, pfocusInfo, keyEntry, 0, 0.0);
  v6 = keyEntry->Code == 9;
  pFocusGroup = pfocusInfo->pFocusGroup;
  Size = pfocusInfo->pFocusGroup->TabableArray.Data.Size;
  v137 = pfocusInfo->pFocusGroup;
  v128 = Size;
  if ( v6 )
  {
    CurFocusIdx = pfocusInfo->CurFocusIdx;
    pfocusInfo->CurFocusIdx = -1;
    v121 = 0;
    if ( Size <= 0 )
      goto LABEL_159;
    while ( 1 )
    {
      if ( (keyEntry->KeysState & 1) != 0 )
      {
        if ( --CurFocusIdx < 0 )
          CurFocusIdx = Size - 1;
      }
      else if ( ++CurFocusIdx >= Size )
      {
        CurFocusIdx = 0;
      }
      pObject = pFocusGroup->TabableArray.Data.Data[CurFocusIdx].pObject;
      if ( pObject )
      {
        if ( pfocusInfo->InclFocusEnabled || pObject->IsTabable(pObject) )
        {
          v11 = pFocusGroup->TabableArray.Data.Data[CurFocusIdx].pObject;
          if ( v11->IsFocusAllowed(v11, v131, pfocusInfo->KeyboardIndex) )
          {
            pfocusInfo->CurFocusIdx = CurFocusIdx;
            goto LABEL_159;
          }
        }
        Size = v128;
      }
      if ( ++v121 >= Size )
        goto LABEL_159;
    }
  }
  v12 = pfocusInfo->CurFocused.pObject;
  if ( !v12 || !v12->IsFocusRectEnabled(v12) && (HIBYTE(v131->Flags) & 3) != 1 && !pfocusInfo->ManualFocus )
    goto LABEL_159;
  Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(pfocusInfo->CurFocused.pObject, &result);
  v13 = (__m128 *)pfocusInfo->CurFocused.pObject->GetFocusRect(pfocusInfo->CurFocused.pObject, &v155);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&result, (__m128 *)&pr, v13);
  v14 = keyEntry->Code;
  if ( pfocusInfo->PrevKeyCode == v14 )
  {
    if ( v14 == 38 || v14 == 40 )
    {
      pr.x1 = pfocusInfo->Prev_aRect.x1;
      pr.x2 = pfocusInfo->Prev_aRect.x2;
    }
    else if ( v14 == 39 || v14 == 37 )
    {
      pr.y1 = pfocusInfo->Prev_aRect.y1;
      pr.y2 = pfocusInfo->Prev_aRect.y2;
    }
  }
  else
  {
    Scaleform::Render::Rect<float>::operator=(&pfocusInfo->Prev_aRect, &pr);
    pfocusInfo->PrevKeyCode = keyEntry->Code;
  }
  v15 = keyEntry->Code;
  if ( v15 == 39 || v15 == 37 )
  {
    v34 = pfocusInfo->CurFocusIdx;
    if ( v15 == 39 )
      rc.x2 = 2147483600.0;
    else
      rc.x2 = -2147483600.0;
    rc.x1 = rc.x2;
    LODWORD(v35) = v128 - 1;
    v120 = 0;
    rc.y2 = 2147483600.0;
    LODWORD(v134) = v128 - 1;
    rc.y1 = 2147483600.0;
    if ( v128 - 1 <= 0 )
      goto LABEL_159;
    v124 = v128 - 1;
    while ( 1 )
    {
      if ( keyEntry->Code == 39 )
        ++v34;
      else
        --v34;
      if ( v34 < v128 )
      {
        if ( v34 < 0 )
          v34 = LODWORD(v35);
      }
      else
      {
        v34 = 0;
      }
      Data = v137->TabableArray.Data.Data;
      v37 = Data[v34].pObject;
      p_pObject = &Data[v34].pObject;
      if ( v37 )
        ++v37->RefCount;
      v39 = *p_pObject;
      if ( !v5->InclFocusEnabled
        && !((unsigned __int8 (__thiscall *)(Scaleform::GFx::DisplayObjectBase *))v39->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix3D)(*p_pObject)
        || !((unsigned __int8 (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::GFx::MovieImpl *, _DWORD))v39->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix)(
              v39,
              v131,
              v5->KeyboardIndex) )
      {
        Scaleform::RefCountNTSImpl::Release(v39);
        goto LABEL_158;
      }
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v39, &v158);
      v40 = (__m128 *)((int (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix2x4<float> *))v39->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].UpdateTransform3D)(
                        v39,
                        &v156);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v158, (__m128 *)&top, v40);
      v136.x1 = 0.0;
      v41 = keyEntry->Code;
      v136.y1 = 0.0;
      v136.x2 = 0.0;
      v136.y2 = 0.0;
      if ( v41 == 39 )
      {
        v146.x1 = pr.x2 + 1.0;
        v146.y1 = pr.y1;
        v146.x2 = 3.4028235e38;
        v146.y2 = pr.y2;
        Scaleform::Render::Rect<float>::operator=(&v136, &v146);
      }
      else
      {
        v147.x1 = 1.1754944e-38;
        v147.y1 = pr.y1;
        v147.x2 = pr.x1 - 1.0;
        v147.y2 = pr.y2;
        Scaleform::Render::Rect<float>::operator=(&v136, &v147);
      }
      if ( Scaleform::Render::Rect<float>::Intersects(&top, &v136)
        && (Scaleform::Render::Rect<float>::Rect<float>(&v154, &top),
            Scaleform::Render::Rect<float>::Intersect(&v154, &v136),
            v90 = v154.y2 - v154.y1,
            v90 >= 40.0) )
      {
        if ( !v120 )
        {
          pfocusInfo->CurFocusIdx = v34;
          Scaleform::Render::Rect<float>::operator=(&rc, &top);
          v120 = 1;
          goto LABEL_157;
        }
      }
      else if ( v120 )
      {
        goto LABEL_157;
      }
      v42 = pr.y2 - pr.y1;
      y1 = pr.y1;
      if ( v41 == 39 )
      {
        v91 = v42;
        v139 = y1 + v91 * 0.5;
        Scaleform::Render::Rect<float>::Rect<float>(&r, &top);
        Scaleform::Render::Rect<float>::Rect<float>(&v140, &rc);
        Scaleform::Render::Rect<float>::HClamp(&r, pr.x2, top.x2);
        Scaleform::Render::Rect<float>::HClamp(&v140, pr.x2, rc.x2);
        if ( !Scaleform::Render::Rect<float>::IsNormal(&r) )
          goto LABEL_157;
        v92 = r.x2 - r.x1;
        v93 = v92 * 0.05000000074505806;
        v44 = v93;
        v45 = v93 <= 0.0 ? v44 - 0.5 : v44 + 0.5;
        if ( (int)v45 <= 3 )
          goto LABEL_157;
        v94 = top.y2 - top.y1;
        v149 = top.y1 + v94 * 0.5;
        v95 = rc.y2 - rc.y1;
        v153 = 0.5 * v95 + rc.y1;
        v96 = r.x1 - pr.x2;
        v97 = 0.05000000074505806 * v96;
        v126 = floorf(v97);
        v98 = v149 - v139;
        v99 = v98 * 0.05000000074505806;
        v127 = floorf(v99);
        v100 = v140.x1 - pr.x2;
        v101 = v100 * 0.05000000074505806;
        v132 = floorf(v101);
        v102 = v153 - v139;
        v103 = v102 * 0.05000000074505806;
        v133 = floorf(v103);
        v46 = 0.0;
        v47 = v126;
        if ( v126 < 0.0 )
          goto LABEL_157;
      }
      else
      {
        v104 = v42;
        v142 = y1 + v104 * 0.5;
        Scaleform::Render::Rect<float>::Rect<float>(&v143, &top);
        Scaleform::Render::Rect<float>::Rect<float>(&v155, &rc);
        Scaleform::Render::Rect<float>::HClamp(&v143, top.x1, pr.x1);
        Scaleform::Render::Rect<float>::HClamp(&v155, rc.x1, pr.x1);
        if ( !Scaleform::Render::Rect<float>::IsNormal(&v143) )
          goto LABEL_157;
        v105 = v143.x2 - v143.x1;
        v106 = v105 * 0.05000000074505806;
        v48 = v106;
        v49 = v106 <= 0.0 ? v48 - 0.5 : v48 + 0.5;
        if ( (int)v49 <= 3 )
          goto LABEL_157;
        v107 = top.y2 - top.y1;
        v151 = top.y1 + v107 * 0.5;
        v108 = rc.y2 - rc.y1;
        v144.y1 = 0.5 * v108 + rc.y1;
        v109 = v143.x2 - pr.x1;
        v110 = 0.05000000074505806 * v109;
        v126 = floorf(v110);
        v111 = v151 - v142;
        v112 = v111 * 0.05000000074505806;
        v127 = floorf(v112);
        v113 = v155.x2 - pr.x1;
        v114 = v113 * 0.05000000074505806;
        v132 = floorf(v114);
        v115 = v144.y1 - v142;
        v116 = v115 * 0.05000000074505806;
        v133 = floorf(v116);
        v46 = 0.0;
        v47 = v126;
        if ( v126 > 0.0 )
          goto LABEL_157;
      }
      if ( v120 )
      {
        if ( v47 < v46 )
          v117 = -v47;
        else
          v117 = v47;
        v50 = v132;
        if ( v132 < v46 )
          v87 = -v50;
        else
          v87 = v132;
        if ( v87 <= (double)v117 )
        {
          if ( v50 != v47 )
            goto LABEL_157;
          v51 = v127;
          if ( v127 < v46 )
            v51 = -v51;
          v52 = v133 < v46;
          v53 = v133;
          if ( v52 )
            v53 = -v53;
          v88 = v53;
          v118 = v51;
          if ( v88 <= (double)v118 )
            goto LABEL_157;
        }
LABEL_156:
        pfocusInfo->CurFocusIdx = v34;
        Scaleform::Render::Rect<float>::operator=(&rc, &top);
        goto LABEL_157;
      }
      if ( v132 * v132 + v133 * v133 > v47 * v47 + v127 * v127 )
        goto LABEL_156;
LABEL_157:
      Scaleform::RefCountNTSImpl::Release(v39);
      v5 = pfocusInfo;
LABEL_158:
      if ( !--v124 )
        goto LABEL_159;
      v35 = v134;
    }
  }
  if ( v15 == 38 || v15 == 40 )
  {
    v16 = pfocusInfo->CurFocusIdx;
    top.x2 = 0.0;
    top.y2 = 0.0;
    v17 = 2147483600.0;
    top.x1 = 2147483600.0;
    if ( v15 != 40 )
      v17 = -2147483600.0;
    top.y1 = v17;
    v119 = 0;
    if ( v128 - 1 > 0 )
    {
      v89 = v128 - 1;
      while ( 1 )
      {
        if ( keyEntry->Code == 40 )
          ++v16;
        else
          --v16;
        if ( v16 < v128 )
        {
          if ( v16 < 0 )
            v16 = v128 - 1;
        }
        else
        {
          v16 = 0;
        }
        v18 = &v137->TabableArray.Data.Data[v16];
        if ( v18->pObject )
          ++v18->pObject->RefCount;
        v19 = v18->pObject;
        if ( v5->InclFocusEnabled
          || ((unsigned __int8 (__thiscall *)(Scaleform::GFx::InteractiveObject *))v19->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix3D)(v18->pObject) )
        {
          if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::GFx::MovieImpl *, _DWORD))v19->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix)(
                 v19,
                 v131,
                 v5->KeyboardIndex) )
          {
            break;
          }
        }
        Scaleform::RefCountNTSImpl::Release(v19);
LABEL_97:
        if ( !--v89 )
          goto LABEL_159;
      }
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v19, &v156);
      v20 = (__m128 *)((int (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *))v19->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].UpdateTransform3D)(
                        v19,
                        &v155);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v156, (__m128 *)&rc, v20);
      v144.x1 = 0.0;
      v21 = keyEntry->Code;
      v144.y1 = 0.0;
      v144.x2 = 0.0;
      v144.y2 = 0.0;
      if ( v21 == 40 )
      {
        v143.x1 = pr.x1;
        v143.y1 = pr.y2 + 1.0;
        v143.x2 = pr.x2;
        v143.y2 = 3.4028235e38;
        Scaleform::Render::Rect<float>::operator=(&v144, &v143);
      }
      else
      {
        r.x1 = pr.x1;
        r.y1 = 1.1754944e-38;
        r.x2 = pr.x2;
        r.y2 = pr.y1 - 1.0;
        Scaleform::Render::Rect<float>::operator=(&v144, &r);
      }
      if ( Scaleform::Render::Rect<float>::Intersects(&rc, &v144)
        && (Scaleform::Render::Rect<float>::Rect<float>(&v154, &rc),
            Scaleform::Render::Rect<float>::Intersect(&v154, &v144),
            v58 = v154.x2 - v154.x1,
            v58 >= 40.0) )
      {
        if ( !v119 )
        {
          pfocusInfo->CurFocusIdx = v16;
          Scaleform::Render::Rect<float>::operator=(&top, &rc);
          v119 = 1;
LABEL_96:
          Scaleform::RefCountNTSImpl::Release(v19);
          v5 = pfocusInfo;
          goto LABEL_97;
        }
      }
      else if ( v119 )
      {
        goto LABEL_96;
      }
      v22 = pr.x2 - pr.x1;
      x1 = pr.x1;
      if ( v21 == 38 )
      {
        v59 = v22;
        v132 = x1 + v59 * 0.5;
        Scaleform::Render::Rect<float>::Rect<float>(&v140, &rc);
        Scaleform::Render::Rect<float>::Rect<float>(&v147, &top);
        Scaleform::Render::Rect<float>::VClamp(&v140, rc.y1, pr.y1);
        Scaleform::Render::Rect<float>::VClamp(&v147, top.y1, pr.y1);
        if ( !Scaleform::Render::Rect<float>::IsNormal(&v140) )
          goto LABEL_96;
        v60 = v140.y2 - v140.y1;
        v61 = v60 * 0.05000000074505806;
        v24 = v61;
        v25 = v61 <= 0.0 ? v24 - 0.5 : v24 + 0.5;
        if ( (int)v25 <= 3 )
          goto LABEL_96;
        v62 = v140.x2 - v140.x1;
        v141 = v140.x1 + v62 * 0.5;
        v63 = v147.x2 - v147.x1;
        v150 = 0.5 * v63 + v147.x1;
        v64 = v141 - v132;
        v65 = 0.05000000074505806 * v64;
        v134 = floorf(v65);
        v66 = v140.y2 - pr.y1;
        v67 = v66 * 0.05000000074505806;
        v135 = floorf(v67);
        v68 = v150 - v132;
        v69 = v68 * 0.05000000074505806;
        v126 = floorf(v69);
        v70 = v147.y2 - pr.y1;
        v71 = v70 * 0.05000000074505806;
        v127 = floorf(v71);
        v26 = 0.0;
        v27 = v135;
        if ( v135 > 0.0 )
          goto LABEL_96;
      }
      else
      {
        v72 = v22;
        v138 = x1 + v72 * 0.5;
        Scaleform::Render::Rect<float>::Rect<float>(&v136, &rc);
        Scaleform::Render::Rect<float>::Rect<float>(&v146, &top);
        Scaleform::Render::Rect<float>::VClamp(&v136, pr.y2, rc.y2);
        Scaleform::Render::Rect<float>::VClamp(&v146, pr.y2, top.y2);
        if ( !Scaleform::Render::Rect<float>::IsNormal(&v136) )
          goto LABEL_96;
        v73 = v136.y2 - v136.y1;
        v74 = v73 * 0.05000000074505806;
        v28 = v74;
        v29 = v74 <= 0.0 ? v28 - 0.5 : v28 + 0.5;
        if ( (int)v29 <= 3 )
          goto LABEL_96;
        v75 = v136.x2 - v136.x1;
        v152 = v136.x1 + v75 * 0.5;
        v76 = v146.x2 - v146.x1;
        v148 = 0.5 * v76 + v146.x1;
        v77 = v152 - v138;
        v78 = 0.05000000074505806 * v77;
        v134 = floorf(v78);
        v79 = v136.y1 - pr.y2;
        v80 = v79 * 0.05000000074505806;
        v135 = floorf(v80);
        v81 = v148 - v138;
        v82 = v81 * 0.05000000074505806;
        v126 = floorf(v82);
        v83 = v146.y1 - pr.y2;
        v84 = v83 * 0.05000000074505806;
        v127 = floorf(v84);
        v26 = 0.0;
        v27 = v135;
        if ( v135 < 0.0 )
          goto LABEL_96;
      }
      if ( v119 )
      {
        if ( v27 < v26 )
          v122 = -v27;
        else
          v122 = v27;
        v30 = v127;
        if ( v127 < v26 )
          v85 = -v30;
        else
          v85 = v127;
        if ( v85 <= (double)v122 )
        {
          if ( v30 != v27 )
            goto LABEL_96;
          v31 = v134;
          if ( v134 < v26 )
            v31 = -v31;
          v32 = v126 < v26;
          v33 = v126;
          if ( v32 )
            v33 = -v33;
          v123 = v33;
          v86 = v31;
          if ( v123 <= (double)v86 )
            goto LABEL_96;
        }
      }
      else if ( v126 * v126 + v127 * v127 <= v27 * v27 + v134 * v134 )
      {
        goto LABEL_96;
      }
      pfocusInfo->CurFocusIdx = v16;
      Scaleform::Render::Rect<float>::operator=(&top, &rc);
      goto LABEL_96;
    }
  }
LABEL_159:
  v54 = v5->CurFocusIdx;
  if ( v54 < 0 || v54 >= v128 )
  {
    v57 = v5->CurFocused.pObject;
    if ( v57 )
      Scaleform::RefCountNTSImpl::Release(v57);
    v5->CurFocused.pObject = 0;
  }
  else
  {
    v55 = (int)&v137->TabableArray.Data.Data[v54];
    if ( *(_DWORD *)v55 )
      ++*(_DWORD *)(*(_DWORD *)v55 + 4);
    v56 = v5->CurFocused.pObject;
    if ( v56 )
      Scaleform::RefCountNTSImpl::Release(v56);
    v5->CurFocused.pObject = *(Scaleform::GFx::InteractiveObject **)v55;
  }
}
