void __cdecl Scaleform::GFx::AS2::AsBroadcasterProto::RemoveListener(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v2; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v3; // eax
  Scaleform::GFx::AS2::ObjectInterface *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // eax
  char v6; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  char v8; // bl

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    if ( v2->T.Type == 7 )
    {
      v3 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v2, Env);
      if ( v3 )
      {
        v4 = &v3->Scaleform::GFx::AS2::ObjectInterface;
LABEL_10:
        v6 = Scaleform::GFx::AS2::AsBroadcaster::RemoveListener(fn->Env, fn->ThisPtr, v4);
        Result = fn->Result;
        v8 = v6;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->V.BooleanValue = v8;
        Result->T.Type = 2;
        return;
      }
    }
    else
    {
      v5 = Scaleform::GFx::AS2::Value::ToObject(v2, Env);
      if ( v5 )
      {
        v4 = &v5->Scaleform::GFx::AS2::ObjectInterface;
        goto LABEL_10;
      }
    }
    v4 = 0;
    goto LABEL_10;
  }
}
