Scaleform::GFx::AS2::GFxAS2LoadCSSTask *__thiscall Scaleform::GFx::AS2::GFxAS2LoadCSSTask::`scalar deleting destructor'(
        Scaleform::GFx::AS2::GFxAS2LoadCSSTask *this,
        char a2)
{
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask::~GFxAS2LoadXMLTask(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
