char __thiscall Scaleform::GFx::AS2::MouseCtorFunction::SetMember(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebp
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx
  Scaleform::GFx::AS2::FunctionRef *v9; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v12; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int *p_Flags; // ebx
  char v16; // bl
  Scaleform::GFx::AS2::FunctionRef result; // [esp+10h] [ebp-Ch] BYREF

  pContext = penv->StringContext.pContext;
  p_StringContext = &penv->StringContext;
  pObject = pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[35].pMovieImpl )
  {
    if ( pContext->GFxExtensions.Value == 1 )
    {
      v9 = Scaleform::GFx::AS2::Value::ToFunction(val, &result, penv);
      Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)&this->pListenersArray, v9);
      if ( (result.Flags & 2) == 0 )
      {
        if ( result.Function )
        {
          RefCount = result.Function->RefCount;
          Function = result.Function;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            result.Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      result.Function = 0;
      if ( (result.Flags & 1) == 0 )
      {
        if ( result.pLocalFrame )
        {
          v12 = result.pLocalFrame->RefCount;
          pLocalFrame = result.pLocalFrame;
          if ( (v12 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v12 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      p_Flags = &penv->Target->pASRoot->pMovieImpl->Flags;
      if ( Scaleform::GFx::AS2::MouseCtorFunction::HasOverloadedCursorTypeFunction(
             (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 16),
             p_StringContext) )
      {
        *p_Flags |= 0x1000u;
      }
      else
      {
        *p_Flags &= ~0x1000u;
      }
    }
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
  if ( name->pNode != (Scaleform::GFx::ASStringNode *)pObject[24].pMovieImpl )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  v16 = Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(
    (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 16),
    p_StringContext,
    penv);
  return v16;
}
