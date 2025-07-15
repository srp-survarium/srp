Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::ShapeMeshProvider::getMorphMatrix(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Matrix2x4<float> *result,
        unsigned int drawLayer,
        unsigned int fillIndex)
{
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v4; // eax
  unsigned int StrokeStyle; // edx
  unsigned int *Data; // edx
  Scaleform::Render::MorphShapeData *pObject; // ecx
  unsigned int v8; // eax
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::Render::Matrix2x4<float> *v10; // esi
  Scaleform::Render::MorphShapeData *v11; // ecx
  Scaleform::RefCountVImpl *v12; // eax
  Scaleform::RefCountVImpl *v13; // ecx
  char v15; // [esp+4h] [ebp-24h] BYREF
  int v16; // [esp+8h] [ebp-20h]
  char v17; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::RefCountVImpl *v18; // [esp+20h] [ebp-8h]
  Scaleform::RefCountVImpl *v19; // [esp+24h] [ebp-4h]

  v4 = &this->DrawLayers.Data.Data[drawLayer];
  StrokeStyle = v4->StrokeStyle;
  if ( !StrokeStyle )
  {
    Data = this->FillToStyleTable.Data.Data;
    pObject = this->pMorphData.pObject;
    v8 = Data[fillIndex + v4->StartFill];
    v16 = 0;
    pObject->pMorphTo.pObject->GetFillStyle(pObject->pMorphTo.pObject, v8, (Scaleform::Render::FillStyleType *)&v15);
    v9 = (Scaleform::RefCountVImpl *)v16;
    v10 = result;
    *result = *(Scaleform::Render::Matrix2x4<float> *)(v16 + 16);
    goto LABEL_10;
  }
  v11 = this->pMorphData.pObject;
  v18 = 0;
  v19 = 0;
  v11->pMorphTo.pObject->GetStrokeStyle(v11->pMorphTo.pObject, StrokeStyle, (Scaleform::Render::StrokeStyleType *)&v17);
  v12 = v18;
  v10 = result;
  v13 = v19;
  if ( v18 )
  {
    result->M[0][0] = *(float *)&v18[2].__vftable;
    result->M[0][1] = *(float *)&v12[2].RefCount;
    result->M[0][2] = *(float *)&v12[3].__vftable;
    result->M[0][3] = *(float *)&v12[3].RefCount;
    result->M[1][0] = *(float *)&v12[4].__vftable;
    result->M[1][1] = *(float *)&v12[4].RefCount;
    result->M[1][2] = *(float *)&v12[5].__vftable;
    result->M[1][3] = *(float *)&v12[5].RefCount;
    if ( v13 )
    {
      Scaleform::RefCountImpl::Release(v13);
      v12 = v18;
    }
    if ( v12 )
    {
      Scaleform::RefCountImpl::Release(v12);
      return result;
    }
  }
  else
  {
    result->M[0][0] = 1.0;
    result->M[0][1] = 0.0;
    result->M[0][2] = 0.0;
    result->M[0][3] = 0.0;
    result->M[1][0] = 0.0;
    result->M[1][2] = 0.0;
    result->M[1][3] = 0.0;
    result->M[1][1] = 1.0;
    if ( v13 )
    {
      Scaleform::RefCountImpl::Release(v13);
      v9 = v18;
LABEL_10:
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
    }
  }
  return v10;
}
