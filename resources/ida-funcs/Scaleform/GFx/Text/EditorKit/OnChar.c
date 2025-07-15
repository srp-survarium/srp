char __thiscall Scaleform::GFx::Text::EditorKit::OnChar(Scaleform::GFx::Text::EditorKit *this, int wcharCode)
{
  int v2; // ebp
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // ecx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *IteratorAt; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *v9; // eax
  int v10; // ecx
  Scaleform::Render::Text::DocView *v12; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *BeginSelection; // edx
  unsigned int EndSelection; // ecx
  unsigned int CursorPos; // edi
  char v16; // bl
  unsigned int v17; // ebx
  Scaleform::Render::Text::DocView *v18; // ecx
  unsigned int v19; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *pArray; // ebp
  Scaleform::Render::Text::DocView::DocumentListener *v21; // ecx
  Scaleform::Render::Text::DocView *v22; // ecx
  Scaleform::Render::Text::DocView *v23; // ecx
  char v24; // al
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v25; // edx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v26; // edi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v27; // [esp+8h] [ebp-18h]
  Scaleform::Render::Text::DocView *v28; // [esp+10h] [ebp-10h]
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+14h] [ebp-Ch] BYREF
  __int16 v30; // [esp+1Ch] [ebp-4h]
  char index; // [esp+24h] [ebp+4h]

  LOWORD(v2) = wcharCode;
  if ( wcharCode && (this->Flags & 0x20) == 0 )
  {
    pObject = this->pRestrict.pObject;
    if ( pObject )
    {
      IteratorAt = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
                     &pObject->RestrictRanges,
                     &result,
                     wcharCode);
      v6 = IteratorAt->Index;
      if ( v6 < 0 || v6 >= IteratorAt->pArray->Ranges.Data.Size )
      {
        v7 = Scaleform::SFtowupper(wcharCode);
        v8 = Scaleform::SFtowlower(wcharCode);
        v2 = v7;
        if ( wcharCode == v7 )
          v2 = v8;
        v9 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
               &this->pRestrict.pObject->RestrictRanges,
               &result,
               v2);
        v10 = v9->Index;
        if ( v10 < 0 || v10 >= v9->pArray->Ranges.Data.Size )
          return 0;
      }
    }
    v12 = this->pDocView.pObject;
    BeginSelection = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v12->BeginSelection;
    EndSelection = v12->EndSelection;
    CursorPos = this->CursorPos;
    v28 = v12;
    index = 0;
    v27.pArray = BeginSelection;
    if ( (unsigned int)BeginSelection >= EndSelection )
      v27.pArray = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v12->EndSelection;
    v27.Index = v12->BeginSelection;
    if ( EndSelection >= (unsigned int)BeginSelection )
      v27.Index = v12->EndSelection;
    v16 = 0;
    if ( this->IsReadOnly(this) )
      return index;
    if ( (_WORD)v2 == 13 )
    {
      v23 = this->pDocView.pObject;
      if ( (v23->Flags & 4) != 0 )
      {
        pArray = v27.pArray;
        this->Flags &= ~0x40u;
        v24 = v23->pDocument.pObject->RTFlags & 2;
        if ( v27.pArray == (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v27.Index )
        {
          v25 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this->CursorPos;
          LOWORD(result.Index) = (unsigned __int8)(v24 != 0 ? 13 : 10);
          result.pArray = v25;
          Scaleform::Render::Text::DocView::EditCommand(v23, 0, &result);
          ++CursorPos;
          v16 = 1;
        }
        else
        {
          v30 = (unsigned __int8)(v24 != 0 ? 13 : 10);
          result = v27;
          Scaleform::Render::Text::DocView::EditCommand(v23, 5u, &result);
          v26 = v27.pArray;
          if ( v27.pArray >= (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v27.Index )
            v26 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v27.Index;
          CursorPos = (unsigned int)&v26->Ranges.Data.Data + 1;
          v16 = 1;
        }
        goto LABEL_25;
      }
    }
    else
    {
      if ( (unsigned __int16)v2 < 0x20u )
        return index;
      v17 = v27.Index;
      if ( v27.pArray != (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v27.Index )
        goto LABEL_33;
      if ( SLOBYTE(this->Flags) < 0 )
        v17 = ++v27.Index;
      if ( v27.pArray == (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v17 )
      {
        v18 = this->pDocView.pObject;
        result.pArray = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)this->CursorPos;
        LOWORD(result.Index) = v2;
        v19 = Scaleform::Render::Text::DocView::EditCommand(v18, 0, &result);
      }
      else
      {
LABEL_33:
        v22 = this->pDocView.pObject;
        result.pArray = v27.pArray;
        result.Index = v17;
        v30 = v2;
        v19 = Scaleform::Render::Text::DocView::EditCommand(v22, 5u, &result);
        CursorPos = (unsigned int)v27.pArray;
        if ( v27.pArray >= (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v17 )
          CursorPos = v17;
      }
      CursorPos += v19;
      v16 = 1;
    }
    pArray = v27.pArray;
LABEL_25:
    if ( this->CursorPos != CursorPos
      || pArray != (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)CursorPos
      || v27.Index != CursorPos )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPos, 0);
      index = 1;
    }
    if ( v16 )
    {
      v21 = v28->pDocumentListener.pObject;
      if ( v21 )
        v21->Editor_OnChanged(v21, this);
    }
    return index;
  }
  return 0;
}
