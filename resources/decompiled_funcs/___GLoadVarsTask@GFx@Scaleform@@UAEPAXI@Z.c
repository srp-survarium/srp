Scaleform::GFx::LoadVarsTask *__thiscall Scaleform::GFx::LoadVarsTask::`scalar deleting destructor'(
        Scaleform::GFx::LoadVarsTask *this,
        char a2)
{
  Scaleform::GFx::LoadVarsTask::~LoadVarsTask(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
