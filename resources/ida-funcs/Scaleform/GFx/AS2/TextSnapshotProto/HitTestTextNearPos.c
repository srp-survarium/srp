void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::HitTestTextNearPos(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  int v7; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  float y; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *closedist; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *closedista; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *closedistb; // [esp+8h] [ebp-14h]
  float closedistc; // [esp+8h] [ebp-14h]
  float v14; // [esp+14h] [ebp-8h]
  float v15; // [esp+18h] [ebp-4h]
  float v16; // [esp+20h] [ebp+4h]
  float v17; // [esp+20h] [ebp+4h]
  float v18; // [esp+20h] [ebp+4h]
  float x; // [esp+20h] [ebp+4h]
  Scaleform::GFx::AS2::FnCall *v20; // [esp+20h] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs >= 2 )
      {
        closedist = fn->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v15 = Scaleform::GFx::AS2::Value::ToNumber(v4, closedist);
        closedista = fn->Env;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v14 = Scaleform::GFx::AS2::Value::ToNumber(v5, closedista);
        if ( fn->NArgs <= 2 )
        {
          v16 = 0.0;
        }
        else
        {
          closedistb = fn->Env;
          v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v16 = Scaleform::GFx::AS2::Value::ToNumber(v6, closedistb);
        }
        v17 = v16 * 20.0;
        closedistc = v17;
        v18 = v14 * 20.0;
        y = v18;
        x = 20.0 * v15;
        v7 = Scaleform::GFx::StaticTextSnapshotData::HitTestTextNearPos(
               (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
               x,
               y,
               closedistc);
        Result = fn->Result;
        v20 = (Scaleform::GFx::AS2::FnCall *)v7;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 3;
        Result->NV.NumberValue = (double)(int)v20;
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
