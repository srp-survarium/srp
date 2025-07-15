void __cdecl Scaleform::GFx::AS2::ObjectProto::IsPrototypeOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *v6; // ecx
  Scaleform::GFx::AS2::Object *v7; // eax
  bool v8; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v10; // bl
  Scaleform::GFx::AS2::Value *v11; // esi

  if ( fn->NArgs < 1 || (unsigned int)(fn->ThisPtr->GetObjectType(fn->ThisPtr) - 2) <= 3 )
    goto LABEL_13;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    p_pProto = &ThisPtr[-2].pProto;
  else
    p_pProto = 0;
  Env = fn->Env;
  v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
  if ( v4->T.Type == 7 )
  {
    v5 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v4, Env);
    if ( !v5 )
      goto LABEL_13;
    v6 = &v5->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    v7 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
    if ( !v7 )
      goto LABEL_13;
    v6 = &v7->Scaleform::GFx::AS2::ObjectInterface;
  }
  if ( v6 )
  {
    v8 = v6->InstanceOf(v6, fn->Env, (const Scaleform::GFx::AS2::Object *)p_pProto, 0);
    Result = fn->Result;
    v10 = v8;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v10;
    Result->T.Type = 2;
    return;
  }
LABEL_13:
  v11 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v11);
  v11->V.BooleanValue = 0;
  v11->T.Type = 2;
}
