void __thiscall Scaleform::GFx::AS2::Value::Asr(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  char v4; // bl
  int v5; // edi

  v4 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v5 = Scaleform::GFx::AS2::Value::ToInt32(this, penv) >> v4;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = v5;
  this->T.Type = 4;
}
