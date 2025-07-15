char __thiscall Scaleform::GFx::Text::EditorKit::OnKeyDown(
        Scaleform::GFx::Text::EditorKit *this,
        int keyCode,
        const Scaleform::KeyModifiers *specKeysState)
{
  Scaleform::Render::Text::DocView *pObject; // ebx
  Scaleform::Render::Text::StyledText *v5; // ecx
  unsigned int Length; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v7; // ecx
  Scaleform::Render::Text::Paragraph *CursorPos; // edi
  char Flags; // al
  Scaleform::Render::Text::DocView *v10; // ecx
  Scaleform::String::DataDesc *EndSelection; // edx
  const Scaleform::Render::Text::Paragraph *v12; // ecx
  Scaleform::String::DataDesc *v13; // ebx
  Scaleform::GFx::TextKeyMap *v14; // ecx
  const Scaleform::GFx::TextKeyMap::KeyMapEntry *v15; // eax
  Scaleform::String::DataDesc *CursorPosInLine; // eax
  unsigned int LineIndexOfChar; // eax
  unsigned int v18; // eax
  unsigned int v19; // ebx
  Scaleform::Render::Text::DocView *v20; // ecx
  unsigned int LineOffset; // eax
  unsigned int v22; // eax
  Scaleform::Render::Text::DocView *v23; // ecx
  unsigned int v24; // edi
  unsigned int LineLength; // eax
  unsigned int v26; // ebx
  unsigned int v27; // eax
  double v28; // st7
  Scaleform::Render::Text::DocView *v29; // ecx
  unsigned int BottomVScroll; // eax
  Scaleform::Render::Text::DocView *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  double v34; // st7
  Scaleform::Render::Text::DocView *v35; // ecx
  unsigned int v36; // eax
  Scaleform::Render::Text::DocView *v37; // ecx
  unsigned int v38; // edi
  char v39; // al
  double LastHorizCursorPos; // st7
  Scaleform::Render::Text::DocView *v41; // ecx
  char v42; // cl
  double x1; // st7
  Scaleform::String::DataDesc *v44; // ebx
  Scaleform::String::DataDesc *v45; // eax
  Scaleform::Render::Text::DocView *v46; // ecx
  Scaleform::String::DataDesc *v47; // eax
  Scaleform::Render::Text::DocView *v48; // ecx
  Scaleform::Render::Text::Paragraph *v49; // ebx
  unsigned __int16 v50; // ax
  Scaleform::Render::Text::DocView::DocumentListener *v51; // ecx
  char v53; // [esp+1Ch] [ebp-30h]
  char v54; // [esp+1Dh] [ebp-2Fh]
  bool v55; // [esp+1Eh] [ebp-2Eh] BYREF
  bool v56; // [esp+1Fh] [ebp-2Dh]
  Scaleform::Render::Text::Paragraph *BeginSelection; // [esp+20h] [ebp-2Ch]
  float x; // [esp+24h] [ebp-28h]
  Scaleform::String::DataDesc *v59; // [esp+28h] [ebp-24h]
  unsigned int pos; // [esp+2Ch] [ebp-20h]
  unsigned int v61[2]; // [esp+30h] [ebp-1Ch] BYREF
  Scaleform::Render::Text::DocView *v62; // [esp+38h] [ebp-14h]
  Scaleform::Render::Rect<float> v63; // [esp+3Ch] [ebp-10h] BYREF

  pObject = this->pDocView.pObject;
  v5 = pObject->pDocument.pObject;
  v62 = pObject;
  Length = Scaleform::Render::Text::StyledText::GetLength(v5);
  v7 = pObject->pDocumentListener.pObject;
  CursorPos = (Scaleform::Render::Text::Paragraph *)this->CursorPos;
  pos = Length;
  v54 = 0;
  if ( v7 )
    keyCode = v7->Editor_OnKey(v7, this, keyCode);
  Flags = this->Flags;
  v10 = this->pDocView.pObject;
  x = -1.0;
  EndSelection = (Scaleform::String::DataDesc *)v10->EndSelection;
  v56 = (Flags & 0x40) != 0;
  v53 = 0;
  BeginSelection = (Scaleform::Render::Text::Paragraph *)v10->BeginSelection;
  if ( BeginSelection >= (Scaleform::Render::Text::Paragraph *)EndSelection )
    BeginSelection = (Scaleform::Render::Text::Paragraph *)EndSelection;
  v12 = (const Scaleform::Render::Text::Paragraph *)v10->BeginSelection;
  if ( EndSelection >= (Scaleform::String::DataDesc *)v12 )
  {
    v13 = EndSelection;
    v59 = EndSelection;
  }
  else
  {
    v13 = (Scaleform::String::DataDesc *)v12;
    v59 = (Scaleform::String::DataDesc *)v12;
  }
  v14 = this->pKeyMap.pObject;
  if ( v14 )
  {
    v15 = Scaleform::GFx::TextKeyMap::Find(v14, keyCode, specKeysState, State_Down);
    v61[0] = (unsigned int)v15;
    if ( v15 )
    {
      switch ( v15->Action )
      {
        case KeyAct_EnterSelectionMode:
          if ( (this->Flags & 2) == 0 )
            break;
          goto LABEL_107;
        case KeyAct_Left:
          if ( CursorPos == (Scaleform::Render::Text::Paragraph *)-1 )
            CursorPos = (Scaleform::Render::Text::Paragraph *)pos;
          if ( CursorPos )
            CursorPos = (Scaleform::Render::Text::Paragraph *)((char *)CursorPos - 1);
          if ( (this->Flags & 0x40) == 0 && BeginSelection != (Scaleform::Render::Text::Paragraph *)v59 )
          {
            CursorPos = BeginSelection;
            CursorPosInLine = v59;
            if ( BeginSelection >= (Scaleform::Render::Text::Paragraph *)v59 )
              goto LABEL_94;
          }
          goto LABEL_95;
        case KeyAct_Right:
          if ( CursorPos == (Scaleform::Render::Text::Paragraph *)-1 )
          {
            CursorPos = (Scaleform::Render::Text::Paragraph *)pos;
          }
          else if ( (unsigned int)CursorPos < pos )
          {
            CursorPos = (Scaleform::Render::Text::Paragraph *)((char *)CursorPos + 1);
          }
          if ( (this->Flags & 0x40) == 0 )
          {
            CursorPosInLine = v59;
            if ( BeginSelection != (Scaleform::Render::Text::Paragraph *)v59 )
            {
              CursorPos = BeginSelection;
              if ( v59 >= (Scaleform::String::DataDesc *)BeginSelection )
                goto LABEL_94;
            }
          }
          goto LABEL_95;
        case KeyAct_Up:
          v39 = this->Flags;
          v63.x1 = 0.0;
          v63.y1 = 0.0;
          v63.x2 = 0.0;
          v63.y2 = 0.0;
          if ( (v39 & 0x40) == 0 )
          {
            CursorPosInLine = (Scaleform::String::DataDesc *)BeginSelection;
            if ( BeginSelection != (Scaleform::Render::Text::Paragraph *)v13 )
            {
              if ( BeginSelection < (Scaleform::Render::Text::Paragraph *)v13 )
                goto LABEL_94;
              CursorPos = (Scaleform::Render::Text::Paragraph *)v13;
              goto LABEL_95;
            }
          }
          if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(this, this->CursorPos, &v63, v61, 0, 1, 0) )
            goto LABEL_95;
          if ( !v61[0] )
          {
$LN60_3:
            CursorPos = 0;
            goto LABEL_95;
          }
          if ( this->LastHorizCursorPos >= 0.0 )
            LastHorizCursorPos = this->LastHorizCursorPos;
          else
            LastHorizCursorPos = v63.x1;
          v41 = this->pDocView.pObject;
          x = LastHorizCursorPos;
          CursorPosInLine = (Scaleform::String::DataDesc *)Scaleform::Render::Text::DocView::GetCursorPosInLine(
                                                             v41,
                                                             v61[0] - 1,
                                                             x);
          goto LABEL_94;
        case KeyAct_Down:
          v42 = this->Flags;
          v63.x1 = 0.0;
          v63.y1 = 0.0;
          v63.x2 = 0.0;
          v63.y2 = 0.0;
          if ( (v42 & 0x40) != 0
            || (CursorPosInLine = (Scaleform::String::DataDesc *)BeginSelection,
                v13 == (Scaleform::String::DataDesc *)BeginSelection) )
          {
            if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(this, this->CursorPos, &v63, v61, 0, 1, 0) )
              goto LABEL_95;
            v38 = v61[0] + 1;
            if ( v38 >= Scaleform::Render::Text::DocView::GetLinesCount(this->pDocView.pObject) )
            {
$LN59_1:
              CursorPos = (Scaleform::Render::Text::Paragraph *)pos;
              goto LABEL_95;
            }
            if ( this->LastHorizCursorPos >= 0.0 )
              x1 = this->LastHorizCursorPos;
            else
              x1 = v63.x1;
            x = x1;
LABEL_72:
            CursorPosInLine = (Scaleform::String::DataDesc *)Scaleform::Render::Text::DocView::GetCursorPosInLine(
                                                               this->pDocView.pObject,
                                                               v38,
                                                               x);
          }
          else if ( v13 >= (Scaleform::String::DataDesc *)BeginSelection )
          {
            CursorPos = (Scaleform::Render::Text::Paragraph *)v13;
            goto LABEL_95;
          }
LABEL_94:
          CursorPos = (Scaleform::Render::Text::Paragraph *)CursorPosInLine;
          goto LABEL_95;
        case KeyAct_PageUp:
          v27 = this->CursorPos;
          v63.x1 = 0.0;
          v63.y1 = 0.0;
          v63.x2 = 0.0;
          v63.y2 = 0.0;
          if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(this, v27, &v63, v61, 0, 1, 0) )
            goto LABEL_95;
          if ( this->LastHorizCursorPos >= 0.0 )
            v28 = this->LastHorizCursorPos;
          else
            v28 = v63.x1;
          v29 = this->pDocView.pObject;
          x = v28;
          BottomVScroll = Scaleform::Render::Text::DocView::GetBottomVScroll(v29);
          v31 = this->pDocView.pObject;
          v32 = BottomVScroll - v31->mLineBuffer.Geom.FirstVisibleLinePos + 1;
          if ( v61[0] < v32 )
            goto $LN60_3;
          CursorPosInLine = (Scaleform::String::DataDesc *)Scaleform::Render::Text::DocView::GetCursorPosInLine(
                                                             v31,
                                                             v61[0] - v32,
                                                             x);
          goto LABEL_94;
        case KeyAct_PageDown:
          v33 = this->CursorPos;
          v63.x1 = 0.0;
          v63.y1 = 0.0;
          v63.x2 = 0.0;
          v63.y2 = 0.0;
          if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(this, v33, &v63, v61, 0, 1, 0) )
            goto LABEL_95;
          if ( this->LastHorizCursorPos >= 0.0 )
            v34 = this->LastHorizCursorPos;
          else
            v34 = v63.x1;
          v35 = this->pDocView.pObject;
          x = v34;
          v36 = Scaleform::Render::Text::DocView::GetBottomVScroll(v35);
          v37 = this->pDocView.pObject;
          v38 = v61[0] + v36 - v37->mLineBuffer.Geom.FirstVisibleLinePos + 1;
          if ( v38 >= Scaleform::Render::Text::DocView::GetLinesCount(v37) )
            goto $LN59_1;
          goto LABEL_72;
        case KeyAct_LineHome:
          LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(
                              this->pDocView.pObject,
                              this->CursorPos);
          if ( LineIndexOfChar == -1 )
            goto LABEL_95;
          CursorPosInLine = (Scaleform::String::DataDesc *)Scaleform::Render::Text::DocView::GetLineOffset(
                                                             this->pDocView.pObject,
                                                             LineIndexOfChar);
          goto LABEL_94;
        case KeyAct_LineEnd:
          v18 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, this->CursorPos);
          v19 = v18;
          if ( v18 != -1 )
          {
            v20 = this->pDocView.pObject;
            v55 = 0;
            pos = Scaleform::Render::Text::DocView::GetLineLength(v20, v18, &v55);
            if ( v55 )
              --pos;
            LineOffset = Scaleform::Render::Text::DocView::GetLineOffset(this->pDocView.pObject, v19);
            CursorPos = (Scaleform::Render::Text::Paragraph *)(pos + LineOffset);
          }
          goto LABEL_95;
        case KeyAct_PageHome:
          CursorPosInLine = (Scaleform::String::DataDesc *)Scaleform::Render::Text::DocView::GetLineOffset(
                                                             this->pDocView.pObject,
                                                             this->pDocView.pObject->mLineBuffer.Geom.FirstVisibleLinePos);
          goto LABEL_94;
        case KeyAct_PageEnd:
          v22 = Scaleform::Render::Text::DocView::GetBottomVScroll(this->pDocView.pObject);
          v23 = this->pDocView.pObject;
          v24 = v22;
          v55 = 0;
          LineLength = Scaleform::Render::Text::DocView::GetLineLength(v23, v22, &v55);
          v26 = LineLength;
          if ( v55 )
            v26 = LineLength - 1;
          CursorPos = (Scaleform::Render::Text::Paragraph *)(v26
                                                           + Scaleform::Render::Text::DocView::GetLineOffset(
                                                               this->pDocView.pObject,
                                                               v24));
          goto LABEL_95;
        case KeyAct_DocHome:
          goto $LN60_3;
        case KeyAct_DocEnd:
          goto $LN59_1;
        case KeyAct_Backspace:
          if ( this->IsReadOnly(this) )
            goto LABEL_95;
          v44 = v59;
          v45 = (Scaleform::String::DataDesc *)BeginSelection;
          this->Flags &= ~0x40u;
          v46 = this->pDocView.pObject;
          if ( v45 == v44 )
          {
            v61[0] = (unsigned int)CursorPos;
            CursorPos = (Scaleform::Render::Text::Paragraph *)((char *)CursorPos
                                                             - Scaleform::Render::Text::DocView::EditCommand(
                                                                 v46,
                                                                 8u,
                                                                 v61));
            v53 = 1;
            goto LABEL_95;
          }
          v61[0] = (unsigned int)v45;
          goto LABEL_77;
        case KeyAct_Delete:
          if ( this->IsReadOnly(this) )
            goto LABEL_95;
          v44 = v59;
          v47 = (Scaleform::String::DataDesc *)BeginSelection;
          this->Flags &= ~0x40u;
          if ( v47 == v44 )
          {
            if ( this->CursorPos < pos )
            {
              v48 = this->pDocView.pObject;
              v61[0] = (unsigned int)CursorPos;
              Scaleform::Render::Text::DocView::EditCommand(v48, 3u, v61);
              v53 = 1;
            }
            goto LABEL_95;
          }
          v46 = this->pDocView.pObject;
          v61[0] = (unsigned int)v47;
