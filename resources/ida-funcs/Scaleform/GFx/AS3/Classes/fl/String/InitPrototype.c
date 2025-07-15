void __thiscall Scaleform::GFx::AS3::Classes::fl::String::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::String *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  Scaleform::GFx::ASStringNode *v4; // esi
  int v5; // ebx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    this,
    obj,
    (Scaleform::GFx::AS3::Value *(__thiscall *__ptr64)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Traits *))(unsigned int)Scaleform::GFx::AS3::Class::ConvertCopy);
  v4 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::fl::String::f;
  v5 = 2;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v4);
    v4 = (Scaleform::GFx::ASStringNode *)((char *)v4 + 20);
    --v5;
  }
  while ( v5 );
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}
