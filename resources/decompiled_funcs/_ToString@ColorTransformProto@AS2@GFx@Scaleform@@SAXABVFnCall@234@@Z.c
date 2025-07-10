void __cdecl Scaleform::GFx::AS2::ColorTransformProto::ToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  float *p_pProto; // edi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::AS2::Environment *v4; // eax
  Scaleform::GFx::AS2::Environment *v5; // edx
  Scaleform::GFx::AS2::Environment *v6; // ecx
  Scaleform::GFx::AS2::Environment *v7; // eax
  Scaleform::GFx::AS2::Environment *v8; // edx
  Scaleform::GFx::AS2::Environment *v9; // ecx
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v13; // zf
  _UNKNOWN **v14; // esi
  int i; // edi
  Scaleform::GFx::ASStringNode *v16; // ecx
  Scaleform::GFx::AS2::Value v17; // [esp+4h] [ebp-48h] BYREF
  Scaleform::StringBuffer str; // [esp+14h] [ebp-38h] BYREF
  Scaleform::GFx::ASString ps[8]; // [esp+2Ch] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+0h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_ColorTransform )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (float *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Env = fn->Env;
    v17.NV.NumberValue = p_pProto[16];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, ps, Env, 6, 0);
    v4 = fn->Env;
    v17.NV.NumberValue = p_pProto[17];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &ps[1], v4, 6, 0);
    v5 = fn->Env;
    v17.NV.NumberValue = p_pProto[18];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &ps[2], v5, 6, 0);
    v6 = fn->Env;
    v17.NV.NumberValue = p_pProto[19];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &ps[3], v6, 6, 0);
    v7 = fn->Env;
    v17.NV.NumberValue = p_pProto[20];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &ps[4], v7, 6, 0);
    v8 = fn->Env;
    v17.NV.NumberValue = p_pProto[21];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &ps[5], v8, 6, 0);
    v9 = fn->Env;
    v17.NV.NumberValue = p_pProto[22];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &ps[6], v9, 6, 0);
    v17.NV.NumberValue = p_pProto[23];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &ps[7], fn->Env, 6, 0);
    Scaleform::StringBuffer::StringBuffer(&str, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&str, "(redMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[0].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ", greenMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[1].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ", blueMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[2].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ", alphaMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[3].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ", redOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[4].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ", greenOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[5].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ", blueOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[6].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ", alphaOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, (char *)ps[7].pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&str, ")", 0xFFFFFFFF);
    pData = str.pData;
    if ( !str.pData )
      pData = (char *)&buf;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   pData,
                   str.Size);
    ++StringNode->RefCount;
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)StringNode;
    v13 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&str);
    v14 = &retaddr;
    for ( i = 7; i >= 0; --i )
    {
      v16 = (Scaleform::GFx::ASStringNode *)*--v14;
      v13 = v16->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "ColorTransform");
  }
}
