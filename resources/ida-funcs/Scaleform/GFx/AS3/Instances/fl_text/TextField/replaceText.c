void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::replaceText(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int beginIndex,
        unsigned int endIndex,
        const Scaleform::GFx::ASString *newText)
{
  Scaleform::GFx::TextField *pObject; // edi
  unsigned int Length; // ebx
  unsigned int v7; // eax
  Scaleform::Render::Text::DocView *v8; // ecx
  unsigned int v9; // ebp
  const Scaleform::Render::Text::TextFormat *v10; // eax
  const Scaleform::Render::Text::ParagraphFormat *v11; // ecx
  wchar_t *v12; // ebx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v13; // ecx
  const Scaleform::Render::Text::ParagraphFormat *pparaFmt; // [esp+4h] [ebp-80Ch] BYREF
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+8h] [ebp-808h] BYREF
  unsigned int len; // [esp+Ch] [ebp-804h]
  wchar_t buf[1024]; // [esp+10h] [ebp-800h] BYREF

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  if ( !Scaleform::GFx::TextField::HasStyleSheet(pObject) )
  {
    Length = Scaleform::GFx::ASConstString::GetLength(&newText->Scaleform::GFx::ASConstString);
    len = Length;
    if ( (beginIndex & 0x80000000) == 0 && (endIndex & 0x80000000) == 0 && beginIndex <= endIndex )
    {
      v7 = Scaleform::Render::Text::StyledText::GetLength(pObject->pDocument.pObject->pDocument.pObject);
      v8 = pObject->pDocument.pObject;
      v9 = beginIndex + Length + v7 - endIndex;
      if ( beginIndex < v7 )
      {
        Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
          v8->pDocument.pObject,
          (Scaleform::Render::Text::TextFormat **)&ptextFmt,
          (Scaleform::Render::Text::ParagraphFormat **)&pparaFmt,
          beginIndex);
        v10 = ptextFmt;
        v11 = pparaFmt;
      }
      else
      {
        v10 = v8->pDocument.pObject->pDefaultTextFormat.pObject;
        ptextFmt = v10;
        v11 = v8->pDocument.pObject->pDefaultParagraphFormat.pObject;
        pparaFmt = v11;
      }
      if ( v10 )
      {
        ++v10->RefCount;
        v11 = pparaFmt;
      }
      if ( v11 )
        ++v11->RefCount;
      if ( Length >= 0x400 )
      {
        v12 = (wchar_t *)Scaleform::Memory::Alloc(2 * Length + 2);
        Scaleform::UTF8Util::DecodeString(v12, newText->pNode->pData, -1);
        Scaleform::GFx::TextField::ReplaceTextA(pObject, v12, beginIndex, endIndex, 0xFFFFFFFF);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
        Length = len;
      }
      else
      {
        Scaleform::UTF8Util::DecodeString(buf, newText->pNode->pData, -1);
        Scaleform::GFx::TextField::ReplaceTextA(pObject, buf, beginIndex, endIndex, 0xFFFFFFFF);
      }
      v13 = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)pObject->pDocument.pObject->pEditorKit.pObject;
      if ( v13 && (unsigned int)Scaleform::GFx::Text::EditorKit::GetCursorPos(v13) > v9 )
        Scaleform::GFx::Text::EditorKit::SetCursorPos(
          (Scaleform::GFx::Text::EditorKit *)pObject->pDocument.pObject->pEditorKit.pObject,
          v9,
          0);
      if ( pparaFmt )
        Scaleform::Render::Text::DocView::SetParagraphFormat(
          pObject->pDocument.pObject,
          pparaFmt,
          beginIndex,
          Length + beginIndex);
      if ( ptextFmt )
      {
        Scaleform::Render::Text::DocView::SetTextFormat(
          pObject->pDocument.pObject,
          ptextFmt,
          beginIndex,
          beginIndex + Length);
        if ( ptextFmt )
          Scaleform::Render::Text::TextFormat::Release((Scaleform::Render::Text::TextFormat *)ptextFmt);
      }
      if ( pparaFmt )
        Scaleform::Render::Text::ParagraphFormat::Release((Scaleform::Render::Text::ParagraphFormat *)pparaFmt);
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
  }
}
