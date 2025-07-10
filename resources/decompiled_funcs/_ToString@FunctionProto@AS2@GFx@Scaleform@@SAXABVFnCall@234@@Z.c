void __cdecl Scaleform::GFx::AS2::FunctionProto::ToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  int v3; // eax

  Result = fn->Result;
  pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->T.Type = 5;
  v3 = *(_DWORD *)&pObject[24].AVMVersion;
  Result->NV.Int32Value = v3;
  ++*(_DWORD *)(v3 + 12);
}
