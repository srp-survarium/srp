char __thiscall Scaleform::GFx::Text::EditorKit::OnKeyDown(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int keyCode,
        const Scaleform::KeyModifiers *specKeysState)
{
  Scaleform::Render::Text::DocView *pObject; // ebx
  Scaleform::Render::Text::StyledText *v5; // ecx
  unsigned int Length; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v7; // ecx
  Scaleform::Render::Text::Paragraph *CursorPos; // edi
  char Flags; // al
  Scaleform::Render::Text::DocView *v10; // ecx
  unsigned int EndSelection; // edx
  unsigned int BeginSelection; // ecx
  Scaleform::String v13; // ebx
  Scaleform::GFx::TextKeyMap *v14; // ecx
  const Scaleform::GFx::TextKeyMap::KeyMapEntry *v15; // eax
  unsigned int CursorPosInLine; // eax
  int LineIndexOfChar; // eax
  signed int v18; // eax
  int v19; // ebx
  Scaleform::Render::Text::DocView *v20; // ecx
  unsigned int LineOffset; // eax
  signed int v22; // eax
  Scaleform::Render::Text::DocView *v23; // ecx
  int v24; // edi
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
  unsigned int v44; // ebx
  unsigned int v45; // eax
  Scaleform::Render::Text::DocView *v46; // ecx
  unsigned int v47; // eax
  Scaleform::Render::Text::DocView *v48; // ecx
  Scaleform::Render::Text::Paragraph *v49; // ebx
  unsigned __int16 v50; // ax
  Scaleform::Render::Text::DocView::DocumentListener *v51; // ecx
  char v53; // [esp+302h] [ebp-30h]
  char v54; // [esp+303h] [ebp-2Fh]
  bool phasNewLine; // [esp+304h] [ebp-2Eh] BYREF
  bool v56; // [esp+305h] [ebp-2Dh]
  unsigned int startPos; // [esp+306h] [ebp-2Ch]
  float x; // [esp+30Ah] [ebp-28h]
  unsigned int endPos; // [esp+30Eh] [ebp-24h]
  unsigned int pos; // [esp+312h] [ebp-20h]
  unsigned int plineIndex[2]; // [esp+316h] [ebp-1Ch] BYREF
  Scaleform::Render::Text::DocView *v62; // [esp+31Eh] [ebp-14h]
  Scaleform::Render::Rect<float> pcursorRect; // [esp+322h] [ebp-10h] BYREF

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
  EndSelection = v10->EndSelection;
  v56 = (Flags & 0x40) != 0;
  v53 = 0;
  startPos = v10->BeginSelection;
  if ( startPos >= EndSelection )
    startPos = EndSelection;
  BeginSelection = v10->BeginSelection;
  if ( EndSelection >= BeginSelection )
  {
    v13.pData = (Scaleform::String::DataDesc *)EndSelection;
    endPos = EndSelection;
  }
  else
  {
    v13.pData = (Scaleform::String::DataDesc *)BeginSelection;
    endPos = BeginSelection;
  }
  v14 = this->pKeyMap.pObject;
  if ( v14 )
  {
    v15 = Scaleform::GFx::TextKeyMap::Find(v14, keyCode, specKeysState, State_Down);
    plineIndex[0] = (unsigned int)v15;
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
          if ( (this->Flags & 0x40) == 0 && startPos != endPos )
          {
            CursorPos = (Scaleform::Render::Text::Paragraph *)startPos;
            CursorPosInLine = endPos;
            if ( startPos >= endPos )
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
            CursorPosInLine = endPos;
            if ( startPos != endPos )
            {
              CursorPos = (Scaleform::Render::Text::Paragraph *)startPos;
              if ( endPos >= startPos )
                goto LABEL_94;
            }
          }
          goto LABEL_95;
        case KeyAct_Up:
          v39 = this->Flags;
          pcursorRect.x1 = 0.0;
          pcursorRect.y1 = 0.0;
          pcursorRect.x2 = 0.0;
          pcursorRect.y2 = 0.0;
          if ( (v39 & 0x40) == 0 )
          {
            CursorPosInLine = startPos;
            if ( (Scaleform::String::DataDesc *)startPos != v13.pData )
            {
              if ( startPos < v13.HeapTypeBits )
                goto LABEL_94;
              CursorPos = (Scaleform::Render::Text::Paragraph *)v13.pData;
              goto LABEL_95;
            }
          }
          if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                  this,
                  this->CursorPos,
                  &pcursorRect,
                  plineIndex,
                  0,
                  1,
                  0) )
            goto LABEL_95;
          if ( !plineIndex[0] )
          {
$LN60_2:
            CursorPos = 0;
            goto LABEL_95;
          }
          if ( this->LastHorizCursorPos >= 0.0 )
            LastHorizCursorPos = this->LastHorizCursorPos;
          else
            LastHorizCursorPos = pcursorRect.x1;
          v41 = this->pDocView.pObject;
          x = LastHorizCursorPos;
          CursorPosInLine = Scaleform::Render::Text::DocView::GetCursorPosInLine(v41, plineIndex[0] - 1, x);
          goto LABEL_94;
        case KeyAct_Down:
          v42 = this->Flags;
          pcursorRect.x1 = 0.0;
          pcursorRect.y1 = 0.0;
          pcursorRect.x2 = 0.0;
          pcursorRect.y2 = 0.0;
          if ( (v42 & 0x40) != 0 || (CursorPosInLine = startPos, v13.pData == (Scaleform::String::DataDesc *)startPos) )
          {
            if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                    this,
                    this->CursorPos,
                    &pcursorRect,
                    plineIndex,
                    0,
                    1,
                    0) )
              goto LABEL_95;
            v38 = plineIndex[0] + 1;
            if ( v38 >= Scaleform::Render::Text::DocView::GetLinesCount(this->pDocView.pObject) )
            {
$LN59_1:
              CursorPos = (Scaleform::Render::Text::Paragraph *)pos;
              goto LABEL_95;
            }
            if ( this->LastHorizCursorPos >= 0.0 )
              x1 = this->LastHorizCursorPos;
            else
              x1 = pcursorRect.x1;
            x = x1;
