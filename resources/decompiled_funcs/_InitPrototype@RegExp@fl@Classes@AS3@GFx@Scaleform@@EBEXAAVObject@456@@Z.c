void __thiscall Scaleform::GFx::AS3::Classes::fl::RegExp::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::RegExp *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTableCheckType(this, obj);
  Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, (Scaleform::GFx::ASStringNode *)f_5);
}
