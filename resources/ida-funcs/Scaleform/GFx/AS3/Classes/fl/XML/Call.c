void __thiscall Scaleform::GFx::AS3::Classes::fl::XML::Call(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        const Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( argc
    && (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pVM, argv), (ValueTraits->Flags & 0x20) == 0)
    && ValueTraits->TraitsType == Traits_XML )
  {
    Scaleform::GFx::AS3::Value::Assign(result, argv);
  }
  else
  {
    this->Construct(this, result, argc, argv, 0);
  }
}
