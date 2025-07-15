void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::HitTestTextNearPos(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  float v9; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *closedist; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *closedista; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *closedistb; // [esp+8h] [ebp-14h]
  float closedistc; // [esp+8h] [ebp-14h]
  float y; // [esp+14h] [ebp-8h]
  float x; // [esp+18h] [ebp-4h]
  int idx; // [esp+20h] [ebp+4h]
  float idxb; // [esp+20h] [ebp+4h]
  float idxc; // [esp+20h] [ebp+4h]
  float idxd; // [esp+20h] [ebp+4h]
  int idxa; // [esp+20h] [ebp+4h]

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
        x = Scaleform::GFx::AS2::Value::ToNumber(v4, closedist);
        closedista = fn->Env;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        y = Scaleform::GFx::AS2::Value::ToNumber(v5, closedista);
        if ( fn->NArgs <= 2 )
        {
          *(float *)&idx = 0.0;
        }
        else
        {
          closedistb = fn->Env;
          v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          *(float *)&idx = Scaleform::GFx::AS2::Value::ToNumber(v6, closedistb);
        }
        idxb = *(float *)&idx * 20.0;
        closedistc = idxb;
        idxc = y * 20.0;
        v9 = idxc;
        idxd = 20.0 * x;
        v7 = Scaleform::GFx::StaticTextSnapshotData::HitTestTextNearPos(
               (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
               idxd,
               v9,
               closedistc);
        Result = fn->Result;
        idxa = v7;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 3;
        Result->NV.NumberValue = (double)idxa;
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
