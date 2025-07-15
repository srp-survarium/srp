BOOL __cdecl Scaleform::Render::Tessellator::cmpMonoChains(
        const Scaleform::Render::Tessellator::MonoChainType *a,
        const Scaleform::Render::Tessellator::MonoChainType *b)
{
  double xt; // st7
  double xb; // st6

  if ( b->ySort == a->ySort )
  {
    if ( b->xb == a->xb )
    {
      xt = a->xt;
      xb = b->xt;
    }
    else
    {
      xt = a->xb;
      xb = b->xb;
    }
  }
  else
  {
    xt = a->ySort;
    xb = b->ySort;
  }
  return xb > xt;
}
