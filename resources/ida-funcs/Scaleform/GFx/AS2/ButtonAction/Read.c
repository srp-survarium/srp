void __thiscall Scaleform::GFx::AS2::ButtonAction::Read(
        Scaleform::GFx::AS2::ButtonAction *this,
        Scaleform::GFx::Stream *pin,
        Scaleform::GFx::TagType tagType,
        unsigned int actionLength)
{
  unsigned int v4; // ebp
  signed int v6; // eax
  unsigned int Pos; // eax
  int v8; // edx
  Scaleform::GFx::AS2::ActionBufferData *New; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData> *v10; // esi

  v4 = actionLength;
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
      v8 = *(unsigned __int16 *)&pin->pBuffer[Pos];
      pin->Pos = Pos + 2;
      this->Conditions = v8;
      v4 = actionLength - 2;
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "-- action conditions %X\n", this->Conditions);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseAction(pin, "-- actions in button\n");
    New = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
    Scaleform::GFx::AS2::ActionBufferData::Read(New, pin, v4);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Actions.Data,
      &this->Actions,
      this->Actions.Data.Size + 1);
    v10 = &this->Actions.Data.Data[this->Actions.Data.Size - 1];
    if ( &this->Actions.Data.Data[this->Actions.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData> *)4 )
    {
      if ( New )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)New);
      v10->pObject = New;
    }
    if ( New )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)New);
  }
}
