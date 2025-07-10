void __thiscall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::Clear(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this)
{
  $445CB3699B64BB30984BADDF1BBAFC2D *v2; // ebp
  Scaleform::RefCountVImpl **pData; // esi
  unsigned int Size; // ebx

  v2 = &this->4;
  if ( this->Size <= 2 )
    pData = (Scaleform::RefCountVImpl **)&this->4;
  else
    pData = (Scaleform::RefCountVImpl **)v2->AD.pData;
  if ( this->Size )
  {
    Size = this->Size;
    do
    {
      if ( *pData )
        Scaleform::RefCountImpl::Release(*pData);
      ++pData;
      --Size;
    }
    while ( Size );
  }
  if ( this->Size > 2 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2->AD.pData);
  this->Size = 0;
}
