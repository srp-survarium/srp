void __thiscall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::RangeData<void *> *range)
{
  unsigned int Size; // edi
  int Index; // ebx
  int NearestRangeIndex; // eax
  int v6; // edi
  int v7; // ebp
  int v8; // eax
  Scaleform::RangeData<void *> *v9; // ecx
  signed int v10; // edx
  signed int v11; // eax
  Scaleform::RangeData<void *> *v12; // ebp
  int v13; // eax
  unsigned int v14; // edx
  signed int v15; // eax
  int v16; // ebx
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *pArray; // ebx
  unsigned int Length; // edx
  int v19; // ebx
  int v20; // ebp
  int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  Scaleform::RangeData<void *> *v24; // eax
  int v25; // ebp
  signed int v26; // edi
  int v27; // ecx
  unsigned int v28; // esi
  Scaleform::RangeData<void *> *v29; // eax
  int v30; // ecx
  signed int v31; // eax
  unsigned int v32; // esi
  Scaleform::RangeData<void *> *v33; // ecx
  Scaleform::RangeData<void *> *v34; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator insertionPoint; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator it; // [esp+10h] [ebp-14h] BYREF
  Scaleform::RangeData<void *> r; // [esp+18h] [ebp-Ch] BYREF

  Size = this->Ranges.Data.Size;
  if ( !Size )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Ranges,
      0,
      range);
    return;
  }
  Index = range->Index;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        (Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *)this,
                        range->Index);
  it.pArray = this;
  if ( NearestRangeIndex >= 0 )
  {
    if ( NearestRangeIndex < Size )
      v6 = NearestRangeIndex;
    else
      v6 = Size - 1;
  }
  else
  {
    v6 = 0;
  }
  v7 = v6;
  v8 = this->Ranges.Data.Data[v6].Index;
  v9 = &this->Ranges.Data.Data[v6];
  it.Index = v6;
  if ( Index < v8
    || (insertionPoint.pArray = (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)(Index + range->Length),
        (int)&insertionPoint.pArray[-1].Ranges.Data.Policy.Capacity + 3 > (signed int)(v9->Length + v8 - 1)) )
  {
    if ( Index < v9->Index || (Length = v9->Length, Index > (int)(Length + v9->Index - 1)) )
    {
      if ( (int)Scaleform::Range::CompareTo(v9, Index) <= 0 )
      {
        v19 = v6 + 1;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          &this->Ranges,
          v6 + 1,
          range);
        if ( v6 < (signed int)this->Ranges.Data.Size )
        {
          ++v6;
          it.Index = v19;
        }
        goto LABEL_37;
      }
      goto LABEL_34;
    }
    if ( v9->Index + Length - Index <= Length )
      v9->Length = Index - v9->Index;
    else
      v9->Length = 0;
    if ( v6 < (signed int)this->Ranges.Data.Size )
      it.Index = ++v6;
LABEL_24:
    pArray = it.pArray;
    insertionPoint.pArray = it.pArray;
    insertionPoint.Index = v6;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Ranges,
      v6,
      range);
    goto LABEL_38;
  }
  if ( v9->Index != Index )
  {
    if ( (signed int)(v9->Index + v9->Length) > (int)insertionPoint.pArray )
    {
      v13 = v9->Index;
      r.Length = v9->Length;
      v14 = v9->Index + r.Length - Index;
      r.Index = v13;
      r.Data = v9->Data;
      Scaleform::Range::ShrinkRange(v9, v14);
      v15 = range->Length + this->Ranges.Data.Data[v7].Length;
      if ( v15 > (int)r.Length )
        v15 = r.Length;
      r.Index += v15;
      r.Length -= v15;
      v16 = v6 + 1;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        &this->Ranges,
        v6 + 1,
        range);
      if ( v6 < (signed int)this->Ranges.Data.Size )
      {
        ++v6;
        it.Index = v16;
      }
      pArray = it.pArray;
      insertionPoint.pArray = it.pArray;
      insertionPoint.Index = v6;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        &this->Ranges,
        v6 + 1,
        &r);
      if ( v6 >= (signed int)this->Ranges.Data.Size )
        goto LABEL_41;
      ++v6;
      goto LABEL_40;
    }
    Scaleform::Range::ShrinkRange(v9, range->Length);
    if ( v6 < (signed int)this->Ranges.Data.Size )
      it.Index = ++v6;
    goto LABEL_24;
  }
  v10 = range->Length;
  v11 = v9->Length;
  if ( v10 > v11 )
    v10 = v9->Length;
  v9->Index += v10;
  v9->Length = v11 - v10;
  v12 = &this->Ranges.Data.Data[v7];
  if ( v12->Length )
  {
LABEL_34:
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Ranges,
      v6,
      range);
    goto LABEL_37;
  }
  *v12 = *range;
