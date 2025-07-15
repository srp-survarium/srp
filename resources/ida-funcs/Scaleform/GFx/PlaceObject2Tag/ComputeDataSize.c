unsigned int __stdcall Scaleform::GFx::PlaceObject2Tag::ComputeDataSize(
        Scaleform::GFx::Stream *pin,
        unsigned int movieVersion)
{
  unsigned int v2; // esi

  v2 = pin->Pos + pin->FilePos - pin->DataSize;
  return Scaleform::GFx::Stream::GetTagEndPosition(pin) - v2;
}
