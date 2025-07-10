void __thiscall Scaleform::GFx::AS2::AvmTextField::OnEventLoad(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::TextField *pDispObj; // edi
  Scaleform::GFx::AS2::Environment *v3; // eax
  char Variable; // bl
  Scaleform::GFx::AS2::Value val; // [esp+Ch] [ebp-10h] BYREF

  pDispObj = (Scaleform::GFx::TextField *)this->pDispObj;
  if ( Scaleform::String::GetLength(&pDispObj->pDef.pObject->DefaultText) )
  {
    if ( !this->VariableName.pNode->Size )
      goto LABEL_7;
    pDispObj->Flags |= 0x8000u;
    v3 = this->GetASEnvironment(this);
    if ( !v3 )
      goto LABEL_7;
    val.T.Type = 0;
    Variable = Scaleform::GFx::AS2::Environment::GetVariable(v3, &this->VariableName, &val, 0, 0, 0, 0);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    if ( !Variable )
    {
LABEL_7:
      Scaleform::GFx::TextField::SetTextValue(
        pDispObj,
        (char *)(((int)this->pDispObj[1].SetX & 0xFFFFFFFC) + 8),
        (pDispObj->Flags & 2) != 0,
        1);
      this->UpdateVariable(&this->Scaleform::GFx::AvmTextFieldBase);
    }
  }
  else
  {
    Scaleform::GFx::TextField::SetTextValue(pDispObj, (char *)&buf, (pDispObj->Flags & 2) != 0, 0);
  }
  this->UpdateTextFromVariable(&this->Scaleform::GFx::AvmTextFieldBase);
}
