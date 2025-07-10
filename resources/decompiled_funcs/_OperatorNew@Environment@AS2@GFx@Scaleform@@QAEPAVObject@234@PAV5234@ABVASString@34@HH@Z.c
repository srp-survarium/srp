Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::Environment::OperatorNew(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Object *ppackageObj,
        const Scaleform::GFx::ASString *className,
        int nargs,
        int argsTopOff)
{
  bool (__thiscall *GetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *); // eax
  const Scaleform::GFx::AS2::FunctionRef *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::FunctionRef result; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value ctor; // [esp+18h] [ebp-10h] BYREF

  GetMember = ppackageObj->GetMember;
  ctor.T.Type = 0;
  if ( GetMember(&ppackageObj->Scaleform::GFx::AS2::ObjectInterface, this, className, &ctor)
    && (ctor.T.Type == 8 || ctor.T.Type == 11) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToFunction(&ctor, &result, this);
    v8 = Scaleform::GFx::AS2::Environment::OperatorNew(this, v7, nargs, argsTopOff);
    if ( (result.Flags & 2) == 0 )
    {
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        Function = result.Function;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
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
        v11 = result.pLocalFrame->RefCount;
        pLocalFrame = result.pLocalFrame;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v11) != 0 )
        {
          result.pLocalFrame->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0;
    if ( ctor.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ctor);
    return v8;
  }
  else
  {
    if ( ctor.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ctor);
    return 0;
  }
}
