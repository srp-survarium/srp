char __thiscall Scaleform::Render::ShapeMeshProvider::generateImage9Grid(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Scale9GridInfo *s9g,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *verOut,
        unsigned int drawLayer)
{
  Scaleform::Render::Rect<float> *p_IdentityBounds; // eax
  double x1; // st7
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *Data; // eax
  unsigned int StartPos; // ecx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  unsigned int v11; // eax
  Scaleform::Render::ShapeDataInterface *v12; // ecx
  Scaleform::Render::TextureManager *v13; // eax
  Scaleform::Render::VertexOutput_vtbl *v14; // eax
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // eax
  bool (__thiscall *v17)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  float y2; // [esp+1DB0h] [ebp-320h] BYREF
  float v19; // [esp+1DB4h] [ebp-31Ch]
  float v20; // [esp+1DB8h] [ebp-318h] BYREF
  Scaleform::RefCountVImpl *v21; // [esp+1DBCh] [ebp-314h]
  int v22; // [esp+1DC0h] [ebp-310h] BYREF
  int v23; // [esp+1DC4h] [ebp-30Ch]
  float v24; // [esp+1DC8h] [ebp-308h]
  float v25; // [esp+1DCCh] [ebp-304h]
  float v26; // [esp+1DD0h] [ebp-300h]
  float v27; // [esp+1DD4h] [ebp-2FCh]
  float v28; // [esp+1DD8h] [ebp-2F8h]
  float v29; // [esp+1DDCh] [ebp-2F4h]
  float x2; // [esp+1DE8h] [ebp-2E8h]
  float y1; // [esp+1DECh] [ebp-2E4h]
  Scaleform::Render::Rect<float> result; // [esp+1DF0h] [ebp-2E0h] BYREF
  int v33; // [esp+1E00h] [ebp-2D0h]
  int v34; // [esp+1E04h] [ebp-2CCh]
  int v35; // [esp+1E08h] [ebp-2C8h]
  Scaleform::Render::Rect<float> imgRect; // [esp+1E10h] [ebp-2C0h] BYREF
  _DWORD v37[13]; // [esp+1E2Ch] [ebp-2A4h] BYREF
  char v38; // [esp+1E60h] [ebp-270h]
  _DWORD v39[3]; // [esp+1E64h] [ebp-26Ch] BYREF
  Scaleform::Render::Matrix2x4<float> uvMatrix; // [esp+1E70h] [ebp-260h] BYREF
  float v41[6]; // [esp+1E90h] [ebp-240h] BYREF
  Scaleform::Render::Scale9GridTess v42; // [esp+1EA8h] [ebp-228h] BYREF

  if ( this->DrawLayers.Data.Data[drawLayer].Image9GridType == I9gMergedSlice )
    p_IdentityBounds = &this->IdentityBounds;
  else
    p_IdentityBounds = Scaleform::Render::ShapeMeshProvider::getLayerBounds(this, &result, drawLayer);
  y1 = p_IdentityBounds->y1;
  x2 = p_IdentityBounds->x2;
  y2 = p_IdentityBounds->y2;
  x1 = p_IdentityBounds->x1;
  Data = this->DrawLayers.Data.Data;
  imgRect.x1 = x1;
  imgRect.y1 = y1;
  imgRect.x2 = x2;
  imgRect.y2 = y2;
  StartPos = Data[drawLayer].StartPos;
  *(float *)&v37[12] = 1.0;
  v37[0] = StartPos;
  pObject = this->pShapeData.pObject;
  memset(&v37[1], 0, 44);
  v38 = 0;
  pObject->ReadPathInfo(pObject, (Scaleform::Render::ShapePosInfo *)v37, v41, v39);
  v11 = v39[0];
  if ( !v39[0] )
    v11 = v39[1];
  v12 = this->pShapeData.pObject;
  v21 = 0;
  v12->GetFillStyle(v12, v11, (Scaleform::Render::FillStyleType *)&v20);
  v13 = mesh->pRenderer2D->pHal.pObject->GetTextureManager(mesh->pRenderer2D->pHal.pObject);
  (*((void (__thiscall **)(Scaleform::RefCountVImpl_vtbl *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::TextureManager *))v21[1].~Scaleform::RefCountVImpl
   + 23))(
    v21[1].__vftable,
    &uvMatrix,
    v13);
  Scaleform::Render::Scale9GridTess::Scale9GridTess(
    &v42,
    Scaleform::Memory::pGlobalHeap,
    s9g,
    &imgRect,
    &uvMatrix,
    (const Scaleform::Render::Matrix2x4<float> *)&v21[2]);
  if ( v42.Indices.Size )
  {
    *(float *)&v22 = 1.0;
    *(float *)&v23 = 0.0;
    LODWORD(result.y1) = v42.Indices.Size;
    v14 = verOut->__vftable;
    v24 = 0.0;
    BeginOutput = v14->BeginOutput;
    v25 = 0.0;
    v26 = 0.0;
    LODWORD(result.x1) = v42.VerCount;
    v28 = 0.0;
    v29 = 0.0;
    LODWORD(result.x2) = &Scaleform::Render::Image9GridVertex::Format;
    v27 = 1.0;
    result.y2 = 0.0;
    v33 = 0;
    v34 = 0;
    v35 = 0;
    if ( !BeginOutput(
            verOut,
            (const Scaleform::Render::VertexOutput::Fill *)&result,
            1u,
            (const Scaleform::Render::Matrix2x4<float> *)&v22) )
    {
LABEL_8:
      if ( v42.Indices.Data != v42.Indices.Static )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v42.Indices.Data);
      v42.Indices.Data = v42.Indices.Static;
      v42.Indices.Size = 0;
      if ( v21 )
        Scaleform::RefCountImpl::Release(v21);
      return 0;
    }
    verOut->SetVertices(verOut, 0, 0, &v42, v42.VerCount);
    verOut->SetIndices(verOut, 0, 0, v42.Indices.Data, v42.Indices.Size);
    verOut->EndOutput(verOut);
  }
  else
  {
    result.x1 = 0.0;
    result.y1 = 0.0;
    result.x2 = 0.0;
    result.y2 = 0.0;
    v17 = verOut->BeginOutput;
    y2 = 0.0;
    LOWORD(v19) = 0;
    v22 = 1;
    v23 = 3;
    v24 = COERCE_FLOAT(&Scaleform::Render::Image9GridVertex::Format);
    v25 = 0.0;
    v26 = 0.0;
    v27 = 0.0;
    v28 = 0.0;
    if ( !v17(
            verOut,
            (const Scaleform::Render::VertexOutput::Fill *)&v22,
            1u,
            &Scaleform::Render::Matrix2x4<float>::Identity) )
      goto LABEL_8;
    verOut->SetVertices(verOut, 0, 0, &result, 1u);
    verOut->SetIndices(verOut, 0, 0, (unsigned __int16 *)&y2, 3u);
    verOut->EndOutput(verOut);
  }
  if ( v42.Indices.Data != v42.Indices.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v42.Indices.Data);
  v42.Indices.Data = v42.Indices.Static;
  v42.Indices.Size = 0;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  return 1;
}
