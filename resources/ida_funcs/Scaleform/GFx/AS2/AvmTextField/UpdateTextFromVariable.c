char __thiscall Scaleform::GFx::AS2::AvmTextField::UpdateTextFromVariable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // ebp
  Scaleform::GFx::TextField *v3; // edi
  Scaleform::GFx::AS2::Environment *v4; // eax
  Scaleform::GFx::AS2::Environment *v5; // esi
  Scaleform::GFx::AS2::ObjectInterface::UserDataHolder **p_pUserDataHolder; // ebx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASString str; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+Ch] [ebp-10h] BYREF

  v2 = &this->Scaleform::GFx::AS2::ObjectInterface;
  if ( !this->FindMember )
    return 1;
  v3 = (Scaleform::GFx::TextField *)*((_DWORD *)&this[-1].VariableVal.NV + 3);
  v3->Flags |= 0x8000u;
  v4 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::ASString *))this[-1].VariableName.pNode[5].pManager)(&this[-1].VariableName);
  v5 = v4;
  if ( !v4 )
    return 0;
  val.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v4, (const Scaleform::GFx::ASString *)v2, &val, 0, 0, 0, 0) )
  {
    Scaleform::GFx::TextField::SetTextValue(v3, (char *)&buf, 0, 0);
LABEL_11:
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    return 0;
  }
  p_pUserDataHolder = &this->pUserDataHolder;
  if ( Scaleform::GFx::AS2::Value::IsEqual(&val, v5, (Scaleform::GFx::AS2::Value *)p_pUserDataHolder) )
    goto LABEL_11;
  Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)p_pUserDataHolder, &val);
  Scaleform::GFx::AS2::Value::ToStringImpl(&val, &str, v5, -1, 0);
  pNode = str.pNode;
  Scaleform::GFx::TextField::SetTextValue(v3, (char *)str.pNode->pData, 0, 0);
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return 1;
}
