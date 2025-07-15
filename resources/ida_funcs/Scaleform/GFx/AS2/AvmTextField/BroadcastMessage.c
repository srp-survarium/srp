void __cdecl Scaleform::GFx::AS2::AvmTextField::BroadcastMessage(Scaleform::GFx::ASString fn)
{
  const Scaleform::GFx::AS2::FnCall *pNode; // esi
  Scaleform::GFx::AS2::Environment *pData; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ecx
  Scaleform::GFx::AS2::Environment *Env; // eax
  int NArgs; // edx
  unsigned int Size; // esi
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [esp+Ch] [ebp-Ch] BYREF
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  pNode = (const Scaleform::GFx::AS2::FnCall *)fn.pNode;
  pData = (Scaleform::GFx::AS2::Environment *)fn.pNode[1].pData;
  v3 = 0;
  if ( fn.pNode[1].pLower <= (Scaleform::GFx::ASStringNode *)(32 * (pData->Stack.Pages.Data.Size - 1)
                                                            + pData->Stack.pCurrent
                                                            - pData->Stack.pPageStart) )
    v3 = &pData->Stack.Pages.Data.Data[(unsigned int)fn.pNode[1].pLower >> 5]->Values[(int)fn.pNode[1].pLower & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v3, &fn, pData, -1, 0);
  ThisPtr = pNode->ThisPtr;
  Env = pNode->Env;
  if ( ThisPtr )
  {
    NArgs = pNode->NArgs;
    Size = Env->Stack.Pages.Data.Size;
    v10 = NArgs - 1;
    v11 = Env->Stack.pCurrent - Env->Stack.pPageStart + 32 * Size - 33;
    pcallback.__vftable = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(Env, ThisPtr, &fn, &pcallback);
  }
  v8 = fn.pNode;
  --fn.pNode->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
