void __thiscall Scaleform::Render::HAL::DrawBundleEntries(
        Scaleform::Render::HAL *this,
        Scaleform::Render::BundleIterator ibundles,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::Render::DisplayPass CurrentPass; // eax
  Scaleform::Render::BundleEntry *i; // eax

  if ( this->CurrentPass == Display_All && this->IsPrepassRequired(this) )
  {
    this->SetDisplayPass(this, Display_Prepass);
    ((void (__thiscall *)(Scaleform::Render::HAL *, Scaleform::Render::BundleEntry *, Scaleform::Render::BundleEntry *, Scaleform::Render::Renderer2DImpl *))this->DrawBundleEntries)(
      this,
      ibundles.pFirst,
      ibundles.pLast,
      r2d);
    this->SetDisplayPass(this, Display_Final);
    ((void (__thiscall *)(Scaleform::Render::HAL *, Scaleform::Render::BundleEntry *, Scaleform::Render::BundleEntry *, Scaleform::Render::Renderer2DImpl *))this->DrawBundleEntries)(
      this,
      ibundles.pFirst,
      ibundles.pLast,
      r2d);
    this->SetDisplayPass(this, Display_All);
  }
  else
  {
    CurrentPass = this->CurrentPass;
    if ( CurrentPass == Display_Prepass )
    {
      this->GetRQProcessor(this)->QueueEmitFilter = QPF_Filters;
      this->GetRQProcessor(this)->QueuePrepareFilter = QPF_Filters;
    }
    else if ( (unsigned int)(CurrentPass - 2) <= 1 )
    {
      this->GetRQProcessor(this)->QueueEmitFilter = QPF_All;
      this->GetRQProcessor(this)->QueuePrepareFilter = QPF_All;
    }
    for ( i = ibundles.pFirst; i; ibundles.pFirst = i )
    {
      i->Key.pImpl->DrawBundleEntry(i->Key.pImpl, i->Key.Data, i, r2d);
      if ( ibundles.pFirst == ibundles.pLast )
        break;
      i = ibundles.pFirst->pNextPattern;
    }
  }
}
