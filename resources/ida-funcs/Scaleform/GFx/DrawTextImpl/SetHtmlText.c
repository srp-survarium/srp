void __thiscall Scaleform::GFx::DrawTextImpl::SetHtmlText(Scaleform::GFx::DrawTextImpl *this, Scaleform::String *str)
{
  Scaleform::MemoryHeap *pHeap; // eax
  unsigned int HeapTypeBits; // edi
  Scaleform::Render::TreeText *pObject; // ebx
  unsigned int Length; // eax
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::GFx::DrawTextManager *v8; // [esp-8h] [ebp-24h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pHeap = this->pDrawTextCtxt.pObject->pHeap;
  HeapTypeBits = str->HeapTypeBits;
  pObject = this->pTextNode.pObject;
  memset(&pimgInfoArr, 0, 12);
  pimgInfoArr.Data.pHeap = pHeap;
  Length = Scaleform::String::GetLength(str);
  Scaleform::Render::TreeText::SetHtmlText(pObject, (char *)((HeapTypeBits & 0xFFFFFFFC) + 8), Length, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    v8 = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, v8, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}


void __thiscall Scaleform::GFx::DrawTextImpl::SetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        char *putf8Str,
        unsigned int lengthInBytes)
{
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::GFx::DrawTextManager *v6; // [esp-8h] [ebp-1Ch]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [esp+4h] [ebp-10h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pObject = this->pTextNode.pObject;
  pimgInfoArr.Data.pHeap = this->pDrawTextCtxt.pObject->pHeap;
  memset(&pimgInfoArr, 0, 12);
  Scaleform::Render::TreeText::SetHtmlText(pObject, putf8Str, lengthInBytes, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    v6 = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, v6, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}


void __thiscall Scaleform::GFx::DrawTextImpl::SetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        wchar_t *pstr,
        unsigned int lengthInChars)
{
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::Text::DocView *DocView; // eax
  Scaleform::GFx::DrawTextManager *v6; // [esp-8h] [ebp-1Ch]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [esp+4h] [ebp-10h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pObject = this->pTextNode.pObject;
  pimgInfoArr.Data.pHeap = this->pDrawTextCtxt.pObject->pHeap;
  memset(&pimgInfoArr, 0, 12);
  Scaleform::Render::TreeText::SetHtmlText(pObject, pstr, lengthInChars, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    v6 = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, v6, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}
