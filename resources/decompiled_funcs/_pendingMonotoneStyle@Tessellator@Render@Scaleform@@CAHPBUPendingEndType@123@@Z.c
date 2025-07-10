unsigned int __cdecl Scaleform::Render::Tessellator::pendingMonotoneStyle(
        const Scaleform::Render::Tessellator::PendingEndType *pe)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // eax

  monotone = pe->monotone;
  if ( monotone )
    return monotone->style;
  else
    return 0;
}
