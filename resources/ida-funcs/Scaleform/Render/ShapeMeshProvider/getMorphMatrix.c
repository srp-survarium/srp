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
  Scaleform::Render::ComplexFill *v12; // eax
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::Render::FillStyleType fillStyle; // [esp+4h] [ebp-24h] BYREF
  Scaleform::Render::StrokeStyleType stroke; // [esp+Ch] [ebp-1Ch] BYREF

  v4 = &this->DrawLayers.Data.Data[drawLayer];
  StrokeStyle = v4->StrokeStyle;
  if ( !StrokeStyle )
  {
    Data = this->FillToStyleTable.Data.Data;
    pObject = this->pMorphData.pObject;
    v8 = Data[fillIndex + v4->StartFill];
    fillStyle.pFill.pObject = 0;
    pObject->pMorphTo.pObject->GetFillStyle(pObject->pMorphTo.pObject, v8, &fillStyle);
    v9 = (Scaleform::RefCountVImpl *)fillStyle.pFill.pObject;
    v10 = result;
    *result = fillStyle.pFill.pObject->ImageMatrix;
    goto LABEL_10;
  }
  v11 = this->pMorphData.pObject;
  stroke.pFill.pObject = 0;
  stroke.pDashes.pObject = 0;
  v11->pMorphTo.pObject->GetStrokeStyle(v11->pMorphTo.pObject, StrokeStyle, &stroke);
  v12 = stroke.pFill.pObject;
  v10 = result;
  v13 = (Scaleform::RefCountVImpl *)stroke.pDashes.pObject;
  if ( stroke.pFill.pObject )
  {
    result->M[0][0] = stroke.pFill.pObject->ImageMatrix.M[0][0];
    result->M[0][1] = v12->ImageMatrix.M[0][1];
    result->M[0][2] = v12->ImageMatrix.M[0][2];
    result->M[0][3] = v12->ImageMatrix.M[0][3];
    result->M[1][0] = v12->ImageMatrix.M[1][0];
    result->M[1][1] = v12->ImageMatrix.M[1][1];
    result->M[1][2] = v12->ImageMatrix.M[1][2];
    result->M[1][3] = v12->ImageMatrix.M[1][3];
    if ( v13 )
    {
      Scaleform::RefCountImpl::Release(v13);
      v12 = stroke.pFill.pObject;
    }
    if ( v12 )
    {
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
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
      v9 = (Scaleform::RefCountVImpl *)stroke.pFill.pObject;
LABEL_10:
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
    }
  }
  return v10;
}
