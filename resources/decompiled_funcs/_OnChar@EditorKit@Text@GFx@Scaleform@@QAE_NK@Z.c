char __thiscall Scaleform::GFx::Text::EditorKit::OnChar(Scaleform::GFx::Text::EditorKit *this, int wcharCode)
{
  int v2; // ebp
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // ecx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *IteratorAt; // eax
  int Index; // ecx
  int v7; // edi
  int v8; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *v9; // eax
  int v10; // ecx
  Scaleform::Render::Text::DocView *v12; // eax
  unsigned int BeginSelection; // edx
  unsigned int EndSelection; // ecx
  unsigned int CursorPos; // edi
  char v16; // bl
  unsigned int v17; // ebx
  Scaleform::Render::Text::DocView *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // ebp
  Scaleform::Render::Text::DocView::DocumentListener *v21; // ecx
  Scaleform::Render::Text::DocView *v22; // ecx
  Scaleform::Render::Text::DocView *v23; // ecx
  char v24; // al
  unsigned int v25; // edx
  unsigned int v26; // edi
  unsigned int beginSel; // [esp+8h] [ebp-18h]
  unsigned int endSel; // [esp+Ch] [ebp-14h]
  Scaleform::Render::Text::DocView *pdocument; // [esp+10h] [ebp-10h]
  Scaleform::Render::Text::DocView::ReplaceTextByCharCommand cmd; // [esp+14h] [ebp-Ch] BYREF
  char rv; // [esp+24h] [ebp+4h]

  LOWORD(v2) = wcharCode;
  if ( wcharCode && (this->Flags & 0x20) == 0 )
  {
    pObject = this->pRestrict.pObject;
    if ( pObject )
    {
      IteratorAt = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
                     &pObject->RestrictRanges,
                     (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *)&cmd,
                     wcharCode);
      Index = IteratorAt->Index;
      if ( Index < 0 || Index >= IteratorAt->pArray->Ranges.Data.Size )
      {
        v7 = Scaleform::SFtowupper(wcharCode);
        v8 = Scaleform::SFtowlower(wcharCode);
        v2 = v7;
        if ( wcharCode == v7 )
          v2 = v8;
        v9 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
               &this->pRestrict.pObject->RestrictRanges,
               (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *)&cmd,
               v2);
        v10 = v9->Index;
        if ( v10 < 0 || v10 >= v9->pArray->Ranges.Data.Size )
          return 0;
      }
    }
    v12 = this->pDocView.pObject;
    BeginSelection = v12->BeginSelection;
    EndSelection = v12->EndSelection;
    CursorPos = this->CursorPos;
    pdocument = v12;
    rv = 0;
    beginSel = BeginSelection;
    if ( BeginSelection >= EndSelection )
      beginSel = v12->EndSelection;
    endSel = v12->BeginSelection;
    if ( EndSelection >= BeginSelection )
      endSel = v12->EndSelection;
    v16 = 0;
    if ( this->IsReadOnly(this) )
      return rv;
    if ( (_WORD)v2 == 13 )
    {
      v23 = this->pDocView.pObject;
      if ( (v23->Flags & 4) != 0 )
      {
        v20 = beginSel;
        this->Flags &= ~0x40u;
        v24 = v23->pDocument.pObject->RTFlags & 2;
        if ( beginSel == endSel )
        {
          v25 = this->CursorPos;
          LOWORD(cmd.EndPos) = (unsigned __int8)(v24 != 0 ? 13 : 10);
          cmd.BeginPos = v25;
          Scaleform::Render::Text::DocView::EditCommand(v23, 0, &cmd);
          ++CursorPos;
          v16 = 1;
        }
        else
        {
          cmd.CharCode = (unsigned __int8)(v24 != 0 ? 13 : 10);
          cmd.BeginPos = beginSel;
          cmd.EndPos = endSel;
          Scaleform::Render::Text::DocView::EditCommand(v23, 5u, &cmd);
          v26 = beginSel;
          if ( beginSel >= endSel )
            v26 = endSel;
          CursorPos = v26 + 1;
          v16 = 1;
        }
        goto LABEL_25;
      }
    }
    else
    {
      if ( (unsigned __int16)v2 < 0x20u )
        return rv;
      v17 = endSel;
      if ( beginSel != endSel )
        goto LABEL_33;
      if ( SLOBYTE(this->Flags) < 0 )
        v17 = ++endSel;
      if ( beginSel == v17 )
      {
        v18 = this->pDocView.pObject;
        cmd.BeginPos = this->CursorPos;
        LOWORD(cmd.EndPos) = v2;
        v19 = Scaleform::Render::Text::DocView::EditCommand(v18, 0, &cmd);
      }
      else
      {
LABEL_33:
        v22 = this->pDocView.pObject;
        cmd.BeginPos = beginSel;
        cmd.EndPos = v17;
        cmd.CharCode = v2;
        v19 = Scaleform::Render::Text::DocView::EditCommand(v22, 5u, &cmd);
        CursorPos = beginSel;
        if ( beginSel >= v17 )
          CursorPos = v17;
      }
      CursorPos += v19;
      v16 = 1;
    }
    v20 = beginSel;
LABEL_25:
    if ( this->CursorPos != CursorPos || v20 != CursorPos || endSel != CursorPos )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPos, 0);
      rv = 1;
    }
    if ( v16 )
    {
      v21 = pdocument->pDocumentListener.pObject;
      if ( v21 )
        v21->Editor_OnChanged(v21, this);
    }
    return rv;
  }
  return 0;
}
