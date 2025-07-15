Scaleform::GFx::LoadBinaryTask *__thiscall Scaleform::GFx::LoadBinaryTask::`scalar deleting destructor'(
        Scaleform::GFx::LoadBinaryTask *this,
        char a2)
{
  Scaleform::GFx::LoadBinaryTask::~LoadBinaryTask(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
