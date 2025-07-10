void __thiscall Scaleform::GFx::TextureGlyphBinder::Visit(
        Scaleform::GFx::TextureGlyphBinder *this,
        unsigned int __formal,
        Scaleform::Render::TextureGlyph *ptextureGlyph)
{
  Scaleform::GFx::ResourceBinding *ResBinding; // ecx
  Scaleform::GFx::Resource_vtbl *v4; // esi
  Scaleform::Render::Image *pObject; // ecx
  volatile unsigned int BindIndex; // [esp-4h] [ebp-10h]
  Scaleform::GFx::ResourceBindData rdata; // [esp+4h] [ebp-8h] BYREF

  if ( !ptextureGlyph->pImage.pObject && ptextureGlyph->BindIndex != -1 )
  {
    ResBinding = this->ResBinding;
    BindIndex = ptextureGlyph->BindIndex;
    rdata.pResource.pObject = 0;
    rdata.pBinding = 0;
    Scaleform::GFx::ResourceBinding::GetResourceData(ResBinding, &rdata, BindIndex);
    if ( rdata.pResource.pObject )
    {
      if ( (rdata.pResource.pObject->GetResourceTypeCode(rdata.pResource.pObject) & 0xFF00) == 0x100 )
      {
        v4 = rdata.pResource.pObject[1].__vftable;
        if ( v4 )
          (*((void (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v4->~Scaleform::GFx::Resource + 1))(rdata.pResource.pObject[1].__vftable);
        pObject = ptextureGlyph->pImage.pObject;
        if ( pObject )
          pObject->Release(pObject);
        ptextureGlyph->pImage.pObject = (Scaleform::Render::Image *)v4;
        ptextureGlyph->BindIndex = -1;
      }
      if ( rdata.pResource.pObject )
        Scaleform::GFx::Resource::Release(rdata.pResource.pObject);
    }
  }
}
