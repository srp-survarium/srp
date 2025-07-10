void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::SetSelected(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // ebx
  Scaleform::GFx::AS2::Value *v6; // eax
  unsigned int v7; // edi
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v10; // [esp-10h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v11; // [esp-10h] [ebp-14h]
  char bselect; // [esp+8h] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs >= 3 )
      {
        Env = fn->Env;
        v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v4 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env);
        v10 = fn->Env;
        v5 = v4;
        v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v7 = Scaleform::GFx::AS2::Value::ToUInt32(v6, v10);
        v11 = fn->Env;
        v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        bselect = Scaleform::GFx::AS2::Value::ToBool(v8, v11);
        if ( v7 <= v5 )
          v7 = v5 + 1;
        Scaleform::GFx::StaticTextSnapshotData::SetSelected(
          (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
          v5,
          v7,
          bselect);
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
