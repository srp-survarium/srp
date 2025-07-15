void __thiscall Scaleform::GFx::AS2::AvmTextField::NotifyChanged(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::Environment *v2; // edi
  int v3; // ebp
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  Scaleform::GFx::DisplayObject *v5; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  Scaleform::GFx::AS2::ObjectInterface *p_VariableVal; // ebp
  int v9; // ebx
  Scaleform::GFx::ASStringNode *v10; // eax
  unsigned int n; // [esp+10h] [ebp-18h]
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+18h] [ebp-10h] BYREF

  v2 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::ASString *))this[-1].VariableName.pNode[5].pManager)(&this[-1].VariableName);
  n = 1;
  if ( v2->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v3 = *(_DWORD *)(*((_DWORD *)&this[-1].VariableVal.NV + 3) + 168);
    if ( v3 != -1 )
    {
      if ( ++v2->Stack.pCurrent >= v2->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v2->Stack);
      pCurrent = v2->Stack.pCurrent;
      if ( pCurrent )
      {
        pCurrent->T.Type = 4;
        pCurrent->NV.Int32Value = v3;
      }
      n = 2;
    }
  }
  v5 = (Scaleform::GFx::DisplayObject *)*((_DWORD *)&this[-1].VariableVal.NV + 3);
  v.T.Type = 7;
  if ( v5 )
  {
    pObject = v5->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v5);
    v.NV.Int32Value = (int)pObject;
    if ( pObject )
      ++pObject->RefCount;
  }
  else
  {
    v.NV.Int32Value = 0;
  }
  ++v2->Stack.pCurrent;
  p_pCurrent = &v2->Stack.pCurrent;
  if ( v2->Stack.pCurrent >= v2->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v2->Stack);
  if ( !*p_pCurrent || (Scaleform::GFx::AS2::Value::Value(*p_pCurrent, &v), v.T.Type >= 5u) )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( this == (Scaleform::GFx::AS2::AvmTextField *)24 )
    p_VariableVal = 0;
  else
    p_VariableVal = (Scaleform::GFx::AS2::ObjectInterface *)&this[-1].VariableVal;
  v9 = v2->Stack.pCurrent - v2->Stack.pPageStart + 32 * v2->Stack.Pages.Data.Size - 32;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "onChanged",
                      9u,
                      0);
  ++ConstStringNode->RefCount;
  if ( p_VariableVal )
  {
    *(_DWORD *)&v.T.Type = &`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    *(_QWORD *)&v.NV.NumberValue = __PAIR64__(v9, n);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v2,
      p_VariableVal,
      (const Scaleform::GFx::ASString *)&ConstStringNode,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&v);
  }
  v10 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&v2->Stack, n);
}
