Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::StringCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::StringCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // edi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::StringObject *v4; // eax
  int v5; // eax
  int v6; // edi
  void (__thiscall *v7)(int, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment **); // edx
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::Value v10; // [esp+18h] [ebp-10h] BYREF

  v2 = penv;
  p_StringContext = &penv->StringContext;
  v4 = (Scaleform::GFx::AS2::StringObject *)penv->StringContext.pContext->pHeap->Alloc(
                                              penv->StringContext.pContext->pHeap,
                                              56,
                                              0);
  if ( v4 )
  {
    Scaleform::GFx::AS2::StringObject::StringObject(v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = *(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment **))(*(_DWORD *)(v6 + 16) + 40);
  pContext = p_StringContext->pContext;
  LOBYTE(penv) = 0;
  v10.T.Type = 10;
  v7(v6 + 16, p_StringContext, &pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount, &v10, &penv);
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  return (Scaleform::GFx::AS2::Object *)v6;
}
