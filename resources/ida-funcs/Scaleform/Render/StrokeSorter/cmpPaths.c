BOOL __cdecl Scaleform::Render::StrokeSorter::cmpPaths(
        const Scaleform::Render::StrokeSorter::SortedPathType *a1,
        const Scaleform::Render::StrokeSorter::SortedPathType *a2)
{
  double y; // st7
  double x; // st6

  if ( a2->x == a1->x )
  {
    y = a1->y;
    x = a2->y;
  }
  else
  {
    y = a1->x;
    x = a2->x;
  }
  return x > y;
}