LABEL_77:
          v61[1] = (unsigned int)v44;
          Scaleform::Render::Text::DocView::EditCommand(v46, 4u, v61);
          CursorPos = BeginSelection;
          if ( BeginSelection >= (Scaleform::Render::Text::Paragraph *)v44 )
            CursorPos = (Scaleform::Render::Text::Paragraph *)v44;
          goto LABEL_79;
        case KeyAct_Copy:
        case KeyAct_Cut:
          if ( !this->pClipboard.pObject )
            goto LABEL_95;
          if ( this->IsReadOnly(this) || *(_DWORD *)v61[0] == 19 )
          {
            this->Flags &= ~0x40u;
            Scaleform::GFx::Text::EditorKit::CopyToClipboard(
              this,
              BeginSelection,
              (const Scaleform::Render::Text::Paragraph *)v59,
              (this->Flags & 4) != 0);
            break;
          }
          CursorPos = (Scaleform::Render::Text::Paragraph *)v59;
          v49 = BeginSelection;
          this->Flags &= ~0x40u;
          Scaleform::GFx::Text::EditorKit::CutToClipboard(this, v49, CursorPos, (this->Flags & 4) != 0);
          if ( v49 >= CursorPos )
          {
LABEL_79:
            v53 = 1;
          }
          else
          {
            CursorPos = v49;
            v53 = 1;
          }
