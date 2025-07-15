void __thiscall Scaleform::GFx::AS3::Value::Assign(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::Value *other)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  unsigned int Flags; // ecx

  if ( other != this )
  {
    if ( (this->Flags & 0x1F) > 9 )
    {
      if ( (this->Flags & 0x200) != 0 )
      {
        pWeakProxy = this->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        this->Flags &= 0xFFFFFDE0;
        this->Bonus.pWeakProxy = 0;
        this->value.VS._1.VInt = 0;
        this->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(this);
      }
    }
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


void __thiscall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, const Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value::V2U v6; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0;
      this->value.VS._1.VInt = 0;
      this->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  if ( v->pNode == &v->pNode->pManager->NullStringNode )
  {
    Flags = this->Flags;
    this->value.VS._1.VInt = 0;
    this->value.VS._2 = v6;
    this->Flags = Flags & 0xFFFFFFE0 | 0xC;
  }
  else
  {
    this->Flags = this->Flags & 0xFFFFFFE0 | 0xA;
    LODWORD(this->value.VNumber) = (Scaleform::GFx::ASString)v->pNode;
    this->value.VS._2 = v6;
    ++*(_DWORD *)(this->value.VS._1.VInt + 12);
  }
}


void __thiscall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value::V2U v6; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0;
      this->value.VS._1.VInt = 0;
      this->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v6;
  if ( v )
  {
    if ( v == &v->pManager->NullStringNode )
    {
      Flags = this->Flags;
      this->value.VS._1.VInt = 0;
      this->value.VS._2 = v6;
      this->Flags = Flags & 0xFFFFFFE0 | 0xC;
    }
    else
    {
      this->Flags = this->Flags & 0xFFFFFFE0 | 0xA;
      ++v->RefCount;
    }
  }
  else
  {
    this->Flags = this->Flags & 0xFFFFFFE0 | 0xC;
  }
}


void __thiscall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0;
      this->value.VS._1.VInt = 0;
      this->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 0xD;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v5;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::Assign(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::Function *v)
{
  Scaleform::GFx::AS3::Value::V2U v3; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 0xE;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v3;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::Assign(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  Scaleform::GFx::AS3::Value::V2U v3; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 0xB;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v3;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}


void __thiscall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0;
      this->value.VS._1.VInt = 0;
      this->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 0xC;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v5;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}
