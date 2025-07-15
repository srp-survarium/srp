void __thiscall Scaleform::Render::TextLayout::TextLayout(
        Scaleform::Render::TextLayout *this,
        const Scaleform::Render::TextLayout::Builder *builder)
{
  this->__vftable = (Scaleform::Render::TextLayout_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::TextLayout_vtbl *)&Scaleform::Render::TextLayout::`vftable';
  this->Param.TextParam.pFont = 0;
  this->Param.TextParam.FontSize = 0;
  this->Param.TextParam.BlurX = 0;
  this->Param.TextParam.GlyphIndex = 0;
  this->Param.TextParam.Flags = 0;
  this->Param.TextParam.BlurY = 0;
  this->Param.TextParam.BlurStrength = 16;
  this->Param.ShadowParam.pFont = 0;
  this->Param.ShadowParam.GlyphIndex = 0;
  this->Param.ShadowParam.Flags = 0;
  this->Param.ShadowParam.BlurY = 0;
  this->Param.ShadowParam.FontSize = 0;
  this->Param.ShadowParam.BlurX = 0;
  this->Param.ShadowParam.BlurStrength = 16;
  this->Param.ShadowOffsetX = 0.0;
  this->Param.ShadowColor = 0;
  this->Param.ShadowOffsetY = 0.0;
  this->Bounds.x1 = 0.0;
  this->Bounds.y1 = 0.0;
  this->Bounds.x2 = 0.0;
  this->Bounds.y2 = 0.0;
  this->ClipBox.x1 = 0.0;
  this->ClipBox.y1 = 0.0;
  this->ClipBox.x2 = 0.0;
  this->ClipBox.y2 = 0.0;
  this->Data.Data.Data = 0;
  this->Data.Data.Size = 0;
  this->Data.Data.Policy.Capacity = 0;
  this->pFonts = 0;
  this->FontCount = 0;
  this->pImages = 0;
  this->ImageCount = 0;
  this->pRefCntData = 0;
  this->RefCntCount = 0;
  Scaleform::Render::TextLayout::Create(this, builder);
}
