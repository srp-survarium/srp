void __thiscall Scaleform::GFx::AS3::SoundObject::ReleaseTarget(Scaleform::GFx::AS3::SoundObject *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *Volume; // ecx
  unsigned int RefCount; // eax

  pObject = (Scaleform::GFx::CharacterHandle *)this->pSample.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pSample.pObject = 0;
  Volume = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->Volume;
  if ( Volume )
  {
    if ( ((unsigned __int8)Volume & 1) != 0 )
    {
      this->Volume = (int)&Volume[-1].RefCount + 3;
      this->Volume = 0;
    }
    else
    {
      RefCount = Volume->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        Volume->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(Volume);
      }
      this->Volume = 0;
    }
  }
}
