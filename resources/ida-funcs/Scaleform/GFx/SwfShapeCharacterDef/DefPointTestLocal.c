bool __thiscall Scaleform::GFx::SwfShapeCharacterDef::DefPointTestLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        const Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  return Scaleform::GFx::ShapeDataBase::DefPointTestLocal(
           this->pShape.pObject,
           this->pShapeMeshProvider.pObject,
           pt,
           testShape,
           pinst);
}
