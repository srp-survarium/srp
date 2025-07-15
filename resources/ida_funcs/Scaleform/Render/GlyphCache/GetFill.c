Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::GlyphCache::GetFill(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::TextLayerType type,
        unsigned int textureId)
{
  Scaleform::Render::PrimitiveFill *result; // eax

  switch ( type )
  {
    case TextLayer_Background:
    case TextLayer_Selection:
    case TextLayer_Shapes:
    case TextLayer_Underline:
    case TextLayer_Cursor:
    case TextLayer_Shapes_Masked:
    case TextLayer_Underline_Masked:
      result = this->pSolidFill.pObject;
      break;
    case TextLayer_Shadow:
    case TextLayer_ShadowText:
    case TextLayer_RasterText:
      result = this->Textures[textureId].pFill.pObject;
      break;
    case TextLayer_Mask:
      result = this->pMaskFill.pObject;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
