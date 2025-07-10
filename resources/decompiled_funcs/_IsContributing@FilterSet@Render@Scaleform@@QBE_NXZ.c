char __thiscall Scaleform::Render::FilterSet::IsContributing(Scaleform::Render::FilterSet *this)
{
  int v3; // esi
  Scaleform::Render::Filter *pObject; // ecx

  if ( this->CacheAsBitmap )
    return 1;
  v3 = 0;
  if ( !this->Filters.Data.Size )
    return 0;
  while ( 1 )
  {
    pObject = this->Filters.Data.Data[v3].pObject;
    if ( pObject )
    {
      if ( pObject->IsContributing(pObject) )
        break;
    }
    if ( ++v3 >= this->Filters.Data.Size )
      return 0;
  }
  return 1;
}
