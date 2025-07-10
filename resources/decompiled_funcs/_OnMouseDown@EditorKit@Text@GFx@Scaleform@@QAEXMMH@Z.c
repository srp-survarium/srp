void __thiscall Scaleform::GFx::Text::EditorKit::OnMouseDown(
        Scaleform::GFx::Text::EditorKit *this,
        float x,
        float y,
        float buttons)
{
  const Scaleform::Render::Rect<float> *ViewRect; // edi
  unsigned __int64 v6; // rax
  unsigned int v7; // edi
  char v8; // bl
  bool v9; // c3
  unsigned __int16 v10; // ax
  Scaleform::Render::Text::DocView *pObject; // ecx
  unsigned int CursorPosAtPoint; // edi
  unsigned __int16 Flags; // ax
  unsigned __int16 v14; // ax
  unsigned int Length; // eax
  float v16; // ecx
  float v17; // ebp
  float v18; // edi
  wchar_t *v19; // ebx
  wchar_t v20; // bx
  unsigned int StartIndex; // ebx
  unsigned int v22; // edi
  const wchar_t *ptext; // [esp+14h] [ebp-Ch]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator it; // [esp+18h] [ebp-8h] BYREF
  unsigned int textLen; // [esp+24h] [ebp+4h]
  unsigned int textLena; // [esp+24h] [ebp+4h]
  Scaleform::Render::Text::Paragraph *ppara; // [esp+28h] [ebp+8h]
  Scaleform::Render::Text::Paragraph *pparaa; // [esp+28h] [ebp+8h]

  if ( (LOBYTE(buttons) & 1) != 0 )
  {
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    buttons = x - ViewRect->x1;
    buttons = floor(buttons);
    *(float *)&textLen = buttons;
    buttons = y - ViewRect->y1;
    buttons = floor(buttons);
    *(float *)&ppara = buttons;
    v6 = Scaleform::Timer::GetTicks() / 0x3E8;
    v7 = v6;
    v8 = 0;
    v9 = *(float *)&textLen == this->LastMousePos.x;
    LOBYTE(buttons) = 0;
    if ( !v9 )
      goto LABEL_9;
    if ( *(float *)&ppara == this->LastMousePos.y && (unsigned int)v6 <= this->LastClickTime + 300 )
    {
      v10 = this->Flags | 0x200;
      if ( (this->Flags & 0x200) != 0 )
        LOBYTE(buttons) = 1;
      else
        v8 = 1;
      this->Flags = v10;
    }
    else
    {
LABEL_9:
      this->Flags &= ~0x200u;
    }
    pObject = this->pDocView.pObject;
    this->LastMousePos.x = *(float *)&textLen;
    this->LastClickTime = v7;
    this->LastMousePos.y = *(float *)&ppara;
    CursorPosAtPoint = Scaleform::Render::Text::DocView::GetCursorPosAtPoint(
                         pObject,
                         *(float *)&textLen,
                         *(float *)&ppara);
    if ( CursorPosAtPoint != -1 )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPosAtPoint, (this->Flags & 2) != 0);
      Flags = this->Flags;
      if ( (Flags & 2) != 0 && (Flags & 0x20) == 0 )
      {
        v14 = Flags | 0x20;
        this->Flags = v14;
        if ( v8 || LOBYTE(buttons) )
        {
          Scaleform::Render::Text::StyledText::GetParagraphByIndex(
            this->pDocView.pObject->pDocument.pObject,
            &it,
            CursorPosAtPoint,
            (unsigned int *)&buttons);
          if ( !Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&it) )
          {
            pparaa = it.pArray->Data.Data[it.CurIndex].pPara;
            Length = Scaleform::Render::Text::Paragraph::GetLength(pparaa);
            v16 = buttons;
            textLena = Length;
            v17 = buttons;
            v18 = buttons;
            if ( v8 )
            {
              ptext = pparaa->Text.pText;
              if ( buttons != 0.0 )
              {
                v19 = &pparaa->Text.pText[LODWORD(buttons) - 1];
                do
                {
                  if ( Scaleform::SFiswspace(*v19) )
                    break;
                  if ( !Scaleform::SFiswalnum(*v19) )
                    break;
                  --LODWORD(v17);
                  --v19;
                }
                while ( v17 != 0.0 );
                v16 = buttons;
                Length = textLena;
              }
              if ( LODWORD(v16) < Length )
              {
                do
                {
                  v20 = ptext[LODWORD(v18)];
                  if ( Scaleform::SFiswspace(v20) )
                    break;
                  if ( !Scaleform::SFiswalnum(v20) )
                    break;
                  ++LODWORD(v18);
                }
                while ( LODWORD(v18) < textLena );
              }
            }
            else
            {
              v17 = 0.0;
              v18 = *(float *)&Length;
            }
            StartIndex = pparaa->StartIndex;
            v22 = StartIndex + LODWORD(v18);
            Scaleform::GFx::Text::EditorKit::SetCursorPos(this, v22, (this->Flags & 2) != 0);
            Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, LODWORD(v17) + StartIndex, v22, 1);
          }
        }
        else if ( (v14 & 0x40) == 0 )
        {
          Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, CursorPosAtPoint, CursorPosAtPoint, 1);
        }
      }
    }
  }
}
