void __thiscall Scaleform::GFx::AS3::Instances::FunctionBase::Construct(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *Object; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> v7; // [esp+8h] [ebp-4h] BYREF

  Object = Scaleform::GFx::AS3::VM::MakeObject(this->pTraits.pObject->pVM, &v7);
  Scaleform::GFx::AS3::Value::Pick(result, Object->pV);
  this->Execute(this, result, argc, argv, 1);
}
