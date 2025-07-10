void __thiscall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASStringNode *v)
{
  unsigned int v2; // edx
  Scaleform::GFx::AS3::Value::V2U v3; // [esp+4h] [ebp-4h]

  this->Flags = 10;
  this->Bonus.pWeakProxy = 0;
  this->value.VS._1.VInt = (int)v;
  if ( v )
  {
    if ( v == &v->pManager->NullStringNode )
    {
      v2 = this->Flags & 0xFFFFFFEC;
      this->value.VS._1.VInt = 0;
      this->value.VS._2 = v3;
      this->Flags = v2 | 0xC;
    }
    else
    {
      ++v->RefCount;
    }
  }
  else
  {
    this->Flags = this->Flags & 0xFFFFFFE0 | 0xC;
  }
}
