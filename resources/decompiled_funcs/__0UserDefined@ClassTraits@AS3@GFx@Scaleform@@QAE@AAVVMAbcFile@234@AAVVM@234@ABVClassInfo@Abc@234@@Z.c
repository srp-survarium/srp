void __thiscall Scaleform::GFx::AS3::ClassTraits::UserDefined::UserDefined(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, 0);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::UserDefined_vtbl *)&Scaleform::GFx::AS3::ClassTraits::UserDefined::`vftable';
  this->File.pObject = file;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  this->Flags |= 0x10u;
  this->class_info = info;
}
