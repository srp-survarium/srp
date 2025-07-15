void __cdecl Scaleform::GFx::AS2::DateProto::DateToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  int v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  int pObject; // ecx
  int v5; // edx
  unsigned __int8 v6; // al
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  Scaleform::GFx::AS2::Object *v10; // ecx
  int v11; // eax
  int v12; // edx
  Scaleform::GFx::AS2::Object *v13; // ecx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v16; // zf
  const char *v17; // [esp+8h] [ebp-ACh] BYREF
  int v18; // [esp+Ch] [ebp-A8h] BYREF
  int v19; // [esp+10h] [ebp-A4h] BYREF
  int v20; // [esp+14h] [ebp-A0h] BYREF
  int v21; // [esp+18h] [ebp-9Ch] BYREF
  int v22; // [esp+1Ch] [ebp-98h] BYREF
  int v23; // [esp+20h] [ebp-94h] BYREF
  int *v24; // [esp+24h] [ebp-90h]
  Scaleform::MsgFormat::Sink v25; // [esp+28h] [ebp-8Ch] BYREF
  __m128i v26[8]; // [esp+34h] [ebp-80h] BYREF

  v1 = 0;
  if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Date )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Date");
    return;
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    p_pProto = &ThisPtr[-2].pProto;
  else
    p_pProto = 0;
  pObject = (int)p_pProto[23].pObject;
  v18 = 0;
  v19 = 0;
  v24 = (int *)&p_pProto[23];
  v5 = (int)p_pProto[24].pObject;
  while ( 1 )
  {
    if ( !(pObject % 4) )
    {
      if ( pObject % 100 || !(pObject % 400) )
      {
        v5 = (int)p_pProto[24].pObject;
        v6 = 1;
        goto LABEL_14;
      }
      v5 = (int)p_pProto[24].pObject;
    }
    v6 = 0;
LABEL_14:
    if ( v5 < months[v6][v1] )
      break;
    if ( ++v1 >= 12 )
    {
      v7 = v18;
      goto LABEL_21;
    }
  }
  v7 = v1;
  if ( v1 )
  {
    v8 = dword_6F8914[12 * Scaleform::GFx::AS2::IsLeapYear(pObject) + v1];
    v5 = (int)p_pProto[24].pObject;
  }
  else
  {
    v8 = 0;
  }
  v19 = v5 - v8 + 1;
LABEL_21:
  v9 = (int)p_pProto[21].pObject;
  v10 = p_pProto[20].pObject;
  if ( v9 < 0 )
    v17 = daynames[(unsigned int)(((3 - -__SPAIR64__(v9, (unsigned int)v10) / 86400000) % 7 + 7) % 7)];
  else
    v17 = daynames[(unsigned int)((__SPAIR64__(v9, (unsigned int)v10) / 86400000 + 4) % 7)];
  v11 = (int)p_pProto[25].pObject / 3600000;
  v12 = (int)p_pProto[25].pObject % 3600000;
  v25.Type = tDataPtr;
  v25.SinkData.DataPtr.Size = 128;
  v18 = v12 / 60000;
  v20 = v11;
  v13 = p_pProto[22].pObject;
  v23 = (int)v13 % 60000 / 1000;
  v22 = (int)v13 / 3600000;
  v21 = (int)v13 % 3600000 / 60000;
  v25.SinkData.pStr = (Scaleform::String *)v26;
  Scaleform::Format<char const *,char const *,int,int,int,int,int,int,int>(
    &v25,
    "{0} {1} {2:2} {3:02}:{4:02}:{5:02} GMT{6:+03}{7:02} {8}",
    &v17,
    &monthnames[v7],
    &v19,
    &v22,
    &v21,
    &v23,
    &v20,
    &v18,
    v24);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 v26);
  ++StringNode->RefCount;
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->T.Type = 5;
  Result->NV.Int32Value = (int)StringNode;
  v16 = ++StringNode->RefCount == 1;
  --StringNode->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}
