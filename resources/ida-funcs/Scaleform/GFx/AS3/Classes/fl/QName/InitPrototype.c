void __thiscall Scaleform::GFx::AS3::Classes::fl::QName::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::QName *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Object::AddDynamicFunc(
    obj,
    (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::fl::QName::ti);
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}