LABEL_72:
            CursorPosInLine = Scaleform::Render::Text::DocView::GetCursorPosInLine(this->pDocView.pObject, v38, x);
          }
          else if ( v13.HeapTypeBits >= startPos )
          {
            CursorPos = (Scaleform::Render::Text::Paragraph *)v13.pData;
            goto LABEL_95;
          }
LABEL_94:
          CursorPos = (Scaleform::Render::Text::Paragraph *)CursorPosInLine;
          goto LABEL_95;
        case KeyAct_PageUp:
          v27 = this->CursorPos;
          pcursorRect.x1 = 0.0;
          pcursorRect.y1 = 0.0;
          pcursorRect.x2 = 0.0;
          pcursorRect.y2 = 0.0;
          if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(this, v27, &pcursorRect, plineIndex, 0, 1, 0) )
            goto LABEL_95;
          if ( this->LastHorizCursorPos >= 0.0 )
            v28 = this->LastHorizCursorPos;
          else
            v28 = pcursorRect.x1;
          v29 = this->pDocView.pObject;
          x = v28;
          BottomVScroll = Scaleform::Render::Text::DocView::GetBottomVScroll(v29);
          v31 = this->pDocView.pObject;
          v32 = BottomVScroll - v31->mLineBuffer.Geom.FirstVisibleLinePos + 1;
          if ( plineIndex[0] < v32 )
            goto $LN60_2;
          CursorPosInLine = Scaleform::Render::Text::DocView::GetCursorPosInLine(v31, plineIndex[0] - v32, x);
          goto LABEL_94;
        case KeyAct_PageDown:
          v33 = this->CursorPos;
          pcursorRect.x1 = 0.0;
          pcursorRect.y1 = 0.0;
          pcursorRect.x2 = 0.0;
          pcursorRect.y2 = 0.0;
          if ( !Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(this, v33, &pcursorRect, plineIndex, 0, 1, 0) )
            goto LABEL_95;
          if ( this->LastHorizCursorPos >= 0.0 )
            v34 = this->LastHorizCursorPos;
          else
            v34 = pcursorRect.x1;
          v35 = this->pDocView.pObject;
          x = v34;
          v36 = Scaleform::Render::Text::DocView::GetBottomVScroll(v35);
          v37 = this->pDocView.pObject;
          v38 = plineIndex[0] + v36 - v37->mLineBuffer.Geom.FirstVisibleLinePos + 1;
          if ( v38 >= Scaleform::Render::Text::DocView::GetLinesCount(v37) )
            goto $LN59_1;
          goto LABEL_72;
        case KeyAct_LineHome:
          LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(
                              this->pDocView.pObject,
                              this->CursorPos);
          if ( LineIndexOfChar == -1 )
            goto LABEL_95;
          CursorPosInLine = Scaleform::Render::Text::DocView::GetLineOffset(this->pDocView.pObject, LineIndexOfChar);
          goto LABEL_94;
        case KeyAct_LineEnd:
          v18 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, this->CursorPos);
          v19 = v18;
          if ( v18 != -1 )
          {
            v20 = this->pDocView.pObject;
            phasNewLine = 0;
            pos = Scaleform::Render::Text::DocView::GetLineLength(v20, v18, &phasNewLine);
            if ( phasNewLine )
              --pos;
            LineOffset = Scaleform::Render::Text::DocView::GetLineOffset(this->pDocView.pObject, v19);
            CursorPos = (Scaleform::Render::Text::Paragraph *)(pos + LineOffset);
          }
          goto LABEL_95;
        case KeyAct_PageHome:
          CursorPosInLine = Scaleform::Render::Text::DocView::GetLineOffset(
                              this->pDocView.pObject,
                              this->pDocView.pObject->mLineBuffer.Geom.FirstVisibleLinePos);
          goto LABEL_94;
        case KeyAct_PageEnd:
          v22 = Scaleform::Render::Text::DocView::GetBottomVScroll(this->pDocView.pObject);
          v23 = this->pDocView.pObject;
          v24 = v22;
          phasNewLine = 0;
          LineLength = Scaleform::Render::Text::DocView::GetLineLength(v23, v22, &phasNewLine);
          v26 = LineLength;
          if ( phasNewLine )
            v26 = LineLength - 1;
          CursorPos = (Scaleform::Render::Text::Paragraph *)(v26
                                                           + Scaleform::Render::Text::DocView::GetLineOffset(
                                                               this->pDocView.pObject,
                                                               v24));
          goto LABEL_95;
        case KeyAct_DocHome:
          goto $LN60_2;
        case KeyAct_DocEnd:
          goto $LN59_1;
        case KeyAct_Backspace:
          if ( this->IsReadOnly(this) )
            goto LABEL_95;
          v44 = endPos;
          v45 = startPos;
          this->Flags &= ~0x40u;
          v46 = this->pDocView.pObject;
          if ( v45 == v44 )
          {
            plineIndex[0] = (unsigned int)CursorPos;
            CursorPos = (Scaleform::Render::Text::Paragraph *)((char *)CursorPos
                                                             - Scaleform::Render::Text::DocView::EditCommand(
                                                                 v46,
                                                                 8u,
                                                                 plineIndex));
            v53 = 1;
            goto LABEL_95;
          }
          plineIndex[0] = v45;
          goto LABEL_77;
        case KeyAct_Delete:
          if ( this->IsReadOnly(this) )
            goto LABEL_95;
          v44 = endPos;
          v47 = startPos;
          this->Flags &= ~0x40u;
          if ( v47 == v44 )
          {
            if ( this->CursorPos < pos )
            {
              v48 = this->pDocView.pObject;
              plineIndex[0] = (unsigned int)CursorPos;
              Scaleform::Render::Text::DocView::EditCommand(v48, 3u, plineIndex);
              v53 = 1;
            }
            goto LABEL_95;
          }
          v46 = this->pDocView.pObject;
          plineIndex[0] = v47;
