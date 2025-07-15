char __thiscall Scaleform::GFx::AS2::AvmTextField::UpdateTextFromVariable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // ebp
  Scaleform::GFx::TextField *v3; // edi
  Scaleform::GFx::AS2::Environment *v4; // eax
  Scaleform::GFx::AS2::Environment *v5; // esi
  Scaleform::GFx::AS2::ObjectInterface::UserDataHolder **p_pUserDataHolder; // ebx
  Scaleform::GFx::ASStringNode *v7; // esi
  Scaleform::GFx::ASStringNode *v10; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+Ch] [ebp-10h] BYREF

  v2 = &this->Scaleform::GFx::AS2::ObjectInterface;
  if ( !this->FindMember )
    return 1;
  v3 = (Scaleform::GFx::TextField *)*((_DWORD *)&this[-1].VariableVal.NV + 3);
  v3->Flags |= 0x8000u;
  v4 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::ASString *))this[-1].VariableName.pNode[5].pManager)(&this[-1].VariableName);
  v5 = v4;
  if ( !v4 )
    return 0;
  v.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v4, __SPAIR64__(&v, (unsigned int)v2), 0, 0, 0) )
  {
    Scaleform::GFx::TextField::SetTextValue(v3, (const __m128i *)uri, 0, 0);
LABEL_11:
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    return 0;
  }
  p_pUserDataHolder = &this->pUserDataHolder;
  if ( Scaleform::GFx::AS2::Value::IsEqual(&v, v5, (Scaleform::GFx::AS2::Value *)p_pUserDataHolder) )
    goto LABEL_11;
  Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)p_pUserDataHolder, &v);
  Scaleform::GFx::AS2::Value::ToStringImpl(&v, (Scaleform::GFx::ASString *)&v10, v5, -1, 0);
  v7 = v10;
  Scaleform::GFx::TextField::SetTextValue(v3, (const __m128i *)v10->pData, 0, 0);
  if ( v7->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}
