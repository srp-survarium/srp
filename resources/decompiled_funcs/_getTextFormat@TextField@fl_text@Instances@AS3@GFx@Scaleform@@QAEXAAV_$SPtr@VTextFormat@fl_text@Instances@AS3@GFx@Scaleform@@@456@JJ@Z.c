void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getTextFormat(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> beginIndex,
        int endIndex)
{
  signed int pObject; // edi
  signed int v6; // ebx
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::MemoryHeap *v8; // eax
  Scaleform::GFx::DisplayObject *v9; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // ecx
  Scaleform::Render::Text::ParagraphFormat paraFmt; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::Render::Text::TextFormat textFmt; // [esp+24h] [ebp-28h] BYREF

  pObject = (signed int)beginIndex.pObject;
  if ( beginIndex.pObject == (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)-1 )
    pObject = 0;
  v6 = endIndex;
  if ( endIndex == -1 )
    v6 = 0x7FFFFFFF;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  beginIndex.pObject = 0;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    pVM,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&beginIndex,
    pVM->TextFormatClass.pObject,
    0,
    0);
  if ( pObject <= v6 )
  {
    v8 = pVM->pMovieRoot->pMovieImpl->GetHeap(pVM->pMovieRoot->pMovieImpl);
    Scaleform::Render::Text::TextFormat::TextFormat(&textFmt, v8);
    v9 = this->pDispObj.pObject;
    paraFmt.RefCount = 1;
    memset(&paraFmt.pTabStops, 0, 16);
    Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
      (Scaleform::Render::Text::StyledText *)v9[1].pRenNode.pObject->pNative,
      &textFmt,
      &paraFmt,
      pObject,
      v6);
    Scaleform::GFx::AS3::Instances::fl_text::TextFormat::SetTextFormat(beginIndex.pObject, &paraFmt, (int)&textFmt);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&paraFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&textFmt);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(result, &beginIndex);
  if ( beginIndex.pObject && ((int)beginIndex.pObject & 1) == 0 )
  {
    RefCount = beginIndex.pObject->RefCount;
    v11 = beginIndex.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      beginIndex.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
    }
  }
}
