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
  Scaleform::GFx::AS2::Value val; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::IMECandidateListStyle st; // [esp+1Ch] [ebp-2Ch] BYREF

  pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
  v2 = (Scaleform::GFx::IMEManagerBase *)pMovieImpl->GetStateAddRef(
                                           &pMovieImpl->Scaleform::GFx::StateBag,
                                           State_IMEManager);
  if ( v2 )
  {
    st.Flags = 0;
    if ( Scaleform::GFx::IMEManagerBase::GetCandidateListStyle(v2, &st) )
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
      if ( (st.Flags & 1) != 0 )
      {
        val.T.Type = 3;
        Env = fn->Env;
        val.NV.NumberValue = (double)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & st.TextColor);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &Env->StringContext,
          "textColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 2) != 0 )
      {
        val.T.Type = 3;
        v8 = fn->Env;
        val.NV.NumberValue = (double)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & st.BackgroundColor);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v8->StringContext,
          "backgroundColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 4) != 0 )
      {
        val.T.Type = 3;
        v9 = fn->Env;
        val.NV.NumberValue = (double)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & st.IndexBackgroundColor);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v9->StringContext,
          "indexBackgroundColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 8) != 0 )
      {
        val.T.Type = 3;
        v10 = fn->Env;
        val.NV.NumberValue = (double)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & st.SelectedTextColor);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v10->StringContext,
          "selectedTextColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 0x10) != 0 )
      {
        val.T.Type = 3;
        v11 = fn->Env;
        val.NV.NumberValue = (double)((unsigned int)&vostok::memory::s_CRT_arena[5574199] & st.SelectedBackgroundColor);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v11->StringContext,
          "selectedTextBackgroundColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 0x20) != 0 )
      {
        val.T.Type = 3;
        v12 = fn->Env;
        val.NV.NumberValue = (double)((unsigned int)&vostok::memory::s_CRT_arena[5574199]
                                    & st.SelectedIndexBackgroundColor);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v12->StringContext,
          "selectedIndexBackgroundColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 0x40) != 0 )
      {
        val.T.Type = 3;
        v13 = fn->Env;
        val.NV.NumberValue = (double)st.FontSize;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v13->StringContext,
          "fontSize",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( SLOBYTE(st.Flags) < 0 )
      {
        val.T.Type = 3;
        v14 = fn->Env;
        val.NV.NumberValue = (double)st.ReadingWindowTextColor;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v14->StringContext,
          "readingWindowTextColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 0x100) != 0 )
      {
        val.T.Type = 3;
        v15 = fn->Env;
        val.NV.NumberValue = (double)st.ReadingWindowBackgroundColor;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v15->StringContext,
          "readingWindowBackgroundColor",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      if ( (st.Flags & 0x200) != 0 )
      {
        val.T.Type = 3;
        v16 = fn->Env;
        val.NV.NumberValue = (double)st.ReadingWindowFontSize;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v6->Scaleform::GFx::AS2::ObjectInterface,
          &v16->StringContext,
          "readingWindowFontSize",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
      if ( v6 )
      {
        RefCount = v6->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v6->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
        }
      }
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v2);
  }
}
