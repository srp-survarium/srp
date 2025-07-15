void __cdecl Scaleform::GFx::AS2::GAS_GetIMECandidateListStyle(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::IMEManagerBase *v2; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // esi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::AS2::Environment *v8; // edx
  Scaleform::GFx::AS2::Environment *v9; // eax
  Scaleform::GFx::AS2::Environment *v10; // ecx
  Scaleform::GFx::AS2::Environment *v11; // edx
  Scaleform::GFx::AS2::Environment *v12; // eax
  Scaleform::GFx::AS2::Environment *v13; // ecx
  Scaleform::GFx::AS2::Environment *v14; // ecx
  Scaleform::GFx::AS2::Environment *v15; // edx
  Scaleform::GFx::AS2::Environment *v16; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v18; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::IMECandidateListStyle v19; // [esp+1Ch] [ebp-2Ch] BYREF

  pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
  v2 = (Scaleform::GFx::IMEManagerBase *)pMovieImpl->GetStateAddRef(
                                           &pMovieImpl->Scaleform::GFx::StateBag,
                                           State_IMEManager);
  if ( v2 )
  {
    v19.Flags = 0;
    if ( Scaleform::GFx::IMEManagerBase::GetCandidateListStyle(v2, &v19) )
    {
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v4 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
      if ( v4 )
      {
        Scaleform::GFx::AS2::Object::Object(v4, fn->Env);
        v6 = v5;
      }
      else
      {
        v6 = 0;
      }
      if ( (v19.Flags & 1) != 0 )
      {
        v18.T.Type = 3;
        Env = fn->Env;
        v18.NV.NumberValue = (double)(v19.TextColor & 0xFFFFFF);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&Env->StringContext,
          "textColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 2) != 0 )
      {
        v18.T.Type = 3;
        v8 = fn->Env;
        v18.NV.NumberValue = (double)(v19.BackgroundColor & 0xFFFFFF);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v8->StringContext,
          "backgroundColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 4) != 0 )
      {
        v18.T.Type = 3;
        v9 = fn->Env;
        v18.NV.NumberValue = (double)(v19.IndexBackgroundColor & 0xFFFFFF);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v9->StringContext,
          "indexBackgroundColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 8) != 0 )
      {
        v18.T.Type = 3;
        v10 = fn->Env;
        v18.NV.NumberValue = (double)(v19.SelectedTextColor & 0xFFFFFF);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v10->StringContext,
          "selectedTextColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 0x10) != 0 )
      {
        v18.T.Type = 3;
        v11 = fn->Env;
        v18.NV.NumberValue = (double)(v19.SelectedBackgroundColor & 0xFFFFFF);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v11->StringContext,
          "selectedTextBackgroundColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 0x20) != 0 )
      {
        v18.T.Type = 3;
        v12 = fn->Env;
        v18.NV.NumberValue = (double)(v19.SelectedIndexBackgroundColor & 0xFFFFFF);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v12->StringContext,
          "selectedIndexBackgroundColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 0x40) != 0 )
      {
        v18.T.Type = 3;
        v13 = fn->Env;
        v18.NV.NumberValue = (double)v19.FontSize;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v13->StringContext,
          "fontSize",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( SLOBYTE(v19.Flags) < 0 )
      {
        v18.T.Type = 3;
        v14 = fn->Env;
        v18.NV.NumberValue = (double)v19.ReadingWindowTextColor;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v14->StringContext,
          "readingWindowTextColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 0x100) != 0 )
      {
        v18.T.Type = 3;
        v15 = fn->Env;
        v18.NV.NumberValue = (double)v19.ReadingWindowBackgroundColor;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v15->StringContext,
          "readingWindowBackgroundColor",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      if ( (v19.Flags & 0x200) != 0 )
      {
        v18.T.Type = 3;
        v16 = fn->Env;
        v18.NV.NumberValue = (double)v19.ReadingWindowFontSize;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          (Scaleform::GFx::ASStringNode *)&v16->StringContext,
          "readingWindowFontSize",
          &v18);
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
      }
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
      if ( v6 )
      {
        RefCount = v6->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v6->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
        }
      }
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v2);
  }
}
