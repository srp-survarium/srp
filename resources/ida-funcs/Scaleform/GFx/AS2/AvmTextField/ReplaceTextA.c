void __cdecl Scaleform::GFx::AS2::AvmTextField::ReplaceTextA(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::TextField *v2; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  double v6; // st7
  unsigned int Length; // ebx
  unsigned int v8; // esi
  unsigned int v9; // eax
  Scaleform::Render::Text::DocView *pObject; // ecx
  unsigned int v11; // ebp
  Scaleform::Render::Text::TextFormat *v12; // eax
  Scaleform::Render::Text::ParagraphFormat *v13; // ecx
  wchar_t *v14; // ebx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v15; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Environment *v17; // [esp-14h] [ebp-834h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-82Ch]
  Scaleform::GFx::AS2::Environment *v19; // [esp-Ch] [ebp-82Ch]
  Scaleform::Render::Text::ParagraphFormat *fmt; // [esp+4h] [ebp-81Ch] BYREF
  unsigned int beginPos[2]; // [esp+8h] [ebp-818h]
  Scaleform::GFx::ASConstString v22; // [esp+10h] [ebp-810h] BYREF
  Scaleform::Render::Text::TextFormat *v23[2]; // [esp+14h] [ebp-80Ch] BYREF
  unsigned int v24; // [esp+1Ch] [ebp-804h]
  wchar_t ptext[1024]; // [esp+20h] [ebp-800h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v2 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v2) && fn->NArgs >= 3 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      *(double *)beginPos = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      v19 = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      *(double *)v23 = Scaleform::GFx::AS2::Value::ToNumber(v4, v19);
      v17 = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v22, v17, -1, 0);
      v6 = *(double *)beginPos;
      Length = Scaleform::GFx::ASConstString::GetLength(&v22);
      v24 = Length;
      v8 = (__int64)*(double *)beginPos;
      *(_QWORD *)beginPos = (__int64)*(double *)v23;
      beginPos[0] = (__int64)*(double *)v23;
      if ( v6 >= 0.0 && *(double *)v23 >= 0.0 && v8 <= (unsigned int)(__int64)*(double *)v23 )
      {
        v9 = Scaleform::Render::Text::StyledText::GetLength(v2->pDocument.pObject->pDocument.pObject);
        pObject = v2->pDocument.pObject;
        v11 = Length + v8 + v9 - beginPos[0];
        if ( v8 < v9 )
        {
          Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(pObject->pDocument.pObject, v23, &fmt, v8);
          v12 = v23[0];
          v13 = fmt;
        }
        else
        {
          v12 = pObject->pDocument.pObject->pDefaultTextFormat.pObject;
          v23[0] = v12;
          v13 = pObject->pDocument.pObject->pDefaultParagraphFormat.pObject;
          fmt = v13;
        }
        if ( v12 )
        {
          ++v12->RefCount;
          v13 = fmt;
        }
        if ( v13 )
          ++v13->RefCount;
        if ( Length >= 0x400 )
        {
          v14 = (wchar_t *)Scaleform::Memory::Alloc(2 * Length + 2);
          Scaleform::UTF8Util::DecodeString(v14, (char *)v22.pNode->pData, -1);
          Scaleform::GFx::TextField::ReplaceTextA(v2, v14, v8, beginPos[0], 0xFFFFFFFF);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
          Length = v24;
        }
        else
        {
          Scaleform::UTF8Util::DecodeString(ptext, (char *)v22.pNode->pData, -1);
          Scaleform::GFx::TextField::ReplaceTextA(v2, ptext, v8, beginPos[0], 0xFFFFFFFF);
        }
        v15 = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)v2->pDocument.pObject->pEditorKit.pObject;
        if ( v15 && (unsigned int)Scaleform::GFx::Text::EditorKit::GetCursorPos(v15) > v11 )
          Scaleform::GFx::Text::EditorKit::SetCursorPos(
            (Scaleform::GFx::Text::EditorKit *)v2->pDocument.pObject->pEditorKit.pObject,
            v11,
            0);
        if ( fmt )
          Scaleform::Render::Text::DocView::SetParagraphFormat(v2->pDocument.pObject, fmt, v8, v8 + Length);
        if ( v23[0] )
        {
          Scaleform::Render::Text::DocView::SetTextFormat(v2->pDocument.pObject, v23[0], v8, v8 + Length);
          if ( v23[0] )
            Scaleform::Render::Text::TextFormat::Release(v23[0]);
        }
        if ( fmt )
          Scaleform::Render::Text::ParagraphFormat::Release(fmt);
        Scaleform::GFx::TextField::SetDirtyFlag(v2);
      }
      pNode = v22.pNode;
      --v22.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}
