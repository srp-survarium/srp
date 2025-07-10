void __thiscall Scaleform::GFx::FontResource::ResolveTextureGlyphs(Scaleform::GFx::FontResource *this)
{
  Scaleform::GFx::FontDataBound *v2; // eax
  Scaleform::Render::Font *v3; // eax
  Scaleform::Render::Font *v4; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  if ( this->pFont.pObject->GetTextureGlyphData(this->pFont.pObject) )
  {
    v6 = 79;
    v2 = (Scaleform::GFx::FontDataBound *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            44,
                                            &v6);
    if ( v2 )
    {
      Scaleform::GFx::FontDataBound::FontDataBound(v2, (Scaleform::GFx::Resource *)this->pFont.pObject, this->pBinding);
      v4 = v3;
    }
    else
    {
      v4 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->pFont.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFont.pObject = v4;
  }
}
