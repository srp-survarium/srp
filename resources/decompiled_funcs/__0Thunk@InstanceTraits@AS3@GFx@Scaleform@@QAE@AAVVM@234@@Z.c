void __thiscall Scaleform::GFx::AS3::InstanceTraits::Thunk::Thunk(
        Scaleform::GFx::AS3::InstanceTraits::Thunk *this,
        Scaleform::GFx::AS3::VM *vm)
{
  const Scaleform::GFx::AS3::ThunkInfo *v3; // esi
  int v4; // ebx

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, &Scaleform::GFx::AS3::fl::FunctionCICpp);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Thunk_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
  this->TraitsType = Traits_Function;
  v3 = Scaleform::GFx::AS3::InstanceTraits::Thunk::f;
  v4 = 3;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, &Scaleform::GFx::AS3::fl::FunctionCI, v3++);
    --v4;
  }
  while ( v4 );
}
