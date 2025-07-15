Scaleform::Render::Size<float> *__thiscall Scaleform::GFx::DrawTextManager::GetTextExtent(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::Render::Size<float> *result,
        const Scaleform::String *str,
        float width,
        Scaleform::GFx::DrawTextManager::TextParams *ptxtParams)
{
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::GFx::DrawTextManager::TextParams *p_DefaultTextParams; // esi
  Scaleform::Render::Text::DocView *v8; // esi
  void *v9; // esi
  Scaleform::Render::Text::ParagraphFormat pfmt; // [esp+14h] [ebp-58h] BYREF
  Scaleform::GFx::DrawTextManager::TextParams txtParams; // [esp+28h] [ebp-44h] BYREF
  Scaleform::Render::Text::TextFormat tfmt; // [esp+44h] [ebp-28h] BYREF
  float widtha; // [esp+78h] [ebp+Ch]
  float ptxtParamsa; // [esp+7Ch] [ebp+10h]
  float ptxtParamsb; // [esp+7Ch] [ebp+10h]
  float ptxtParamsc; // [esp+7Ch] [ebp+10h]

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this);
  pHeap = this->pHeap;
  tfmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&tfmt.FontList, pHeap);
  Scaleform::StringDH::StringDH(&tfmt.Url, pHeap);
  p_DefaultTextParams = ptxtParams;
  tfmt.pImageDesc.pObject = 0;
  tfmt.pFontHandle.pObject = 0;
  tfmt.ColorV = -16777216;
  tfmt.LetterSpacing = 0;
  tfmt.FontSize = 0;
  tfmt.FormatFlags = 0;
  tfmt.PresentMask = 0;
  pfmt.RefCount = 1;
  memset(&pfmt.pTabStops, 0, 16);
  if ( !ptxtParams )
    p_DefaultTextParams = &this->pImpl->DefaultTextParams;
  txtParams.TextColor.Raw = p_DefaultTextParams->TextColor.Raw;
  txtParams.HAlignment = p_DefaultTextParams->HAlignment;
  txtParams.VAlignment = p_DefaultTextParams->VAlignment;
  txtParams.FontStyle = p_DefaultTextParams->FontStyle;
  txtParams.FontSize = p_DefaultTextParams->FontSize;
  Scaleform::String::String(&txtParams.FontName, &p_DefaultTextParams->FontName);
  txtParams.Underline = p_DefaultTextParams->Underline;
  txtParams.Multiline = p_DefaultTextParams->Multiline;
  ptxtParamsa = width * 20.0;
  txtParams.WordWrap = p_DefaultTextParams->WordWrap;
  v8 = Scaleform::GFx::DrawTextManager::CreateTempDoc(this, &txtParams, &tfmt, &pfmt, ptxtParamsa, 0.0);
  txtParams.WordWrap = 0;
  txtParams.Multiline = 0;
  Scaleform::GFx::DrawTextManager::SetTextParams(this, v8, &txtParams, &tfmt, &pfmt);
  Scaleform::Render::Text::DocView::SetText(v8, (const char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8), 0xFFFFFFFF);
  widtha = Scaleform::Render::Text::DocView::GetTextHeight(v8);
  ptxtParamsb = Scaleform::Render::Text::DocView::GetTextWidth(v8) * 0.05000000074505806;
  result->Width = ptxtParamsb + 4.0;
  ptxtParamsc = 0.05000000074505806 * widtha;
  result->Height = ptxtParamsc + 4.0;
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
  v9 = (void *)(txtParams.FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((txtParams.FontName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pfmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&tfmt);
  return result;
}


Scaleform::Render::Size<float> *__thiscall Scaleform::GFx::DrawTextManager::GetTextExtent(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::Render::Size<float> *result,
        const char *putf8Str,
        float width,
        Scaleform::GFx::DrawTextManager::TextParams *ptxtParams)
{
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::GFx::DrawTextManager::TextParams *p_DefaultTextParams; // esi
  Scaleform::Render::Text::DocView *v8; // esi
  void *v9; // esi
  Scaleform::Render::Text::ParagraphFormat pfmt; // [esp+14h] [ebp-58h] BYREF
  Scaleform::GFx::DrawTextManager::TextParams txtParams; // [esp+28h] [ebp-44h] BYREF
  Scaleform::Render::Text::TextFormat tfmt; // [esp+44h] [ebp-28h] BYREF
  float widtha; // [esp+78h] [ebp+Ch]
  float ptxtParamsa; // [esp+7Ch] [ebp+10h]
  float ptxtParamsb; // [esp+7Ch] [ebp+10h]
  float ptxtParamsc; // [esp+7Ch] [ebp+10h]

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this);
  pHeap = this->pHeap;
  tfmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&tfmt.FontList, pHeap);
  Scaleform::StringDH::StringDH(&tfmt.Url, pHeap);
  p_DefaultTextParams = ptxtParams;
  tfmt.pImageDesc.pObject = 0;
  tfmt.pFontHandle.pObject = 0;
  tfmt.ColorV = -16777216;
  tfmt.LetterSpacing = 0;
  tfmt.FontSize = 0;
  tfmt.FormatFlags = 0;
  tfmt.PresentMask = 0;
  pfmt.RefCount = 1;
  memset(&pfmt.pTabStops, 0, 16);
  if ( !ptxtParams )
    p_DefaultTextParams = &this->pImpl->DefaultTextParams;
  txtParams.TextColor.Raw = p_DefaultTextParams->TextColor.Raw;
  txtParams.HAlignment = p_DefaultTextParams->HAlignment;
  txtParams.VAlignment = p_DefaultTextParams->VAlignment;
  txtParams.FontStyle = p_DefaultTextParams->FontStyle;
  txtParams.FontSize = p_DefaultTextParams->FontSize;
  Scaleform::String::String(&txtParams.FontName, &p_DefaultTextParams->FontName);
  txtParams.Underline = p_DefaultTextParams->Underline;
  txtParams.Multiline = p_DefaultTextParams->Multiline;
  ptxtParamsa = width * 20.0;
  txtParams.WordWrap = p_DefaultTextParams->WordWrap;
  v8 = Scaleform::GFx::DrawTextManager::CreateTempDoc(this, &txtParams, &tfmt, &pfmt, ptxtParamsa, 0.0);
  txtParams.WordWrap = 0;
  txtParams.Multiline = 0;
  Scaleform::GFx::DrawTextManager::SetTextParams(this, v8, &txtParams, &tfmt, &pfmt);
  Scaleform::Render::Text::DocView::SetText(v8, putf8Str, 0xFFFFFFFF);
  widtha = Scaleform::Render::Text::DocView::GetTextHeight(v8);
  ptxtParamsb = Scaleform::Render::Text::DocView::GetTextWidth(v8) * 0.05000000074505806;
  result->Width = ptxtParamsb + 4.0;
  ptxtParamsc = 0.05000000074505806 * widtha;
  result->Height = ptxtParamsc + 4.0;
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
  v9 = (void *)(txtParams.FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((txtParams.FontName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pfmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&tfmt);
  return result;
}


Scaleform::Render::Size<float> *__thiscall Scaleform::GFx::DrawTextManager::GetTextExtent(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::Render::Size<float> *result,
        const wchar_t *pwstr,
        float width,
        Scaleform::GFx::DrawTextManager::TextParams *ptxtParams)
{
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::GFx::DrawTextManager::TextParams *p_DefaultTextParams; // esi
  Scaleform::Render::Text::DocView *v8; // esi
  void *v9; // esi
  Scaleform::Render::Text::ParagraphFormat pfmt; // [esp+14h] [ebp-58h] BYREF
  Scaleform::GFx::DrawTextManager::TextParams txtParams; // [esp+28h] [ebp-44h] BYREF
  Scaleform::Render::Text::TextFormat tfmt; // [esp+44h] [ebp-28h] BYREF
  float widtha; // [esp+78h] [ebp+Ch]
  float ptxtParamsa; // [esp+7Ch] [ebp+10h]
  float ptxtParamsb; // [esp+7Ch] [ebp+10h]
  float ptxtParamsc; // [esp+7Ch] [ebp+10h]

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this);
  pHeap = this->pHeap;
  tfmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&tfmt.FontList, pHeap);
  Scaleform::StringDH::StringDH(&tfmt.Url, pHeap);
  p_DefaultTextParams = ptxtParams;
  tfmt.pImageDesc.pObject = 0;
  tfmt.pFontHandle.pObject = 0;
  tfmt.ColorV = -16777216;
  tfmt.LetterSpacing = 0;
  tfmt.FontSize = 0;
  tfmt.FormatFlags = 0;
  tfmt.PresentMask = 0;
  pfmt.RefCount = 1;
  memset(&pfmt.pTabStops, 0, 16);
  if ( !ptxtParams )
    p_DefaultTextParams = &this->pImpl->DefaultTextParams;
  txtParams.TextColor.Raw = p_DefaultTextParams->TextColor.Raw;
  txtParams.HAlignment = p_DefaultTextParams->HAlignment;
  txtParams.VAlignment = p_DefaultTextParams->VAlignment;
  txtParams.FontStyle = p_DefaultTextParams->FontStyle;
  txtParams.FontSize = p_DefaultTextParams->FontSize;
  Scaleform::String::String(&txtParams.FontName, &p_DefaultTextParams->FontName);
  txtParams.Underline = p_DefaultTextParams->Underline;
  txtParams.Multiline = p_DefaultTextParams->Multiline;
  ptxtParamsa = width * 20.0;
  txtParams.WordWrap = p_DefaultTextParams->WordWrap;
  v8 = Scaleform::GFx::DrawTextManager::CreateTempDoc(this, &txtParams, &tfmt, &pfmt, ptxtParamsa, 0.0);
  txtParams.WordWrap = 0;
  txtParams.Multiline = 0;
  Scaleform::GFx::DrawTextManager::SetTextParams(this, v8, &txtParams, &tfmt, &pfmt);
  Scaleform::Render::Text::DocView::SetText(v8, pwstr, 0xFFFFFFFF);
  widtha = Scaleform::Render::Text::DocView::GetTextHeight(v8);
  ptxtParamsb = Scaleform::Render::Text::DocView::GetTextWidth(v8) * 0.05000000074505806;
  result->Width = ptxtParamsb + 4.0;
  ptxtParamsc = 0.05000000074505806 * widtha;
  result->Height = ptxtParamsc + 4.0;
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
  v9 = (void *)(txtParams.FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((txtParams.FontName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pfmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&tfmt);
  return result;
}
