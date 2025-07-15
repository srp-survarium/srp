void __thiscall Scaleform::Render::ShapeMeshProvider::acquireShapeData(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::MorphShapeData *pObject; // eax
  unsigned int v3; // edi
  Scaleform::RefCountVImpl *p_ShapeData1; // esi
  Scaleform::RefCountVImpl *v5; // ecx
  int *p_pShapeData; // eax
  int v7; // esi
  int v8; // eax
  unsigned int v9; // ebx
  int (__thiscall *v10)(int, _DWORD *, _BYTE *, float *); // edx
  int i; // eax
  int (__thiscall *v12)(int, _DWORD *, float *); // edx
  int (__thiscall *v13)(int, _DWORD *, _BYTE *, float *); // edx
  unsigned int Size; // ebx
  unsigned int v15; // esi
  int v16; // edx
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *Data; // ecx
  unsigned int *v18; // eax
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v19; // ecx
  Scaleform::Render::ShapeMeshProvider *v20; // esi
  Scaleform::ArrayLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2,Scaleform::ArrayDefaultPolicy> *p_DrawLayers; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_FillToStyleTable; // esi
  int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // esi
  Scaleform::Render::ShapeMeshProvider *v26; // esi
  Scaleform::Render::MeshProvider_vtbl *v27; // edx
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::Render::MeshProvider *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  int v29; // eax
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v30; // eax
  char *v31; // esi
  Scaleform::RefCountVImpl *v32; // [esp+1C3Eh] [ebp-3D0h] BYREF
  char v33; // [esp+1C45h] [ebp-3C9h]
  float v34; // [esp+1C46h] [ebp-3C8h]
  Scaleform::Render::ShapeMeshProvider *v35; // [esp+1C4Ah] [ebp-3C4h]
  float v36; // [esp+1C4Eh] [ebp-3C0h] BYREF
  float v37[3]; // [esp+1C52h] [ebp-3BCh] BYREF
  float v38[10]; // [esp+1C5Eh] [ebp-3B0h] BYREF
  _DWORD v39[13]; // [esp+1C86h] [ebp-388h] BYREF
  int v40; // [esp+1CBAh] [ebp-354h]
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType val; // [esp+1CBEh] [ebp-350h] BYREF
  _BYTE v42[24]; // [esp+1CE6h] [ebp-328h] BYREF
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> v43; // [esp+1CFEh] [ebp-310h] BYREF

  pObject = this->pMorphData.pObject;
  v3 = 0;
  v35 = this;
  v34 = 0.0;
  if ( pObject )
  {
    p_ShapeData1 = (Scaleform::RefCountVImpl *)&pObject->ShapeData1;
    LODWORD(v34) = 1;
    if ( pObject != (Scaleform::Render::MorphShapeData *)-36 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)&pObject->ShapeData1);
    v5 = p_ShapeData1;
    v32 = p_ShapeData1;
    p_pShapeData = (int *)&v32;
  }
  else
  {
    v5 = v32;
    p_pShapeData = (int *)&this->pShapeData;
  }
  v7 = *p_pShapeData;
  if ( (LOBYTE(v34) & 1) != 0 && v5 )
    Scaleform::RefCountImpl::Release(v5);
  v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 24))(v7);
  *(float *)&v39[12] = 1.0;
  v43.pHeap = Scaleform::Memory::pGlobalHeap;
  v43.Data = v43.Static;
  this->Strokes = 0;
  v39[0] = v8;
  memset(&v39[1], 0, 44);
  LOBYTE(v40) = 0;
  v43.Size = 0;
  v43.Reserved = 32;
  v9 = v8;
  v10 = *(int (__thiscall **)(int, _DWORD *, _BYTE *, float *))(*(_DWORD *)v7 + 32);
  v33 = 1;
  *(float *)&v32 = 0.0;
  for ( i = v10(v7, v39, v42, v37); i; v3 = 0 )
  {
    if ( i == 2 && !v33 )
      v32 = (Scaleform::RefCountVImpl *)((char *)v32 + 1);
    val.ShapeLayer = (unsigned int)v32;
    *(float *)&val.Styles[2] = v37[2];
    *(float *)val.Styles = v37[0];
    *(float *)&val.Styles[1] = v37[1];
    v12 = *(int (__thiscall **)(int, _DWORD *, float *))(*(_DWORD *)v7 + 36);
    val.Pos = v9;
    if ( v12(v7, v39, v38) )
    {
      do
        ++v3;
      while ( (*(int (__thiscall **)(int, _DWORD *, float *))(*(_DWORD *)v7 + 36))(v7, v39, v38) );
    }
    val.EdgeCount = v3;
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2>::PushBack(&v43, &val);
    v13 = *(int (__thiscall **)(int, _DWORD *, _BYTE *, float *))(*(_DWORD *)v7 + 32);
    v9 = v39[0];
    v33 = 0;
    i = v13(v7, v39, v42, v37);
  }
  Size = v43.Size;
  v15 = 0;
  v34 = 0.0;
  if ( v43.Size )
  {
    v16 = 0;
    *(float *)&v32 = 0.0;
    do
    {
      Data = v43.Data;
      v18 = (unsigned int *)((char *)&v43.Data->ShapeLayer + (unsigned int)v32);
      if ( *(unsigned int *)((char *)&v43.Data->Styles[3] + (unsigned int)v32) && (v18[2] || v18[3] || v18[4]) )
      {
        v43.Data[v16].ShapeLayer = *v18;
        v19 = &Data[v16];
        v19->Pos = v18[1];
        v19->Styles[0] = v18[2];
        v19->Styles[1] = v18[3];
        v19->Styles[2] = v18[4];
        v19->EdgeCount = v18[5];
        Size = v43.Size;
        ++v15;
        ++v16;
      }
      v32 += 3;
      ++LODWORD(v34);
    }
    while ( LODWORD(v34) < Size );
    if ( v15 < Size )
      v43.Size = v15;
  }
  v20 = v35;
  p_DrawLayers = &v35->DrawLayers;
  if ( v35->DrawLayers.Data.Size )
  {
    if ( (v35->DrawLayers.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_DrawLayers->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_DrawLayers->Data.Data);
        p_DrawLayers->Data.Data = 0;
      }
      p_DrawLayers->Data.Policy.Capacity = 0;
    }
  }
  else if ( !v35->DrawLayers.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v35->DrawLayers.Data,
      &v35->DrawLayers,
      0);
  }
  p_FillToStyleTable = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v20->FillToStyleTable;
  p_DrawLayers->Data.Size = 0;
  if ( p_FillToStyleTable->Size )
  {
    if ( (p_FillToStyleTable->Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_FillToStyleTable->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_FillToStyleTable->Data);
        p_FillToStyleTable->Data = 0;
      }
      p_FillToStyleTable->Policy.Capacity = 0;
    }
  }
  else if ( !p_FillToStyleTable->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_FillToStyleTable,
      p_FillToStyleTable,
      0);
  }
  p_FillToStyleTable->Size = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  if ( v43.Size )
  {
    do
    {
      if ( v23 != *(unsigned int *)((char *)&v43.Data->ShapeLayer + v3) )
      {
        Scaleform::Render::ShapeMeshProvider::createDrawLayers(v35, &v43, v24, v25);
        v23 = *(unsigned int *)((char *)&v43.Data->ShapeLayer + v3);
        v24 = v25;
      }
      ++v25;
      v3 += 24;
    }
    while ( v25 < v43.Size );
    v3 = 0;
  }
  v26 = v35;
  Scaleform::Render::ShapeMeshProvider::createDrawLayers(v35, &v43, v24, v43.Size);
  v27 = v26->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable;
  v38[0] = 1.0;
  GetBounds = v27->GetBounds;
  v38[1] = 0.0;
  v38[2] = 0.0;
  v38[3] = 0.0;
  v38[4] = 0.0;
  v38[6] = 0.0;
  v38[7] = 0.0;
  v38[5] = 1.0;
  v29 = (int)GetBounds(
               &v26->Scaleform::Render::MeshProvider,
               (Scaleform::Render::Rect<float> *)&val,
               (const Scaleform::Render::Matrix2x4<float> *)v38);
  v34 = *(float *)(v29 + 4);
  v32 = *(Scaleform::RefCountVImpl **)(v29 + 8);
  v36 = *(float *)(v29 + 12);
  v26->IdentityBounds.x1 = *(float *)v29;
  v26->IdentityBounds.y1 = v34;
  v26->IdentityBounds.x2 = *(float *)&v32;
  v26->IdentityBounds.y2 = v36;
  if ( Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(v26) )
  {
    if ( p_DrawLayers->Data.Size <= 1 )
    {
      if ( p_DrawLayers->Data.Policy.Capacity <= 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &p_DrawLayers->Data,
          p_DrawLayers,
          1u);
    }
    else if ( (p_DrawLayers->Data.Policy.Capacity & 0xFFFFFFFE) > 2 )
    {
      if ( p_DrawLayers->Data.Data )
      {
        v30 = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       p_DrawLayers->Data.Data,
                                                                       80);
      }
      else
      {
        LODWORD(v36) = 2;
        v30 = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       p_DrawLayers,
                                                                       80,
                                                                       &v36);
      }
      p_DrawLayers->Data.Data = v30;
      p_DrawLayers->Data.Policy.Capacity = 4;
      p_DrawLayers->Data.Size = 1;
      v30->Image9GridType = I9gMergedSlice;
      goto LABEL_60;
    }
    p_DrawLayers->Data.Size = 1;
    p_DrawLayers->Data.Data->Image9GridType = I9gMergedSlice;
    goto LABEL_60;
  }
  v34 = 0.0;
  if ( v26->DrawLayers.Data.Size )
  {
    do
    {
      v31 = (char *)p_DrawLayers->Data.Data + v3;
      if ( !*((_DWORD *)v31 + 3)
        && Scaleform::Render::ShapeMeshProvider::checkI9gLayer(
             v35,
             (const Scaleform::Render::ShapeMeshProvider::DrawLayerType *)((char *)p_DrawLayers->Data.Data + v3)) )
      {
        *((_DWORD *)v31 + 4) = 1;
      }
      v3 += 20;
      ++LODWORD(v34);
    }
    while ( LODWORD(v34) < v35->DrawLayers.Data.Size );
  }
LABEL_60:
  if ( v43.Data != v43.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43.Data);
}
