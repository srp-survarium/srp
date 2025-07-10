void __cdecl Scaleform::GFx::AS2::DateProto::DateToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  int v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  int pObject; // ecx
  int edx7; // edx
  unsigned __int8 al11; // al
  int ebx16; // ebx
  int v8; // eax
  int eax21; // eax
  Scaleform::GFx::AS2::Object *v10; // ecx
  int v11; // eax
  int v12; // edx
  Scaleform::GFx::AS2::Object *v13; // ecx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *v15; // edi
  bool v16; // zf
  const char *dayname; // [esp+8h] [ebp-ACh] BYREF
  int month; // [esp+Ch] [ebp-A8h] BYREF
  int day; // [esp+10h] [ebp-A4h] BYREF
  int v7; // [esp+14h] [ebp-A0h] BYREF
  int v5; // [esp+18h] [ebp-9Ch] BYREF
  int v4; // [esp+1Ch] [ebp-98h] BYREF
  int v6; // [esp+20h] [ebp-94h] BYREF
  int *v9; // [esp+24h] [ebp-90h]
  Scaleform::MsgFormat::Sink result; // [esp+28h] [ebp-8Ch] BYREF
  char out[128]; // [esp+34h] [ebp-80h] BYREF

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
  month = 0;
  day = 0;
  v9 = (int *)&p_pProto[23];
  edx7 = (int)p_pProto[24].pObject;
  while ( 1 )
  {
    if ( !(pObject % 4) )
    {
      if ( pObject % 100 || !(pObject % 400) )
      {
        edx7 = (int)p_pProto[24].pObject;
        al11 = 1;
        goto LABEL_14;
      }
      edx7 = (int)p_pProto[24].pObject;
    }
    al11 = 0;
LABEL_14:
    if ( edx7 < months[al11][v1] )
      break;
    if ( ++v1 >= 12 )
    {
      ebx16 = month;
      goto LABEL_21;
    }
  }
  ebx16 = v1;
  if ( v1 )
  {
    v8 = dword_865024[12 * Scaleform::GFx::AS2::IsLeapYear(pObject) + v1];
    edx7 = (int)p_pProto[24].pObject;
  }
  else
  {
    v8 = 0;
  }
  day = edx7 - v8 + 1;
LABEL_21:
  eax21 = (int)p_pProto[21].pObject;
  v10 = p_pProto[20].pObject;
  if ( eax21 < 0 )
    dayname = daynames[(unsigned int)(((3 - -__SPAIR64__(eax21, (unsigned int)v10) / 86400000) % 7 + 7) % 7)];
  else
    dayname = daynames[(unsigned int)((__SPAIR64__(eax21, (unsigned int)v10) / 86400000 + 4) % 7)];
  v11 = (int)p_pProto[25].pObject / ((int)&loc_36EE7F + 1);
  v12 = (int)p_pProto[25].pObject % ((int)&loc_36EE7F + 1);
  result.Type = tDataPtr;
  result.SinkData.DataPtr.Size = 128;
  month = v12 / 60000;
  v7 = v11;
  v13 = p_pProto[22].pObject;
  v6 = (int)v13 % 60000 / 1000;
  v4 = (int)v13 / ((int)&loc_36EE7F + 1);
  v5 = (int)v13 % ((int)&loc_36EE7F + 1) / 60000;
  result.SinkData.pStr = (Scaleform::String *)out;
  Scaleform::Format<char const *,char const *,int,int,int,int,int,int,int>(
    &result,
    "{0} {1} {2:2} {3:02}:{4:02}:{5:02} GMT{6:+03}{7:02} {8}",
    &dayname,
    &monthnames[ebx16],
    &day,
    &v4,
    &v5,
    &v6,
    &v7,
    &month,
    v9);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 out);
  ++StringNode->RefCount;
  v15 = fn->Result;
  if ( v15->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v15->T.Type = 5;
  v15->NV.Int32Value = (int)StringNode;
  v16 = ++StringNode->RefCount == 1;
  --StringNode->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}
