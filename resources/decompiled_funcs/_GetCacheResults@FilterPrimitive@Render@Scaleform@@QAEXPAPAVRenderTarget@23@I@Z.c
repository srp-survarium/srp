void __thiscall Scaleform::Render::FilterPrimitive::GetCacheResults(
        Scaleform::Render::FilterPrimitive *this,
        Scaleform::Render::RenderTarget **results,
        unsigned int count)
{
  unsigned int v3; // eax
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *CacheResults; // ecx

  v3 = 0;
  if ( count )
  {
    CacheResults = this->CacheResults;
    do
    {
      results[v3++] = CacheResults->pObject;
      ++CacheResults;
    }
    while ( v3 < count );
  }
}
