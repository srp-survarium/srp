void __cdecl Scaleform::GFx::AS2::TextFieldProto::MakeStyle(
        const Scaleform::GFx::AS2::FnCall *fn,
        const Scaleform::Render::Text::HighlightInfo *hinfo)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // edi
  const Scaleform::Render::Text::HighlightInfo *v6; // esi
  char *v7; // edx
  Scaleform::GFx::AS2::LocalFrame *ConstStringNode; // esi
  double v10; // st7
  Scaleform::GFx::AS2::Environment *Env; // eax
  double v12; // st7
  Scaleform::GFx::AS2::Environment *v13; // eax
  double v14; // st7
  Scaleform::GFx::AS2::Environment *v15; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v17; // [esp+Ch] [ebp-14h] BYREF

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v3 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS2::Object::Object(v3, fn->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = hinfo;
  if ( (hinfo->Flags & 7) != 0 )
  {
    switch ( hinfo->Flags & 7 )
    {
      case 1:
        v7 = "single";
        goto LABEL_11;
      case 2:
        v7 = "thick";
        goto LABEL_11;
      case 3:
        v7 = "dotted";
        goto LABEL_11;
      case 5:
        v7 = "ditheredSingle";
        goto LABEL_11;
      case 6:
        v7 = "ditheredThick";
LABEL_11:
        ConstStringNode = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                               (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                               v7,
                                                               strlen(v7),
                                                               0);
        ++ConstStringNode->RefCount;
        v17.V.BooleanValue = 5;
        v17.V.FunctionValue.pLocalFrame = ConstStringNode;
        ++ConstStringNode->RefCount;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v5->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
          "underlineStyle",
          (const Scaleform::GFx::AS2::Value *)&v17.NV.4);
        if ( v17.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v17.NV.4);
        if ( ConstStringNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)ConstStringNode);
        v6 = hinfo;
        break;
      default:
        break;
    }
  }
  if ( (v6->Flags & 0x20) != 0 )
  {
    v10 = (double)(v6->UnderlineColor.Raw & 0xFFFFFF);
    v17.V.BooleanValue = 3;
    Env = fn->Env;
    *(double *)((char *)&v17.NV.NumberValue + 4) = v10;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::ASStringNode *)&Env->StringContext,
      "underlineColor",
      (const Scaleform::GFx::AS2::Value *)&v17.NV.4);
    if ( v17.V.BooleanValue >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v17.NV.4);
  }
  if ( (v6->Flags & 8) != 0 )
  {
    v12 = (double)(v6->BackgroundColor.Raw & 0xFFFFFF);
    v17.V.BooleanValue = 3;
    v13 = fn->Env;
    *(double *)((char *)&v17.NV.NumberValue + 4) = v12;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::ASStringNode *)&v13->StringContext,
      "backgroundColor",
      (const Scaleform::GFx::AS2::Value *)&v17.NV.4);
    if ( v17.V.BooleanValue >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v17.NV.4);
  }
  if ( (v6->Flags & 0x10) != 0 )
  {
    v14 = (double)(v6->TextColor.Raw & 0xFFFFFF);
    v17.V.BooleanValue = 3;
    v15 = fn->Env;
    *(double *)((char *)&v17.NV.NumberValue + 4) = v14;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      (Scaleform::GFx::ASStringNode *)&v15->StringContext,
      "textColor",
      (const Scaleform::GFx::AS2::Value *)&v17.NV.4);
    if ( v17.V.BooleanValue >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v17.NV.4);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}
