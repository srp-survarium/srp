void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::GetCount(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // eax
  unsigned int CharCount; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  unsigned int v5; // edi

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        CharCount = Scaleform::GFx::StaticTextSnapshotData::GetCharCount((Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13]);
        Result = fn->Result;
        v5 = CharCount;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->NV.Int32Value = v5;
        Result->T.Type = 4;
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "TextSnapshot");
  }
}
