bool __thiscall Scaleform::GFx::AS2::MouseCtorFunction::HasOverloadedCursorTypeFunction(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Value *v3; // eax
  bool v4; // bl
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v7; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::FunctionRef result; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v11; // [esp+14h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Value::Value(&v11, psc, Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType);
  v4 = this->SetCursorTypeFunc.Function != Scaleform::GFx::AS2::Value::ToFunction(v3, &result, 0)->Function;
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
      v7 = result.pLocalFrame->RefCount;
      pLocalFrame = result.pLocalFrame;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v7) != 0 )
      {
        result.pLocalFrame->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  result.pLocalFrame = 0;
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  return v4;
}
