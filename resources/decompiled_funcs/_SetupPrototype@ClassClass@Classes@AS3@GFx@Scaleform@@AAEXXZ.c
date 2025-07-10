void __thiscall Scaleform::GFx::AS3::Classes::ClassClass::SetupPrototype(
        Scaleform::GFx::AS3::Classes::ClassClass *this)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Classes::ClassClass_vtbl *v5; // edi
  Scaleform::GFx::AS3::Object *Prototype; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [esp+8h] [ebp-4h] BYREF

  pV = Scaleform::GFx::AS3::VM::MakeObject(this->pTraits.pObject->pVM, &result)->pV;
  pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)this->pPrototype.pObject;
  if ( pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pPrototype.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->pPrototype.pObject = pV;
  }
  v5 = this->__vftable;
  Prototype = Scaleform::GFx::AS3::Class::GetPrototype(this);
  v5->InitPrototype(this, Prototype);
}
