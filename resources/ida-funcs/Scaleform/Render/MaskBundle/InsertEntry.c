void __thiscall Scaleform::Render::MaskBundle::InsertEntry(
        Scaleform::Render::MaskBundle *this,
        unsigned int index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v3; // esi
  Scaleform::Render::CacheEffect *i; // esi
  Scaleform::Render::BundleEntry *pNext; // esi

  v3 = entry;
  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  for ( i = v3->pSourceNode->Effects.pEffect; i; i = i->pNext )
  {
    if ( i->GetType(i) == State_UserEventHandler )
      break;
  }
  pNext = (Scaleform::Render::BundleEntry *)i[9].pNext;
  entry = pNext;
  if ( pNext != (Scaleform::Render::BundleEntry *)&Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pNext->pNextPattern->pChain;
  Scaleform::Render::MaskPrimitive::Insert(
    &this->Prim,
    index,
    (const Scaleform::Render::MatrixPoolImpl::HMatrix *)&entry);
  if ( entry != (Scaleform::Render::BundleEntry *)&Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release((Scaleform::Render::MatrixPoolImpl::DataHeader *)entry->pNextPattern);
}
