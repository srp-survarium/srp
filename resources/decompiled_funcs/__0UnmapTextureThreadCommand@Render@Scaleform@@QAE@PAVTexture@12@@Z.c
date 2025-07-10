void __thiscall Scaleform::Render::UnmapTextureThreadCommand::UnmapTextureThreadCommand(
        Scaleform::Render::UnmapTextureThreadCommand *this,
        Scaleform::GFx::Resource *ptex)
{
  this->__vftable = (Scaleform::Render::UnmapTextureThreadCommand_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::UnmapTextureThreadCommand_vtbl *)&Scaleform::Render::UnmapTextureThreadCommand::`vftable';
  if ( ptex )
    Scaleform::RefCountImpl::AddRef(ptex);
  this->pTexture.pObject = (Scaleform::Render::Texture *)ptex;
}
