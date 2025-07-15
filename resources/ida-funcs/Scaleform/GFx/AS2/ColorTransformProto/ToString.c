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
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v13; // zf
  _UNKNOWN **v14; // esi
  int i; // edi
  Scaleform::GFx::ASStringNode *v16; // ecx
  Scaleform::GFx::AS2::Value v17; // [esp+4h] [ebp-48h] BYREF
  Scaleform::StringBuffer v18; // [esp+14h] [ebp-38h] BYREF
  Scaleform::GFx::ASString v19; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::ASString v20; // [esp+30h] [ebp-1Ch] BYREF
  Scaleform::GFx::ASString v21; // [esp+34h] [ebp-18h] BYREF
  Scaleform::GFx::ASString v22; // [esp+38h] [ebp-14h] BYREF
  Scaleform::GFx::ASString v23; // [esp+3Ch] [ebp-10h] BYREF
  Scaleform::GFx::ASString v24; // [esp+40h] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v25; // [esp+44h] [ebp-8h] BYREF
  Scaleform::GFx::ASString v26; // [esp+48h] [ebp-4h] BYREF
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
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v19, Env, 6, 0);
    v4 = fn->Env;
    v17.NV.NumberValue = p_pProto[17];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v20, v4, 6, 0);
    v5 = fn->Env;
    v17.NV.NumberValue = p_pProto[18];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v21, v5, 6, 0);
    v6 = fn->Env;
    v17.NV.NumberValue = p_pProto[19];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v22, v6, 6, 0);
    v7 = fn->Env;
    v17.NV.NumberValue = p_pProto[20];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v23, v7, 6, 0);
    v8 = fn->Env;
    v17.NV.NumberValue = p_pProto[21];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v24, v8, 6, 0);
    v9 = fn->Env;
    v17.NV.NumberValue = p_pProto[22];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v25, v9, 6, 0);
    v17.NV.NumberValue = p_pProto[23];
    v17.T.Type = 3;
    Scaleform::GFx::AS2::Value::ToStringImpl(&v17, &v26, fn->Env, 6, 0);
    Scaleform::StringBuffer::StringBuffer(&v18, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)"(redMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v19.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)", greenMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v20.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)", blueMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v21.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)", alphaMultiplier=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v22.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)", redOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v23.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)", greenOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v24.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)", blueOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v25.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)", alphaOffset=", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)v26.pNode->pData, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v18, (const __m128i *)")", 0xFFFFFFFF);
    pData = (__m128i *)v18.pData;
    if ( !v18.pData )
      pData = (__m128i *)uri;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   pData,
                   v18.Size);
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
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v18);
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
