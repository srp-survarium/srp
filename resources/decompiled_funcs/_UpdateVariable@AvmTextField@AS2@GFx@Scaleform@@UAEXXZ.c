void __thiscall Scaleform::GFx::AS2::AvmTextField::UpdateVariable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::ASString *v2; // ebp
  Scaleform::GFx::AS2::Environment *v3; // ebx
  Scaleform::GFx::ASString *Text; // eax
  Scaleform::GFx::AS2::Value *p_pUserDataHolder; // esi
  Scaleform::GFx::ASString *v6; // edi
  int pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASString result; // [esp+8h] [ebp-4h] BYREF

  v2 = (Scaleform::GFx::ASString *)&this->Scaleform::GFx::AS2::ObjectInterface;
  if ( this->FindMember )
  {
    v3 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::ASString *))this[-1].VariableName.pNode[5].pManager)(&this[-1].VariableName);
    if ( v3 )
    {
      Text = Scaleform::GFx::TextField::GetText(
               *((Scaleform::GFx::TextField **)&this[-1].VariableVal.NV + 3),
               &result,
               0);
      p_pUserDataHolder = (Scaleform::GFx::AS2::Value *)&this->pUserDataHolder;
      v6 = Text;
      if ( p_pUserDataHolder->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_pUserDataHolder);
      p_pUserDataHolder->T.Type = 5;
      pNode = (int)v6->pNode;
      p_pUserDataHolder->NV.Int32Value = (int)v6->pNode;
      ++*(_DWORD *)(pNode + 12);
      v8 = result.pNode;
      --result.pNode->RefCount;
      if ( !v8->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      Scaleform::GFx::AS2::Environment::SetVariable(v3, (int)v2, v2, p_pUserDataHolder, 0, 1);
    }
  }
}
