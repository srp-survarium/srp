void __cdecl Scaleform::GFx::AS2::GAS_GlobalTrace(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v3; // eax
  Scaleform::GFx::AS2::ObjectInterface *v4; // esi
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // eax
  Scaleform::GFx::AS2::Environment *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  bool v9; // zf
  Scaleform::GFx::AS2::Environment *v10; // edx
  Scaleform::GFx::AS2::Value *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // ebp
  unsigned int Size; // esi
  char *i; // eax
  Scaleform::GFx::AS2::Environment *v15; // [esp-4h] [ebp-808h]
  Scaleform::GFx::ASStringNode *v16; // [esp+10h] [ebp-7F4h] BYREF
  Scaleform::GFx::AS2::Value v17; // [esp+14h] [ebp-7F0h] BYREF
  Scaleform::GFx::AS2::Value v18; // [esp+24h] [ebp-7E0h] BYREF
  char _Dst[2000]; // [esp+34h] [ebp-7D0h] BYREF

  Env = fn->Env;
  v2 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  v15 = fn->Env;
  if ( v2->T.Type == 7 )
  {
    v3 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v2, v15);
    if ( !v3 )
      goto LABEL_20;
    v4 = &v3->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(v2, v15);
    if ( !v5 )
      goto LABEL_20;
    v4 = &v5->Scaleform::GFx::AS2::ObjectInterface;
  }
  if ( v4 )
  {
    p_StringContext = &fn->Env->StringContext;
    v17.T.Type = 0;
    if ( v4->GetMemberRaw(
           v4,
           p_StringContext,
           (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[25].pMovieImpl,
           &v17)
      && (v17.T.Type == 8 || v17.T.Type == 11) )
    {
      v7 = fn->Env;
      v18.T.Type = 0;
      Scaleform::GFx::AS2::GAS_Invoke(
        &v17,
        &v18,
        v4,
        v7,
        0,
        v7->Stack.pCurrent - v7->Stack.pPageStart + 32 * v7->Stack.Pages.Data.Size - 31,
        0);
      Scaleform::GFx::AS2::Value::ToStringImpl(&v18, (Scaleform::GFx::ASString *)&v16, fn->Env, -1, 0);
      v8 = v16;
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(
        &fn->Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>,
        "%s\n",
        v16->pData);
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
      return;
    }
    if ( v17.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
  }
LABEL_20:
  v10 = fn->Env;
  v11 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (v10->Stack.Pages.Data.Size - 1) + v10->Stack.pCurrent - v10->Stack.pPageStart )
    v11 = &v10->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v11, (Scaleform::GFx::ASString *)&v16, v10, -1, 0);
  v12 = v16;
  Size = v16->Size;
  if ( Size >= 0x7D0 )
    Size = 1999;
  strncpy_s((int)fn, _Dst, 2000, v16->pData, Size);
  _Dst[Size] = 0;
  for ( i = _Dst; *i; ++i )
  {
    if ( *i == 13 )
      *i = 10;
  }
  if ( v12->Size >= 0x7D0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(
      &fn->Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>,
      "%s ...<truncated>\n",
      _Dst);
  else
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(
      &fn->Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>,
      "%s\n",
      _Dst);
  v9 = v12->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
