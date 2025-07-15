int __thiscall Scaleform::GFx::Text::EditorKit::PasteFromClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::String::DataDesc *startPos,
        Scaleform::String endPos,
        unsigned int useRichClipboard)
{
  int v5; // ebx
  Scaleform::GFx::TextClipboard *pObject; // ecx
  Scaleform::String::DataDesc *pData; // ebp
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v8; // edi
  Scaleform::Render::Text::StyledText *v9; // eax
  Scaleform::RefCountNTSImpl *v10; // ebp
  Scaleform::Render::Text::DocView *v11; // ecx
  unsigned int v12; // eax
  const Scaleform::WStringBuffer *v13; // eax
  unsigned int Length; // ecx
  wchar_t *pText; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  Scaleform::Render::Text::DocView *v18; // ecx
  unsigned int v19; // edi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v20; // ebp
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *CharAt; // edi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *IteratorAt; // eax
  int Index; // ecx
  int v24; // eax
  bool v25; // zf
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v26; // edi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *v27; // eax
  int v28; // ecx
  Scaleform::Render::Text::DocView *v29; // ecx
  Scaleform::Render::Text::DocView *v30; // ecx
  void *v31; // esi
  _DWORD v33[2]; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v34; // [esp+10h] [ebp-24h] BYREF
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator v35; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::RefCountNTSImpl *v36; // [esp+20h] [ebp-14h]
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v37; // [esp+24h] [ebp-10h] BYREF
  Scaleform::String::DataDesc *v38; // [esp+28h] [ebp-Ch]
  wchar_t *v39; // [esp+2Ch] [ebp-8h]
  unsigned int v40; // [esp+30h] [ebp-4h]

  v5 = -1;
  if ( this->IsReadOnly(this) )
    return -1;
  pObject = this->pClipboard.pObject;
  if ( !pObject )
    return -1;
  pData = endPos.pData;
  v8 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)startPos;
  if ( endPos.HeapTypeBits < (unsigned int)startPos )
  {
    endPos.pData = startPos;
    v8 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)pData;
    pData = startPos;
  }
  if ( (_BYTE)useRichClipboard && pObject->ContainsRichText(pObject) )
  {
    v9 = this->pClipboard.pObject->GetStyledText(this->pClipboard.pObject);
    v10 = v9;
    if ( v9 )
    {
      ++v9->RefCount;
      if ( Scaleform::Render::Text::StyledText::GetLength(v9) )
      {
        v11 = this->pDocView.pObject;
        this->Flags &= ~0x40u;
        if ( v8 == (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)endPos.pData )
        {
          v33[0] = v8;
          v33[1] = v10;
          v12 = Scaleform::Render::Text::DocView::EditCommand(v11, 2u, v33);
        }
        else
        {
          v35.Index = (int)endPos.pData;
          v35.pArray = v8;
          v36 = v10;
          v12 = Scaleform::Render::Text::DocView::EditCommand(v11, 7u, &v35);
        }
        v5 = (int)v8 + v12;
      }
      Scaleform::RefCountNTSImpl::Release(v10);
    }
  }
  else
  {
    v13 = this->pClipboard.pObject->GetText(this->pClipboard.pObject);
    if ( v13->Length )
    {
      this->Flags &= ~0x40u;
      Length = v13->Length;
      pText = v13->pText;
      if ( v8 == (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)pData )
      {
        if ( !pText )
          pText = (wchar_t *)&unk_6E53BC;
        v35.pArray = v8;
        v35.Index = (int)pText;
        v36 = (Scaleform::RefCountNTSImpl *)Length;
        v16 = Scaleform::Render::Text::DocView::EditCommand(this->pDocView.pObject, 1u, &v35);
      }
      else
      {
        if ( !pText )
          pText = (wchar_t *)&unk_6E53BC;
        v39 = pText;
        v37 = v8;
        v38 = pData;
        v40 = Length;
        v16 = Scaleform::Render::Text::DocView::EditCommand(this->pDocView.pObject, 6u, &v37);
      }
      v5 = (int)v8 + v16;
    }
  }
  if ( this->pRestrict.pObject )
  {
    v17 = Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject);
    v18 = this->pDocView.pObject;
    v19 = v17;
    v33[0] = v17;
    Scaleform::Render::Text::DocView::GetText(v18, &endPos);
    v20 = 0;
    useRichClipboard = 0;
    if ( v19 )
    {
      do
      {
        CharAt = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)Scaleform::String::GetCharAt(&endPos, useRichClipboard);
        IteratorAt = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
                       &this->pRestrict.pObject->RestrictRanges,
                       &v34,
                       (int)CharAt);
        Index = IteratorAt->Index;
        if ( Index < 0 || Index >= IteratorAt->pArray->Ranges.Data.Size )
        {
          startPos = (Scaleform::String::DataDesc *)Scaleform::SFtowupper((int)CharAt);
          v24 = Scaleform::SFtowlower((int)CharAt);
          v25 = CharAt == (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)startPos;
          v26 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)startPos;
          if ( v25 )
            v26 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v24;
          v27 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
                  &this->pRestrict.pObject->RestrictRanges,
                  &v35,
                  (int)v26);
          v28 = v27->Index;
          if ( v28 >= 0 && v28 < v27->pArray->Ranges.Data.Size )
          {
            v38 = (Scaleform::String::DataDesc *)((char *)&v20->Ranges.Data.Data + 1);
            v30 = this->pDocView.pObject;
            v37 = v20;
            LOWORD(v39) = (_WORD)v26;
            Scaleform::Render::Text::DocView::EditCommand(v30, 5u, &v37);
          }
          else
          {
            v29 = this->pDocView.pObject;
            startPos = (Scaleform::String::DataDesc *)v20;
            Scaleform::Render::Text::DocView::EditCommand(v29, 3u, &startPos);
            v20 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)((char *)v20 - 1);
          }
        }
        v20 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)((char *)v20 + 1);
        ++useRichClipboard;
      }
      while ( useRichClipboard < v33[0] );
    }
    v31 = (void *)(endPos.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((endPos.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
  }
  return v5;
}
