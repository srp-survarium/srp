void __thiscall Scaleform::GFx::Stream::ReadRgba(Scaleform::GFx::Stream *this, Scaleform::Render::Color *pc)
{
  signed int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 v5; // cl

  Scaleform::GFx::Stream::ReadRgb(this, pc);
  v3 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v3 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  Pos = this->Pos;
  v5 = this->pBuffer[Pos];
  this->Pos = Pos + 1;
  pc->Channels.Alpha = v5;
}
