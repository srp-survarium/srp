void __thiscall Scaleform::GFx::AS3::Classes::Function::InitPrototype(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  Scaleform::GFx::ASStringNode *v4; // esi
  int v5; // ebx

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  v4 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::Function::f;
  v5 = 4;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v4);
    v4 = (Scaleform::GFx::ASStringNode *)((char *)v4 + 20);
    --v5;
  }
  while ( v5 );
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}