LABEL_95:
          if ( (Scaleform::Render::Text::Paragraph *)this->CursorPos != CursorPos )
          {
            Scaleform::GFx::Text::EditorKit::SetCursorPos(this, (unsigned int)CursorPos, (this->Flags & 2) != 0);
            this->LastHorizCursorPos = x;
LABEL_100:
            v54 = 1;
            goto LABEL_101;
          }
          v50 = this->Flags;
          if ( (v50 & 0x40) == 0 && BeginSelection != (Scaleform::Render::Text::Paragraph *)v59 )
          {
            Scaleform::GFx::Text::EditorKit::SetCursorPos(this, (unsigned int)CursorPos, (v50 & 2) != 0);
            goto LABEL_100;
          }
LABEL_101:
          if ( v53 )
          {
            if ( !v54 )
              Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(this->pDocView.pObject, this->CursorPos);
            v51 = v62->pDocumentListener.pObject;
            if ( v51 )
              v51->Editor_OnChanged(v51, this);
          }
          break;
        case KeyAct_Paste:
          LOBYTE(v61[0]) = (this->Flags & 4) != 0;
          CursorPosInLine = (Scaleform::String::DataDesc *)Scaleform::GFx::Text::EditorKit::PasteFromClipboard(
                                                             this,
                                                             (Scaleform::String::DataDesc *)BeginSelection,
                                                             (Scaleform::String)v13,
                                                             v61[0]);
          if ( CursorPosInLine == (Scaleform::String::DataDesc *)-1 )
            goto LABEL_95;
          v53 = 1;
          goto LABEL_94;
        case KeyAct_SelectAll:
          Scaleform::GFx::Text::EditorKit::SetCursorPos(this, pos);
          Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, 0, pos, 1);
          break;
        default:
          break;
      }
    }
  }
  if ( v56 )
LABEL_107:
    this->Flags |= 0x40u;
  return v54;
}
