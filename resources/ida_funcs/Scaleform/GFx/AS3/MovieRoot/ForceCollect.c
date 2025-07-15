void __thiscall Scaleform::GFx::AS3::MovieRoot::ForceCollect(
        Scaleform::GFx::AS3::MovieRoot *this,
        unsigned int gcFlags)
{
  unsigned int v2; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax

  if ( gcFlags )
  {
    if ( gcFlags == 1 )
    {
      v2 = 16;
    }
    else if ( gcFlags == 2 )
    {
      v2 = 32;
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v2 = 8;
  }
  pMovieImpl = this->pMovieImpl;
  if ( !pMovieImpl->pRenderRoot.pObject || (pMovieImpl->Flags2 & 4) != 0 )
    v2 |= 1u;
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
    this->MemContext.pObject->ASGC.pObject,
    (Scaleform::GFx::Resource *)pMovieImpl->AdvanceStats.pObject,
    v2);
}
