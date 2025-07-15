Scaleform::GFx::MovieHeaderData *__thiscall Scaleform::GFx::MovieHeaderData::operator=(
        Scaleform::GFx::MovieHeaderData *this,
        const Scaleform::GFx::MovieHeaderData *__that)
{
  float x2; // [esp+4h] [ebp-8h]
  float y2; // [esp+8h] [ebp-4h]
  float y1; // [esp+10h] [ebp+4h]

  this->FileLength = __that->FileLength;
  this->Version = __that->Version;
  y1 = __that->FrameRect.y1;
  x2 = __that->FrameRect.x2;
  y2 = __that->FrameRect.y2;
  this->FrameRect.x1 = __that->FrameRect.x1;
  this->FrameRect.y1 = y1;
  this->FrameRect.x2 = x2;
  this->FrameRect.y2 = y2;
  this->FPS = __that->FPS;
  this->FrameCount = __that->FrameCount;
  this->SWFFlags = __that->SWFFlags;
  Scaleform::GFx::ExporterInfoImpl::SetData(
    &this->mExporterInfo,
    __that->mExporterInfo.SI.Version,
    __that->mExporterInfo.SI.Format,
    (const __m128i *)__that->mExporterInfo.SI.pSWFName,
    (const __m128i *)__that->mExporterInfo.SI.pPrefix,
    __that->mExporterInfo.SI.ExportFlags,
    0);
  return this;
}
