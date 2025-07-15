void __cdecl Scaleform::GFx::AS2::ArrayCtorFunction::DeclareArray(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ArrayObject *v3; // eax
  Scaleform::GFx::AS2::ArrayObject *v4; // eax
  Scaleform::GFx::AS2::ArrayObject *v5; // ebp
  Scaleform::GFx::AS2::Environment *Env; // eax
  bool (__thiscall *SetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::FunctionRef ctor; // [esp+18h] [ebp-10h] BYREF

  v1 = fn;
  pHeap = fn->Env->StringContext.pContext->pHeap;
  v3 = (Scaleform::GFx::AS2::ArrayObject *)pHeap->Alloc(pHeap, 80u, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v3, v1->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  Env = v1->Env;
  SetMember = v5->SetMember;
  LOBYTE(fn) = 1;
  LOBYTE(ctor.Function) = 4;
  ctor.pLocalFrame = 0;
  SetMember(
    &v5->Scaleform::GFx::AS2::ObjectInterface,
    Env,
    (const Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount,
    (const Scaleform::GFx::AS2::Value *)&ctor,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  if ( LOBYTE(ctor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&ctor);
  Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, &ctor, ASBuiltin_Array);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    &v5->Scaleform::GFx::AS2::ObjectInterface,
    &v1->Env->StringContext,
    &ctor);
  if ( v1->NArgs )
    Scaleform::GFx::AS2::ArrayObject::InitArray(v5, v1);
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v5);
  Flags = ctor.Flags;
  if ( (ctor.Flags & 2) == 0 )
  {
    Function = ctor.Function;
    if ( ctor.Function )
    {
      RefCount = ctor.Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        ctor.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = ctor.pLocalFrame;
    if ( ctor.pLocalFrame )
    {
      v12 = ctor.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v12) != 0 )
      {
        ctor.pLocalFrame->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  v13 = v5->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v13) != 0 )
  {
    v5->RefCount = v13 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
  }
}
