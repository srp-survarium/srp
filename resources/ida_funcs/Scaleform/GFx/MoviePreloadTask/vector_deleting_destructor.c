Scaleform::GFx::MoviePreloadTask *__thiscall Scaleform::GFx::MoviePreloadTask::`vector deleting destructor'(
        Scaleform::GFx::MoviePreloadTask *this,
        char a2)
{
  Scaleform::GFx::MoviePreloadTask::~MoviePreloadTask(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
