void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef *src)
{
  Scaleform::GFx::AS3::Value *pFirst; // ecx
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  pFirst = (Scaleform::GFx::AS3::Value *)src->pFirst;
  this->First = *src->pFirst;
  if ( (pFirst->Flags & 0x1F) > 9 )
  {
    if ( (pFirst->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(pFirst);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pFirst);
  }
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
