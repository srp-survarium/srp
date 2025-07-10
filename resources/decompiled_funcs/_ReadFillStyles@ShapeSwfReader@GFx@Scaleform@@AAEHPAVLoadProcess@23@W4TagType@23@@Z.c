Scaleform::GFx::AS3::RefCountBaseGC<328> *__thiscall Scaleform::GFx::ShapeSwfReader::ReadFillStyles(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v6; // eax
  unsigned int Pos; // eax
  unsigned __int8 v8; // cl
  Scaleform::GFx::LoadProcess *U16; // esi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  unsigned int Size; // edi
  unsigned int v12; // edi
  Scaleform::GFx::SWFProcessInfo *v13; // eax
  Scaleform::Render::FillStyleType *FillStyle; // esi
  Scaleform::Render::ComplexFill *pObject; // eax
  Scaleform::Render::ComplexFill *v16; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *off; // [esp+10h] [ebp-8h]
  Scaleform::GFx::FillStyleSwfReader fr; // [esp+14h] [ebp-4h] BYREF
  Scaleform::GFx::LoadProcess *pa; // [esp+1Ch] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v6 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v6 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  v8 = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  U16 = (Scaleform::GFx::LoadProcess *)v8;
  if ( tagType > Tag_DefineShape && v8 == 255 )
    U16 = (Scaleform::GFx::LoadProcess *)(unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p);
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  off = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(p_ProcessInfo->Stream.Pos
                                                   + p_ProcessInfo->Stream.FilePos
                                                   - p_ProcessInfo->Stream.DataSize);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(off);
  Size = this->FillStyles.Data.Size;
  if ( U16 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->FillStyles,
      (unsigned int)U16 + Size);
    v12 = Size;
    pa = U16;
    do
    {
      v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !v13 )
        v13 = &p->ProcessInfo;
      v13->Stream.UnusedBits = 0;
      fr.FillStyle = &this->FillStyles.Data.Data[v12];
      FillStyle = fr.FillStyle;
      Scaleform::GFx::FillStyleSwfReader::Read(&fr, p, tagType);
      pObject = FillStyle->pFill.pObject;
      if ( pObject && (pObject->pImage.pObject || pObject->BindIndex != -1) )
        this->Shape->Flags |= 1u;
      v16 = FillStyle->pFill.pObject;
      if ( v16 && v16->BindIndex != -1 )
        this->Shape->Flags |= 4u;
      ++v12;
      pa = (Scaleform::GFx::LoadProcess *)((char *)pa - 1);
    }
    while ( pa );
  }
  return off;
}
