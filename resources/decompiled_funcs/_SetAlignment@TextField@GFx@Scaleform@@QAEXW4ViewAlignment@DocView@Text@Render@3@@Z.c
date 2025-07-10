void __thiscall Scaleform::GFx::TextField::SetAlignment(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Text::DocView::ViewAlignment alignment)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  char v3; // cl

  pObject = this->pDocument.pObject;
  v3 = alignment ^ pObject->AlignProps;
  pObject->RTFlags |= 1u;
  pObject->AlignProps ^= v3 & 3;
}
