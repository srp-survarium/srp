void __thiscall Scaleform::GFx::StrokeStyleSwfReader::Read(
        Scaleform::GFx::StrokeStyleSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::Render::FillStyleType *tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v6; // eax
  unsigned int Pos; // eax
  unsigned __int16 v8; // cx
  Scaleform::Render::FillStyleType *v9; // esi
  __int16 U16; // bx
  unsigned int v11; // ebx
  Scaleform::Render::StrokeStyleType *StrokeStyle; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v14; // ecx
  unsigned int Raw; // eax
  Scaleform::Render::GradientData *v16; // eax
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *p_pFill; // esi
  signed int width; // [esp+10h] [ebp-Ch]
  Scaleform::Render::FillStyleType v20; // [esp+14h] [ebp-8h] BYREF
  float miterSize; // [esp+20h] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v6 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v6 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  miterSize = 3.0;
  v8 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v9 = tagType;
  U16 = 0;
  width = v8;
  if ( tagType == (Scaleform::Render::FillStyleType *)83 )
  {
    U16 = Scaleform::GFx::LoadProcess::ReadU16(p);
    if ( (U16 & 0x20) != 0 )
      miterSize = (double)(unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p) * 0.00390625;
  }
  v11 = Scaleform::GFx::StrokeStyleSwfReader::ConvertSwfLineStyles(U16);
  if ( (v11 & 8) != 0 )
  {
    v20.pFill.pObject = 0;
    tagType = &v20;
    Scaleform::GFx::FillStyleSwfReader::Read(
      (Scaleform::GFx::FillStyleSwfReader *)&tagType,
      p,
      (Scaleform::GFx::TagType)v9);
    this->StrokeStyle->Color = v20.Color;
    this->StrokeStyle->Miter = miterSize;
    StrokeStyle = this->StrokeStyle;
    this->StrokeStyle->Width = (float)width;
    if ( v20.pFill.pObject )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v20.pFill.pObject);
    pObject = (Scaleform::RefCountVImpl *)StrokeStyle->pFill.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    StrokeStyle->pFill.pObject = v20.pFill.pObject;
    v14 = (Scaleform::RefCountVImpl *)v20.pFill.pObject;
    if ( v20.pFill.pObject )
    {
      v16 = v20.pFill.pObject->pGradient.pObject;
      if ( !v16 || !v16->RecordCount )
      {
LABEL_19:
        if ( v14 )
          Scaleform::RefCountImpl::Release(v14);
        goto LABEL_24;
      }
      Raw = v16->pRecords->ColorV.Raw;
    }
    else
    {
      Raw = v20.Color;
    }
    this->StrokeStyle->Color = Raw;
    v14 = (Scaleform::RefCountVImpl *)v20.pFill.pObject;
    goto LABEL_19;
  }
  Scaleform::GFx::LoadProcess::ReadRgbaTag(p, (Scaleform::Render::Color *)&tagType, (Scaleform::GFx::TagType)v9);
  this->StrokeStyle->Color = (unsigned int)tagType;
  this->StrokeStyle->Miter = miterSize;
  v17 = (Scaleform::RefCountVImpl *)this->StrokeStyle->pFill.pObject;
  p_pFill = &this->StrokeStyle->pFill;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  p_pFill->pObject = 0;
  this->StrokeStyle->Width = (float)(unsigned int)width;
LABEL_24:
  this->StrokeStyle->Units = 0.050000001;
  this->StrokeStyle->Flags = v11;
}
