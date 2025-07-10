void __thiscall Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>(
        Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> > *this,
        const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *src)
{
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  this->First = *src->pFirst;
  pSecond = (Scaleform::GFx::AS3::Value *)src->pSecond;
  this->Second = *pSecond;
  if ( (pSecond->Flags & 0x1F) > 9 )
  {
    if ( (pSecond->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(pSecond);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pSecond);
  }
}
