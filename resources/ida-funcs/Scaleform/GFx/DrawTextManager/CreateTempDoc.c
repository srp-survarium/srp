Scaleform::Render::Text::DocView *__thiscall Scaleform::GFx::DrawTextManager::CreateTempDoc(
        Scaleform::GFx::DrawTextManager *this,
        const Scaleform::GFx::DrawTextManager::TextParams *txtParams,
        Scaleform::Render::Text::TextFormat *tfmt,
        Scaleform::Render::Text::ParagraphFormat *pfmt,
        float width,
        float height)
{
  char v6; // bl
  Scaleform::Render::Text::DocView *v8; // edi
  Scaleform::GFx::Resource **Log; // eax
  Scaleform::Render::Text::DocView *v10; // eax
  Scaleform::Render::Text::DocView *v11; // esi
  Scaleform::Ptr<Scaleform::Log> result; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::Render::Rect<float> rect; // [esp+10h] [ebp-10h] BYREF

  v6 = 0;
  result.pObject = 0;
  v8 = (Scaleform::Render::Text::DocView *)this->pHeap->Alloc(this->pHeap, 272, 0);
  if ( v8 )
  {
    v6 = 1;
    Log = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLog(&this->Scaleform::GFx::StateBag, &result);
    Scaleform::Render::Text::DocView::DocView(
      v8,
      this->pImpl->pTextAllocator.pObject,
      (Scaleform::GFx::Resource *)this->pImpl->pFontManager.pObject,
      *Log);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  if ( (v6 & 1) != 0 && result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  Scaleform::Render::Text::TextFormat::InitByDefaultValues(tfmt);
  Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(pfmt);
  rect.x1 = 0.0;
  rect.y1 = 0.0;
  rect.x2 = width + 0.0;
  rect.y2 = height + 0.0;
  Scaleform::Render::Text::DocView::SetViewRect(v11, &rect, UseExternally);
  if ( txtParams->Multiline )
    v11->Flags |= 4u;
  else
    v11->Flags &= ~4u;
  if ( txtParams->WordWrap && width > 0.0 )
  {
    Scaleform::Render::Text::DocView::SetWordWrap(v11);
    if ( txtParams->Multiline )
    {
      Scaleform::Render::Text::DocView::SetAutoSizeY(v11);
      return v11;
    }
  }
  else
  {
    Scaleform::Render::Text::DocView::SetAutoSizeX(v11);
    Scaleform::Render::Text::DocView::ClearWordWrap(v11);
  }
  return v11;
}
