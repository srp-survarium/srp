Scaleform::GFx::AS3::Instances::fl_display::Scene *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Scene::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::Scene *this,
        char a2)
{
  Scaleform::GFx::Sprite *pObject; // ecx

  pObject = this->SpriteObj.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
