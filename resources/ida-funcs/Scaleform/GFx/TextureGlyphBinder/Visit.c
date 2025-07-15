void __thiscall Scaleform::GFx::TextureGlyphBinder::Visit(
        Scaleform::GFx::TextureGlyphBinder *this,
        unsigned int __formal,
        Scaleform::Render::TextureGlyph *ptextureGlyph)
{
  Scaleform::GFx::ResourceBinding *ResBinding; // ecx
  Scaleform::Render::Image *v4; // esi
  Scaleform::Render::Image *pObject; // ecx
  unsigned int BindIndex; // [esp-4h] [ebp-10h]
  Scaleform::GFx::ResourceBindData v7; // [esp+4h] [ebp-8h] BYREF

  if ( !ptextureGlyph->pImage.pObject && ptextureGlyph->BindIndex != -1 )
  {
    ResBinding = this->ResBinding;
    BindIndex = ptextureGlyph->BindIndex;
    v7.pResource.pObject = 0;
    v7.pBinding = 0;
    Scaleform::GFx::ResourceBinding::GetResourceData(ResBinding, &v7, BindIndex);
    if ( v7.pResource.pObject )
    {
      if ( (v7.pResource.pObject->GetResourceTypeCode(v7.pResource.pObject) & 0xFF00) == 0x100 )
      {
        v4 = (Scaleform::Render::Image *)v7.pResource.pObject[1].__vftable;
        if ( v4 )
          v4->AddRef((struct Scaleform::Render::Image *)v7.pResource.pObject[1].__vftable);
        pObject = ptextureGlyph->pImage.pObject;
        if ( pObject )
          pObject->Release(pObject);
        ptextureGlyph->pImage.pObject = v4;
        ptextureGlyph->BindIndex = -1;
      }
      if ( v7.pResource.pObject )
        Scaleform::GFx::Resource::Release(v7.pResource.pObject);
    }
  }
}
