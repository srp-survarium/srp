void __thiscall Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(
        Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> *this)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  if ( (this->_2.Flags & 0x1F) > 9 )
  {
    if ( (this->_2.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->_2.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->_2.Flags &= 0xFFFFFDE0;
      this->_2.Bonus.pWeakProxy = 0;
      this->_2.value.VS._1.VInt = 0;
      this->_2.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->_2);
    }
  }
}
