void __thiscall Scaleform::Render::UnmapTextureThreadCommand::Execute(
        Scaleform::Render::UnmapTextureThreadCommand *this)
{
  Scaleform::Render::Texture *pObject; // ecx

  pObject = this->pTexture.pObject;
  if ( pObject )
    pObject->Unmap(pObject);
}
