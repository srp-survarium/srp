BOOL __thiscall Scaleform::GFx::AS2::CFunctionObject::IsEqual(
        Scaleform::GFx::AS2::CFunctionObject *this,
        Scaleform::GFx::AS2::FunctionObject *f)
{
  return f->IsCFunction(f)
      && this->pFunction == (void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *))f[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
}
