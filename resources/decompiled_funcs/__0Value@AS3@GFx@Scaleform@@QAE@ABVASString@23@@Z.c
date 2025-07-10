void __thiscall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, const Scaleform::GFx::ASString *v)
{
  unsigned int v2; // edx
  Scaleform::GFx::AS3::Value::V2U v3; // [esp+4h] [ebp-4h]

  this->Flags = 10;
  this->Bonus.pWeakProxy = 0;
  LODWORD(this->value.VNumber) = (Scaleform::GFx::ASString)v->pNode;
  if ( v->pNode == &v->pNode->pManager->NullStringNode )
  {
    v2 = this->Flags & 0xFFFFFFEC;
    this->value.VS._1.VInt = 0;
    this->value.VS._2 = v3;
    this->Flags = v2 | 0xC;
  }
  else
  {
    ++*(_DWORD *)(this->value.VS._1.VInt + 12);
  }
}
