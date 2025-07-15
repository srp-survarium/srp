void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::Value *other)
{
  unsigned int Flags; // edx

  if ( other != this )
  {
    Flags = other->Flags;
    _mm_prefetch((const char *)other, 2);
    this->Flags = Flags;
    this->Bonus.pWeakProxy = other->Bonus.pWeakProxy;
    this->value.VNumber = other->value.VNumber;
    if ( (this->Flags & 0x1F) > 9 )
    {
      if ( (this->Flags & 0x200) != 0 )
        ++this->Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(this);
    }
  }
}


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


void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Class *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xD;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::Function *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xE;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xB;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xC;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}
