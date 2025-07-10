void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
  if ( !v )
    goto LABEL_4;
  if ( v == &v->pManager->NullStringNode )
  {
    this->value.VS._1.VInt = 0;
    this->value.VS._2 = v2;
LABEL_4:
    this->Flags = this->Flags & 0xFFFFFFE0 | 0xC;
    return;
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 0xA;
  ++*(_DWORD *)(this->value.VS._1.VInt + 12);
}
