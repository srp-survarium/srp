BOOL __cdecl Scaleform::Render::Scale9GridTess::cmpCodes(
        const Scaleform::Render::Scale9GridTess::TmpVertexType *a,
        const Scaleform::Render::Scale9GridTess::TmpVertexType *b)
{
  return a->AreaCode < b->AreaCode;
}
