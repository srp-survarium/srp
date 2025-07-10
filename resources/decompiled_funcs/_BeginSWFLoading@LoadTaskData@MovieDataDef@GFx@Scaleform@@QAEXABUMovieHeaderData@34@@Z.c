void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::BeginSWFLoading(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        const Scaleform::GFx::MovieHeaderData *header)
{
  Scaleform::GFx::MovieHeaderData::operator=(&this->Header, header);
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->LoadingFrame, LS_LoadingFrames);
}
