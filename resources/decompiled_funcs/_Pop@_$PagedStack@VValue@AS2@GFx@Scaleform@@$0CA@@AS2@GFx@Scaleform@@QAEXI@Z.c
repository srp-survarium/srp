void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this,
        unsigned int n)
{
  unsigned int i; // edi

  for ( i = n; i; --i )
  {
    if ( this->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
    if ( --this->pCurrent < this->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(this);
  }
}
