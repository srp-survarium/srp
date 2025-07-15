void __thiscall Scaleform::Render::ShapeMeshProvider::acquireShapeData(Scaleform::Render::ShapeMeshProvider *this)
{
  char v1; // bl
  Scaleform::Render::MorphShapeData *pObject; // eax
  Scaleform::RefCountVImpl *p_ShapeData1; // esi
  Scaleform::RefCountVImpl *v4; // ecx
  int *p_pShapeData; // eax
  int v6; // esi
  int v7; // eax
  unsigned int v8; // edi
  char v9; // bl
  int i; // eax
  int (__thiscall *v11)(int, _DWORD *, float *); // edx
  unsigned int v12; // edi
  unsigned int Size; // ebx
  int v14; // edi
  unsigned int v15; // esi
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *Data; // ecx
  int v17; // edx
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v18; // eax
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v19; // ecx
  Scaleform::Render::ShapeMeshProvider *v20; // ebx
  bool v21; // zf
  Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // edi
  unsigned int v23; // esi
  unsigned int v24; // ecx
  unsigned int *p_StrokeStyle; // eax
  Scaleform::AmpServer *Instance; // eax
  void **v27; // esi
  unsigned int v28; // eax
  unsigned int v29; // esi
  unsigned int ShapeLayer; // ecx
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *v31; // edx
  int v32; // edi
  Scaleform::Render::MeshProvider_vtbl *v33; // edx
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::Render::MeshProvider *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  int v35; // eax
  unsigned int v36; // esi
  unsigned int v37; // ebx
  unsigned int *v38; // eax
  Scaleform::AmpServer *v39; // eax
  char *v40; // esi
  Scaleform::RefCountVImpl *v41; // [esp+34h] [ebp-3C8h] BYREF
  Scaleform::Render::ShapeMeshProvider *v42; // [esp+38h] [ebp-3C4h]
  float v43; // [esp+3Ch] [ebp-3C0h] BYREF
  _DWORD v44[3]; // [esp+40h] [ebp-3BCh] BYREF
  float v45[10]; // [esp+4Ch] [ebp-3B0h] BYREF
  _DWORD v46[13]; // [esp+74h] [ebp-388h] BYREF
  int v47; // [esp+A8h] [ebp-354h]
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType val; // [esp+ACh] [ebp-350h] BYREF
  _BYTE v49[24]; // [esp+D4h] [ebp-328h] BYREF
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> paths; // [esp+ECh] [ebp-310h] BYREF

  v1 = 0;
  v43 = 0.0;
  pObject = this->pMorphData.pObject;
  v42 = this;
  if ( pObject )
  {
    p_ShapeData1 = (Scaleform::RefCountVImpl *)&pObject->ShapeData1;
    v1 = 1;
    if ( pObject != (Scaleform::Render::MorphShapeData *)-36 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)&pObject->ShapeData1);
    v4 = p_ShapeData1;
    v41 = p_ShapeData1;
    p_pShapeData = (int *)&v41;
  }
  else
  {
    p_pShapeData = (int *)&this->pShapeData;
    v4 = v41;
  }
  v6 = *p_pShapeData;
  if ( (v1 & 1) != 0 && v4 )
    Scaleform::RefCountImpl::Release(v4);
  v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 24))(v6);
  *(float *)&v46[12] = 1.0;
  paths.pHeap = Scaleform::Memory::pGlobalHeap;
  v46[0] = v7;
  memset(&v46[1], 0, 44);
  paths.Size = 0;
  *(float *)&v41 = 0.0;
  v8 = v7;
  v42->Strokes = 0;
  paths.Data = paths.Static;
  LOBYTE(v47) = 0;
  paths.Reserved = 32;
  v9 = 1;
  for ( i = (*(int (__thiscall **)(int, _DWORD *, _BYTE *, _DWORD *))(*(_DWORD *)v6 + 32))(v6, v46, v49, v44);
        i;
        i = (*(int (__thiscall **)(int, _DWORD *, _BYTE *, _DWORD *))(*(_DWORD *)v6 + 32))(v6, v46, v49, v44) )
  {
    if ( i == 2 && !v9 )
      v41 = (Scaleform::RefCountVImpl *)((char *)v41 + 1);
    val.ShapeLayer = (unsigned int)v41;
    val.Styles[2] = v44[2];
    val.Styles[0] = v44[0];
    val.Styles[1] = v44[1];
    v11 = *(int (__thiscall **)(int, _DWORD *, float *))(*(_DWORD *)v6 + 36);
    val.Pos = v8;
    v12 = 0;
    if ( v11(v6, v46, v45) )
    {
      do
        ++v12;
      while ( (*(int (__thiscall **)(int, _DWORD *, float *))(*(_DWORD *)v6 + 36))(v6, v46, v45) );
    }
    val.EdgeCount = v12;
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2>::PushBack(&paths, &val);
    v8 = v46[0];
    v9 = 0;
  }
  Size = paths.Size;
  v14 = 0;
  v15 = 0;
  *(float *)&v41 = 0.0;
  if ( paths.Size )
  {
    Data = paths.Data;
    v17 = 0;
    do
    {
      v18 = &Data[v14];
      if ( Data[v14].EdgeCount && (v18->Styles[0] || v18->Styles[1] || v18->Styles[2]) )
      {
        Data[v17].ShapeLayer = v18->ShapeLayer;
        v19 = &Data[v17];
        v19->Pos = v18->Pos;
        v19->Styles[0] = v18->Styles[0];
        v19->Styles[1] = v18->Styles[1];
        v19->Styles[2] = v18->Styles[2];
        v19->EdgeCount = v18->EdgeCount;
        Data = paths.Data;
        Size = paths.Size;
        ++v15;
        ++v17;
      }
      ++v14;
      v41 = (Scaleform::RefCountVImpl *)((char *)v41 + 1);
    }
    while ( (unsigned int)v41 < Size );
    if ( v15 < Size )
      paths.Size = v15;
  }
  v20 = v42;
  v21 = v42->DrawLayers.Data.Size == 0;
  p_Data = &v42->DrawLayers.Data;
  v42 = (Scaleform::Render::ShapeMeshProvider *)((char *)v42 + 20);
  if ( v21 )
  {
    if ( !p_Data->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Data,
        p_Data,
        0);
  }
  else if ( (p_Data->Policy.Capacity & 0xFFFFFFFE) != 0 )
  {
    if ( p_Data->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Data->Data);
      p_Data->Data = 0;
    }
    p_Data->Policy.Capacity = 0;
  }
  v23 = 0;
  p_Data->Size = 0;
  if ( v20->DrawLayers.Data.Size )
  {
    v24 = v20->DrawLayers.Data.Size;
    p_StrokeStyle = &p_Data->Data->StrokeStyle;
    do
    {
      if ( *p_StrokeStyle )
        ++v23;
      p_StrokeStyle += 5;
      --v24;
    }
    while ( v24 );
  }
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->RemoveStrokes(Instance, v23);
  v27 = (void **)&v20->FillToStyleTable.Data.Data;
  if ( v20->FillToStyleTable.Data.Size )
  {
    if ( (v20->FillToStyleTable.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( *v27 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v27);
        *v27 = 0;
      }
      v20->FillToStyleTable.Data.Policy.Capacity = 0;
    }
  }
  else if ( !v20->FillToStyleTable.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v20->FillToStyleTable,
      &v20->FillToStyleTable,
      0);
  }
  v28 = 0;
  v20->FillToStyleTable.Data.Size = 0;
  v29 = 0;
  ShapeLayer = 0;
  if ( paths.Size )
  {
    v31 = paths.Data;
    v32 = 0;
    do
    {
      if ( ShapeLayer != v31[v32].ShapeLayer )
      {
        Scaleform::Render::ShapeMeshProvider::createDrawLayers(v20, &paths, v28, v29);
        v31 = paths.Data;
        ShapeLayer = paths.Data[v32].ShapeLayer;
        v28 = v29;
      }
      ++v29;
      ++v32;
    }
    while ( v29 < paths.Size );
    p_Data = (Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy> *)v42;
  }
  Scaleform::Render::ShapeMeshProvider::createDrawLayers(v20, &paths, v28, paths.Size);
  v33 = v20->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable;
  v45[0] = 1.0;
  GetBounds = v33->GetBounds;
  v45[1] = 0.0;
  v45[2] = 0.0;
  v45[3] = 0.0;
  v45[4] = 0.0;
  v45[6] = 0.0;
  v45[7] = 0.0;
  v45[5] = 1.0;
  v35 = (int)GetBounds(
               &v20->Scaleform::Render::MeshProvider,
               (Scaleform::Render::Rect<float> *)&val,
               (const Scaleform::Render::Matrix2x4<float> *)v45);
  v42 = *(Scaleform::Render::ShapeMeshProvider **)(v35 + 4);
  v41 = *(Scaleform::RefCountVImpl **)(v35 + 8);
  v43 = *(float *)(v35 + 12);
  v20->IdentityBounds.x1 = *(float *)v35;
  v20->IdentityBounds.y1 = *(float *)&v42;
  v20->IdentityBounds.x2 = *(float *)&v41;
  v20->IdentityBounds.y2 = v43;
  if ( Scaleform::Render::ShapeMeshProvider::checkI9gMergedSlice(v20) )
  {
    if ( p_Data->Size <= 1 )
    {
      if ( p_Data->Policy.Capacity <= 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::ShapeMeshProvider::DrawLayerType,Scaleform::AllocatorLH_POD<Scaleform::Render::ShapeMeshProvider::DrawLayerType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Data,
          p_Data,
          1u);
    }
    else if ( (p_Data->Policy.Capacity & 0xFFFFFFFE) > 2 )
    {
      if ( p_Data->Data )
      {
        p_Data->Data = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                                Scaleform::Memory::pGlobalHeap,
                                                                                p_Data->Data,
                                                                                80);
      }
      else
      {
        LODWORD(v43) = 2;
        p_Data->Data = (Scaleform::Render::ShapeMeshProvider::DrawLayerType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                                Scaleform::Memory::pGlobalHeap,
                                                                                p_Data,
                                                                                80,
                                                                                &v43);
      }
      p_Data->Policy.Capacity = 4;
    }
    p_Data->Size = 1;
    v36 = 0;
    if ( v20->DrawLayers.Data.Size )
    {
      v37 = v20->DrawLayers.Data.Size;
      v38 = &p_Data->Data->StrokeStyle;
      do
      {
        if ( *v38 )
          ++v36;
        v38 += 5;
        --v37;
      }
      while ( v37 );
    }
    v39 = Scaleform::AmpServer::GetInstance();
    v39->RemoveStrokes(v39, v36);
    p_Data->Data->Image9GridType = I9gMergedSlice;
  }
  else
  {
    *(float *)&v42 = 0.0;
    if ( v20->DrawLayers.Data.Size )
    {
      *(float *)&v41 = 0.0;
      do
      {
        v40 = (char *)v41 + (unsigned int)p_Data->Data;
        if ( !*((_DWORD *)v40 + 3)
          && Scaleform::Render::ShapeMeshProvider::checkI9gLayer(
               v20,
               (const Scaleform::Render::ShapeMeshProvider::DrawLayerType *)((char *)v41 + (unsigned int)p_Data->Data)) )
        {
          *((_DWORD *)v40 + 4) = 1;
        }
        v41 = (Scaleform::RefCountVImpl *)((char *)v41 + 20);
        v42 = (Scaleform::Render::ShapeMeshProvider *)((char *)v42 + 1);
      }
      while ( (unsigned int)v42 < v20->DrawLayers.Data.Size );
    }
  }
  if ( paths.Data != paths.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, paths.Data);
}
