void __thiscall Scaleform::Render::FilterBundle::InsertEntry(
        Scaleform::Render::FilterBundle *this,
        unsigned int index,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v3; // esi
  Scaleform::Render::CacheEffect *i; // esi
  Scaleform::Render::BundleEntry *Length; // esi

  v3 = entry;
  Scaleform::Render::Bundle::InsertEntry(this, index, entry);
  for ( i = v3->pSourceNode->Effects.pEffect; i; i = i->pNext )
  {
    if ( i->GetType(i) == State_ActionControl )
      break;
  }
  Length = (Scaleform::Render::BundleEntry *)i[6].Length;
  entry = Length;
  if ( Length != (Scaleform::Render::BundleEntry *)&Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++Length->pNextPattern->pChain;
  Scaleform::Render::FilterPrimitive::Insert(
    &this->Prim,
    index,
    (const Scaleform::Render::MatrixPoolImpl::HMatrix *)&entry);
  if ( entry != (Scaleform::Render::BundleEntry *)&Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release((Scaleform::Render::MatrixPoolImpl::DataHeader *)entry->pNextPattern);
}
