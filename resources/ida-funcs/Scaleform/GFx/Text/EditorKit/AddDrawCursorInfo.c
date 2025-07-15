void __thiscall Scaleform::GFx::Text::EditorKit::AddDrawCursorInfo(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::Render::TextLayout::Builder *bld)
{
  unsigned __int16 Flags; // ax
  Scaleform::Render::Text::DocView *pObject; // eax
  unsigned __int16 FormatCounter; // cx
  unsigned int x_low; // ebx
  bool (__thiscall *HasCompositionString)(struct Scaleform::GFx::Text::EditorKit *); // eax
  unsigned int CursorPos; // edi
  Scaleform::Render::Text::DocView::DocumentText *v9; // eax
  Scaleform::Render::Text::TextFormat *v10; // eax
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // ecx
  Scaleform::Render::Text::DocView *v12; // eax
  Scaleform::Render::Rect<float> *p_VisibleRect; // edi
  unsigned int Raw; // [esp-4h] [ebp-84h]
  Scaleform::Render::Point<float> pt; // [esp+10h] [ebp-70h] BYREF
  Scaleform::Render::Point<float> v16; // [esp+18h] [ebp-68h] BYREF
  Scaleform::Render::Rect<float> v; // [esp+20h] [ebp-60h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+30h] [ebp-50h] BYREF
  Scaleform::Render::Text::HighlighterPosIterator result; // [esp+4Ch] [ebp-34h] BYREF

  if ( !this->IsReadOnly(this) )
  {
    Flags = this->Flags;
    if ( (Flags & 0x400) != 0 )
    {
      if ( (Flags & 0x100) != 0 )
      {
        Scaleform::GFx::Text::EditorKit::UpdateWideCursor(this);
      }
      else if ( (Flags & 8) != 0 )
      {
        pObject = this->pDocView.pObject;
        FormatCounter = this->CursorRect.FormatCounter;
        x_low = -1;
        pt.x = NAN;
        if ( FormatCounter != pObject->FormatCounter )
        {
          HasCompositionString = this->HasCompositionString;
          v.x1 = 0.0;
          CursorPos = this->CursorPos;
          v.y1 = 0.0;
          v.x2 = 0.0;
          v.y2 = 0.0;
          if ( HasCompositionString(this) )
            CursorPos += this->pComposStr.pObject->CursorPos;
          if ( Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(
                 this,
                 CursorPos,
                 &v,
                 (unsigned int *)&pt,
                 (unsigned int *)&v16,
                 0,
                 0) )
          {
            v9 = this->pDocView.pObject->pDocument.pObject;
            v.x2 = v.x1;
            v10 = v9->pDefaultTextFormat.pObject;
            if ( v10 && (v10->PresentMask & 1) != 0 )
              this->CursorColor.Raw = v10->ColorV;
            pHighlight = this->pDocView.pObject->pHighlight;
            if ( pHighlight )
            {
              Scaleform::Render::Text::Highlighter::GetPosIterator(
                &pHighlight->HighlightManager,
                &result,
                this->CursorPos,
                0xFFFFFFFF);
              if ( (result.CurDesc.Info.Flags & 0x10) != 0 )
                this->CursorColor = *Scaleform::Render::Text::HighlightInfo::GetTextColor(
                                       &result.CurDesc.Info,
                                       (Scaleform::Render::Color *)&v16);
            }
          }
          else
          {
            v.x1 = 0.0;
            v.y1 = 0.0;
            v16.x = 0.0 + 0.0;
            v.x2 = v16.x;
            v.y2 = v16.x;
          }
          Scaleform::Render::Text::CachedValue<Scaleform::Render::Rect<float>>::SetValue(
            &this->CursorRect,
            &v,
            this->pDocView.pObject->FormatCounter);
          x_low = LODWORD(pt.x);
        }
        Scaleform::Render::Rect<float>::Rect<float>(&r, &this->CursorRect.Value);
        v12 = this->pDocView.pObject;
        p_VisibleRect = &v12->mLineBuffer.Geom.VisibleRect;
        pt.x = (float)v12->mLineBuffer.Geom.HScrollOffset;
        LODWORD(v16.x) = Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&v12->mLineBuffer);
        pt.y = (float)LODWORD(v16.x);
        Scaleform::Render::Rect<float>::operator-=(&r, &pt);
        v16.x = p_VisibleRect->x1;
        v16.y = p_VisibleRect->y1;
        Scaleform::Render::Rect<float>::operator+=(&r, &v16);
        if ( p_VisibleRect->y2 < (double)r.y2 )
        {
          if ( x_low == -1 )
            x_low = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, this->CursorPos);
          if ( Scaleform::Render::Text::LineBuffer::IsLineVisible(&this->pDocView.pObject->mLineBuffer, x_low) )
            r.y2 = p_VisibleRect->y2;
        }
        if ( Scaleform::Render::Rect<float>::Contains(p_VisibleRect, &r) )
        {
          Raw = this->CursorColor.Raw;
          r.x2 = r.x1 + 20.0;
          Scaleform::Render::TextLayout::Builder::AddCursor(bld, &r, Raw);
        }
      }
    }
  }
}
