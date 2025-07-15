void __thiscall Scaleform::GFx::TextFieldDef::Read(
        Scaleform::GFx::TextFieldDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ecx
  bool v6; // bl
  int v7; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  unsigned int Id; // eax
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::ResourceHandle::HandleType HType; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // ecx
  int v14; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // ecx
  double v17; // st7
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // ecx
  int v19; // ecx
  unsigned int v20; // eax
  int v21; // ecx
  int v22; // eax
  unsigned int v23; // eax
  Scaleform::GFx::TextFieldDef::alignment v24; // edx
  int v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  unsigned int v28; // eax
  int v29; // eax
  unsigned int v30; // eax
  int v31; // eax
  unsigned int v32; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v33; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v34; // ecx
  bool hasFontClass; // [esp+53h] [ebp-Dh]
  bool hasColor; // [esp+54h] [ebp-Ch]
  bool hasMaxLength; // [esp+55h] [ebp-Bh]
  bool hasLayout; // [esp+56h] [ebp-Ah]
  bool hasText; // [esp+57h] [ebp-9h]
  Scaleform::GFx::ResourceHandle hres; // [esp+58h] [ebp-8h] BYREF

  if ( p->pAltStream )
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  else
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &this->TextRect);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v5);
  pAltStream->Stream.UnusedBits = 0;
  hasText = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 8u;
  else
    this->Flags &= ~8u;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)((this->Flags >> 3) & 1));
  hasColor = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  hasMaxLength = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  v6 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  hasFontClass = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x10u;
  else
    this->Flags &= ~0x10u;
  hasLayout = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags &= ~0x20u;
  else
    this->Flags |= 0x20u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x40u;
  else
    this->Flags &= ~0x40u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x1000u;
  else
    this->Flags &= ~0x1000u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x80u;
  else
    this->Flags &= ~0x80u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags &= ~0x100u;
  else
    this->Flags |= 0x100u;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)((this->Flags >> 6) & 1));
  if ( v6 )
  {
    v7 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v7 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    Pos = pAltStream->Stream.Pos;
    v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
    pAltStream->Stream.Pos = Pos + 2;
    this->FontId.Id = (unsigned __int16)v9;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v9);
    Id = this->FontId.Id;
    hres.HType = RH_Pointer;
    hres.BindIndex = 0;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
      p->pLoadData.pObject,
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&hres,
      (Scaleform::GFx::ResourceId)Id);
    pResource = hres.pResource;
    if ( hres.HType == RH_Pointer && hres.BindIndex )
    {
      Scaleform::RefCountImpl::AddRef(hres.pResource);
      pResource = hres.pResource;
    }
    if ( this->pFont.HType == RH_Pointer && this->pFont.BindIndex )
    {
      Scaleform::GFx::Resource::Release(this->pFont.pResource);
      pResource = hres.pResource;
    }
    HType = hres.HType;
    this->pFont.HType = hres.HType;
    this->pFont.BindIndex = (unsigned int)pResource;
    if ( HType == RH_Pointer && pResource )
      Scaleform::GFx::Resource::Release(pResource);
  }
  else
  {
    if ( !hasFontClass )
      goto LABEL_51;
    Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->FontClass);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v13);
  }
  v14 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v14 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v15 = pAltStream->Stream.Pos;
  v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v15];
  pAltStream->Stream.Pos = v15 + 2;
  *(float *)&hres.HType = (float)(unsigned __int16)v16;
  v17 = *(float *)&hres.HType;
  this->TextHeight = *(float *)&hres.HType;
  *(float *)&hres.HType = v17 * 0.05000000074505806;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v16);
LABEL_51:
  if ( hasColor )
  {
    Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, &this->ColorV);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v18);
  }
  if ( hasMaxLength )
  {
    v19 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v19 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v20 = pAltStream->Stream.Pos;
    v21 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v20];
    pAltStream->Stream.Pos = v20 + 2;
    this->MaxLength = v21;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v21);
  }
  if ( hasLayout )
  {
    this->Flags |= 0x200u;
    v22 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v22 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    v23 = pAltStream->Stream.Pos;
    v24 = pAltStream->Stream.pBuffer[v23];
    pAltStream->Stream.Pos = v23 + 1;
    this->Alignment = v24;
    v25 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v25 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v26 = pAltStream->Stream.Pos;
    hres.HType = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v26];
    pAltStream->Stream.Pos = v26 + 2;
    this->LeftMargin = (float)hres.HType;
    v27 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v27 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v28 = pAltStream->Stream.Pos;
    hres.HType = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v28];
    pAltStream->Stream.Pos = v28 + 2;
    this->RightMargin = (float)hres.HType;
    v29 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v29 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v30 = pAltStream->Stream.Pos;
    hres.HType = *(__int16 *)&pAltStream->Stream.pBuffer[v30];
    pAltStream->Stream.Pos = v30 + 2;
    this->Indent = (float)hres.HType;
    v31 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v31 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v32 = pAltStream->Stream.Pos;
    v33 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v32];
    pAltStream->Stream.Pos = v32 + 2;
    *(float *)&hres.HType = (float)(__int16)v33;
    this->Leading = *(float *)&hres.HType;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v33);
  }
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->VariableName);
  if ( hasText )
    Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->DefaultText);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v34);
}
