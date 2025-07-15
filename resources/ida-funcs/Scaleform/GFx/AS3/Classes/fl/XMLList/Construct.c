void __thiscall Scaleform::GFx::AS3::Classes::fl::XMLList::Construct(
        Scaleform::GFx::AS3::Classes::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax

  if ( argc == 1
    && (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, argv),
        ValueTraits->TraitsType == Traits_XMLList)
    && (ValueTraits->Flags & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(_this, argv);
  }
  else
  {
    Scaleform::GFx::AS3::Class::Construct(this, _this, argc, argv, extCall);
  }
}
