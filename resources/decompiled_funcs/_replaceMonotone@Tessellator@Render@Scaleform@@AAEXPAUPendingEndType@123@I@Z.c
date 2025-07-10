void __thiscall Scaleform::Render::Tessellator::replaceMonotone(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::PendingEndType *pe,
        unsigned int style)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // eax

  if ( style )
  {
    monotone = pe->monotone;
    if ( monotone )
    {
      if ( monotone->style != style )
      {
        if ( monotone->start )
        {
          *Scaleform::Render::Tessellator::startMonotone(this, style) = *pe->monotone;
          monotone = pe->monotone;
          monotone->start = 0;
          monotone->d.m.lastIdx = -1;
          monotone->d.m.prevIdx1 = -1;
          monotone->d.m.prevIdx2 = -1;
          monotone->lowerBase = 0;
        }
      }
      monotone->style = style;
    }
    else
    {
      pe->monotone = Scaleform::Render::Tessellator::startMonotone(this, style);
    }
  }
}
