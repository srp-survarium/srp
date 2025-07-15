void __thiscall Scaleform::GFx::TextField::SetTextColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::MemoryHeap *v3; // edi
  Scaleform::Render::Text::DocView *pObject; // ecx
  Scaleform::Render::Text::DocView *v5; // eax
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::Text::TextFormat fmt; // [esp+8h] [ebp-28h] BYREF

  v3 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  fmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&fmt.FontList, v3);
  Scaleform::StringDH::StringDH(&fmt.Url, v3);
  fmt.LetterSpacing = 0;
  fmt.pImageDesc.pObject = 0;
  fmt.pFontHandle.pObject = 0;
  fmt.FormatFlags = 0;
  fmt.FontSize = 0;
  fmt.ColorV = rgb & 0xFFFFFF | 0xFF000000;
  pObject = this->pDocument.pObject;
  fmt.PresentMask = 1;
  Scaleform::Render::Text::DocView::SetTextFormat(pObject, &fmt, 0, 0xFFFFFFFF);
  Scaleform::Render::Text::TextFormat::operator=(
    &fmt,
    this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
  v5 = this->pDocument.pObject;
  fmt.PresentMask |= 1u;
  fmt.ColorV = rgb & 0xFFFFFF | fmt.ColorV & 0xFF000000;
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v5->pDocument.pObject, &fmt);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}
