void __thiscall Scaleform::GFx::AS3::Classes::fl::XMLList::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::XMLList *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  Scaleform::GFx::ASStringNode *v4; // esi
  int v5; // ebx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTableCheckType(this, obj);
  v4 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::fl::XMLList::f;
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
