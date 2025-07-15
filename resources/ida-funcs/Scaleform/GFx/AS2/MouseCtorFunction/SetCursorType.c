void __cdecl Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  int v4; // edi
  bool v5; // cc
  Scaleform::GFx::AS2::Value *v6; // ecx
  int v7; // eax
  Scaleform::GFx::AS2::Environment *v8; // edx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // ecx
  Scaleform::GFx::UserEventHandler *pObject; // ecx
  __int64 v12; // [esp+10h] [ebp-14h] BYREF
  int v13; // [esp+18h] [ebp-Ch]
  int v14; // [esp+1Ch] [ebp-8h]
  Scaleform::GFx::MovieImpl *proot; // [esp+20h] [ebp-4h]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  v4 = 0;
  v5 = fn->NArgs <= 0;
  proot = pMovieImpl;
  if ( !v5 )
  {
    v6 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v6 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v12 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v6, Env);
    v4 = v12;
  }
  v7 = 0;
  if ( fn->NArgs >= 2 )
  {
    v8 = fn->Env;
    v9 = fn->FirstArgBottomIndex - 1;
    v10 = 0;
    if ( v9 <= 32 * (v8->Stack.Pages.Data.Size - 1) + v8->Stack.pCurrent - v8->Stack.pPageStart )
      v10 = &v8->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    pMovieImpl = proot;
    v12 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v10, fn->Env);
    v7 = v12;
  }
  pObject = pMovieImpl->pUserEventHandler.pObject;
  if ( pObject )
  {
    v14 = v7;
    BYTE4(v12) = 0;
    LODWORD(v12) = 23;
    v13 = v4;
    pObject->HandleEvent(pObject, pMovieImpl, (const Scaleform::GFx::Event *)&v12);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      fn->Env,
      "No user event handler interface is installed; Mouse.setCursorType failed.");
  }
}


char __cdecl Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType(
        Scaleform::GFx::MovieImpl *proot,
        unsigned int mouseIndex,
        unsigned int cursorType)
{
  Scaleform::GFx::UserEventHandler *pObject; // ecx
  int v5; // [esp+0h] [ebp-10h] BYREF
  char v6; // [esp+4h] [ebp-Ch]
  unsigned int v7; // [esp+8h] [ebp-8h]
  unsigned int v8; // [esp+Ch] [ebp-4h]

  pObject = proot->pUserEventHandler.pObject;
  if ( !pObject )
    return 0;
  v7 = cursorType;
  v6 = 0;
  v5 = 23;
  v8 = mouseIndex;
  pObject->HandleEvent(pObject, proot, (const Scaleform::GFx::Event *)&v5);
  return 1;
}
