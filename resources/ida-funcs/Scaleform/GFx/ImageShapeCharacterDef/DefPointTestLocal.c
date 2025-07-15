bool __thiscall Scaleform::GFx::ImageShapeCharacterDef::DefPointTestLocal(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        const Scaleform::Render::Point<float> *pt,
        bool testShape,
        const Scaleform::GFx::DisplayObjectBase *pinst)
{
  float v6[4]; // [esp+1Ch] [ebp-10h] BYREF

  this->pShapeMeshProvider.pObject->GetIdentityBounds(
    &this->pShapeMeshProvider.pObject->Scaleform::Render::MeshProvider,
    (Scaleform::Render::Rect<float> *)v6);
  if ( v6[2] < (double)pt->x || v6[0] > (double)pt->x || v6[3] < (double)pt->y || v6[1] > (double)pt->y )
    return 0;
  if ( testShape )
    return Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
             this->pShape.pObject,
             &Scaleform::Render::Matrix2x4<float>::Identity,
             pt->x,
             pt->y);
  return 1;
}
