void __thiscall Scaleform::GFx::DrawTextImpl::SetHtmlText(Scaleform::GFx::DrawTextImpl *this, Scaleform::String *str)
{
  Scaleform::MemoryHeap *pHeap; // eax
  unsigned int HeapTypeBits; // edi
  Scaleform::Render::TreeText *pObject; // ebx
  unsigned int Length; // eax
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::GFx::DrawTextManager *v8; // [esp-8h] [ebp-24h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imgInfoArr; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pHeap = this->pDrawTextCtxt.pObject->pHeap;
  HeapTypeBits = str->HeapTypeBits;
  pObject = this->pTextNode.pObject;
  memset(&imgInfoArr, 0, 12);
  imgInfoArr.Data.pHeap = pHeap;
  Length = Scaleform::String::GetLength(str);
  Scaleform::Render::TreeText::SetHtmlText(
    pObject,
    (const char *)((HeapTypeBits & 0xFFFFFFFC) + 8),
    Length,
    &imgInfoArr);
  if ( imgInfoArr.Data.Size )
  {
    v8 = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, v8, &imgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    imgInfoArr.Data.Data,
    imgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, imgInfoArr.Data.Data);
}


void __thiscall Scaleform::GFx::DrawTextImpl::SetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        const char *putf8Str,
        unsigned int lengthInBytes)
{
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::GFx::DrawTextManager *v6; // [esp-8h] [ebp-1Ch]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imgInfoArr; // [esp+4h] [ebp-10h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pObject = this->pTextNode.pObject;
  imgInfoArr.Data.pHeap = this->pDrawTextCtxt.pObject->pHeap;
  memset(&imgInfoArr, 0, 12);
  Scaleform::Render::TreeText::SetHtmlText(pObject, putf8Str, lengthInBytes, &imgInfoArr);
  if ( imgInfoArr.Data.Size )
  {
    v6 = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, v6, &imgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    imgInfoArr.Data.Data,
    imgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, imgInfoArr.Data.Data);
}


void __thiscall Scaleform::GFx::DrawTextImpl::SetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        const wchar_t *pstr,
        unsigned int lengthInChars)
{
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::GFx::DrawTextManager *v6; // [esp-8h] [ebp-1Ch]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imgInfoArr; // [esp+4h] [ebp-10h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pObject = this->pTextNode.pObject;
  imgInfoArr.Data.pHeap = this->pDrawTextCtxt.pObject->pHeap;
  memset(&imgInfoArr, 0, 12);
  Scaleform::Render::TreeText::SetHtmlText(pObject, pstr, lengthInChars, &imgInfoArr);
  if ( imgInfoArr.Data.Size )
  {
    v6 = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, v6, &imgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    imgInfoArr.Data.Data,
    imgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, imgInfoArr.Data.Data);
}
