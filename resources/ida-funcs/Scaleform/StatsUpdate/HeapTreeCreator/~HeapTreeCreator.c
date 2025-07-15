void __thiscall Scaleform::StatsUpdate::HeapTreeCreator::~HeapTreeCreator(
        Scaleform::StatsUpdate::HeapTreeCreator *this)
{
  Scaleform::MemItem *pObject; // eax
  unsigned int v3; // edi
  unsigned int i; // edi
  unsigned int j; // edi
  unsigned int k; // edi
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::RefCountVImpl *v13; // ecx

  pObject = this->MovieViewRoot.pObject;
  v3 = 0;
  this->__vftable = (Scaleform::StatsUpdate::HeapTreeCreator_vtbl *)&Scaleform::StatsUpdate::HeapTreeCreator::`vftable';
  if ( pObject->Children.Data.Size )
  {
    do
      Scaleform::MemItem::SetValue(
        this->MovieViewRoot.pObject,
        this->MovieViewRoot.pObject->Value + this->MovieViewRoot.pObject->Children.Data.Data[v3++].pObject->Value);
    while ( v3 < this->MovieViewRoot.pObject->Children.Data.Size );
  }
  for ( i = 0; i < this->MovieDataRoot.pObject->Children.Data.Size; ++i )
    Scaleform::MemItem::SetValue(
      this->MovieDataRoot.pObject,
      this->MovieDataRoot.pObject->Value + this->MovieDataRoot.pObject->Children.Data.Data[i].pObject->Value);
  for ( j = 0; j < this->VideoRoot.pObject->Children.Data.Size; ++j )
    Scaleform::MemItem::SetValue(
      this->VideoRoot.pObject,
      this->VideoRoot.pObject->Value + this->VideoRoot.pObject->Children.Data.Data[j].pObject->Value);
  for ( k = 0; k < this->OtherRoot.pObject->Children.Data.Size; ++k )
    Scaleform::MemItem::SetValue(
      this->OtherRoot.pObject,
      this->OtherRoot.pObject->Value + this->OtherRoot.pObject->Children.Data.Data[k].pObject->Value);
  v7 = (Scaleform::RefCountVImpl *)this->UnusedSpaceRoot.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = (Scaleform::RefCountVImpl *)this->OtherRoot.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v9 = (Scaleform::RefCountVImpl *)this->VideoRoot.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::RefCountVImpl *)this->MovieDataRoot.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v11 = (Scaleform::RefCountVImpl *)this->MovieViewRoot.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v12 = (Scaleform::RefCountVImpl *)this->GlobalHeap.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v13 = (Scaleform::RefCountVImpl *)this->UsedSpaceRoot.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  this->__vftable = (Scaleform::StatsUpdate::HeapTreeCreator_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
}
