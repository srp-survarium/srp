Scaleform::GFx::MovieDataDef::LoadTaskData *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::`scalar deleting destructor'(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        char a2)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData::~LoadTaskData(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
