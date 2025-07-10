unsigned int __stdcall Scaleform::GFx::PlaceObject3Tag::ComputeDataSize(Scaleform::GFx::Stream *pin)
{
  unsigned int v1; // esi

  v1 = pin->Pos + pin->FilePos - pin->DataSize;
  return Scaleform::GFx::Stream::GetTagEndPosition(pin) - v1;
}
