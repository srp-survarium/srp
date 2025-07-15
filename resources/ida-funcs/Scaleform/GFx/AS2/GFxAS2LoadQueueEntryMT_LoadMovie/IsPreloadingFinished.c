BOOL __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::IsPreloadingFinished(
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this)
{
  return Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
}
