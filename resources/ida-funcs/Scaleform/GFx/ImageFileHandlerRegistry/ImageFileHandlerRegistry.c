void __thiscall Scaleform::GFx::ImageFileHandlerRegistry::ImageFileHandlerRegistry(
        Scaleform::GFx::ImageFileHandlerRegistry *this,
        Scaleform::GFx::ImageFileHandlerRegistry::InitType init)
{
  Scaleform::Render::ImageFileHandlerRegistry *v3; // edi

  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::ImageFileHandlerRegistry_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  v3 = &this->Scaleform::Render::ImageFileHandlerRegistry;
  this->RefCount = 1;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::ImageFileHandlerRegistry_vtbl *)&Scaleform::GFx::State::`vftable';
  this->SType = State_ImageFileHandlerRegistry;
  Scaleform::Render::ImageFileHandlerRegistry::ImageFileHandlerRegistry(
    &this->Scaleform::Render::ImageFileHandlerRegistry,
    0);
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::ImageFileHandlerRegistry_vtbl *)&Scaleform::GFx::ImageFileHandlerRegistry::`vftable'{for `Scaleform::GFx::State'};
  v3->__vftable = (Scaleform::Render::ImageFileHandlerRegistry_vtbl *)&Scaleform::GFx::ImageFileHandlerRegistry::`vftable'{for `Scaleform::Render::ImageFileHandlerRegistry'};
  if ( init == 1 )
  {
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(v3, &Scaleform::Render::SIF::FileReader::Instance);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(v3, &Scaleform::Render::TGA::FileReader::Instance);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(v3, &Scaleform::Render::JPEG::FileReader::Instance);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(v3, &Scaleform::Render::PNG::FileReader::Instance);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(v3, &Scaleform::Render::DDS::FileReader::Instance);
  }
}
