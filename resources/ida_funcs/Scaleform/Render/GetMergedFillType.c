Scaleform::Render::PrimitiveFillType __cdecl Scaleform::Render::GetMergedFillType(
        Scaleform::Render::FillType ft0,
        Scaleform::Render::FillType ft1,
        unsigned int mergeFlags)
{
  unsigned __int8 F0; // cl
  Scaleform::Render::FillTypeMergeInfo *v4; // eax

  F0 = FillTypeMergeTable[0].F0;
  v4 = FillTypeMergeTable;
  do
  {
    if ( F0 == ft0 && mergeFlags == v4->MergeFlags && (v4->F1 == ft1 || (mergeFlags & 2) == 0) )
      break;
    F0 = v4[1].F0;
    ++v4;
  }
  while ( F0 );
  return v4->Result;
}
