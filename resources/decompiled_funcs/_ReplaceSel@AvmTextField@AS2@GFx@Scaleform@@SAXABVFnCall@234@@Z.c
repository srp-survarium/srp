void __cdecl Scaleform::GFx::AS2::AvmTextField::ReplaceSel(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::TextField *v2; // esi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::Render::Text::DocView::DocumentText *pObject; // eax
  const Scaleform::Render::Text::ParagraphFormat *v5; // edx
  unsigned int Length; // ebp
  Scaleform::Render::Text::EditorKitBase_vtbl *v7; // eax
  unsigned int v8; // ecx
  unsigned int GetCompositionString; // ebx
  wchar_t *v10; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-18h] [ebp-82Ch]
  Scaleform::GFx::ASString str; // [esp+4h] [ebp-810h] BYREF
  unsigned int endPos; // [esp+8h] [ebp-80Ch]
  const Scaleform::Render::Text::ParagraphFormat *pparaFmt; // [esp+Ch] [ebp-808h]
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+10h] [ebp-804h]
  wchar_t buf[1024]; // [esp+14h] [ebp-800h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v2 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v2) && fn->NArgs >= 1 && v2->pDocument.pObject->pEditorKit.pObject )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v3, &str, Env, -1, 0);
      pObject = v2->pDocument.pObject->pDocument.pObject;
      v5 = pObject->pDefaultParagraphFormat.pObject;
      ptextFmt = pObject->pDefaultTextFormat.pObject;
      pparaFmt = v5;
      Length = Scaleform::GFx::ASConstString::GetLength(&str);
      v7 = v2->pDocument.pObject->pEditorKit.pObject[1].__vftable;
      v8 = (unsigned int)v7[1].~Scaleform::Render::Text::EditorKitBase;
      GetCompositionString = (unsigned int)v7->GetCompositionString;
      if ( GetCompositionString >= v8 )
        GetCompositionString = (unsigned int)v7[1].~Scaleform::Render::Text::EditorKitBase;
      endPos = (unsigned int)v7->GetCompositionString;
      if ( v8 >= endPos )
        endPos = v8;
      if ( Length >= 0x400 )
      {
        v10 = (wchar_t *)Scaleform::Memory::Alloc(2 * Length + 2);
        Scaleform::UTF8Util::DecodeString(v10, str.pNode->pData, -1);
        Scaleform::GFx::TextField::ReplaceTextA(v2, v10, GetCompositionString, endPos, 0xFFFFFFFF);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
      }
      else
      {
        Scaleform::UTF8Util::DecodeString(buf, str.pNode->pData, -1);
        Scaleform::GFx::TextField::ReplaceTextA(v2, buf, GetCompositionString, endPos, 0xFFFFFFFF);
      }
      Scaleform::GFx::Text::EditorKit::SetCursorPos(
        (Scaleform::GFx::Text::EditorKit *)v2->pDocument.pObject->pEditorKit.pObject,
        GetCompositionString + Length,
        0);
      if ( pparaFmt )
        Scaleform::Render::Text::DocView::SetParagraphFormat(
          v2->pDocument.pObject,
          pparaFmt,
          GetCompositionString,
          GetCompositionString + Length);
      if ( ptextFmt )
        Scaleform::Render::Text::DocView::SetTextFormat(
          v2->pDocument.pObject,
          ptextFmt,
          GetCompositionString,
          GetCompositionString + Length);
      Scaleform::GFx::TextField::SetDirtyFlag(v2);
      pNode = str.pNode;
      --str.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}
