Scaleform::GFx::SubImageResourceInfo *__thiscall Scaleform::GFx::SubImageResourceInfo::`scalar deleting destructor'(
        Scaleform::GFx::SubImageResourceInfo *this,
        char a2)
{
  Scaleform::GFx::ImageResource *pObject; // ecx

  pObject = this->Image.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
