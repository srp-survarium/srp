void __thiscall Scaleform::GFx::AS2::AvmTextField::OnEventLoad(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::TextField *pDispObj; // edi
  Scaleform::GFx::AS2::Environment *v3; // eax
  bool Variable; // bl
  __int64 v5; // [esp-18h] [ebp-34h]
  Scaleform::GFx::AS2::Value v6; // [esp+Ch] [ebp-10h] BYREF

  pDispObj = (Scaleform::GFx::TextField *)this->pDispObj;
  if ( Scaleform::String::GetLength(&pDispObj->pDef.pObject->DefaultText) )
  {
    if ( !this->VariableName.pNode->Size )
      goto LABEL_7;
    pDispObj->Flags |= 0x8000u;
    v3 = this->GetASEnvironment(this);
    if ( !v3 )
      goto LABEL_7;
    HIDWORD(v5) = &v6;
    LODWORD(v5) = &this->VariableName;
    v6.T.Type = 0;
    Variable = Scaleform::GFx::AS2::Environment::GetVariable(v3, v5, 0, 0, 0);
    if ( v6.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v6);
    if ( !Variable )
    {
LABEL_7:
      Scaleform::GFx::TextField::SetTextValue(
        pDispObj,
        (const __m128i *)(((int)this->pDispObj[1].SetX & 0xFFFFFFFC) + 8),
        (pDispObj->Flags & 2) != 0,
        1);
      this->UpdateVariable(&this->Scaleform::GFx::AvmTextFieldBase);
    }
  }
  else
  {
    Scaleform::GFx::TextField::SetTextValue(pDispObj, (const __m128i *)uri, (pDispObj->Flags & 2) != 0, 0);
  }
  this->UpdateTextFromVariable(&this->Scaleform::GFx::AvmTextFieldBase);
}


void __thiscall Scaleform::GFx::AS2::AvmTextField::OnEventLoad(char *this)
{
  Scaleform::GFx::AS2::AvmTextField::OnEventLoad((Scaleform::GFx::AS2::AvmTextField *)(this - 24));
}
