void __cdecl Scaleform::GFx::AS2::ArrayCtorFunction::DeclareArray(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ArrayObject *v3; // eax
  Scaleform::GFx::AS2::ArrayObject *v4; // eax
  Scaleform::GFx::AS2::ArrayObject *v5; // ebp
  Scaleform::GFx::AS2::Environment *Env; // eax
  bool (__thiscall *SetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  char v8; // bl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // ecx
  int v10; // eax
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  int v12; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v14; // [esp+18h] [ebp-10h] BYREF

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
  v14.T.Type = 4;
  v14.NV.Int32Value = 0;
  SetMember(
    &v5->Scaleform::GFx::AS2::ObjectInterface,
    Env,
    (const Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount,
    &v14,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, (Scaleform::GFx::AS2::FunctionRef *)&v14, ASBuiltin_Array);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    &v5->Scaleform::GFx::AS2::ObjectInterface,
    &v1->Env->StringContext,
    (const Scaleform::GFx::AS2::FunctionRef *)&v14);
  if ( v1->NArgs )
    Scaleform::GFx::AS2::ArrayObject::InitArray(v5, v1);
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v5);
  v8 = BYTE4(v14.NV.NumberValue);
  if ( (BYTE4(v14.NV.NumberValue) & 2) == 0 )
  {
    v9 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v14.T.Type;
    if ( *(_DWORD *)&v14.T.Type )
    {
      v10 = *(_DWORD *)(*(_DWORD *)&v14.T.Type + 12);
      if ( (v10 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)&v14.T.Type + 12) = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  if ( (v8 & 1) == 0 )
  {
    pStringNode = v14.V.pStringNode;
    if ( v14.NV.Int32Value )
    {
      v12 = *(_DWORD *)(v14.NV.Int32Value + 12);
      if ( (v12 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(v14.NV.Int32Value + 12) = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
      }
    }
  }
  RefCount = v5->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    v5->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
  }
}
