void __cdecl Scaleform::GFx::AS2::ArrayCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ArrayObject *v5; // eax
  Scaleform::GFx::AS2::ArrayObject *v6; // eax
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v8; // edx
  int NArgs; // eax
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value *v11; // eax
  int v12; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v14; // [esp+Ch] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v15; // [esp+18h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array
    && !v1->ThisPtr->IsBuiltinPrototype(v1->ThisPtr) )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
  }
  else
  {
    pHeap = v1->Env->StringContext.pContext->pHeap;
    v5 = (Scaleform::GFx::AS2::ArrayObject *)pHeap->Alloc(pHeap, 80u, 0);
    if ( v5 )
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v5, v1->Env);
    else
      v6 = 0;
    p_pProto = v6;
  }
  Env = v1->Env;
  v8 = p_pProto->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
  LOBYTE(fn) = 1;
  v15.T.Type = 4;
  v15.NV.Int32Value = 0;
  v8->SetMember(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    Env,
    (const Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount,
    &v15,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  if ( v15.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v15);
  NArgs = v1->NArgs;
  if ( NArgs )
  {
    if ( NArgs == 1 && ((Type = Scaleform::GFx::AS2::FnCall::Arg(v1, 0)->T.Type, Type == 3) || Type == 4) )
    {
      v14 = v1->Env;
      v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v12 = Scaleform::GFx::AS2::Value::ToInt32(v11, v14);
      Scaleform::GFx::AS2::ArrayObject::Resize(p_pProto, v12);
    }
    else
    {
      Scaleform::GFx::AS2::ArrayObject::InitArray(p_pProto, v1);
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, p_pProto);
  RefCount = p_pProto->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
}
