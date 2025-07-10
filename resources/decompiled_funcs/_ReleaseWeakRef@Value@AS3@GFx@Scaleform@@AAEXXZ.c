void __thiscall Scaleform::GFx::AS3::Value::ReleaseWeakRef(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  pWeakProxy = this->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  this->Flags &= 0xFFFFFDE0;
  this->Bonus.pWeakProxy = 0;
  this->value.VS._1.VInt = 0;
  this->value.VS._2.VObj = 0;
}
