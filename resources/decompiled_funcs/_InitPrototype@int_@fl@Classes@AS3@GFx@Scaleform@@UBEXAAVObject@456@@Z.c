void __thiscall Scaleform::GFx::AS3::Classes::fl::int_::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::int_ *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  Scaleform::GFx::ASStringNode *v4; // esi
  int v5; // ebx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  v4 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::fl::int_::ti;
  v5 = 6;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v4);
    v4 = (Scaleform::GFx::ASStringNode *)((char *)v4 + 20);
    --v5;
  }
  while ( v5 );
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}
