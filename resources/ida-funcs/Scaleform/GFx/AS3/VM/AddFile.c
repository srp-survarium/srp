void __thiscall Scaleform::GFx::AS3::VM::AddFile(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *file)
{
  this->Loader->AddFile(this->Loader, file);
}
