int __thiscall Scaleform::GFx::Text::EditorKit::PasteFromClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *startPos,
        Scaleform::String endPos,
        unsigned int useRichClipboard)
{
  int v5; // ebx
  Scaleform::GFx::TextClipboard *pObject; // ecx
  unsigned int HeapTypeBits; // ebp
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v8; // edi
  Scaleform::Render::Text::StyledText *v9; // eax
  Scaleform::RefCountNTSImpl *v10; // ebp
  Scaleform::Render::Text::DocView *v11; // ecx
  unsigned int v12; // eax
  const Scaleform::WStringBuffer *v13; // eax
  unsigned int Length; // ecx
  const wchar_t *pText; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  Scaleform::Render::Text::DocView *v18; // ecx
  unsigned int v19; // edi
  unsigned int v20; // ebp
  int CharAt; // edi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *IteratorAt; // eax
  int Index; // ecx
  int v24; // eax
  bool v25; // zf
  int v26; // edi
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *v27; // eax
  int v28; // ecx
  Scaleform::Render::Text::DocView *v29; // ecx
  Scaleform::Render::Text::DocView *v30; // ecx
  void *v31; // esi
  unsigned int l[2]; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+10h] [ebp-24h] BYREF
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator command; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::RefCountNTSImpl *v36; // [esp+20h] [ebp-14h]
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v37; // [esp+24h] [ebp-10h] BYREF
  unsigned int v38; // [esp+28h] [ebp-Ch]
  const wchar_t *v39; // [esp+2Ch] [ebp-8h]
  unsigned int v40; // [esp+30h] [ebp-4h]

  v5 = -1;
  if ( this->IsReadOnly(this) )
    return -1;
  pObject = this->pClipboard.pObject;
  if ( !pObject )
    return -1;
  HeapTypeBits = endPos.HeapTypeBits;
  v8 = startPos;
  if ( endPos.HeapTypeBits < (unsigned int)startPos )
  {
    endPos.pData = (Scaleform::String::DataDesc *)startPos;
    v8 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)HeapTypeBits;
    HeapTypeBits = (unsigned int)startPos;
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
          l[0] = (unsigned int)v8;
          l[1] = (unsigned int)v10;
          v12 = Scaleform::Render::Text::DocView::EditCommand(v11, 2u, l);
        }
        else
        {
          command.Index = (int)endPos.pData;
          command.pArray = v8;
          v36 = v10;
          v12 = Scaleform::Render::Text::DocView::EditCommand(v11, 7u, &command);
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
      if ( v8 == (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)HeapTypeBits )
      {
        if ( !pText )
          pText = &word_96B534;
        command.pArray = v8;
        command.Index = (int)pText;
        v36 = (Scaleform::RefCountNTSImpl *)Length;
        v16 = Scaleform::Render::Text::DocView::EditCommand(this->pDocView.pObject, 1u, &command);
      }
      else
      {
        if ( !pText )
          pText = &word_96B534;
        v39 = pText;
        v37 = v8;
        v38 = HeapTypeBits;
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
    l[0] = v17;
    Scaleform::Render::Text::DocView::GetText(v18, &endPos);
    v20 = 0;
    useRichClipboard = 0;
    if ( v19 )
    {
      do
      {
        CharAt = Scaleform::String::GetCharAt(&endPos, useRichClipboard);
        IteratorAt = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
                       &this->pRestrict.pObject->RestrictRanges,
                       &result,
                       CharAt);
        Index = IteratorAt->Index;
        if ( Index < 0 || Index >= IteratorAt->pArray->Ranges.Data.Size )
        {
          startPos = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)Scaleform::SFtowupper(CharAt);
          v24 = Scaleform::SFtowlower(CharAt);
          v25 = CharAt == (_DWORD)startPos;
          v26 = (int)startPos;
          if ( v25 )
            v26 = v24;
          v27 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
                  &this->pRestrict.pObject->RestrictRanges,
                  &command,
                  v26);
          v28 = v27->Index;
          if ( v28 >= 0 && v28 < v27->pArray->Ranges.Data.Size )
          {
            v38 = v20 + 1;
            v30 = this->pDocView.pObject;
            v37 = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v20;
            LOWORD(v39) = v26;
            Scaleform::Render::Text::DocView::EditCommand(v30, 5u, &v37);
          }
          else
          {
            v29 = this->pDocView.pObject;
            startPos = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)v20;
            Scaleform::Render::Text::DocView::EditCommand(v29, 3u, &startPos);
            --v20;
          }
        }
        ++v20;
        ++useRichClipboard;
      }
      while ( useRichClipboard < l[0] );
    }
    v31 = (void *)(endPos.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((endPos.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
  }
  return v5;
}
