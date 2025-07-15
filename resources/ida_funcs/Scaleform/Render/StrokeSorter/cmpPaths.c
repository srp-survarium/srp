BOOL __cdecl Scaleform::Render::StrokeSorter::cmpPaths(
        const Scaleform::Render::StrokeSorter::SortedPathType *a,
        const Scaleform::Render::StrokeSorter::SortedPathType *b)
{
  double y; // st7
  double x; // st6

  if ( b->x == a->x )
  {
    y = a->y;
    x = b->y;
  }
  else
  {
    y = a->x;
    x = b->x;
  }
  return x > y;
}
