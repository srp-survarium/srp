void __thiscall Scaleform::GFx::AS3::Classes::fl::XML::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  Scaleform::GFx::ASStringNode *v4; // esi
  int v5; // ebx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTableCheckType(this, obj);
  v4 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::fl::XML::f;
  v5 = 3;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v4);
    v4 = (Scaleform::GFx::ASStringNode *)((char *)v4 + 20);
    --v5;
  }
  while ( v5 );
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}
