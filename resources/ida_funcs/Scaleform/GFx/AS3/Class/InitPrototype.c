void __thiscall Scaleform::GFx::AS3::Class::InitPrototype(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    this,
    obj,
    (Scaleform::GFx::AS3::Value *(__thiscall *__ptr64)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))(unsigned int)Scaleform::GFx::AS3::Class::ConvertCheckType);
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}
