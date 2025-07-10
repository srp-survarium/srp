void __thiscall Scaleform::GFx::AS2::Value::SetString(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // eax

  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 5;
  pNode = str->pNode;
  this->NV.Int32Value = (int)str->pNode;
  ++pNode->RefCount;
}
