Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::Object>(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v)
{
  Scaleform::GFx::AS3::Value::Assign(this, v->pObject);
  return this;
}


Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::ThunkFunction>(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> v)
{
  unsigned int v3; // edx
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+Ch] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  v3 = this->Flags & 0xFFFFFFEF;
  LODWORD(this->value.VNumber) = v;
  this->value.VS._2 = v5;
  this->Flags = v3 | 0xF;
  return this;
}


Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::XML>(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v)
{
  Scaleform::GFx::AS3::Value::Pick(this, v.pV);
  return this;
}


Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::Value *other)
{
  Scaleform::GFx::AS3::Value::Assign(this, other);
  return this;
}


Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::Value::Assign(this, v);
  return this;
}


Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::Value::Assign(this, v);
  return this;
}


Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::Function *v)
{
  Scaleform::GFx::AS3::Value::Assign(this, v);
  return this;
}


Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value::Assign(this, v);
  return this;
}
