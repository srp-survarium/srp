Scaleform::GFx::AS2::GenericDisplayObj *__thiscall Scaleform::GFx::AS2::GenericDisplayObj::`vector deleting destructor'(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        char a2)
{
  Scaleform::GFx::ShapeBaseCharacterDef *pObject; // ecx

  pObject = this->pDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  Scaleform::GFx::DisplayObjectBase::~DisplayObjectBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
