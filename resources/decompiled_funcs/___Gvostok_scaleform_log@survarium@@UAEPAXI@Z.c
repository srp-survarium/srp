survarium::vostok_scaleform_log *__thiscall survarium::vostok_scaleform_log::`scalar deleting destructor'(
        survarium::vostok_scaleform_log *this,
        char a2)
{
  Scaleform::Log::~Log(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