LABEL_77:
          plineIndex[1] = v44;
          Scaleform::Render::Text::DocView::EditCommand(v46, 4u, plineIndex);
          CursorPos = (Scaleform::Render::Text::Paragraph *)startPos;
          if ( startPos >= v44 )
            CursorPos = (Scaleform::Render::Text::Paragraph *)v44;
          goto LABEL_79;
        case KeyAct_Copy:
        case KeyAct_Cut:
          if ( !this->pClipboard.pObject )
            goto LABEL_95;
          if ( this->IsReadOnly(this) || *(_DWORD *)plineIndex[0] == 19 )
          {
            this->Flags &= ~0x40u;
            Scaleform::GFx::Text::EditorKit::CopyToClipboard(
              this,
              (Scaleform::Render::Text::Paragraph *)startPos,
              (Scaleform::Render::Text::Paragraph *)endPos,
              (this->Flags & 4) != 0);
            break;
          }
          CursorPos = (Scaleform::Render::Text::Paragraph *)endPos;
          v49 = (Scaleform::Render::Text::Paragraph *)startPos;
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
          if ( (v50 & 0x40) == 0 && startPos != endPos )
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
          LOBYTE(plineIndex[0]) = (this->Flags & 4) != 0;
          CursorPosInLine = Scaleform::GFx::Text::EditorKit::PasteFromClipboard(
                              this,
                              (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)startPos,
                              v13,
                              plineIndex[0]);
          if ( CursorPosInLine == -1 )
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
