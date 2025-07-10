int __stdcall Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(Scaleform::GFx::Stream *pin)
{
  signed int v1; // eax
  unsigned int Pos; // eax
  unsigned __int8 v3; // bl
  unsigned int v4; // edx

  v1 = pin->DataSize - pin->Pos;
  pin->UnusedBits = 0;
  if ( v1 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(pin);
  Pos = pin->Pos;
  v3 = pin->pBuffer[Pos];
  v4 = pin->FilePos - pin->DataSize;
  pin->Pos = ++Pos;
  Scaleform::GFx::Stream::SetPosition(pin, v4 + Pos - 1);
  return v3 >> 7;
}
