void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  int v3; // edi

  pCurrent = this->pCurrent;
  if ( &pCurrent[-3] >= this->pPageStart )
  {
    if ( pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
    --this->pCurrent;
    if ( this->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
    --this->pCurrent;
    if ( this->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
    --this->pCurrent;
  }
  else
  {
    v3 = 3;
    do
    {
      if ( this->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
      if ( --this->pCurrent < this->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(this);
      --v3;
    }
    while ( v3 );
  }
}
