void __thiscall Scaleform::GFx::AS2::ButtonAction::Read(
        Scaleform::GFx::AS2::ButtonAction *this,
        Scaleform::GFx::Stream *pin,
        Scaleform::GFx::TagType tagType,
        unsigned int actionLength)
{
  unsigned int v4; // ebp
  Scaleform::GFx::AS2::ButtonAction *v5; // ebx
  signed int v6; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ecx
  Scaleform::GFx::AS2::ActionBufferData *New; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData> *v10; // esi

  v4 = actionLength;
  v5 = this;
  if ( actionLength )
  {
    if ( tagType == Tag_ButtonCharacter )
    {
      this->Conditions = 8;
    }
    else
    {
      v6 = pin->DataSize - pin->Pos;
      pin->UnusedBits = 0;
      if ( v6 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
      Pos = pin->Pos;
      this = (Scaleform::GFx::AS2::ButtonAction *)*(unsigned __int16 *)&pin->pBuffer[Pos];
      pin->Pos = Pos + 2;
      v5->Conditions = (unsigned __int16)this;
      v4 = actionLength - 2;
    }
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v8);
    New = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
    Scaleform::GFx::AS2::ActionBufferData::Read(New, pin, v4);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v5->Actions.Data,
      &v5->Actions,
      v5->Actions.Data.Size + 1);
    v10 = &v5->Actions.Data.Data[v5->Actions.Data.Size - 1];
    if ( &v5->Actions.Data.Data[v5->Actions.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData> *)4 )
    {
      if ( New )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)New);
      v10->pObject = New;
    }
    if ( New )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)New);
  }
}
