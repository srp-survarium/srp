void __userpurge Scaleform::GFx::AS2::BooleanObject::SetValue(
        Scaleform::GFx::AS2::BooleanObject *this@<ecx>,
        int a2@<edi>,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  this->bValue = Scaleform::GFx::AS2::Value::ToBool(v, a2, penv);
}
