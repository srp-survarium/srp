void __cdecl Scaleform::GFx::AS2::TextFormatProto::GetTextExtent(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::InteractiveObject *Target; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::MemoryHeap *v8; // ecx
  Scaleform::Render::Text::DocView *v9; // ebx
  Scaleform::Render::Text::Allocator *TextAllocator; // eax
  Scaleform::Render::Text::DocView *v11; // eax
  Scaleform::Render::Text::DocView *v12; // esi
  Scaleform::GFx::AS2::Value *v13; // eax
  const Scaleform::Render::Text::TextFormat *v14; // eax
  const Scaleform::Render::Text::ParagraphFormat *v15; // eax
  double TextWidth; // st7
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::ObjectInterface *v18; // ebx
  double TextHeight; // st7
  Scaleform::GFx::AS2::Environment *v20; // ecx
  double v21; // st7
  Scaleform::GFx::AS2::Environment *v22; // eax
  double v23; // st7
  Scaleform::GFx::AS2::Environment *v24; // edx
  bool v25; // bl
  Scaleform::StringDH *FontList; // eax
  int v27; // eax
  Scaleform::RefCountVImpl *v28; // ebx
  double v29; // st6
  int v30; // eax
  double v31; // st6
  double v32; // st5
  double v33; // st7
  double v34; // st5
  Scaleform::GFx::AS2::Environment *v35; // ecx
  Scaleform::GFx::AS2::Environment *v36; // ecx
  Scaleform::GFx::ASStringNode *RefCount; // ecx
  Scaleform::GFx::AS2::Object *v39; // ecx
  unsigned int v40; // eax
  Scaleform::GFx::AS2::Environment *x; // [esp+10h] [ebp-BCh]
  Scaleform::GFx::Resource *y; // [esp+14h] [ebp-B8h]
  Scaleform::GFx::AS2::Environment *y_4; // [esp+18h] [ebp-B4h]
  int v44; // [esp+30h] [ebp-9Ch]
  char v45; // [esp+30h] [ebp-9Ch]
  Scaleform::GFx::MovieImpl *pMovieImpl; // [esp+34h] [ebp-98h]
  float v47; // [esp+34h] [ebp-98h]
  float v48; // [esp+34h] [ebp-98h]
  Scaleform::GFx::AS2::ObjectInterface *v49; // [esp+34h] [ebp-98h]
  Scaleform::GFx::AS2::Value sz; // [esp+3Ch] [ebp-90h] BYREF
  Scaleform::GFx::AS2::Object *obj; // [esp+4Ch] [ebp-80h]
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [esp+50h] [ebp-7Ch] BYREF
  __int16 v53; // [esp+64h] [ebp-68h]
  __int16 v54; // [esp+66h] [ebp-66h]
  Scaleform::RefCountNTSImpl *v55; // [esp+68h] [ebp-64h]
  Scaleform::Render::Text::TextFormat rect; // [esp+6Ch] [ebp-60h] BYREF
  Scaleform::Render::Text::TextFormat defaultTextFmt; // [esp+A4h] [ebp-28h] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( fn->NArgs )
  {
    if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_TextFormat )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "TextFormat");
      return;
    }
    ThisPtr = fn->ThisPtr;
    v44 = ThisPtr ? (int)&ThisPtr[-2].pProto : 0;
    Target = fn->Env->Target;
    v55 = Target;
    if ( Target )
    {
      ++Target->RefCount;
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v5 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
      if ( v5 )
      {
        Scaleform::GFx::AS2::Object::Object(v5, fn->Env);
        obj = v6;
      }
      else
      {
        obj = 0;
      }
      x = fn->Env;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v7, (Scaleform::GFx::ASString *)&defaultParagraphFmt, x, -1, 0);
      v8 = fn->Env->StringContext.pContext->pHeap;
      v9 = (Scaleform::Render::Text::DocView *)v8->Alloc(v8, 272u, 0);
      if ( v9 )
      {
        pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
        y = (Scaleform::GFx::Resource *)Target->GetFontManager(Target);
        TextAllocator = Scaleform::GFx::MovieImpl::GetTextAllocator(pMovieImpl);
        Scaleform::Render::Text::DocView::DocView(v9, TextAllocator, y, 0);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      v12->pDocument.pObject->RTFlags |= 2u;
      Scaleform::Render::Text::DocView::SetAutoSizeX(v12);
      Scaleform::Render::Text::DocView::SetAutoSizeY(v12);
      if ( fn->Env->StringContext.SWFVersion >= 7u && fn->NArgs >= 2 )
      {
        y_4 = fn->Env;
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        *(double *)&sz.T.Type = Scaleform::GFx::AS2::Value::ToNumber(v13, y_4);
        v12->Flags &= ~1u;
        Scaleform::Render::Text::DocView::SetWordWrap(v12);
        v47 = *(double *)&sz.T.Type;
        *(float *)&sz.T.Type = v47 * 20.0;
        *(float *)&sz.V.pStringNode = 0.0;
        Scaleform::Render::Rect<float>::Rect<float>(
          (Scaleform::Render::Rect<float> *)&rect,
          0.0,
          0.0,
          (const Scaleform::Render::Size<float> *)&sz);
        Scaleform::Render::Text::DocView::SetViewRect(v12, (const Scaleform::Render::Rect<float> *)&rect, UseExternally);
      }
      v12->Flags |= 4u;
      Scaleform::Render::Text::TextFormat::TextFormat(&defaultTextFmt, fn->Env->StringContext.pContext->pHeap);
      v53 = 0;
      defaultParagraphFmt.pTabStops = (unsigned int *)1;
      memset(&defaultParagraphFmt.BlockIndent, 0, 12);
      v54 = 0;
      Scaleform::Render::Text::TextFormat::InitByDefaultValues(&defaultTextFmt);
      Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues((Scaleform::Render::Text::ParagraphFormat *)&defaultParagraphFmt.pTabStops);
      v14 = Scaleform::Render::Text::TextFormat::Merge(
              &defaultTextFmt,
              &rect,
              (const Scaleform::Render::Text::TextFormat *)(v44 + 52));
      Scaleform::Render::Text::TextFormat::operator=(&defaultTextFmt, v14);
      Scaleform::Render::Text::TextFormat::~TextFormat(&rect);
      v15 = Scaleform::Render::Text::ParagraphFormat::Merge(
              (Scaleform::Render::Text::ParagraphFormat *)&defaultParagraphFmt.pTabStops,
              (Scaleform::Render::Text::ParagraphFormat *)&rect,
              (const Scaleform::Render::Text::ParagraphFormat *)(v44 + 92));
      Scaleform::Render::Text::ParagraphFormat::operator=(
        (Scaleform::Render::Text::ParagraphFormat *)&defaultParagraphFmt.pTabStops,
        v15);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&rect);
      Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v12->pDocument.pObject, &defaultTextFmt);
      Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
        v12->pDocument.pObject,
        (const Scaleform::Render::Text::ParagraphFormat *)&defaultParagraphFmt.pTabStops);
      Scaleform::Render::Text::DocView::SetText(v12, *(char **)defaultParagraphFmt.RefCount, 0xFFFFFFFF);
      Scaleform::Render::Text::DocView::Format(v12);
      TextWidth = Scaleform::Render::Text::DocView::GetTextWidth(v12);
      Env = fn->Env;
      sz.NV.NumberValue = (TextWidth + 80.0) * 0.05;
      v18 = &obj->Scaleform::GFx::AS2::ObjectInterface;
      sz.T.Type = 3;
      Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        &obj->Scaleform::GFx::AS2::ObjectInterface,
        (Scaleform::GFx::ASStringNode *)&Env->StringContext,
        "textFieldWidth",
        &sz);
      if ( sz.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&sz);
      TextHeight = Scaleform::Render::Text::DocView::GetTextHeight(v12);
      v20 = fn->Env;
      sz.NV.NumberValue = (TextHeight + 80.0) * 0.05;
      sz.T.Type = 3;
      Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        v18,
        (Scaleform::GFx::ASStringNode *)&v20->StringContext,
        "textFieldHeight",
        &sz);
      if ( sz.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&sz);
      v21 = Scaleform::Render::Text::DocView::GetTextWidth(v12);
      v22 = fn->Env;
      sz.NV.NumberValue = v21 * 0.05;
      sz.T.Type = 3;
      Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        v18,
        (Scaleform::GFx::ASStringNode *)&v22->StringContext,
        "width",
        &sz);
      if ( sz.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&sz);
      v23 = Scaleform::Render::Text::DocView::GetTextHeight(v12);
      v24 = fn->Env;
      sz.NV.NumberValue = v23 * 0.05;
      sz.T.Type = 3;
      Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        v18,
        (Scaleform::GFx::ASStringNode *)&v24->StringContext,
        "height",
        &sz);
      if ( sz.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&sz);
      v25 = (defaultTextFmt.FormatFlags & 2) != 0;
      v45 = defaultTextFmt.FormatFlags & 1;
      FontList = Scaleform::Render::Text::TextFormat::GetFontList(&defaultTextFmt);
      v27 = (int)v12->pFontManager.pObject->CreateFontHandle(
                   v12->pFontManager.pObject,
                   (const char *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                   (v45 != 0 ? 2 : 0) | v25 | 0x10,
                   1,
                   0);
      v28 = (Scaleform::RefCountVImpl *)v27;
      v29 = 0.0;
      if ( v27 )
      {
        v30 = *(_DWORD *)(v27 + 24);
        v31 = *(float *)(v30 + 8);
        v32 = *(float *)(v30 + 12);
        if ( 0.0 != v31 )
        {
LABEL_30:
          v33 = v32;
          if ( v32 == 0.0 )
            v33 = 1024.0 - v31;
          LOBYTE(rect.RefCount) = 3;
          v48 = (double)defaultTextFmt.FontSize * 0.05000000074505806;
          v34 = v48 * 20.0 * 0.0009765625;
          *(_QWORD *)&sz.T.Type = (__int64)(v33 * v34 * 0.05);
          v35 = fn->Env;
          *(double *)&rect.FontList = (double)(unsigned int)(__int64)(0.05 * (v31 * v34));
          v49 = &obj->Scaleform::GFx::AS2::ObjectInterface;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            &obj->Scaleform::GFx::AS2::ObjectInterface,
            (Scaleform::GFx::ASStringNode *)&v35->StringContext,
            "ascent",
            (const Scaleform::GFx::AS2::Value *)&rect);
          if ( LOBYTE(rect.RefCount) >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&rect);
          LOBYTE(rect.RefCount) = 3;
          v36 = fn->Env;
          *(double *)&rect.FontList = (double)*(unsigned int *)&sz.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v49,
            (Scaleform::GFx::ASStringNode *)&v36->StringContext,
            "descent",
            (const Scaleform::GFx::AS2::Value *)&rect);
          if ( LOBYTE(rect.RefCount) >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&rect);
          Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, obj);
          if ( v28 )
            Scaleform::RefCountImpl::Release(v28);
          Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&defaultParagraphFmt.pTabStops);
          Scaleform::Render::Text::TextFormat::~TextFormat(&defaultTextFmt);
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
          RefCount = (Scaleform::GFx::ASStringNode *)defaultParagraphFmt.RefCount;
          if ( (*(_DWORD *)(defaultParagraphFmt.RefCount + 12))-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
          v39 = obj;
          if ( obj )
          {
            v40 = obj->RefCount;
            if ( (v40 & 0x3FFFFFF) != 0 )
            {
              obj->RefCount = v40 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v39);
            }
          }
          Scaleform::RefCountNTSImpl::Release(v55);
          return;
        }
        v29 = *(float *)(v30 + 12);
      }
      v32 = v29;
      v31 = 960.0;
      goto LABEL_30;
    }
  }
}
