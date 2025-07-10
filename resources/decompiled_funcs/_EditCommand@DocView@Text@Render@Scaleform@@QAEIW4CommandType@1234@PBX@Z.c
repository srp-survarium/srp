unsigned int __thiscall Scaleform::Render::Text::DocView::EditCommand(
        Scaleform::Render::Text::DocView *this,
        unsigned int cmdId,
        void *command)
{
  int v3; // edi
  const wchar_t **v6; // ebx
  unsigned int v7; // edi
  unsigned int Length; // eax
  unsigned int MaxLength; // ecx
  Scaleform::Render::Text::StyledText **v10; // ebx
  unsigned int v11; // ebp
  unsigned int v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  const wchar_t *v15; // edx
  unsigned int v16; // ebp
  unsigned int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned int inserted; // edi
  const void *v22; // edi
  unsigned int v23; // ebx
  unsigned int v24; // ebp
  bool v25; // zf
  unsigned int v26; // eax
  unsigned int v27; // edx
  unsigned int v28; // ecx
  unsigned int v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // edi
  unsigned int v32; // ebx
  unsigned int v33; // eax
  unsigned int v34; // ecx
  unsigned int v35; // edi
  unsigned int v36; // ebp
  unsigned int v37; // edi
  unsigned int v38; // edi
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  Scaleform::Render::Text::Paragraph *pPara; // ebp
  const Scaleform::Render::Text::ParagraphFormat *v41; // ebx
  Scaleform::Render::Text::Allocator *Allocator; // eax
  unsigned int v43; // edi
  unsigned int v44; // ebx
  unsigned int v45; // [esp-10h] [ebp-38h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+8h] [ebp-20h] BYREF
  Scaleform::Render::Text::ParagraphFormat newFmt; // [esp+10h] [ebp-18h] BYREF

  v3 = 0;
  switch ( cmdId )
  {
    case 0u:
      if ( this->MaxLength
        && Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject) + 1 > this->MaxLength )
      {
        return v3;
      }
      return Scaleform::Render::Text::StyledText::InsertString(
               this->pDocument.pObject,
               (const wchar_t *)command + 2,
               *(_DWORD *)command,
               1u,
               NLP_ReplaceCRLF);
    case 1u:
      v6 = (const wchar_t **)command;
      v7 = *((_DWORD *)command + 2);
      Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
      MaxLength = this->MaxLength;
      if ( MaxLength && Length + v7 > MaxLength )
        v7 = MaxLength - Length;
      return Scaleform::Render::Text::StyledText::InsertString(
               this->pDocument.pObject,
               v6[1],
               (unsigned int)*v6,
               v7,
               (this->Flags & 4) != 0 ? NLP_CompressCRLF : NLP_IgnoreCRLF);
    case 2u:
      v10 = (Scaleform::Render::Text::StyledText **)command;
      v11 = -1;
      if ( this->MaxLength )
      {
        v12 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
        v13 = Scaleform::Render::Text::StyledText::GetLength(v10[1]);
        v14 = this->MaxLength;
        if ( v12 + v13 > v14 )
          v11 = v14 - v12;
      }
      return Scaleform::Render::Text::StyledText::InsertStyledText(
               this->pDocument.pObject,
               v10[1],
               (unsigned int)*v10,
               v11);
    case 3u:
      Scaleform::Render::Text::DocView::RemoveText(this, *(_DWORD *)command, *(_DWORD *)command + 1);
      return 1;
    case 4u:
      v43 = *((_DWORD *)command + 1);
      if ( *(_DWORD *)command <= v43 )
      {
        v44 = *(_DWORD *)command;
      }
      else
      {
        v44 = *((_DWORD *)command + 1);
        v43 = *(_DWORD *)command;
      }
      Scaleform::Render::Text::DocView::RemoveText(this, v44, v43);
      return v43 - v44;
    case 5u:
      v15 = (const wchar_t *)command;
      v16 = *((_DWORD *)command + 1);
      if ( *(_DWORD *)command <= v16 )
      {
        v17 = *(_DWORD *)command;
      }
      else
      {
        v17 = *((_DWORD *)command + 1);
        v16 = *(_DWORD *)command;
      }
      if ( !this->MaxLength )
        goto LABEL_23;
      v18 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
      v19 = v16;
      if ( v16 >= v18 )
        v19 = v18;
      v20 = v17;
      if ( v17 >= v18 )
        v20 = v18;
      if ( v20 - v19 + v18 + 1 > this->MaxLength )
        return v3;
      v15 = (const wchar_t *)command;
LABEL_23:
      inserted = Scaleform::Render::Text::StyledText::InsertString(
                   this->pDocument.pObject,
                   v15 + 4,
                   v17,
                   1u,
                   (this->Flags & 4) != 0 ? NLP_CompressCRLF : NLP_IgnoreCRLF);
      Scaleform::Render::Text::DocView::RemoveText(this, v17 + 1, v16 + 1);
      return inserted;
    case 6u:
      v22 = command;
      if ( *(_DWORD *)command <= *((_DWORD *)command + 1) )
      {
        v23 = *(_DWORD *)command;
        v24 = *((_DWORD *)command + 1);
      }
      else
      {
        v23 = *((_DWORD *)command + 1);
        v24 = *(_DWORD *)command;
      }
      v25 = this->MaxLength == 0;
      cmdId = *((_DWORD *)command + 3);
      if ( !v25 )
      {
        v26 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
        v27 = v24;
        if ( v24 >= v26 )
          v27 = v26;
        v28 = v23;
        if ( v23 >= v26 )
          v28 = v26;
        v29 = v28 - v27 + v26;
        v30 = this->MaxLength;
        if ( v29 + *((_DWORD *)v22 + 3) > v30 )
          cmdId = v30 - v29;
      }
      v31 = Scaleform::Render::Text::StyledText::InsertString(
              this->pDocument.pObject,
              *((const wchar_t **)v22 + 2),
              v23,
              cmdId,
              (this->Flags & 4) != 0 ? NLP_CompressCRLF : NLP_IgnoreCRLF);
      Scaleform::Render::Text::DocView::RemoveText(this, v31 + v23, v31 + v24);
      return v31;
    case 7u:
      if ( *(_DWORD *)command <= *((_DWORD *)command + 1) )
      {
        v32 = *(_DWORD *)command;
        cmdId = *((_DWORD *)command + 1);
      }
      else
      {
        v32 = *((_DWORD *)command + 1);
        cmdId = *(_DWORD *)command;
      }
      paraIter.pArray = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)-1;
      if ( this->MaxLength )
      {
        v33 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
        v34 = cmdId;
        v35 = v33;
        if ( cmdId >= v33 )
          v34 = v33;
        if ( v32 < v33 )
          v33 = v32;
        v36 = this->MaxLength;
        v37 = v33 - v34 + v35;
        if ( v37
           + Scaleform::Render::Text::StyledText::GetLength(*((Scaleform::Render::Text::StyledText **)command + 2)) > v36 )
          paraIter.pArray = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)(this->MaxLength - v37);
      }
      v38 = Scaleform::Render::Text::StyledText::InsertStyledText(
              this->pDocument.pObject,
              *((const Scaleform::Render::Text::StyledText **)command + 2),
              v32,
              (unsigned int)paraIter.pArray);
      Scaleform::Render::Text::DocView::RemoveText(this, v38 + v32, v38 + cmdId);
      return v38;
    case 8u:
      v45 = *(_DWORD *)command;
      pObject = this->pDocument.pObject;
      cmdId = 0;
      Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &paraIter, v45, &cmdId);
      if ( Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>>::Iterator::IsFinished(&paraIter) )
        goto LABEL_56;
      if ( cmdId )
        goto LABEL_56;
      pPara = paraIter.pArray->Data.Data[paraIter.CurIndex].pPara;
      v41 = pPara->pFormat.pObject;
      if ( !v41 )
        goto LABEL_56;
      if ( Scaleform::Render::Text::ParagraphFormat::IsBullet(pPara->pFormat.pObject) )
      {
        Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(&newFmt, v41);
        newFmt.PresentMask = newFmt.PresentMask & 0x7F7F | 0x80;
LABEL_51:
        Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this->pDocument.pObject);
        Scaleform::Render::Text::Paragraph::SetFormat(pPara, Allocator, &newFmt);
        this->OnDocumentChanged(this, 2u);
        Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&newFmt);
        return 0;
      }
      if ( v41->Indent || v41->BlockIndent )
      {
        Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(&newFmt, v41);
        newFmt.Indent = 0;
        newFmt.BlockIndent = 0;
        newFmt.PresentMask |= 6u;
        goto LABEL_51;
      }
LABEL_56:
      if ( !*(_DWORD *)command )
        return 0;
      Scaleform::Render::Text::DocView::RemoveText(this, *(_DWORD *)command - 1, *(_DWORD *)command);
      return 1;
    default:
      return v3;
  }
}
