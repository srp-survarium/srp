void __thiscall Scaleform::GFx::Stream::ReadRgb(Scaleform::GFx::Stream *this, Scaleform::Render::Color *pc)
{
  signed int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 v5; // cl
  signed int v6; // edx
  unsigned int v7; // eax
  unsigned __int8 v8; // cl
  signed int v9; // edx
  unsigned int v10; // eax
  unsigned __int8 v11; // cl

  v3 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v3 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  Pos = this->Pos;
  v5 = this->pBuffer[Pos];
  this->Pos = Pos + 1;
  pc->Channels.Red = v5;
  v6 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v6 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  v7 = this->Pos;
  v8 = this->pBuffer[v7];
  this->Pos = v7 + 1;
  pc->Channels.Green = v8;
  v9 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v9 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  v10 = this->Pos;
  v11 = this->pBuffer[v10];
  this->Pos = v10 + 1;
  pc->Channels.Blue = v11;
  pc->Channels.Alpha = -1;
}
