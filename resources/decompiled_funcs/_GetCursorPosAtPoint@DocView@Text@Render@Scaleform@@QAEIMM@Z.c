int __thiscall Scaleform::Render::Text::DocView::GetCursorPosAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  Scaleform::Render::Text::LineBuffer *pLineBuffer; // eax
  signed int CurrentPos; // ecx
  float yoff; // [esp+Ch] [ebp-2Ch]
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+10h] [ebp-28h] BYREF
  float v9; // [esp+30h] [ebp-8h]
  int v10; // [esp+34h] [ebp-4h]
  float xa; // [esp+3Ch] [ebp+4h]
  float ya; // [esp+40h] [ebp+8h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  xa = x - (this->mLineBuffer.Geom.VisibleRect.x1 - this->ViewRect.x1);
  ya = y - (this->mLineBuffer.Geom.VisibleRect.y1 - this->ViewRect.y1);
  yoff = (double)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&this->mLineBuffer) + ya;
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(&this->mLineBuffer, &it, yoff);
  pLineBuffer = it.pLineBuffer;
  if ( !it.pLineBuffer
    || (CurrentPos = it.CurrentPos, it.CurrentPos >= it.pLineBuffer->Lines.Data.Size)
    || (it.CurrentPos & 0x80000000) != 0 )
  {
    it.pHighlight = 0;
    v9 = 0.0;
    it.YOffset = 0.0;
    if ( ya > 0.0 )
      CurrentPos = this->mLineBuffer.Lines.Data.Size - 1;
    else
      CurrentPos = 0;
    LOBYTE(v10) = (this->mLineBuffer.Geom.Flags & 4) != 0;
    pLineBuffer = &this->mLineBuffer;
    *(_DWORD *)&it.StaticText = v10;
    it.CurrentPos = CurrentPos;
    it.pLineBuffer = &this->mLineBuffer;
  }
  if ( pLineBuffer && CurrentPos < pLineBuffer->Lines.Data.Size && CurrentPos >= 0 )
    return Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(this, CurrentPos, xa);
  else
    return -(this->mLineBuffer.Lines.Data.Size != 0);
}
