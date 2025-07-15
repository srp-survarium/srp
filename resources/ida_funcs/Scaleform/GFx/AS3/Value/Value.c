void __thiscall Scaleform::GFx::AS3::Value::Value(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v)
{
  this->Flags = 0;
  this->Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::AssignUnsafe(this, v->pObject);
}


void __thiscall Scaleform::GFx::AS3::Value::Value(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Value *other,
        Scaleform::GFx::AS3::StrongRefType __formal)
{
  unsigned int Flags; // eax

  this->Bonus.pWeakProxy = 0;
  Flags = other->Flags;
  _mm_prefetch((const char *)other, 2);
  this->Flags = Flags;
  this->Bonus.pWeakProxy = other->Bonus.pWeakProxy;
  this->value = *(Scaleform::GFx::AS3::Value::VU *)&other->value.VNumber;
  if ( (other->Flags & 0x1F) > 9 )
  {
    if ( (other->Flags & 0x200) != 0 )
      ++other->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(other);
  }
  if ( (this->Flags & 0x200) != 0 )
    Scaleform::GFx::AS3::Value::MakeStrongRef(this);
}


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


void __thiscall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
{
  this->Flags = 13;
  this->Bonus.pWeakProxy = 0;
  this->value.VS._1.VInt = (int)v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::Value(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  this->Flags = 11;
  this->Bonus.pWeakProxy = 0;
  this->value.VS._1.VInt = (int)v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  this->Flags = 12;
  this->Bonus.pWeakProxy = 0;
  this->value.VS._1.VInt = (int)v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}