LABEL_37:
  pArray = it.pArray;
  insertionPoint.pArray = it.pArray;
  insertionPoint.Index = v6;
LABEL_38:
  if ( v6 < (signed int)this->Ranges.Data.Size )
  {
    ++v6;
LABEL_40:
    it.Index = v6;
  }
LABEL_41:
  if ( !Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished((Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> >::Iterator *)&it) )
  {
    v20 = v6;
    do
    {
      v21 = this->Ranges.Data.Data[v6].Index;
      if ( v21 < range->Index
        || (signed int)(this->Ranges.Data.Data[v20].Length + v21 - 1) > (signed int)(range->Length + range->Index - 1) )
      {
        break;
      }
      if ( v6 >= 0 && v6 < this->Ranges.Data.Size )
      {
        v22 = this->Ranges.Data.Size;
        if ( v22 == 1 )
        {
          Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            &this->Ranges.Data,
            0);
        }
        else
        {
          memmove(
            (unsigned __int8 *)&this->Ranges.Data.Data[v20],
            (unsigned __int8 *)&this->Ranges.Data.Data[v20 + 1],
            12 * (v22 - v6 - 1));
          --this->Ranges.Data.Size;
        }
      }
    }
    while ( !Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished((Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> >::Iterator *)&it) );
  }
  if ( v6 >= 0 && v6 < this->Ranges.Data.Size )
  {
    v23 = range->Length;
    v24 = &this->Ranges.Data.Data[v6];
    v25 = v23 + range->Index - 1;
    if ( v25 >= v24->Index )
    {
      v26 = v24->Length;
      if ( v25 <= v26 + v24->Index - 1 )
      {
        v27 = range->Index + v23 - v24->Index;
        if ( v27 > v26 )
          v27 = v24->Length;
        v24->Index += v27;
        v24->Length = v26 - v27;
      }
    }
  }
  it.Index = insertionPoint.Index;
  if ( insertionPoint.Index >= 0 )
  {
    v28 = insertionPoint.Index - 1;
    if ( insertionPoint.Index - 1 >= 0 && v28 < pArray->Ranges.Data.Size )
    {
      v29 = &pArray->Ranges.Data.Data[v28];
      if ( v29->Length )
      {
        if ( v29->Index + v29->Length == range->Index
          && v29->Data == pArray->Ranges.Data.Data[insertionPoint.Index].Data )
        {
          v29->Length += range->Length;
          Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(&insertionPoint);
          insertionPoint.Index = v28;
        }
      }
      else
      {
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &pArray->Ranges,
          --insertionPoint.Index);
      }
    }
  }
  v30 = pArray->Ranges.Data.Size;
  v31 = insertionPoint.Index;
  it.pArray = pArray;
  it.Index = insertionPoint.Index;
  if ( insertionPoint.Index < v30 )
  {
    v31 = insertionPoint.Index + 1;
    it.Index = insertionPoint.Index + 1;
  }
  if ( v31 >= 0 && v31 < (unsigned int)v30 )
  {
    v32 = pArray->Ranges.Data.Data[v31].Length;
    v33 = &pArray->Ranges.Data.Data[v31];
    if ( v32 )
    {
      v34 = &pArray->Ranges.Data.Data[insertionPoint.Index];
      if ( v34->Index + v34->Length == v33->Index && v34->Data == v33->Data )
      {
        v34->Length += v32;
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(&it);
      }
    }
    else
    {
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &pArray->Ranges,
        v31);
    }
  }
}
