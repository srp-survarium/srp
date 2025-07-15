void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::SetSelectColor(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-Ch]

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && v1->NArgs >= 1 )
      {
        Env = v1->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        fn = (const Scaleform::GFx::AS2::FnCall *)Scaleform::GFx::AS2::Value::ToUInt32(v4, Env);
        HIBYTE(fn) = -1;
        Scaleform::GFx::StaticTextSnapshotData::SetSelectColor(
          (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
          (const Scaleform::Render::Color *)&fn);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "TextSnapshot");
  }
}
