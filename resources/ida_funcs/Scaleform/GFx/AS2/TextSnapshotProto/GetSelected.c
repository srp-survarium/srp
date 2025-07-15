void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::GetSelected(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v3; // eax
  unsigned int v4; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  unsigned int CharCount; // eax
  char IsSelected; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  char v9; // bl
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-10h]
  Scaleform::GFx::AS2::Environment *v11; // [esp-Ch] [ebp-10h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs >= 1 )
      {
        Env = fn->Env;
        v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v4 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env);
        if ( fn->NArgs <= 1 )
        {
          CharCount = Scaleform::GFx::StaticTextSnapshotData::GetCharCount((Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13]);
        }
        else
        {
          v11 = fn->Env;
          v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
          CharCount = Scaleform::GFx::AS2::Value::ToUInt32(v5, v11);
        }
        if ( CharCount <= v4 )
          CharCount = v4 + 1;
        IsSelected = Scaleform::GFx::StaticTextSnapshotData::IsSelected(
                       (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
                       v4,
                       CharCount);
        Result = fn->Result;
        v9 = IsSelected;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 2;
        Result->V.BooleanValue = v9;
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
