void __thiscall Scaleform::Render::PrimitivePrepareBuffer::patchEmitDrawStartIfEq(
        Scaleform::Render::PrimitivePrepareBuffer *this,
        Scaleform::Render::PrimitiveBatch *check,
        Scaleform::Render::PrimitiveBatch *drawStart)
{
  Scaleform::Render::PrimitiveEmitBuffer *pEmitBuffer; // eax

  pEmitBuffer = this->pEmitBuffer;
  if ( this->pItem == pEmitBuffer->pItem && pEmitBuffer->pDraw == check )
    pEmitBuffer->pDraw = drawStart;
}
