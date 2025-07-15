Scaleform::GFx::MovieImageLoadTask *__thiscall Scaleform::GFx::MovieImageLoadTask::`scalar deleting destructor'(
        Scaleform::GFx::MovieImageLoadTask *this,
        char a2)
{
  Scaleform::GFx::MovieImageLoadTask::~MovieImageLoadTask(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
