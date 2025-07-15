void __thiscall Scaleform::GFx::SwfShapeCharacterDef::SetRectBoundsLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        const Scaleform::Render::Rect<float> *r,
        int a3)
{
  ((void (__thiscall *)(Scaleform::GFx::ShapeDataBase *, const Scaleform::Render::Rect<float> *, int))this->pShape.pObject->SetRectBoundsLocal)(
    this->pShape.pObject,
    r,
    a3);
}
