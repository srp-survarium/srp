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
