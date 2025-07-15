void __thiscall Scaleform::GFx::AS3::VSBase::PopBack(Scaleform::GFx::AS3::VSBase *this, unsigned int n)
{
  unsigned int i; // edi
  Scaleform::GFx::AS3::Value *pCurrent; // ecx

  for ( i = n; i; --this->pCurrent )
  {
    pCurrent = this->pCurrent;
    --i;
    if ( (this->pCurrent->Flags & 0x1F) > 9 )
    {
      if ( (this->pCurrent->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(pCurrent);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(pCurrent);
    }
  }
}
