void __cdecl Scaleform::GFx::AS2::StringProto::StringToLowerCase(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::ASConstString *p_pProto; // eax
  Scaleform::GFx::ASStringNode *v3; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v5; // zf

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::ASConstString *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v3 = Scaleform::GFx::ASConstString::ToLowerNode(p_pProto + 13);
    ++v3->RefCount;
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)v3;
    v5 = ++v3->RefCount == 1;
    --v3->RefCount;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v3);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
