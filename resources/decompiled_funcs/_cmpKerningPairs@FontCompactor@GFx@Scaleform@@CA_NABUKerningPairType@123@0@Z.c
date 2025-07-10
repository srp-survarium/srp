BOOL __cdecl Scaleform::GFx::FontCompactor::cmpKerningPairs(
        const Scaleform::GFx::FontCompactor::KerningPairType *a,
        const Scaleform::GFx::FontCompactor::KerningPairType *b)
{
  bool v2; // cf

  v2 = a->Char1 < b->Char1;
  if ( a->Char1 == b->Char1 )
    return a->Char2 < b->Char2;
  return v2;
}
