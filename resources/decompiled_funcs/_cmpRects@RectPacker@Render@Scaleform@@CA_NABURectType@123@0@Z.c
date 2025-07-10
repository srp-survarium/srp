BOOL __cdecl Scaleform::Render::RectPacker::cmpRects(
        const Scaleform::Render::RectPacker::RectType *a,
        const Scaleform::Render::RectPacker::RectType *b)
{
  return *(_QWORD *)&b->x < *(_QWORD *)&a->x;
}
