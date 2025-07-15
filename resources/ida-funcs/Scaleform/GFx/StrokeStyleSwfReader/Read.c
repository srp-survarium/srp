void __thiscall Scaleform::GFx::StrokeStyleSwfReader::Read(
        Scaleform::GFx::StrokeStyleSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned int *tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v6; // eax
  unsigned int Pos; // eax
  unsigned __int16 v8; // cx
  unsigned int *v9; // esi
  __int16 U16; // bx
  unsigned int v11; // ebx
  Scaleform::Render::StrokeStyleType *StrokeStyle; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v14; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::Resource_vtbl *v16; // eax
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *p_pFill; // esi
  int v19; // [esp+10h] [ebp-Ch]
  unsigned int v20; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::Resource *v21; // [esp+18h] [ebp-4h]
  float v22; // [esp+20h] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v6 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v6 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v22 = 3.0;
  v8 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v9 = tagType;
  U16 = 0;
  v19 = v8;
  if ( tagType == (unsigned int *)83 )
  {
    U16 = Scaleform::GFx::LoadProcess::ReadU16(p);
    if ( (U16 & 0x20) != 0 )
      v22 = (double)(unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p) * 0.00390625;
  }
  v11 = Scaleform::GFx::StrokeStyleSwfReader::ConvertSwfLineStyles(U16);
  if ( (v11 & 8) != 0 )
  {
    v21 = 0;
    tagType = &v20;
    Scaleform::GFx::FillStyleSwfReader::Read((Scaleform::GFx::FillStyleSwfReader *)&tagType, p, (int)v9);
    this->StrokeStyle->Color = v20;
    this->StrokeStyle->Miter = v22;
    StrokeStyle = this->StrokeStyle;
    this->StrokeStyle->Width = (float)v19;
    if ( v21 )
      Scaleform::RefCountImpl::AddRef(v21);
    pObject = (Scaleform::RefCountVImpl *)StrokeStyle->pFill.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    StrokeStyle->pFill.pObject = (Scaleform::Render::ComplexFill *)v21;
    v14 = (Scaleform::RefCountVImpl *)v21;
    if ( v21 )
    {
      v16 = v21[1].__vftable;
      if ( !v16 || !HIWORD(v16->GetResourceTypeCode) )
      {
LABEL_19:
        if ( v14 )
          Scaleform::RefCountImpl::Release(v14);
        goto LABEL_24;
      }
      v15 = *((_DWORD *)v16->GetResourceReport + 1);
    }
    else
    {
      v15 = v20;
    }
    this->StrokeStyle->Color = v15;
    v14 = (Scaleform::RefCountVImpl *)v21;
    goto LABEL_19;
  }
  Scaleform::GFx::LoadProcess::ReadRgbaTag(p, (Scaleform::Render::Color *)&tagType, (int)v9);
  this->StrokeStyle->Color = (unsigned int)tagType;
  this->StrokeStyle->Miter = v22;
  v17 = (Scaleform::RefCountVImpl *)this->StrokeStyle->pFill.pObject;
  p_pFill = &this->StrokeStyle->pFill;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  p_pFill->pObject = 0;
  this->StrokeStyle->Width = (float)(unsigned int)v19;
LABEL_24:
  this->StrokeStyle->Units = 0.050000001;
  this->StrokeStyle->Flags = v11;
}
