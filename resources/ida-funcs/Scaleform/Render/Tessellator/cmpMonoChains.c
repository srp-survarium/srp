BOOL __cdecl Scaleform::Render::Tessellator::cmpMonoChains(
        const Scaleform::Render::Tessellator::MonoChainType *a1,
        const Scaleform::Render::Tessellator::MonoChainType *a2)
{
  double xt; // st7
  double xb; // st6

  if ( a2->ySort == a1->ySort )
  {
    if ( a2->xb == a1->xb )
    {
      xt = a1->xt;
      xb = a2->xt;
    }
    else
    {
      xt = a1->xb;
      xb = a2->xb;
    }
  }
  else
  {
    xt = a1->ySort;
    xb = a2->ySort;
  }
  return xb > xt;
}
