char __thiscall Scaleform::Render::FilterSet::CanCacheAcrossTransform(
        Scaleform::Render::FilterSet *this,
        BOOL deltaTrans,
        BOOL deltaRot,
        BOOL deltaScale)
{
  int v5; // esi
  Scaleform::Render::Filter *pObject; // ecx

  v5 = 0;
  if ( !this->Filters.Data.Size )
    return 1;
  while ( 1 )
  {
    pObject = this->Filters.Data.Data[v5].pObject;
    if ( pObject )
    {
      if ( !pObject->CanCacheAcrossTransform(pObject, deltaTrans, deltaRot, deltaScale) )
        break;
    }
    if ( ++v5 >= this->Filters.Data.Size )
      return 1;
  }
  return 0;
}
