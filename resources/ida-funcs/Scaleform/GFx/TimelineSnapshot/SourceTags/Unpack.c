void __userpurge Scaleform::GFx::TimelineSnapshot::SourceTags::Unpack(
        Scaleform::GFx::TimelineSnapshot::SourceTags *this@<ecx>,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        char a16)
{
  int v17; // edi
  float *v18; // esi
  Scaleform::GFx::GFxPlaceObjectBase *pDepthTag; // eax
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *v20; // edi
  Scaleform::GFx::GFxPlaceObjectBase *pCharIdTag; // eax
  int v22; // eax
  Scaleform::GFx::GFxPlaceObjectBase *pMatrixTag; // eax
  int v24; // eax
  unsigned int v25; // eax
  double v26; // st7
  float *v27; // eax
  Scaleform::GFx::GFxPlaceObjectBase *pClassNameTag; // eax
  int v29; // eax
  Scaleform::GFx::GFxPlaceObjectBase *pCxFormTag; // eax
  int v31; // eax
  Scaleform::GFx::GFxPlaceObjectBase *pBlendModeTag; // eax
  int v33; // eax
  Scaleform::GFx::GFxPlaceObjectBase *pClipDepthTag; // eax
  int v35; // eax
  Scaleform::GFx::GFxPlaceObjectBase *pRatioTag; // eax
  int v37; // eax
  Scaleform::GFx::GFxPlaceObjectBase *pFiltersTag; // eax
  int v39; // eax
  int v40; // eax
  Scaleform::GFx::Resource *v41; // ecx
  float *v42; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v44; // edi
  char *v45; // esi
  Scaleform::RefCountVImpl *v46; // ecx
  _QWORD v47[5]; // [esp+400h] [ebp-3F0h] BYREF
  float v48[18]; // [esp+428h] [ebp-3C8h] BYREF
  _BYTE v49[112]; // [esp+470h] [ebp-380h] BYREF
  _BYTE v50[112]; // [esp+4E0h] [ebp-310h] BYREF
  _BYTE v51[112]; // [esp+550h] [ebp-2A0h] BYREF
  _BYTE v52[112]; // [esp+5C0h] [ebp-230h] BYREF
  _BYTE v53[112]; // [esp+630h] [ebp-1C0h] BYREF
  _BYTE v54[112]; // [esp+6A0h] [ebp-150h] BYREF
  _BYTE v55[112]; // [esp+710h] [ebp-E0h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData v56; // [esp+780h] [ebp-70h] BYREF

  this->pMainTag->Unpack(this->pMainTag, data);
  v17 = 8;
  v18 = v48;
  do
  {
    Scaleform::Render::Cxform::Cxform((Scaleform::Render::Cxform *)(v18 - 10));
    *(v18 - 2) = 1.0;
    v18[6] = 0.0;
    *(v18 - 1) = 0.0;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    v18[4] = 0.0;
    v18[5] = 0.0;
    v18[3] = 1.0;
    *((_DWORD *)v18 + 9) = 0x40000;
    *((_WORD *)v18 + 23) = 0;
    v18[7] = 0.0;
    v18[8] = 0.0;
    *((_WORD *)v18 + 22) = 0;
    *((_BYTE *)v18 + 48) = 0;
    v18[10] = 0.0;
    v18 += 28;
    --v17;
  }
  while ( v17 >= 0 );
  pDepthTag = this->pDepthTag;
  if ( pDepthTag == this->pMainTag )
  {
    v20 = data;
  }
  else
  {
    ((void (__stdcall *)(_QWORD *))pDepthTag->Unpack)(v47);
    v20 = data;
    *(float *)&data->Pos.Depth = v48[8];
    data->Pos.Flags.Flags |= 1u;
  }
  pCharIdTag = this->pCharIdTag;
  if ( pCharIdTag != this->pMainTag )
  {
    if ( this->pDepthTag == pCharIdTag )
    {
      v22 = 0;
    }
    else
    {
      ((void (__stdcall *)(_BYTE *))pCharIdTag->Unpack)(v49);
      v22 = 1;
    }
    *(float *)&v20->Pos.CharacterId.Id = v48[28 * v22 + 9];
    v20->Pos.Flags.Flags |= 2u;
  }
  pMatrixTag = this->pMatrixTag;
  if ( pMatrixTag != this->pMainTag )
  {
    if ( this->pDepthTag == pMatrixTag )
    {
      v24 = 0;
    }
    else if ( this->pCharIdTag == pMatrixTag )
    {
      v24 = 1;
    }
    else
    {
      ((void (__stdcall *)(_BYTE *))pMatrixTag->Unpack)(v50);
      v24 = 2;
    }
    v25 = 112 * v24;
    v20->Pos.Matrix_1.M[0][0] = *(float *)&v47[v25 / 8 + 4];
    v20->Pos.Matrix_1.M[0][1] = *((float *)&v47[v25 / 8 + 4] + 1);
    v20->Pos.Matrix_1.M[0][2] = v48[v25 / 4];
    v26 = v48[v25 / 4 + 1];
    v27 = (float *)&v47[v25 / 8 + 4];
    v20->Pos.Matrix_1.M[0][3] = v26;
    v20->Pos.Matrix_1.M[1][0] = v27[4];
    v20->Pos.Matrix_1.M[1][1] = v27[5];
    v20->Pos.Matrix_1.M[1][2] = v27[6];
    v20->Pos.Matrix_1.M[1][3] = v27[7];
    v20->Pos.Flags.Flags |= 4u;
  }
  pClassNameTag = this->pClassNameTag;
  if ( pClassNameTag != this->pMainTag )
  {
    if ( this->pDepthTag == pClassNameTag )
    {
      v29 = 0;
    }
    else if ( this->pCharIdTag == pClassNameTag )
    {
      v29 = 1;
    }
    else if ( this->pMatrixTag == pClassNameTag )
    {
      v29 = 2;
    }
    else
    {
      ((void (__stdcall *)(_BYTE *))pClassNameTag->Unpack)(v51);
      v29 = 3;
    }
    *(float *)&v20->Pos.ClassName = v48[28 * v29 + 10];
    v20->Pos.Flags.Flags |= 0x100u;
  }
  pCxFormTag = this->pCxFormTag;
  if ( pCxFormTag != this->pMainTag )
  {
    if ( this->pDepthTag == pCxFormTag )
    {
      v31 = 0;
    }
    else if ( this->pCharIdTag == pCxFormTag )
    {
      v31 = 1;
    }
    else if ( this->pMatrixTag == pCxFormTag )
    {
      v31 = 2;
    }
    else if ( this->pClassNameTag == pCxFormTag )
    {
      v31 = 3;
    }
    else
    {
      ((void (__stdcall *)(_BYTE *))pCxFormTag->Unpack)(v52);
      v31 = 4;
    }
    qmemcpy(data, &v47[14 * v31], 0x20u);
    data->Pos.Flags.Flags |= 8u;
    v20 = data;
  }
  pBlendModeTag = this->pBlendModeTag;
  if ( pBlendModeTag != this->pMainTag )
  {
    if ( this->pDepthTag == pBlendModeTag )
    {
      v33 = 0;
    }
    else if ( this->pCharIdTag == pBlendModeTag )
    {
      v33 = 1;
    }
    else if ( this->pMatrixTag == pBlendModeTag )
    {
      v33 = 2;
    }
    else if ( this->pClassNameTag == pBlendModeTag )
    {
      v33 = 3;
    }
    else if ( this->pCxFormTag == pBlendModeTag )
    {
      v33 = 4;
    }
    else
    {
      ((void (__stdcall *)(_BYTE *))pBlendModeTag->Unpack)(v53);
      v33 = 5;
    }
    v20->Pos.BlendMode = LOBYTE(v48[28 * v33 + 12]);
    v20->Pos.Flags.Flags |= 0x80u;
  }
  pClipDepthTag = this->pClipDepthTag;
  if ( pClipDepthTag != this->pMainTag )
  {
    if ( this->pDepthTag == pClipDepthTag )
    {
      v35 = 0;
    }
    else if ( this->pCharIdTag == pClipDepthTag )
    {
      v35 = 1;
    }
    else if ( this->pMatrixTag == pClipDepthTag )
    {
      v35 = 2;
    }
    else if ( this->pClassNameTag == pClipDepthTag )
    {
      v35 = 3;
    }
    else if ( this->pCxFormTag == pClipDepthTag )
    {
      v35 = 4;
    }
    else if ( this->pBlendModeTag == pClipDepthTag )
    {
      v35 = 5;
    }
    else
    {
      ((void (__stdcall *)(_BYTE *))pClipDepthTag->Unpack)(v54);
      v35 = 6;
    }
    v20->Pos.ClipDepth = LOWORD(v48[28 * v35 + 11]);
    v20->Pos.Flags.Flags |= 0x40u;
  }
  pRatioTag = this->pRatioTag;
  if ( pRatioTag != this->pMainTag )
  {
    if ( this->pDepthTag == pRatioTag )
    {
      v37 = 0;
    }
    else if ( this->pCharIdTag == pRatioTag )
    {
      v37 = 1;
    }
    else if ( this->pMatrixTag == pRatioTag )
    {
      v37 = 2;
    }
    else if ( this->pClassNameTag == pRatioTag )
    {
      v37 = 3;
    }
    else if ( this->pCxFormTag == pRatioTag )
    {
      v37 = 4;
    }
    else if ( this->pBlendModeTag == pRatioTag )
    {
      v37 = 5;
    }
    else if ( this->pClipDepthTag == pRatioTag )
    {
      v37 = 6;
    }
    else
    {
      ((void (__stdcall *)(_BYTE *))pRatioTag->Unpack)(v55);
      v37 = 7;
    }
    v20->Pos.Ratio = v48[28 * v37 + 7];
    v20->Pos.Flags.Flags |= 0x10u;
  }
  pFiltersTag = this->pFiltersTag;
  if ( pFiltersTag != this->pMainTag )
  {
    if ( this->pDepthTag == pFiltersTag )
    {
      v39 = 0;
    }
    else if ( this->pCharIdTag == pFiltersTag )
    {
      v39 = 1;
    }
    else if ( this->pMatrixTag == pFiltersTag )
    {
      v39 = 2;
    }
    else if ( this->pClassNameTag == pFiltersTag )
    {
      v39 = 3;
    }
    else if ( this->pCxFormTag == pFiltersTag )
    {
      v39 = 4;
    }
    else if ( this->pBlendModeTag == pFiltersTag )
    {
      v39 = 5;
    }
    else if ( this->pClipDepthTag == pFiltersTag )
    {
      v39 = 6;
    }
    else if ( this->pRatioTag == pFiltersTag )
    {
      v39 = 7;
    }
    else
    {
      pFiltersTag->Unpack(this->pFiltersTag, &v56);
      v39 = 8;
    }
    v40 = 28 * v39;
    v41 = (Scaleform::GFx::Resource *)LODWORD(v48[v40 + 6]);
    v42 = &v48[v40 + 6];
    if ( v41 )
      Scaleform::RefCountImpl::AddRef(v41);
    pObject = (Scaleform::RefCountVImpl *)v20->Pos.pFilters.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    v20->Pos.pFilters.pObject = *(Scaleform::Render::FilterSet **)v42;
    v20->Pos.Flags.Flags |= 0x20u;
  }
  v44 = 8;
  v45 = &a16;
  do
  {
    v46 = (Scaleform::RefCountVImpl *)*((_DWORD *)v45 - 28);
    v45 -= 112;
    if ( v46 )
      Scaleform::RefCountImpl::Release(v46);
    --v44;
  }
  while ( v44 >= 0 );
}
