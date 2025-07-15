void __cdecl Scaleform::GFx::AS2::GAS_NumberToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  char *v5; // eax
  Scaleform::String *v6; // esi
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v9; // zf
  Scaleform::GFx::AS2::Environment *Env; // [esp+10h] [ebp-4Ch]
  char destStr[64]; // [esp+1Ch] [ebp-40h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Number )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v3 = 10;
    if ( fn->NArgs > 0 )
    {
      Env = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v3 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
    }
    v5 = Scaleform::GFx::NumberUtil::ToString(*(double *)&p_pProto[14].pObject, destStr, 0x40u, v3);
    v6 = (Scaleform::String *)&p_pProto[16];
    Scaleform::String::operator=(v6, v5);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   (char *)((v6->HeapTypeBits & 0xFFFFFFFC) + 8));
    ++StringNode->RefCount;
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)StringNode;
    v9 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Number");
  }
}
