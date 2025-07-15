void __thiscall Scaleform::GFx::AS3Support::AS3Support(Scaleform::GFx::AS3Support *this)
{
  this->__vftable = (Scaleform::GFx::AS3Support_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_AS3Support;
  this->__vftable = (Scaleform::GFx::AS3Support_vtbl *)&Scaleform::GFx::AS3Support::`vftable';
  Scaleform::GFx::RegisterTagLoader(0x4Cu, Scaleform::GFx::AS3::SymbolClassLoader);
  Scaleform::GFx::RegisterTagLoader(0x52u, Scaleform::GFx::AS3::DoAbcLoader);
}
