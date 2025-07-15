void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::replaceSelectedText(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::TextField *pObject; // esi
  Scaleform::Render::Text::DocView::DocumentText *v4; // eax
  unsigned int Length; // ebp
  Scaleform::Render::Text::EditorKitBase_vtbl *v6; // eax
  unsigned int v7; // ecx
  unsigned int GetCompositionString; // ebx
  wchar_t *v9; // edi
  unsigned int endPos; // [esp+8h] [ebp-80Ch]
  const Scaleform::Render::Text::ParagraphFormat *pparaFmt; // [esp+Ch] [ebp-808h]
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+10h] [ebp-804h]
  wchar_t buf[1024]; // [esp+14h] [ebp-800h] BYREF

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  if ( !Scaleform::GFx::TextField::HasStyleSheet(pObject) )
  {
    v4 = pObject->pDocument.pObject->pDocument.pObject;
    ptextFmt = v4->pDefaultTextFormat.pObject;
    pparaFmt = v4->pDefaultParagraphFormat.pObject;
    Length = Scaleform::GFx::ASConstString::GetLength(&value->Scaleform::GFx::ASConstString);
    v6 = pObject->pDocument.pObject->pEditorKit.pObject[1].__vftable;
    v7 = (unsigned int)v6[1].~Scaleform::Render::Text::EditorKitBase;
    GetCompositionString = (unsigned int)v6->GetCompositionString;
    if ( GetCompositionString >= v7 )
      GetCompositionString = (unsigned int)v6[1].~Scaleform::Render::Text::EditorKitBase;
    endPos = (unsigned int)v6->GetCompositionString;
    if ( v7 >= endPos )
      endPos = (unsigned int)v6[1].~Scaleform::Render::Text::EditorKitBase;
    if ( Length >= 0x400 )
    {
      v9 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2 * Length + 2, 0);
      Scaleform::UTF8Util::DecodeString(v9, (char *)value->pNode->pData, -1);
      Scaleform::GFx::TextField::ReplaceTextA(pObject, v9, GetCompositionString, endPos, 0xFFFFFFFF);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    }
    else
    {
      Scaleform::UTF8Util::DecodeString(buf, (char *)value->pNode->pData, -1);
      Scaleform::GFx::TextField::ReplaceTextA(pObject, buf, GetCompositionString, endPos, 0xFFFFFFFF);
    }
    Scaleform::GFx::Text::EditorKit::SetCursorPos(
      (Scaleform::GFx::Text::EditorKit *)pObject->pDocument.pObject->pEditorKit.pObject,
      GetCompositionString + Length,
      0);
    if ( pparaFmt )
      Scaleform::Render::Text::DocView::SetParagraphFormat(
        pObject->pDocument.pObject,
        pparaFmt,
        GetCompositionString,
        GetCompositionString + Length);
    if ( ptextFmt )
      Scaleform::Render::Text::DocView::SetTextFormat(
        pObject->pDocument.pObject,
        ptextFmt,
        GetCompositionString,
        GetCompositionString + Length);
    Scaleform::GFx::TextField::SetDirtyFlag(pObject);
  }
}
