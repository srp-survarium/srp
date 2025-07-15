Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::SwfShapeCharacterDef::GetBoundsLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float __formal)
{
  Scaleform::Render::Rect<float> *v4; // eax
  double y2; // st7
  Scaleform::Render::Rect<float> *v6; // eax
  float v7[4]; // [esp+10h] [ebp-20h] BYREF
  _BYTE v8[16]; // [esp+20h] [ebp-10h] BYREF

  this->pShape.pObject->GetBoundsLocal(this->pShape.pObject, (Scaleform::Render::Rect<float> *)v7);
  if ( v7[2] > (double)v7[0] && v7[3] > (double)v7[1] )
    v4 = (Scaleform::Render::Rect<float> *)v7;
  else
    v4 = this->pShapeMeshProvider.pObject->GetIdentityBounds(
           &this->pShapeMeshProvider.pObject->Scaleform::Render::MeshProvider,
           v8);
  result->x1 = v4->x1;
  result->y1 = v4->y1;
  result->x2 = v4->x2;
  y2 = v4->y2;
  v6 = result;
  result->y2 = y2;
  return v6;
}
