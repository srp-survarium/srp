void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::ASString *v)
{
  unsigned int v2; // edx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value::V2U v4; // [esp+8h] [ebp-4h]

  if ( v->pNode == &v->pNode->pManager->NullStringNode )
  {
    v2 = this->Flags & 0xFFFFFFEC;
    this->value.VS._1.VInt = 0;
    this->value.VS._2 = v4;
    this->Flags = v2 | 0xC;
  }
  else
  {
    this->Flags = this->Flags & 0xFFFFFFE0 | 0xA;
    pNode = v->pNode;
    LODWORD(this->value.VNumber) = (Scaleform::GFx::ASString)v->pNode;
    this->value.VS._2 = v4;
    ++pNode->RefCount;
  }
}
