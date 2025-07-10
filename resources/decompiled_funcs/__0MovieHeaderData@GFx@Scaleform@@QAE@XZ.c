void __thiscall Scaleform::GFx::MovieHeaderData::MovieHeaderData(Scaleform::GFx::MovieHeaderData *this)
{
  this->Version = -1;
  this->FileLength = 0;
  this->FrameRect.x1 = 0.0;
  this->FrameRect.y1 = 0.0;
  this->FrameRect.x2 = 0.0;
  this->FrameRect.y2 = 0.0;
  this->SWFFlags = 0;
  this->FPS = 1.0;
  Scaleform::String::String(&this->mExporterInfo.Prefix);
  Scaleform::String::String(&this->mExporterInfo.SWFName);
  this->mExporterInfo.CodeOffsets.Data.Data = 0;
  this->mExporterInfo.CodeOffsets.Data.Size = 0;
  this->mExporterInfo.CodeOffsets.Data.Policy.Capacity = 0;
  this->mExporterInfo.SI.Format = File_Unopened;
  this->mExporterInfo.SI.pSWFName = 0;
  this->mExporterInfo.SI.pPrefix = 0;
  this->mExporterInfo.SI.ExportFlags = 0;
  this->mExporterInfo.SI.Version = 0;
  this->FrameCount = 1;
}
