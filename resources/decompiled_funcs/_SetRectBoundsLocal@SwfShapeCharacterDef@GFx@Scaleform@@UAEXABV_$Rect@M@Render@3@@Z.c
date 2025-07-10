void __thiscall Scaleform::GFx::SwfShapeCharacterDef::SetRectBoundsLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        const Scaleform::Render::Rect<float> *r)
{
  this->pShape.pObject->SetRectBoundsLocal(this->pShape.pObject, r);
}
