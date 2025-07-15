void __cdecl Scaleform::GFx::AS2::AvmTextField::BroadcastMessage(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ecx
  Scaleform::GFx::AS2::Environment *v5; // eax
  int NArgs; // edx
  unsigned int Size; // esi
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback v9[3]; // [esp+Ch] [ebp-Ch] BYREF

  v1 = fn;
  Env = fn->Env;
  v3 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
  ThisPtr = v1->ThisPtr;
  v5 = v1->Env;
  if ( ThisPtr )
  {
    NArgs = v1->NArgs;
    Size = v5->Stack.Pages.Data.Size;
    v9[1].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(NArgs - 1);
    v9[2].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)(v5->Stack.pCurrent
                                                                                - v5->Stack.pPageStart
                                                                                + 32 * Size
                                                                                - 33);
    v9[0].__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v5,
      ThisPtr,
      (const Scaleform::GFx::ASString *)&fn,
      v9);
  }
  v8 = (Scaleform::GFx::ASStringNode *)fn;
  --fn->ThisFunctionRef.Function;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
